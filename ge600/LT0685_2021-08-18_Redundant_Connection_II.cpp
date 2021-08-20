
#include "../header/myheader.h"

class LT0685
{
public:

// D D

// uf


// 。。都挺长的。20行以上。


//vector<int> parent(n+1, 0), candA, candB;
// step 1, check whether there is a node with two parents
// step 2, union find
//for (int i = 1; i <= n; i++) parent[i] = i;
//for (auto &edge:edges) {
    // Now every node only has 1 parent, so root of v is implicitly v






//Runtime: 24 ms, faster than 17.79% of C++ online submissions for Redundant Connection II.
//Memory Usage: 13.5 MB, less than 10.67% of C++ online submissions for Redundant Connection II.
// 重复反向边
// 崩了， 不如直接 挨个剔除边，然后看下是否有环。。。
    vector<int> lt0685c(vector<vector<int>>& edges)
    {
        unordered_map<int, vector<int>> map2;
        unordered_map<int, int> map3;
        unordered_map<int, int> map4;
        int db = -1;        // repeat edge
        int sz1 = edges.size();
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = edges[i][0];
            int t3 = edges[i][1];
            map2[t2].push_back(t3);
            map2[t3].push_back(t2);
            if (map3.find(t2 * 10000 + t3) != map3.end())
            {
                db = i;
            }
            map3[t2 * 10000 + t3] = i;
            map3[t3 * 10000 + t2] = -1;         // 。
            map4[t3]++;
        }
        if (db >= 0)
        {
            int t2 = edges[db][0];
            int t3 = edges[db][1];
            if (map4[t2] == 2)
            {
                return {t3, t2};
            }
            else if (map4[t3] == 2)
            {
                return {t2, t3};
            }
            else
            {
                if (map3[t2 * 10000 + t3] > map3[t3 * 10000 + t2])
                {
                    return {t2, t3};
                }
                else
                {
                    return {t3, t2};
                }
            }
        }
        unordered_set<int> set2;
        vector<int> vi;
        int t2 = dfsc1(map2, edges[0][0], set2, vi, -1);

        if (t2 <= 1)
            return {-1, -1};

        #ifdef __test
        showVectorInt(vi);
        for (auto& p : map4)
        {
            cout<<p.first<<" : "<<p.second<<endl;
        }
        #endif // __test


