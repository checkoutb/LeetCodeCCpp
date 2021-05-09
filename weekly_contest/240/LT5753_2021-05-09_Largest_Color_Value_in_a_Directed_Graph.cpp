
#include "../../header/myheader.h"

class LT5753
{
public:


//1804 / 11577	Ouha 	7	0:16:50	0:06:21 	0:16:50

// D

//Topological Sort


// memo

// dp



// 在每个结点上 保存 后续可能的 数组值？
// tle.......
// 找入度为0的。。 这样会跳过环。没说连通图。
    int lt5753a(string colors, vector<vector<int>>& edges)
    {
        vector<int> vi(123, 0);
        vector<bool> visit(colors.size(), false);
        vector<bool> allvis(colors.size(), false);
        vector<bool> hasIn(colors.size(), false);
        unordered_map<int, vector<int>> map2;
        for (vector<int>& vi : edges)
        {
            map2[vi[0]].push_back(vi[1]);
            hasIn[vi[1]] = true;
        }
        int ans = 0;
        for (int i = 0; i < colors.size(); ++i)
        {
            if (hasIn[i])
                continue;
            int t2 = dfsa1(i, visit, allvis, map2, vi, colors);
            if (t2 == -1)
                return -1;
            ans = max(ans, t2);
        }
        for (int i = 0; i < allvis.size(); ++i)
        {
            if (allvis[i] == false)
                return -1;
        }
        return ans;
    }

    int dfsa1(int node, vector<bool>& visit, vector<bool>& allvis, unordered_map<int, vector<int>>& map2, vector<int>& vi, string& col)
    {
        if (visit[node])
            return -1;

        visit[node] = true;
        allvis[node] = true;
        vi[col[node]]++;
        if (map2.find(node) == map2.end())
        {
            #ifdef __test
//            for (int i = 'a'; i <= 'z'; ++i)
//            {
//                cout<<vi[i]<<endl;
//            }
            #endif // __test

            int t2 = *max_element(begin(vi) + (int) 'a', end(vi));
            vi[col[node]]--;
            visit[node] = false;
            return t2;
        }
        int ans = 0;
        for (int i : map2[node])
        {
            int t2 = dfsa1(i, visit, allvis, map2, vi, col);
            if (t2 == -1)
            {
                return -1;
            }
            ans = max(ans, t2);
        }
        visit[node] = false;
        vi[col[node]]--;
        return ans;
    }


};

int main()
{
//    string s = "abaca";
//    myvvi vv = {{0,1},{0,2},{2,3},{3,4}};

    string s = "a";
    myvvi vv = {{0,0}};

    LT5753 lt;

    cout<<lt.lt5753a(s, vv)<<endl;

    return 0;
}
