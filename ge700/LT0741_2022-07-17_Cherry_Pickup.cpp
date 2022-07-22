
#include "../header/myheader.h"

class LT0741
{
public:

    // D

    //  



    // g


    // 2个机器人那个
    int lt0741c(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        vector<vector<vector<int>>> vvvi(sz1, vector<vector<int>>(sz2, vector<int>(sz2, 0)));

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {

            }
        }

        return vvvi[sz1 - 1][sz2 - 1][sz2 - 1];
    }



    // tle。。。
    // 4层for 没有办法追踪果园的状态，但是dfs觉得会tle。。。
    int lt0741b(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        int ans = dfsa1(grid, 0, 0);
        return max(0, ans);
    }

    int dfsa1(vector<vector<int>>& vvi, int row, int col)
    {
        if (row == vvi.size() || col == vvi[0].size())
            return -1;
        if (vvi[row][col] == -1)
            return -1;

        if (row == vvi.size() - 1 && col == vvi[0].size() - 1)
        {
            return dpa1(vvi);
        }

        int t1 = vvi[row][col];
        vvi[row][col] = 0;
        int t2 = dfsa1(vvi, row, col + 1);
        int t3 = dfsa1(vvi, row + 1, col);

        if (t2 == -1 && t3 == -1)
            return -1;
        
        vvi[row][col] = t1;
        return t1 + (max(t2, t3));
    }

    int dpa1(vector<vector<int>>& grd)
    {
        int sz1 = grd.size();
        int sz2 = grd[0].size();

        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MIN >> 2));

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (grd[i][j] == -1)
                    continue;

                if (i == 0 && j == 0)
                {
                    vvi[i][j] = grd[i][j];
                    continue;
                }

                //vvi[i][j] = max(i == 0 ? INT_MIN>>2 : vvi[i - 1][j], (j == 0 ? INT_MIN>>2 : vvi[i][j - 1])) + grd[i][j];

                //if (i == 0)
                //    vvi[i][j] = (j == 0 ? 0 : vvi[i][j - 1]) + grd[i][j];
                //else if (j == 0)
                //    vvi[i][j] = vvi[i - 1][j] + grid[i][j];
                //else

                int tp = i == 0 ? INT_MIN >> 2 : vvi[i - 1][j];
                int lf = j == 0 ? INT_MIN >> 2 : vvi[i][j - 1];

                if (tp < 0 && lf < 0)
                    continue;
                vvi[i][j] = max(tp, lf) + grd[i][j];
            }
        }

#ifdef __test
        cout << " ---------------- " << endl;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                cout << grd[i][j] << ", ";
            }
            cout << endl;
        }
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                cout << vvi[i][j] << ", ";
            }
            cout << endl;
        }
#endif

        return vvi[sz1 - 1][sz2 - 1];
    }



    // 右下  左上
    // 走的路实际上一样的， 所以 是找 2条 00 - sz1sz2 的路， 这两条路的 相加最大。
    // 交叉没有意义，所以 应该是 一条路 始终在另一条路的 上方或 相切。
    // 50*50 * 50*50
    int lt0741a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<vector<vector<vector<int>>>> v4i(sz1, vector<vector<vector<int>>>(sz2, vector<vector<int>>(sz1, vector<int>(sz2, -1))));

        for (int a = 0; a < sz1; ++a)
        {
            for (int b = 0; b < sz2; ++b)
            {
                if (grid[a][b] == -1)
                {
                    continue;
                }
                int t2 = max((a == 0 ? 0 : grid[a - 1][b]), (b == 0 ? 0 : grid[a][b - 1])) + grid[a][b];
                grid[a][b] = 0;
                for (int c = 0; c < sz1; ++c)
                {
                    for (int d = 0; d < sz2; ++d)
                    {

                    }
                }
                //grid[a][b] = 
            }
        }
        return v4i[sz1 - 1][sz2 - 1][sz1 - 1][sz2 - 1];
    }

};

int main()
{

    LT0741 lt;

    //myvvi vv = { {0,1,-1},{1,0,-1},{1,1,1} };

    //myvvi vv = { {1,1,-1},{1,-1,1},{-1,1,1} };

    myvvi vv = { {1, 1, 1, 1, 1}, { 1, 1, -1, 1, 1 }, { -1, -1, 1, 1, 1 }, { 1, 1, 1, 1, 1 }, { -1, 1, 1, 1, 1 }};          // 13


    cout << lt.lt0741b(vv) << endl;

    return 0;
}
