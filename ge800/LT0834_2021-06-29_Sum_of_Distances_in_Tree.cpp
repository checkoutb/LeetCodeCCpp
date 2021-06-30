
#include "../header/myheader.h"

class LT0834
{
public:

// D D



//    Let's solve it with node 0 as root.
//
//    Initial an array of hashset tree, tree[i] contains all connected nodes to i.
//    Initial an array count, count[i] counts all nodes in the subtree i.
//    Initial an array of res, res[i] counts sum of distance in subtree i.
//
//    Post order dfs traversal, update count and res:
//    count[root] = sum(count[i]) + 1
//    res[root] = sum(res[i]) + sum(count[i])
//
//    Pre order dfs traversal, update res:
//    When we move our root from parent to its child i, count[i] points get 1 closer to root, n - count[i] nodes get 1 futhur to root.
//    res[i] = res[root] - count[i] + N - count[i]
//
//    return res, done.
// 2个数组，res count.  res是return的，所以res是每个结点与其他节点的距离和。
// count是 以 结点x为root 的子树的结点数。
// 后续遍历，统计 子树结点数(count)，
// res[root] = sum(res[i]) + sum(count[i])  是什么意思？？ 这个子树的每个子结点的 距离和 和 子树的结点数。。。。？？？

//    vector<unordered_set<int>> tree;
//    vector<int> res, count;
//    void dfs(int root, int pre) {
//        for (auto i : tree[root]) {
//            if (i == pre) continue;
//            dfs(i, root);
//            count[root] += count[i];
//            res[root] += res[i] + count[i];
//        }
//    }
//
//    void dfs2(int root, int pre) {
//        for (auto i : tree[root]) {
//            if (i == pre) continue;
//            res[i] = res[root] - count[i] + count.size() - count[i];      // root是父结点，所以是父结点的 距离和 - 本子树的结点(离本子树更近一步) + 所有结点-本子树(所有-本子树，就是其他结点，离非本子树的结点更远1步)
                                    // 从父结点下来，离本子树中所有每个结点，近了一步， 离非本子树的所有结点 各远了一步。
                            // 。。。这个res[i] 是 左值， 所以之前的赋值感觉没有什么用啊。
                            // 只有res[0] 是有效的。其他都会被覆盖掉。
                            // 所以 res[0] 就是 0和其他结点的距离和。
//            dfs2(i, root);
//        }
//    }

// res[root] = sum(res[i]) + sum(count[i])   就是 所有直接子结点的距离和 + 所有结点数 就等于 它到子树中所有结点的 距离和。
//     有图比较清晰，先 root节点的 所有 直接子节点 的森林 ， 然后增加一个 root节点， 此时的距离和 就是 之前的距离和 + 结点个数(每个结点到原先根结点的距离再加1 就是到新root的距离。)


// 还有，N最大1万，依然都是 myvvi， 然后push_back
// 也有道理，联通图，所以 vvi中每行 都是有值的。 用map也需要1万个k-v对。






//Runtime: 96 ms, faster than 52.60% of C++ online submissions for Sum of Distances in Tree.
//Memory Usage: 34.8 MB, less than 35.91% of C++ online submissions for Sum of Distances in Tree.
// 以0为根。 dfs计算下每个结点的子树中结点总个数。 以及0的总距离。
// 然后dfs移动。  对于每个结点，子数中结点个数的距离会减去， 但是外部的结点个数的距离会增加。
    vector<int> lt0834a(int n, vector<vector<int>>& edges)
    {
        vector<int> vi(n, -1);       // subtree's node count
        int dis = 0;        // distance
        unordered_map<int, vector<int>> map2;
        for (vector<int>& v : edges)
        {
            map2[v[0]].push_back(v[1]);
            map2[v[1]].push_back(v[0]);
        }
        dfsa1(map2, 0, dis, 0, vi, -1);

        #ifdef __test
        cout<<dis<<endl;
        showVectorInt(vi);
        #endif // __test

        vector<int> ans(n, 0);
        ans[0] = dis;
        for (int i : map2[0])
            dfsa2(map2, i, vi, 0, ans);

        return ans;
    }
    void dfsa2(unordered_map<int, vector<int>>& map2, int idx, vector<int>& vi, int prev, vector<int>& ans)
    {
        int t2 = ans[prev];
        int t4 = vi[idx];
        int tother = vi[0] - t4;
        t2 = t2 - t4 + tother;
        ans[idx] = t2;
        for (int i : map2[idx])
        {
            if (prev != i)
                dfsa2(map2, i, vi, idx, ans);
        }
    }
    int dfsa1(unordered_map<int, vector<int>>& map2, int idx, int& dis, int depth, vector<int>& vi, int prev)
    {
        dis += depth;
        int cnt = 1;
//        if (map2.find(idx) != map2.end())         // connected.
            for (int i : map2[idx])
            {
                if (prev != i)
                    cnt += dfsa1(map2, i, dis, depth + 1, vi, idx);
            }
        vi[idx] = cnt;          // include root
        return cnt;
    }

};

int main()
{
    int n = 6;
    myvvi vv = {{0,1},{0,2},{2,3},{2,4},{2,5}};

    LT0834 lt;

    myvi v = lt.lt0834a(n, vv);

    showVectorInt(v);


    return 0;
}
