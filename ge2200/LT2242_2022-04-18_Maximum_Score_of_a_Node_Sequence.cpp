
#include "../header/myheader.h"

class LT2242
{
public:




// error

// dp保存的是这个节点的 idx 的最大值， 没有 去除 来源。


//    There is an edge connecting every pair of adjacent nodes in the sequence.
//    No node appears more than once in the sequence.
// 这2个加起来，感觉就是 无环 无分叉的路
// 长度4。 dfs不会超时。
// 第一步可以当作有向图 来决定 走向。 不行的，会少。
// 但是节点太多了。  不知道是不是 dfs 一个 长度4的数组 进入。
// 以每个结点都 dfs一次的话，感觉会tle。
// dp， 记录这个节点为起点，长度1/2/3/4 的最大分数。   这样dfs能快一点。
    int lt2242a(vector<int>& scores, vector<vector<int>>& edges)
    {
        int sz1 = scores.size();
        unordered_map<int, vector<int>> map2;
        for (vector<int>& vi : edges)
        {
            map2[vi[0]].push_back(vi[1]);
            map2[vi[1]].push_back(vi[0]);
        }
        vector<vector<int>> vvi(sz1, vector<int>(4, -1));           // 除了本节点，还需要几个节点
        for (int i = 0; i < sz1; ++i)
        {
            vvi[i][0] = scores[i];
        }
        vector<bool> ck(sz1, false);        // checked?
        unordered_set<int> set2;        // circle
        for (int i = 0; i < sz1; ++i)
        {
            if (ck[i])
                continue;

//            set2.clear();
            dfsa1(i, 3, map2, set2, ck, vvi);       // vvi[i][3]
//            dfsa1(i, 2, map2, set2, ck, vvi);
//            dfsa1(i, 1, map2, set2, ck, vvi);
//            ck[i] = true;                        // 会出错。
        }

        int ans = -1;
        for (int i = 0; i < sz1; ++i)
            ans = max(ans, vvi[i][3]);

        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
            {
                cout<<i<<", ";
            }
            cout<<endl;
        }
        #endif // __test

        return ans;
    }

    void dfsa1(int node, int len, unordered_map<int, vector<int>>& map2, unordered_set<int>& set2, vector<bool>& ck, vector<vector<int>>& vvi)
    {
        if (len == 0)
            return;
        if (ck[node])
            return;
        set2.insert(node);
        int t2 = -1;
        for (int n : map2[node])
        {
            if (set2.find(n) != set2.end())
                continue;

            dfsa1(n, len - 1, map2, set2, ck, vvi);
            t2 = max(t2, vvi[n][len - 1]);
        }
        if (t2 != -1)
            vvi[node][len] = t2 + vvi[node][0];
        set2.erase(node);
    }

//    // return 长度idx的最大值  1开始
//    vector<int> dfsa1()
//    {
//
//    }

};

int main()
{

    LT2242 lt;

//    myvi scores = {5,2,9,8,4};
//    myvvi vv = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};

//    myvi scores = {9,20,6,4,11,12};
//    myvvi vv = {{0,3},{5,3},{2,4},{1,3}};

    myvi scores = {1,3,2,1,8,10,12,14};
    myvvi vv = {{6,7},{5,7},{4,7},{3,7},{2,6},{1,6},{0,6},{5,6}};           // 44


    cout<<lt.lt2242a(scores, vv)<<endl;

    return 0;
}
