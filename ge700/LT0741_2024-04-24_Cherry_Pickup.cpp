
#include "../header/myheader.h"

class LT0741
{
public:

    // D D

    // if(dp[i][j][x]!=-1){
    //     return dp[i][j][x];
    //
    // . 当一个机器人位置确定后， 另一个只要 直到 x轴/y轴 的位置 ，就可以 推出 唯一的 y/x 轴位置





// Runtime
// 844ms
// Beats5.10%of users with C++
// Memory
// 401.55MB
// Beats24.74%of users with C++

    // 0 empty, pass,  1,cherry,pass, -1,no cherry,no pass
    // (0,0) right,down to (n,n),  then  left,up to (0,0) 。
    // must reach (n,n)， no road, no cherry
    // 50 * 50
    // ...?
    // 类似于， 2个机器人同时从 (0,0)出发， 然后最终到到(n,n)， 可以拿多少。
    int cherryPickup(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        vector<vector<int>> vvi(sz1 * sz1, vector<int>(sz1 *  sz1, -1));     // [robot1][robot2] = max got
        int ans = 0;
        dfsa1(vvi, 0, 0, 0, 0, grid[0][0], ans, sz1, grid);
        return ans;
    }

    void dfsa1(vector<vector<int>>& vvi, int r1x, int r1y, int r2x, int r2y, int got, int& ans,
               int sz1, vector<vector<int>>&  vv2)
    {
        if (r1x == sz1 - 1 && r1y == sz1 - 1)
        {
            ans = max(ans, got);   //  just vvi[][]
            return;
        }
        int k1 = r1x * sz1 + r1y;
        int k2 = r2x * sz1 + r2y;
        if (vvi[k1][k2] >= got)
            return;

        vvi[k1][k2] = got;
        int n1x,n1y,n2x,n2y;
        int arr[2][2] = {{1,0},{0,1}};
        int pk1, pk2;
        for (int i = 0; i < 2; ++i)
        {
            n1x = r1x + arr[i][0];
            n1y = r1y + arr[i][1];
            if (n1x == sz1 || n1y == sz1 || vv2[n1x][n1y] == -1)
                continue;

            if (vv2[n1x][n1y] == 1)
            {
                vv2[n1x][n1y] = 0;
                pk1 = 1;
                ++got;
            }
            else
            {
                pk1 = 0;
            }

            for (int j = 0; j < 2; ++j)
            {
                n2x = r2x + arr[j][0];
                n2y = r2y + arr[j][1];
                if (n2x == sz1 || n2y == sz1 || vv2[n2x][n2y] == -1)
                    continue;

                pk2 = vv2[n2x][n2y];
                vv2[n2x][n2y] = 0;
                got += pk2;

                dfsa1(vvi, n1x, n1y, n2x, n2y, got, ans, sz1, vv2);

                got -= pk2;
                vv2[n2x][n2y] = pk2;
            }

            got -= pk1;
            vv2[n1x][n1y] = pk1;
        }
    }
};

int main()
{

    LT0741 lt;

    myvvi vv {{0,1,-1},{1,0,-1},{1,1,1}};

    cout<<lt.cherryPickup(vv);

    return 0;
}