        int a, b, mxi;
        mxi = -1;
        for (int i = 0; i < vi.size(); ++i)
        {
            if (map4[vi[i]] == 2)
            {
                int pre = vi[(i - 1 + vi.size()) % vi.size()];
                int me = vi[i];
                int nxt = vi[(i + 1) % vi.size()];

                if (map3[pre * 10000 + me] == -1)
                {
                    return {nxt, me};
                }
                else if (map3[nxt * 10000 + me] == -1)      // next -> me
                {
                    return {pre, me};
                }
                else
                {


                // 越写越离谱了。。。
                int t2 = max(map3[pre * 10000 + me], map3[me * 10000 + pre]);
                int t3 = max(map3[me * 10000 + nxt], map3[me + nxt * 10000]);
                if (t2 > t3)
                {
                    if (map3[pre * 10000 + me] == -1)
                    {
                        return {me, pre};
                    }
                    else
                    {
                        return {pre, me};
                    }
                }
                else
                {
                    if (map3[me * 10000 + nxt] == -1)
                    {
                        return {nxt, me};
                    }
                    else
                    {
                        return {me, nxt};
                    }
                }

                }

//                if (map3[pre * 10000 + me] > map3[me * 10000 + nxt])
//                {
//                    return {pre, me};
//                }
//                else
//                {
//                    return {me, nxt};
//                }
//                return {vi[(i + 1) % vi.size()], vi[i]};
            }
            int t2 = max(map3[vi[i] * 10000 + vi[(i + 1) % vi.size()]], map3[vi[(i + 1) % vi.size()] * 10000 + vi[i]]);
            if (t2 > mxi)
            {
                mxi = t2;
            }
        }
//        if (map4[vi[vi.size() - 1]] == 2)
//        {
////            return {vi[0], vi[vi.size() - 1]};
//        }
//        t2 = map3[vi[0] * 10000 + vi[vi.size() - 1]];
//        if (t2 > mxi)
//            mxi = t2;
        return edges[mxi];
    }

    // 1:in circle, 0:no circle, 2:has circle, but not in circle
    int dfsc1(unordered_map<int, vector<int>>& map2, int idx, unordered_set<int>& set2, vector<int>& vi, int parent)
    {
        if (set2.find(idx) != end(set2))
        {
            vi.push_back(idx);      // 2nd visit.
            return 1;
//            return true;
        }
//        if (map2.find(idx) != end(map2))      // no-direct.
        set2.insert(idx);
        int t2 = 0;
        for (int i : map2[idx])
        {
            if (i == parent)
                continue;
            if ((t2 = dfsc1(map2, i, set2, vi, idx)) > 0)
            {
                if (t2 == 2)
                    return 2;

                if (vi[0] != idx)
                {
                    vi.push_back(idx);
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
        }
        set2.erase(idx);
        return 0;
    }


// dfs找环可以代替bfs
    vector<int> lt0685b(vector<vector<int>>& edges)
    {
        unordered_set<int> set2;
        unordered_map<int, vector<int>> map2;
        int sz1 = edges.size();
        for (int i = 0; i < sz1; ++i)
        {
            map2[edges[i][0]].push_back(edges[i][1]);
        }
        return {-1,-1};
    }

    // .......  这里没有环。。。只是多了一条边。。。 无向图是环， 有向图不是。
    // 树多一条边， 是无向图的环。
    bool dfsb1(unordered_map<int, vector<int>>& map2, int idx, unordered_set<int>& set2, vector<int>& vi)
    {
        if (set2.find(idx) != end(set2))
        {
            vi.push_back(idx);
            return true;
        }
        if (map2.find(idx) != end(map2))
        {
            for (int i : map2[idx])
            {
                if (dfsb1(map2, i, set2, vi))
                {
                    vi.push_back(idx);
                    return true;
                }
            }
        }
        return false;
    }



// 指向已经遍历过的，就是多余的。
// 多种可能，应该是指root的选择，就Example 2来说， 如果root选4,那么应该删除[3,4]
// 这个应该无所谓，只要第一条边的起始作为root，然后遍历，删除的就是最后一条吧。
// 不，边可以乱序的。 所以 可能会增加一个点 作为root。 碰到点，对比下下标吧。
// 本来想bfs遍历，然后如果 一条边的终点 是已经访问过的，那么就 认为是 多余的， 这里有个问题， 多余 说明成环了， 那么这条环上 下标最大的点是哪个？
// 树中怎么找 环。 好像还是一个 set，碰到的 第一次已访问，就是 环的开始， 但是 环还有分支。那就dfs然后回溯回来？
// 后来想到了uf。uf就是一棵树，多叉树。 当一条边的2个结点 都属于同一颗树时，就是环。
// 不过uf找环有点。 好像更简单了， 不压缩路径的uf 就是一棵二叉树(这道题没有说是不是 二叉树。。)，就是一棵树。
// 从2个结点出发，把 父结点全部 按序获得，， 然后 看下 最早 同时出现在 2个vector中的节点，然后 2边的合并下，就是环。
// 1000个节点也不算多。
// uf吧，  bfs的话，主要是环难处理，数据结构啊。

// ..感觉不对劲，这到题目 应该是 从有向图中找环，然后看环的边 下标最大的。 会不会出现菱形。。就是入度为2. 也无所谓。

// .uf的话，好像不需要 处理环。 碰到环，就是结果。。
    vector<int> lt0685a(vector<vector<int>>& edges)
    {
//        unordered_set<int> set2;        // visited
//        unordered_map<int, vector<pair<int, int>>> map2;        // <start, <end, index>>
//        for (int i = 0; i < edges.size(); ++i)
//        {
//            map2[edges[i][0]].push_back({edges[i][1], i});      // directed
//        }
        unordered_map<int, int> map2;
        vector<int> vi(edges.size() + 1);           // 5个点，4条边，多一条。
        for (int i = 0; i < edges.size(); ++i)
        {
            int p1 = edges[i][0];
            int p2 = edges[i][1];

            map2[p2]++;
//            if (map2[p2] >= 2)
//                return {p1, p2};

            int t1 = uf(vi, p1);        // st
            int t2 = uf(vi, p2);        // en
            #ifdef __test
            cout<<p1<<", "<<p2<<", "<<t1<<", "<<t2<<endl;
            showVectorInt(vi);
            #endif // __test
            if (t1 != 0 && t2 == t1)
            {
//                for (unordered_map<int, int>::iterator it = begin(map2); it != end(map2); it++)
//                {
//                    if (it->second == 2)
//                    {
//                        return {vi[it->first], it->first};          // 不行的，先一个0然后写出6,
//                    }
//                }
                // 好像只有圆的时候 才成环，且没有入度为2的。。

                // 而且可能先o，然后再6, o的时候是不知道 哪个入度2.

                // 而且环不是这样判断的，现在的判断是错误的。  画圆，这里的代码判断不出来的。

                // circle
//                return {p1, p2};
            }
            else
            {
                vi[p2] = p1;
            }
        }
        return edges[0];
//        return {-1, -1};
    }
    int uf(vector<int>& vi, int idx)
    {
        if (vi[idx] == 0)
            return idx;
        return uf(vi, vi[idx]);
//        if (idx == 0)
//            return 0;
//        if (vi[idx] = 0)
//            return uf(vi, vi[idx]);
    }

};

int main()
{
//    myvvi vv = {{1,2},{1,3},{2,3}};     // 2,3
//[[1,2],[2,3],[3,4],[4,1],[1,5]]
//    myvvi vv = {{1,2},{2,3},{3,4},{4,1},{1,5}};       // 4,1

//[[2,1],[3,1],[4,2],[1,4]]
    myvvi vv = {{2,1},{3,1},{4,2},{1,4}};           // 2,1      // 1的入度为2. 目前的代码直接返回第一个行不行。。。不行。

// [[5,2],[5,1],[3,1],[3,4],[3,5]]
//    myvvi vv = {{5,2},{5,1},{3,1},{3,4},{3,5}};         // 3,1 .看来得记录入度了。。出现入度为2的 也可以直接return.. 上面的过不了了。。

    // 看来是，先成环，然后取其中 入度2的。 如果都是入度1,那么返回 下标最大。  就像数字6,出错的边肯定是 交叉的那里。6的收笔不能碰到
    // 会发生覆盖。

//    [[4,2],[1,5],[5,2],[5,3],[2,4]]
//    myvvi vv = {{4,2},{1,5},{5,2},{5,3},{2,4}};         // 4,2


    LT0685 lt;

    myvi v = lt.lt0685c(vv);

    cout<<v[0]<<", "<<v[1]<<endl;

    return 0;
}
