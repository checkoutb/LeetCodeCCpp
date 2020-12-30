
#include "../header/myheader.h"

class LT0547
{
public:


// D D

//        for (int i = 0; i < n; ++i) {
//            if (!visited[i]) {
//                dfs(M, visited, i);
//                count++;
//            }
//        }
//     void dfs(vector<vector<int>>& M, vector<int>& visited, int i) {
//         visited[i] = true;
//         for (int j = 0; j < M.size(); ++j) {
//             if (M[i][j] && !visited[j]) {
//                 dfs(M, visited, j);
//             }
//         }
//     }

// 借助queue visit bfs。


//return scipy.sparse.csgraph.connected_components(M)[0]

//return len(set(map(tuple, (np.matrix(M, dtype='bool')**len(M)).A)))


//Runtime: 40 ms, faster than 94.97% of C++ online submissions for Number of Provinces.
//Memory Usage: 14 MB, less than 78.64% of C++ online submissions for Number of Provinces.
    int lt0547a(vector<vector<int>>& isConnected)
    {
        int sz1 = isConnected.size();
        vector<int> v(sz1, -1);
        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; ++j)
            {
                if (isConnected[i][j])
                {
//                    cout<<ufa1(v, j)<<", "<<ufa1(v, i)<<endl;
                    int pi = ufa1(v, i);
                    int pj = ufa1(v, j);
                    if (pi != pj)
                        v[pi] = pj;
//                    v[ufa1(v, j)] = ufa1(v, i);
                }
            }
        }
        int ans = 0;
        for (int i : v)
            if (i == -1)
                ans++;
        return ans;
    }

    // return index.
    int ufa1(vector<int>& v, int i)
    {
        if (v[i] == -1)
        {
            return i;
        }
        int idx = ufa1(v, v[i]);
        v[i] = idx;
        return idx;
    }

};

int main()
{
//    myvvi vv = {{1,1,0},{1,1,0},{0,0,1}};

//    myvvi vv = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};

    myvvi vv = {{1,1,1},{1,1,1},{1,1,1}};

    LT0547 lt;

    cout<<lt.lt0547a(vv);

    return 0;
}
