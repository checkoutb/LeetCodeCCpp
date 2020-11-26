
#include "../header/myheader.h"

class LT1462
{
public:

// D

// Floyd
//connected[i][j] = connected[i][j] || connected[i][k] && connected[k][j];

// dfs + memo
//dp.resize(n, vector<int>(n, -1));
//        for (int i = 0; i < mp[a].size(); i++) {
//            if (mp[a][i] == b || dfs(mp, mp[a][i], b))
//                return dp[a][b] = 1;
//        }

// bfs
//        for(int i=0; i<n; i++){
//            q.push(i);
//            while(!q.empty()){
//                int node = q.front();
//                q.pop();
//                 for(int neighbor : adj[node]){
//                    if(visited[i][neighbor]) continue;
//                    isReachable[i][neighbor]  = 1;
//                    visited[i][neighbor] = 1;
//                    q.push(neighbor);
//                }
//            }
//        }


// 还没到 之前出错的地方就tle了。。
    vector<bool> lt1462b(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        vector<bool> ans(queries.size(), false);
        vector<vector<int>> vvmap2(n);     // prerequest : course
        vector<bool> haspre(n, false);
        for (vector<int>& pre : prerequisites)
        {
            haspre[pre[1]] = true;
            vvmap2[pre[0]].push_back(pre[1]);
        }
        queue<int> que1;
        for (int i = 0; i < n; ++i)
        {
            if (!haspre[i])
                que1.push(i);
        }
        bool arr[100][100] = {{false}};
        fill(begin(arr[0]), end(arr[0]), false);

        while (!que1.empty())
        {
            int fnt = que1.front();
            que1.pop();
            vector<int>& childs = vvmap2[fnt];
            for (int chd : childs)
            {
                que1.push(chd);
                arr[fnt][chd] = true;
                if (haspre[fnt])
                    for (int i = 0; i < n; ++i)
                    {
                        arr[i][chd] |= arr[i][fnt];
                    }
            }
        }
        for (int i = 0, mxi = queries.size(); i < mxi; ++i)
        {
            if (arr[queries[i][0]][queries[i][1]])
                ans[i] = true;
        }
        return ans;

//        vector<bool> ans(queries.size(), false);
////        unordered_set<int> haspre;
//        unordered_map<int, vector<int>> map2;       // prerequest : {courses}
//        for (vector<int>& pre : prerequisites)
//        {
//            map2[pre[1]].push_back
////            haspre.insert(pre[1]);
//        }
//        queue<int> que1;
//        for (int i = 0; i < n; ++i)
//            if (haspre.find(i) == haspre.end())
//                que1.push(i);
//        while (!que1.empty())
//        {
//
//        }
//        return ans;
    }




// error..
    vector<bool> lt1462a(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
//        vector<vector<int>> vv(n);          // course : {prerequests}
//        for (vector<int>& v : prerequisites)
//        {
//            vv[v[0]].push_back(v[1]);
//        }

        std::sort(begin(prerequisites), end(prerequisites), [](const vector<int>& v1, const vector<int>& v2){ return v1[1] == v2[1] ? v1[0] < v2[0] : v1[1] < v2[1]; });
        bool arr[100][100] = {{false}};         // row is prexxx
        std::fill(begin(arr[0]), end(arr[0]), false);
        for (vector<int>& v : prerequisites)
        {
            arr[v[0]][v[1]] = true;
            for (int i = 0; i < n; ++i)
                arr[i][v[1]] |= arr[i][v[0]];
        }

        std::sort(begin(prerequisites), end(prerequisites), [](const vector<int>& v1, const vector<int>& v2){ return v1[1] == v2[1] ? v1[0] > v2[0] : v1[1] > v2[1]; });
        for (vector<int>& v : prerequisites)
        {
            arr[v[0]][v[1]] = true;
            for (int i = 0; i < n; ++i)
                arr[i][v[1]] |= arr[i][v[0]];
        }
        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i)
        {
            if (arr[queries[i][0]][queries[i][1]])
                ans[i] = true;
        }
        return ans;
    }

};

int main()
{

//    int n{2};
//    vector<vector<int>> pre = {{1,0}};
//    vector<vector<int>> q = {{0,1},{1,0}};

//    int n{5};
//    vector<vector<int>> pre = {{0,1},{3,4},{1,2},{2,3}};
//    vector<vector<int>> q = {{0,4},{4,0},{1,3},{3,0}};

    int n{5};
    vector<vector<int>> pre = {{4,3},{4,1},{4,0},{3,2},{3,1},{3,0},{2,1},{2,0},{1,0}};
    vector<vector<int>> q = {{1,4},{4,2},{0,1},{4,0},{0,2},{1,3},{0,1}};        // [false,true,false,true,false,false,false]



    LT1462 lt;

    vector<bool> ans = lt.lt1462b(n,pre, q);
    for (bool b : ans)
        cout<<b<<", ";

    return 0;
}
