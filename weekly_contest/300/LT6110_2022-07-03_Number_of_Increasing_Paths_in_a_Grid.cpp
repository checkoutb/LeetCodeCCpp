
#include "../../header/myheader.h"

class LT6110
{
public:



    
    //814 / 25148	Ouha 	18	1:02 : 20	0 : 07 : 16 	0 : 18 : 10 	0 : 48 : 03 	1 : 02 : 20



    // AC ¡£¡£¡£        2022-7-3 11:32 
    int lta(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        vector<vector<int>> vvi(sz1, vector<int>(sz2, -1));

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (vvi[i][j] == -1)
                {
                    int t2 = dfsa1(grid, vvi, i, j);

                }
            }
        }

        int ans = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                ans = (ans + vvi[i][j]) % MOD;
            }
        }

#ifdef __test

        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout << i << ", ";
            cout << endl;
        }
#endif


        return ans;
    }

    int dfsa1(vector<vector<int>>& grid, vector<vector<int>>& vvi, int r, int c)
    {

#ifdef __test
        cout << r << ", " << c << endl;
#endif

        if (vvi[r][c] != -1)
            return vvi[r][c];

        int arr[] = { 1,0,-1,0,1 };
        int ans = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < 4; ++i)
        {
            int tr = r + arr[i];
            int tc = c + arr[i + 1];

            if (tr < 0 || tc < 0 || tr >= grid.size() || tc >= grid[0].size() || grid[tr][tc] <= grid[r][c])
                continue;

            int t2 = dfsa1(grid, vvi, tr, tc);

            ans = (ans + t2) % MOD;

        }
        vvi[r][c] = (ans + 1) % MOD;
#ifdef __test
        //cout<<" eennndd  "<< r<<", "<<c<<" === "<<
#endif
        return vvi[r][c];
    }

};

int main()
{

    LT6110 lt;

    //myvvi vv = { {1,1},{3,4} };

    myvvi vv = { {1},{2} };

    cout << lt.lta(vv) << endl;

    return 0;
}
