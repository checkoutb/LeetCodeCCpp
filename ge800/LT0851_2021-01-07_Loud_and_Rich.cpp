
#include "../header/myheader.h"

class LT0851
{
public:

// D D

//    int dfs(int i, vector<int>& quiet) {
//        if (res[i] >= 0) return res[i];
//        res[i] = i;
//        for (int j : richer2[i]) if (quiet[res[i]] > quiet[dfs(j, quiet)]) res[i] = res[j];
//        return res[i];
//    }
// <0 就是 自己。



//        while (!q.empty()) {
//            auto idx = q.front();
//            q.pop_front();
//            for (auto next : graph[idx]) {
//                if (quiet[answers[next]] > quiet[answers[idx]]) {
//                    answers[next] = answers[idx];
//                }
//                if (--indegrees[next] == 0) {
//                    q.push_back(next);
//                }
//            }
//        }
// bfs



//Runtime: 196 ms, faster than 72.83% of C++ online submissions for Loud and Rich.
//Memory Usage: 43.3 MB, less than 59.78% of C++ online submissions for Loud and Rich.
    vector<int> lt0851a(vector<vector<int>>& richer, vector<int>& quiet)
    {
        unordered_map<int, vector<int>> map2;       // poor : rich
        for (vector<int>& vi : richer)
        {
            map2[vi[1]].push_back(vi[0]);
        }
        vector<int> ans(quiet.size(), -1);
        for (int i = 0; i < quiet.size(); ++i)
            ans[i] = -1 - i;
        for (int i = 0; i < quiet.size(); ++i)
        {
            if (ans[i] < 0)
            {
                dfsa1(ans, map2, i, quiet);
            }
        }
        return ans;
    }
    int dfsa1(vector<int>& ans, unordered_map<int, vector<int>>& map2, int x, vector<int>& q)
    {
        vector<int>& vi = map2[x];
        if (ans[x] >= 0)
            return ans[x];

        int gtmnx = -(ans[x] + 1);
//        cout<<" . ."<<x<<endl;
        for (int i : vi)
        {
            if (ans[i] < 0)
            {
                int gt2 = dfsa1(ans, map2, i, q);
//                if ()
            }

//            if (q[gtmnx < 0 ? -(gtmnx + 1) : gtmnx] > q[ans[i]])
//                gtmnx = ans[i];
            if (q[gtmnx] > q[ans[i]])
                gtmnx = ans[i];

//            cout<<i<<endl;
//            if (ans[i] != -1)
//            {
////                if (gtmnx < 0)
////                {
////                    gtmnx = ans[i];
////                }
////                else
////                {
//                    if (q[gtmnx] > q[ans[i]])
//                    {
//                        gtmnx = ans[i];
//                    }
////                }
//            }
//            else
//            {
//                int gt2 = dfsa1(ans, map2, i, q);
////                if (gtmnx < 0)
////                    gtmnx = gt2;
////                else
//                    if (q[gtmnx] > q[gt2])
//                        gtmnx = gt2;
//            }
        }
//        if (gtmnx < 0)
//            gtmnx = -(gtmnx + 1);
        ans[x] = gtmnx;
        return gtmnx;
    }

};

int main()
{

    myvvi v = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    myvi q = {3,2,5,4,6,1,7,0};

    LT0851 lt;

    myvi vi = lt.lt0851a(v, q);

    showVectorInt(vi);

    return 0;
}
