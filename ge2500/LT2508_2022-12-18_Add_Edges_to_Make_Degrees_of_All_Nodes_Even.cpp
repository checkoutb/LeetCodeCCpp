
#include "../header/myheader.h"

class LT2508
{
public:

    // D D

    //if (odd.size() == 2) {
    //    for (auto& g : graph)
    //        if (!g.count(odd[0]) && !g.count(odd[1])) return true;
    //    return false;
    //}
    //if (odd.size() == 4) {
    //    int cnt = 0;
    //    for (int i = 0; i < 4; ++i)
    //        for (int j = i + 1; j < 4; ++j)
    //            if (graph[odd[i]].count(odd[j])) ++cnt;
    //    return cnt < 3;
    //}



    //if (odd.size() == 2)
    //    for (int i = 1; i <= n; ++i)
    //        if (al[odd[0]].count(i) == 0 && al[odd[1]].count(i) == 0)
    //            return true;
    //if (odd.size() == 4)
    //    return (al[odd[0]].count(odd[1]) == 0 && al[odd[2]].count(odd[3]) == 0)
    //    || (al[odd[0]].count(odd[2]) == 0 && al[odd[1]].count(odd[3]) == 0)
    //    || (al[odd[0]].count(odd[3]) == 0 && al[odd[1]].count(odd[2]) == 0);
    //return odd.size() == 0;


    //Runtime1107 ms
    //    Beats
    //    55 %
    //    Memory137.4 MB
    //    Beats
    //    60 %
    bool lt2508a(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> vvi(n + 1);

        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }
        vector<int> vi;
        for (int i = 1; i <= n; ++i)
        {
            if (vvi[i].size() % 2)
            {
                vi.push_back(i);
            }
        }

        if (vi.empty())
            return true;
        
        if (vi.size() == 2)
        {
            //// 4个点，只有一条边，是false。 不 是true。 。 2个端点都连到 另一个相同点上。
            //// 2个点，一条边 是false。
            //return n > 2;
            // 4个点，全连接，去掉一条边， 是false。

            int a = vi[0], b = vi[1];
            bool in = false;
            for (int i = 0; i < vvi[a].size() && !in; ++i)
            {
                if (vvi[a][i] == b)
                {
                    in = true;
                }
            }

            if (!in)            // a b 没有直接相连
                return true;

            unordered_set<int> set2(begin(vvi[a]), end(vvi[a]));
            set2.insert(begin(vvi[b]), end(vvi[b]));

            if (set2.size() != n)       // 能找到一个点c，它 既没有和a，也没有和b 相连，这样 需要 2条边，连接a-c, b-c 即可 全偶数
            {
                return true;
            }
            else
            {
                return false;
            }

            //std::sort(begin(vvi[a]), end(vvi[a]));
            //std::sort(begin(vvi[b]), end(vvi[b]));

            //int t2 = 1;
            //int idx1 = 0;
            //int idx2 = 0;

            //while (idx1 < vvi[a].size() || idx2 < vvi[b].size())
            //{
            //    if (idx1 == vvi[a].size())
            //    {
            //        if ()
            //        {
            //        }
            //    }
            //    else if (idx2 == vvi[b].size())
            //    {

            //    }
            //    else
            //    {

            //    }
            //}

        }
        else if (vi.size() == 4)
        {
            // 只能穷举3个可能啊。

            int a = vi[0], b = vi[1], c = vi[2], d = vi[3];

            sort(begin(vvi[a]), end(vvi[a]));
            sort(begin(vvi[b]), end(vvi[b]));
            sort(begin(vvi[c]), end(vvi[c]));
            //sort(begin(vvi[d]), end(vvi[d]));

            // a-b
            if (!containa1(vvi[a], b) && !containa1(vvi[c], d))
            {
                return true;
            }

            // a-c
            if (!containa1(vvi[a], c) && !containa1(vvi[b], d))
            {
                return true;
            }

            // a-d
            if (!containa1(vvi[a], d) && !containa1(vvi[b], c))
                return true;

            return false;
        }
        else
        {
            return false;
        }


    }

    bool containa1(vector<int>& vi, int t2)
    {
        //sort(begin(vi), end(vi));
        auto it = lower_bound(begin(vi), end(vi), t2);
        
        return it != end(vi) && (*it == t2);
    }

};

int main()
{

    LT2508 lt;

    int n = 4;
    myvvi vv = { {1,2},{2,3},{2,4},{3,4} };

    cout << lt.lt2508a(n, vv) << endl;

    return 0;
}
