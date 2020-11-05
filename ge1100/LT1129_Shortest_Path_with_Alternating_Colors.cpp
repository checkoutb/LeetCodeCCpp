
#include "../header/myheader.h"

class LT1129
{
public:


// D D

// bfs

//        for (int i = 1; i < n; i++) {
//            res[0][i] = 2 * n;
//            res[1][i] = 2 * n;
//        }
// rv,rb 的初始化。

//Set<Integer>[][] graph = new HashSet[2][n];
//            for (int nxt : graph[1 - colr][vert]) {
//                if (res[1 - colr][nxt] == 2 * n) {
//                    res[1 - colr][nxt] = 1 + res[colr][vert];
//                    q.offer(new int[] {nxt, 1 - colr});
//                }
//            }
// vert 是上一个点，



//Runtime: 36 ms, faster than 71.79% of C++ online submissions for Shortest Path with Alternating Colors.
//Memory Usage: 15.5 MB, less than 5.36% of C++ online submissions for Shortest Path with Alternating Colors.
    vector<int> lt1129b(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges)
    {
        vector<int> rv(n, 10000);
        vector<int> bv(n, 10000);
        unordered_map<int, vector<int>> redmap;
        unordered_map<int, vector<int>> bluemap;
        for (vector<int>& v : red_edges)
        {
            redmap[v[0]].push_back(v[1]);
        }
        for (vector<int>& v : blue_edges)
        {
            bluemap[v[0]].push_back(v[1]);
        }
        rv[0] = 0;
        bv[0] = 0;
        dfsa1(0, true, redmap, bluemap, 0, rv, bv);
        dfsa1(0, false, redmap, bluemap, 0, rv, bv);
        for (int i = 0; i < n; i++)
        {
            int t = min(rv[i], bv[i]);
            rv[i] = t == 10000 ? -1 : t;
        }
        return rv;
    }

    void dfsa1(int lastN, bool lastRed, unordered_map<int, vector<int>>& red, unordered_map<int, vector<int>>& blue, int len, vector<int>& rv, vector<int>& bv)
    {
        len++;
        if (lastRed)
        {
            if (blue.find(lastN) != blue.end())
            {
                vector<int>& v = blue[lastN];
                for (int p : v)
                {
                    if (bv[p] > len)
                    {
                        bv[p] = len;
                        dfsa1(p, false, red, blue, len, rv, bv);
                    }
                }
            }
        }
        else
        {
            if (red.find(lastN) != red.end())
            {
                vector<int>& v = red[lastN];
                for (int p : v)
                {
                    if (rv[p] > len)
                    {
                        rv[p] = len;
                        dfsa1(p, true, red, blue, len, rv, bv);
                    }
                }
            }
        }
    }


//// md,kancuole.
//// md,floyd,dijkstra,prim,kruskal. doubuhui...erqie quanshi jiaquan de .
//// dp? [][][] ?
//    vector<int> lt1129a(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges)
//    {
//        vector<vector<pair<int, int>>> vvp(n, vector<pair<int, int>>(n, {1000, 1000}));
//        vector<int> ans(n);
//
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//
//            }
//        }
//
//        return ans;
//    }


};

int main()
{

//    int n = 3;
//    vector<vector<int>> r = {{0,1},{0,2}};
//    vector<vector<int>> b = {{1,0}};

    int n = 5;
    vector<vector<int>> r = {{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> b = {{1,2},{2,3},{3,1}};



    LT1129 lt;
//    vector<int> v = lt.lt1129b(3,r,b);
//    showVectorInt(v);
    showVectorInt(lt.lt1129b(n,r,b));

    return 0;
}
