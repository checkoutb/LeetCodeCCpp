
#include "../header/myheader.h"

class LT1293
{
public:

// D D

// bfs

// vector<vector<int>> visited. 保存剩下的次数。 由于bfs，所以步骤必然在增长。







//Runtime: 40 ms, faster than 69.59% of C++ online submissions for Shortest Path in a Grid with Obstacles Elimination.
//Memory Usage: 8.2 MB, less than 97.11% of C++ online submissions for Shortest Path in a Grid with Obstacles Elimination.
// 到达这个点，还剩x次，最少要走几步。
//1 <= m, n <= 40
//1 <= k <= m*n
// 内存会炸的，感觉只要算下 如果k > m+n， 直接返回。 这样 vvvi就ok了。
    int lt1293a(vector<vector<int>>& grid, int k)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        if (k > sz1 + sz2)          // 0,0  sz1,sz2 是不是 0， 这里可以-1,-2
            return sz1 + sz2 - 2;
        vector<vector<vector<int>>> vvvi(sz1, vector<vector<int>>(sz2, vector<int>(k + 1, INT_MAX)));
//        vvvi[0][0][k] = 0;
        // ... hai dei dfs...

//        cout<<"..."<<endl;
//        cout<<k<<endl;

        dfsa1(vvvi, 0, 0, k, grid, 0);
//        cout<<" ."<<endl;
        int ans = *min_element(begin(vvvi[sz1 - 1][sz2 - 1]), end(vvvi[sz1 - 1][sz2 - 1]));
        return ans == INT_MAX ? -1 : ans;
    }
    int arr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    // 好像不需要3维，只需要dfs就可以了。。  不，可以视为memo，不然 tle的。
    void dfsa1(vector<vector<vector<int>>>& vvvi, int i, int j, int eli, vector<vector<int>>& grid, int step)
    {
        #ifdef __test
//        getchar();
        #endif // __test
        if (i < 0 || j < 0 || i >= vvvi.size() || j >= vvvi[0].size())
        {
            return;
        }
        if (grid[i][j] == 1)
            eli--;
        if (eli < 0)
            return;
        if (step >= vvvi[i][j][eli])
            return;
        vvvi[i][j][eli] = step;
        for (int a = vvvi[0][0].size() - 1; a > eli; --a)
        {
            if (vvvi[i][j][a] <= vvvi[i][j][eli])           // 可用次数多，且路程更短。
            {
                return;
            }
        }
        for (int a = 0; a < 4; ++a)
        {
            dfsa1(vvvi, i + arr[a][0], j + arr[a][1], eli, grid, step + 1);
        }
    }

};

int main()
{
//    myvvi vv = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
//    int k = 1;

    myvvi vv = {{0,1,1},{1,1,1},{1,0,0}};
    int k = 1;

    LT1293 lt;

    cout<<lt.lt1293a(vv, k);

    return 0;
}
