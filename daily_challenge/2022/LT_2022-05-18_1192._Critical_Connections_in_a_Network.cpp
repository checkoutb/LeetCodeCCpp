
#include "../../header/myheader.h"

class LT
{
public:

// D D

//We record the timestamp that we visit each node.
//For each node, we check every neighbor except its parent and return a smallest timestamp in all its neighbors.
//If this timestamp is strictly less than the node's timestamp,we know that this node is somehow in a cycle.
//Otherwise, this edge from the parent to this node is a critical connection.

// dfs内部 就可以知道 是不是割边。






//Runtime: 849 ms, faster than 53.64% of C++ online submissions for Critical Connections in a Network.
//Memory Usage: 181.6 MB, less than 45.21% of C++ online submissions for Critical Connections in a Network.

// 我记得这种 一条边可以把图区分成2个部分的，这种边应该有个名字的。。 搜Tarjan，无关。
// 。。 感觉： 从某个点dfs遍历全部， 由于应该是连同图，所以 能遍历完。 不行，本想的是，在边上记录经过了多少次，如果能划分成2个部分，那么应该是 左部分个数 * 右部分个数。
//                                      。。。 但是有环。而且 可能有路径没有遍历到，导致另外一条边 承担了所有的 遍历。 环好解决，但是 路径没有被遍历到，就不行了。。
// 。。hint： use Tarjan.  割边。 。。 Tarjan的百科里看到了LCA，强连同分量。。没看到 割边。。
//  。。 割边 好像就是 不同强连同分量 之间的边。。。

/*

https://www.cnblogs.com/nullzx/p/7968110.html

假设DFS中我们从顶点U访问到了顶点V（此时顶点V还未被访问过），那么我们称顶点U为顶点V的父顶点，V为U的孩子顶点。
在顶点U之前被访问过的顶点，我们就称之为U的祖先顶点。

显然如果顶点U的所有孩子顶点可以不通过父顶点U而访问到U的祖先顶点，那么说明此时去掉顶点U不影响图的连通性，U就不是割点。
相反，如果顶点U至少存在一个孩子顶点，必须通过父顶点U才能访问到U的祖先顶点，那么去掉顶点U后，顶点U的祖先顶点和孩子顶点就不连通了，说明U是一个割点。


割点：判断顶点U是否为割点，用U顶点的dnf值和它的所有的孩子顶点的low值进行比较，
如果存在至少一个孩子顶点V满足low[v] >= dfn[u]，就说明顶点V访问顶点U的祖先顶点，必须通过顶点U，
而不存在顶点V到顶点U祖先顶点的其它路径，所以顶点U就是一个割点。对于没有孩子顶点的顶点，显然不会是割点。

桥（割边）：low[v] > dfn[u] 就说明V-U是桥

*/
// 看起来是： dfn[] 就是第一次访问这个 结点是的 时间序号。
// low[]，初始值 是dfn， 然后遍历 子结点后， 子结点会返回 它所遇到的最小序号。 然后更新本结点的low，然后返回本结点的low
// 然后 遍历边，如果出现 low[x] > dfn[y] , 那么就是桥。

// 因为 割边 的 对立 应该(可能) 是 环。。 环是 肯定没有 割边的， 所以 low 就是 找环。

    vector<vector<int>> lta(int n, vector<vector<int>>& connections)
    {
        unordered_map<int, vector<int>> map2;
        vector<int> dfn(n, 0);
        vector<int> low(n, INT_MAX);
        vector<vector<int>> ans;

        for (vector<int>& vi : connections)
        {
            map2[vi[0]].push_back(vi[1]);
            map2[vi[1]].push_back(vi[0]);
        }
        int tm = 0;
        dfsa1(map2, dfn, low, tm, 0, -1);

        #ifdef __test
        showVectorInt(dfn);
        showVectorInt(low);
        #endif // __test

        for (vector<int>& vi : connections)
        {
            int w = vi[0], v = vi[1];
            if (low[w] > dfn[v] || low[v] > dfn[w])
            {
                ans.push_back(vi);
            }
        }
        return ans;
    }

    int dfsa1(unordered_map<int, vector<int>>& map2, vector<int>& dfn, vector<int>& low, int& tm, int node, int parent)
    {
//        if (dfn[node] != 0)
//        {
//            return low[]
//        }

        #ifdef __test
        cout<<node<<endl;
        #endif // __test

        tm++;
        int lw = tm;
        dfn[node] = tm;
        low[node] = tm;             // ..........需要先设置，不然 绕一圈后 获得的是 预设置的INT_MAX。。
        for (int chd : map2[node])
        {
//            if (dfn[chd] != 0)        // ... 这个跳过，就没有办法获得 已经遍历过的值了。。。
//            {
//                continue;
//            }
//            if (dfn[chd] != 0)
//            {
//                lw = min()
//            }
//            lw = min(lw, dfsa1(map2, dfn, low, tm, chd));

            if (chd == parent)          // .......
                continue;

            lw = min(lw, dfn[chd] == 0 ? dfsa1(map2, dfn, low, tm, chd, node) : low[chd]);

        }
        low[node] = lw;
        return low[node];
    }


};

int main()
{

    LT lt;

    int n{4};
    myvvi vv = {{0,1},{1,2},{2,0},{1,3}};

    myvvi v2 = lt.lta(n, vv);

    for (myvi& vi : v2)
    {
        cout<<vi[0]<<", "<<vi[1]<<endl;
    }

    return 0;
}
