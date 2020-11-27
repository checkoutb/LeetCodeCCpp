
#include "../header/myheader.h"

class LT1519
{
public:

// D D

//void dfs(int i, string &l, vector<vector<int>>& al, int cnt[], vector<int> &res) {
//    if (res[i] == 0) {
//        res[i] = 1;
//        for (auto j : al[i]) {
//            int cnt1[26] = {};
//            dfs(j, l, al, cnt1, res);
//            for (auto k = 0; k < 26; ++k)
//                cnt[k] += cnt1[k];
//        }
//        res[i] = ++cnt[l[i] - 'a'];
//    }
//}
//vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
//    vector<int> res(n);
//    int cnt[26] = {};
//    vector<vector<int>> al(n);
//    for (auto &e : edges) {
//        al[e[0]].push_back(e[1]);
//        al[e[1]].push_back(e[0]);
//    }
//    dfs(0, labels, al, cnt, res);
//    return res;
//}
// res[i] == 0 说明第一次碰到，需要遍历， 其他(子结点又回到父结点)不需要遍历，
// 。。 差不多， 我是 dfs 返回 新数组，  这里是把新数组 作为&参数 发下去， 反正每次都得 新建一个数组。
//  不，差距是  我需要 把 return的 数组 压栈， 应该无所谓， 这里应该压栈的是 一个 指向vector的指针？  不过 那 vector<int>*   这种岂不是废物？
// 。。  难道 真的把 vector 压栈了？。。。。。
// 还有就是 传递的时候 会 触发 复制构造函数 吧？  就是  dfs里的 vector 和 外层接受的 vector 不是同一个对象吧？
// 。。。


// 还好，基本 700ms-1000ms
// 估计主要是 dfs 返回  vector<int>， 但是 后序遍历 只能返回 新的数组啊。。
//Runtime: 1056 ms, faster than 17.83% of C++ online submissions for Number of Nodes in the Sub-Tree With the Same Label.
//Memory Usage: 216.6 MB, less than 45.80% of C++ online submissions for Number of Nodes in the Sub-Tree With the Same Label.
// 多叉树。
    vector<int> lt1519a(int n, vector<vector<int>>& edges, string labels)
    {
        vector<int> ans(n, -1);
        vector<bool> visit(n, false);
        vector<vector<int>> map2(n);
        for (vector<int>& vi : edges)
        {
            map2[vi[0]].push_back(vi[1]);
            map2[vi[1]].push_back(vi[0]);
        }
        vector<int> vi = dfsa1(map2, ans, visit, labels, 0, -1);
        ans[0] = vi[labels[0] - 'a'];       // 。。 多余了。。
        return ans;
    }

    vector<int> dfsa1(vector<vector<int>>& map2, vector<int>& ans, vector<bool>& visit, string& labels, int node, int parent)
    {
        vector<int> ans3(26, 0);
        ans3[labels[node] - 'a']++;
//        visit[node] = true;
        for (int i : map2[node])
        {
//            if (visit[i])
            if (i == parent)
                continue;
            vector<int> vi = dfsa1(map2, ans, visit, labels, i, node);
            for (int i = 0; i < 26; ++i)
                ans3[i] += vi[i];
        }
//        visit[node] = false;
        ans[node] = ans3[labels[node] - 'a'];
        return ans3;
    }

};

int main()
{

//    myvvi vv = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
//    string l = "abaedcd";
//    int n{7};

//    myvvi vv = {{0,1},{1,2},{0,3}};
//    string l = "bbbb";
//    int n{4};

//    myvvi vv = {{0,1},{0,2},{1,3},{0,4}};
//    string l = "aabab";
//    int n{5};

    myvvi vv = {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6}};
    string l = "aaabaaa";
    int n{7};

    LT1519 lt;

    myvi ans = lt.lt1519a(n, vv, l);
    showVectorInt(ans);

    return 0;
}
