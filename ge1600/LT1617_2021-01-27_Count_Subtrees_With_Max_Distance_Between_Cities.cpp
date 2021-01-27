
#include "../header/myheader.h"

class LT1617
{
public:

// D

// Floyd

// dfs, bitmask
//    nodes == bitset<16>(s).count()



// gg
// 记录每个分支的最大深度， dp
    vector<int> lt1617b(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, int> map2;
    }



// 以任意一个点作为起点，bfs扩展。 去重。   不， 只看最长的，所以会多很多。  一个最长的 + 长度小于最长的点的全排列。
// 树， subtree, 所以是 联通子树， 能找到一个 root
// 最多15个点，所以brute force 估计可以。
// 怎么去重。  点的集合，从小到大排序，组成string | ，  不需要， 最多15 ，所以 1<<15 + 1<<11 + ..
// 感觉，不去重，直接结果/2 不知道对不对的。不对，  感觉是 /端点数。。

// 为什么不是直接 全排序，然后 再计算 最大长度呢。  全排序的时候 计算 最大长度， 就是 最深的 2个点，不， 是root的每个分支的可能的最深的点。
// 分支的最大长度 就是 以这个分支为root，个数-1的 最大长度。  dp
// bu,可能 分支为root 指向了 自己的root，会导致长度不对。
    vector<int> lt1617a(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, int> map2;       // city : tag
        unordered_map<int, vector<int>> map3;       // city : neighbours
        vector<int> ans(n, 0);
        queue<int> que1;
        unordered_set<int> set2;
        vector<vector<int>> vvi(16, vector<int>(16, 0));                // city : length : maxLength
        vector<vector<vector<pair<int, int>>>> vvv(16, vector<vector<pair<int, int>>>(16));       // city : length : <neighbours, tag>
        unordered_map<int, int> map1;       // maxLen : tag
        for (int i = 1; i <= n; ++i)
        {
            map2[i] = 1 << i;
            que1.push(1 << i);
        }
        for (vector<int>& vi : edges)
        {
            map3[vi[0]].push_back(vi[1]);
            map3[vi[1]].push_back(vi[0]);
        }
        for (int i = 1; i <= n; ++i)
        {
            vvv[i][0].push_back(i);
        }
        for (int i = 1; i <= n; ++i)        // length
        {
            for (int j = 1; j <= n; ++j)        // city
            {
                for (pair<int, int>& pii : vvv[j][i])
                {
                    int nb = pii.first;
                    int tag = pii.second;       // where is parent's tag?
                }
//                for (int nb : vvv[j][i])        // neighbours
//                {
//                    int par = nb / 100;         // parent + self;
//                    int sf = nb % 100;
//                    for (int chd : map3[sf])
//                    {
//                        if (par == chd)
//                            continue;
//                        vvv[j][i + 1].push_back(sf * 100 + chd);
//                    }
//                }
                vector<int> tvi;
                for (int m = 0; m < vvv[j][i].size(); ++m)
                {
                    tvi.push_back(vv[j][i]);
                }
                sort(begin(tvi), end(tvi));
//                int mxlen =
            }
        }
        return ans;
    }

};

int main()
{

    LT1617 lt;


    return 0;
}
