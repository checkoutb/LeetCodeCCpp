
#include "../header/myheader.h"

class LT2246
{
public:

// D D


//    int n = parent.size(), res = 1;
//    vector<int> cnt(n), top1(n, 1), top2(n, 1);
//    for (int i = 1; i < n; ++i)
//        ++cnt[parent[i]];
//    vector<int> q;
//    for (int i = 1; i < n; ++i)
//        if (cnt[i] == 0)
//            q.push_back(i);
//    while (!q.empty() && q.back() != 0) {
//        vector<int> q1;
//        for (int i : q) {
//            int p = parent[i];
//            int length = 1 + (s[i] != s[p] ? top1[i] : 0);
//            if (top1[p] <= length) {
//                top2[p] = top1[p];
//                top1[p] = length;
//            }
//            else
//                top2[p] = max(top2[p], length);
//            if (--cnt[p] == 0) {
//                q1.push_back(p);
//                res = max(res, top1[p] + top2[p] - 1);
//            }
//        }
//        swap(q, q1);
//    }
// top1,top2 保存 这个节点 的 最长的 2个路径。



//    int longestPath(vector<int>& parent, string s) {
//        int n = s.size(), res = 0;
//        vector<vector<int>> children(n, vector<int>());
//        for (int i = 1; i < n; ++i)
//            children[parent[i]].push_back(i);
//        dfs(children, s, res, 0);
//        return res;
//    }
//
//    int dfs(vector<vector<int>>& children, string& s, int& res, int i) {
//        int big1 = 0, big2 = 0;
//        for (int& j : children[i]) {
//            int cur = dfs(children, s, res, j);
//            if (s[i] == s[j]) continue;
//            if (cur > big2) big2 = cur;
//            if (big2 > big1) swap(big1, big2);
//        }
//        res = max(res, big1 + big2 + 1);
//        return big1 + 1;
//    }



// 还需要注意 子节点遍历完，才开始 父节点。
//Runtime: 633 ms, faster than 75.00% of C++ online submissions for Longest Path With Different Adjacent Characters.
//Memory Usage: 170.1 MB, less than 100.00% of C++ online submissions for Longest Path With Different Adjacent Characters.
    int lt2246b(vector<int>& parent, string s)
    {
        int sz1 = parent.size();
        vector<int> vi(sz1, 1);
        unordered_set<int> set2;
        unordered_map<int, int> map2;
        for (int i : parent)
        {
            map2[i]++;
            set2.insert(i);
        }

        queue<int> que2;
        for (int i = 0; i < sz1; ++i)
        {
            if (set2.find(i) == set2.end())
            {
                que2.push(i);
            }
        }

        int ans = 1;
        while (!que2.empty())
        {
            int node = que2.front();
            que2.pop();
            int par = parent[node];
            if (par == -1)
                continue;

            map2[par]--;
            if (map2[par] == 0)
                que2.push(par);
            if (s[node] == s[par])
                continue;

            int t2 = vi[node] + 1;
            if ((t2 + vi[par] - 1) > ans)
            {
                ans = t2 + vi[par] - 1;
            }
            vi[par] = max(vi[par], t2);
        }
        return ans;
    }


// parent 不是层级遍历的。。  error
    int lt2246a(vector<int>& parent, string s)
    {
        int ans = 1;
        vector<int> vi(parent.size(), 1);
        for (int i = parent.size() - 1; i >= 0; --i)
        {
            int node = i;
            int par = parent[node];
            if (par == -1)
                continue;

//            if (vi[node] == 0)
//                vi[node] = 1;

            if (s[node] == s[par])
                continue;

            int t2 = vi[node] + 1;
            if ((t2 + vi[par] - 1) > ans)
            {
                ans = t2 + vi[par] - 1;
            }
            vi[par] = max(vi[par], t2);
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test

        return ans;
    }

};

int main()
{

    LT2246 lt;

//    myvi v = {-1,0,0,1,1,2};
//    string s = "abacbe";

//    myvi v = {-1,0,0,0};
//    string s = "aabc";

//    myvi v = {-1,0};
//    string s = "hz";

    myvi v = {-1,137,65,60,73,138,81,17,45,163,145,99,29,162,19,20,132,132,13,60,21,18,155,65,13,163,
    125,102,96,60,50,101,100,86,162,42,162,94,21,56,45,56,13,23,101,76,57,89,4,161,16,139,29,60,44,
    127,19,68,71,55,13,36,148,129,75,41,107,91,52,42,93,85,125,89,132,13,141,21,152,21,79,160,130,103,
    46,65,71,33,129,0,19,148,65,125,41,38,104,115,130,164,138,108,65,31,13,60,29,116,26,58,118,10,138,
    14,28,91,60,47,2,149,99,28,154,71,96,60,106,79,129,83,42,102,34,41,55,31,154,26,34,127,42,133,113,
    125,113,13,54,132,13,56,13,42,102,135,130,75,25,80,159,39,29,41,89,85,19};
    string s = "ajunvefrdrpgxltugqqrwisyfwwtldxjgaxsbbkhvuqeoigqssefoyngykgtthpzvsxgxrqedntvsjcpdnupvqtroxmbpsdwoswxfarnixkvcimzgvrevxnxtkkovwxcjmtgqrrsqyshxbfxptuvqrytctujnzzydhpal";


    cout<<lt.lt2246b(v, s)<<endl;

    return 0;
}
