
#include "../header/myheader.h"

class LT1857
{
public:

    // D D

    //class Solution {
    //    typedef array<int, 26> T;
    //public:
    //    int largestPathValue(string C, vector<vector<int>>& E) {
    //        unordered_map<int, vector<int>> G;
    //        vector<int> indegree(C.size());
    //        for (auto& e : E) {
    //            G[e[0]].push_back(e[1]); // build graph
    //            indegree[e[1]]++; // count indegrees
    //        }
    //        vector<T> cnt(C.size(), T{}); // cnt[i][j] is the maximum count of j-th color from the ancester nodes to node i.
    //        queue<int> q;
    //        for (int i = 0; i < C.size(); ++i) {
    //            if (indegree[i] == 0) { // if this node has 0 indegree, we can use it as a source node
    //                q.push(i);
    //                cnt[i][C[i] - 'a'] = 1; // the count of the current color should be 1
    //            }
    //        }
    //        int ans = 0, seen = 0;
    //        while (q.size()) {
    //            auto u = q.front();
    //            q.pop();
    //            int val = *max_element(begin(cnt[u]), end(cnt[u])); // we use the maximum of all the maximum color counts as the color value.
    //            ans = max(ans, val);
    //            ++seen;
    //            for (int v : G[u]) {
    //                for (int i = 0; i < 26; ++i) {
    //                    cnt[v][i] = max(cnt[v][i], cnt[u][i] + (i == C[v] - 'a')); // try to use node `u` to update all the color counts of node `v`.
    //                }
    //                if (--indegree[v] == 0) {
    //                    q.push(v);
    //                }
    //            }
    //        }
    //        return seen < C.size() ? -1 : ans;
    //    }
    //};
    // This line int val = *max_element(begin(cnt[u]), end(cnt[u])); can be replaced with int val = cnt[u][C[u] - 'a']; because there must be a path that has the greatest color value and ends with the corresponding color.
    // 。入度为0，可以作为topo sort的起点。
    // 这里 --indegree[v] == 0 才会 push 到队列中，所以如果有环，那么 环的"开始"节点，被 "开始"节点 自己ref着，所以 入度永远不可能为0.
    //      所以 seen < C.size，
    // 出现次数最多的颜色，它出现最多次的时候，肯定是在 它这个颜色的节点上的， 所以 不需要 max_element，只需要 使用 本节点的颜色 就可以了。



//Runtime: 1159 ms, faster than 33.08 % of C++ online submissions for Largest Color Value in a Directed Graph.
//Memory Usage : 284.6 MB, less than 5.31 % of C++ online submissions for Largest Color Value in a Directed Graph.
    int lt1857a(string colors, vector<vector<int>>& edges)
    {
        int sz1 = colors.size();
        //vector<bool> vst(sz1, false);
        vector<vector<int>> vvi(sz1, vector<int>(26, -1));

        unordered_map<int, vector<int>> map2;
        for (vector<int>& vi : edges)
        {
            map2[vi[0]].push_back(vi[1]);
            if (vi[0] == vi[1])
                return -1;
        }

        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            dfsa1(colors, i, vvi, map2);
            for (int c : vvi[i])
            {
                if (c == -1)
                    return -1;
                ans = max(ans, c);
            }
        }
        return ans;
    }

    void dfsa1(string& cls, int idx, vector<vector<int>>& vvi, unordered_map<int, vector<int>>& map2)
    {
        if (vvi[idx][0] != -1)
            return;

        if (vvi[idx][1] == -2)
        {
            return;
        }
        vvi[idx][1] = -2;

        vector<int> vi(26, 0);
        for (int nxt : map2[idx])
        {
            dfsa1(cls, nxt, vvi, map2);
            if (vvi[nxt][0] == -1)
            {
                vvi[idx][0] = -1;
                return;
            }
            else
            {
                for (int i = 0; i < 26; ++i)
                {
                    vi[i] = max(vi[i], vvi[nxt][i]);
                }
            }
        }
        vi[cls[idx] - 'a']++;
        for (int i = 0; i < 26; ++i)
        {
            vvi[idx][i] = vi[i];
        }
    }

};

int main()
{

    LT1857 lt;

    //string cls = "abaca";
    //myvvi vv = { {0,1},{0,2},{2,3},{3,4} };

    string cls = "a";
    myvvi vv = { {0,0} };

    cout << lt.lt1857a(cls, vv) << endl;

    return 0;
}
