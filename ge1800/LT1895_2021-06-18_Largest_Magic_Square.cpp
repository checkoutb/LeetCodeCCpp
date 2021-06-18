
#include "../header/myheader.h"

class LT1895
{
public:

// D D

//    int m = grid.size(), n = grid[0].size(), res = 0;
//    vector<vector<int>> rows(m + 2, vector<int>(n + 2)), cols(rows), d1(rows), d2(rows);
//    for (int i = 1; i <= m; ++i)
//        for (int j = 1; j <= n; ++j) {
//            rows[i][j] += grid[i - 1][j - 1] + rows[i][j - 1];
//            cols[i][j] += grid[i - 1][j - 1] + cols[i - 1][j];
//            d1[i][j] += grid[i - 1][j - 1] + d1[i - 1][j - 1];
//            d2[i][j] += grid[i - 1][j - 1] + d2[i - 1][j + 1];
//        }
//    for (int i = 1; i <= m; ++i)
//        for (int j = 1; j <= n; ++j)
//            for (int k = min(m - i, n - j); k > res; --k) {
//                int sum = d1[i + k][j + k] - d1[i - 1][j - 1];
//                bool match = sum == d2[i + k][j] - d2[i - 1][j + k + 1];
//                for (int l = 0; l <= k && match; ++l) {
//                    match &= sum == rows[i + l][j + k] - rows[i + l][j - 1];
//                    match &= sum == cols[i + k][j + l] - cols[i - 1][j + l];
//                }
//                res = match ? k : res;
//            }
//    return res + 1;


//    int m = grid.size(), n = grid[0].size(), res = 0;
//    vector<vector<int>> rows(m + 2, vector<int>(n + 2)), cols(rows);
//    for (int i = 1; i <= m; ++i)
//        for (int j = 1; j <= n; ++j) {
//            rows[i][j] += grid[i - 1][j - 1] + rows[i][j - 1];
//            cols[i][j] += grid[i - 1][j - 1] + cols[i - 1][j];
//        }
//    for (int i = 1; i <= m; ++i)
//        for (int j = 1; j <= n; ++j)
//            for (int k = min(m - i, n - j); k > res; --k) {
//                int sum = rows[i][j + k] - rows[i][j - 1], l = 0, d1 = 0, d2 = 0;
//                for (; l <= k; ++l) {
//                    if (sum != rows[i + l][j + k] - rows[i + l][j - 1]
//                        || sum != cols[i + k][j + l] - cols[i - 1][j + l])
//                        break;
//                    d1 += grid[i - 1 + l][j - 1 + l];
//                    d2 += grid[i - 1 + k - l][j - 1 + l];
//                }
//                res = l > k && d1 == sum && d2 == sum ? k : res;
//            }
//    return res + 1;




//Runtime: 20 ms, faster than 93.56% of C++ online submissions for Largest Magic Square.
//Memory Usage: 10.2 MB, less than 43.89% of C++ online submissions for Largest Magic Square.
    int lt1895a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<vector<int>> vvr(sz1, vector<int>(sz2, 0));        // row's sum
        vector<vector<int>> vvc(sz1, vector<int>(sz2, 0));        // column
        for (int i = 0; i < sz1; ++i)
        {
            vvr[i][0] = grid[i][0];
        }
        for (int j = 0; j < sz2; ++j)
        {
            vvc[0][j] = grid[0][j];
        }
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 1; j < sz2; ++j)
            {
                vvr[i][j] = vvr[i][j - 1] + grid[i][j];
            }
        }
        for (int j = 0; j < sz2; ++j)
        {
            for (int i = 1; i < sz1; ++i)
            {
                vvc[i][j] = vvc[i - 1][j] + grid[i][j];
            }
        }
        #ifdef __test
//        for (myvi& vi : vvr)
//        {
//            for (int i : vi)
//                cout<<i<<", ";
//            cout<<endl;
//        }
//        for (myvi& vi : vvc)
//        {
//            for (int i : vi)
//                cout<<i<<", ";
//            cout<<endl;
//        }

        #endif // __test
        int ans = 1;
        for (int i = 0; i < sz1 - 1; ++i)
        {
            for (int j = 0; j < sz2 - 1; ++j)
            {
                int mxlen = min(sz1 - i, sz2 - j);
                for (int len = ans + 1; len <= mxlen; len++)
                {
                    if (isMagic(grid, i, j, len, vvr, vvc))
                    {
                        #ifdef __test
//                        cout<<"aaa "<<len<<endl;
                        #endif // __test
                        ans = len;
                    }
                }
            }
        }
        return ans;
    }

    bool isMagic(vector<vector<int>>& vvi, int i, int j, int len, vector<vector<int>>& vvr, vector<vector<int>>& vvc)
    {
        int tr = -1;
//        int tc = -1;
        int t1 = 0;
        int t2 = 0;
        for (int m = 0; m < len; ++m)
        {
            int trbig = vvr[i + m][j + len - 1];
            int trsml = j == 0 ? 0 : vvr[i + m][j - 1];
            if (tr == -1)
                tr = (trbig - trsml);
            if (tr != (trbig - trsml))
            {
//                #ifdef __test
//                if (i == 1 && j == 1)
//                {
//                    cout<<(trbig)<<", "<<trsml<<" = = ="<<tr<<endl;
//                }
//                #endif // __test
                return false;
            }

//            if (tr != -1 && tr != (trbig - trsml))
//            {
//                return false;
//            }
//            tr = trbig - trsml;

            int tcbig = vvc[i + len - 1][j + m];
            int tcsml = i == 0 ? 0 : vvc[i - 1][j + m];
            if (tr != (tcbig - tcsml))
            {
//                #ifdef __test
//                if (i == 1 && j == 1)
//                {
//                    cout<<tr<<", "<<tcbig<<",.... "<<tcsml<<", "<<m<<", "<<len<<", "<<i<<", "<<j<<endl;
//                }
//                #endif // __test
                return false;
            }

            t1 += vvi[i + m][j + m];
            t2 += vvi[i + m][j + len - 1 - m];

        }
        #ifdef __test
//        cout<<i<<", "<<j<<endl;
        #endif // __test
        return t1 == t2 && t1 == tr;
    }


};

int main()
{

//    myvvi vv = {{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};

    myvvi vv = {{5,1,3,1},{9,3,3,1},{1,3,3,8}};

    LT1895 lt;

    cout<<lt.lt1895a(vv)<<endl;

    return 0;
}
