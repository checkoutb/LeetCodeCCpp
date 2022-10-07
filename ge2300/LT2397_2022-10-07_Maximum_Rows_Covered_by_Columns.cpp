
#include "../header/myheader.h"

class LT2397
{
public:

    // D D

    //int next_popcount(int n) {
    //    int c = (n & -n), r = n + c;
    //    return (((r ^ n) >> 2) / c) | r;
    //}
    //int maximumRows(vector<vector<int>>& mat, int cols) {
    //    int m = mat.size(), n = mat[0].size(), res = 0;
    //    for (int mask = (1 << cols) - 1; mask < (1 << n); mask = next_popcount(mask)) {
    //        int rows = 0;
    //        for (int i = 0, j = 0; i < m; ++i) {
    //            for (j = 0; j < n; ++j)
    //                if (mat[i][j] && (mask & (1 << j)) == 0)
    //                    break;
    //            rows += j == n;
    //        }
    //        res = max(res, rows);
    //    }
    //    return res;
    //}


//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Maximum Rows Covered by Columns.
//Memory Usage : 8.5 MB, less than 85.10 % of C++ online submissions for Maximum Rows Covered by Columns.

    // .. 这问的应该是， 如果原数组 有1，那么这行 的 1 必须全部 被 包含。  或者原数组中 这行没有1.  这2种情况 ans + 1.
    // 
    // 要取1，就必须拿完全部的1， 0可以随意
    // 要么 全0， 一个1 也不拿。  1所在的列
    // 1<< .  |  全0 ，  & 全1
    // chose or not
    int lt2397a(vector<vector<int>>& matrix, int numSelect)
    {
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();
        //vector<int> vi(sz2);
        vector<int> vi(sz1);
        for (int j = 0; j < sz2; ++j)
        {
            for (int i = 0; i < sz1; ++i)
            {
                vi[i] += matrix[i][j];
            }

            //int t2 = 0;
            //for (int i = 0; i < sz1; ++i)
            //{
            //    if (matrix[i][j])
            //    {
            //        t2 |= (1 << matrix[i][j]);
            //    }
            //}
            //vi[j] = t2;
        }
        int ans = 0;
        //dfsa1(vi, 0, numSelect, sz2, 0, INT_MAX, ans, sz1);
        
        vector<int> v2(sz1);

        dfsa2(matrix, 0, sz1, sz2, numSelect, v2, ans, vi);

        return ans;
    }


    void dfsa2(vector<vector<int>>& vvi, int idx, int& sz1, int& sz2, int remain, vector<int>& vi, int& ans, vector<int>& vfix)
    {
        if (idx == sz2)
        {
            if (remain == 0)
            {
                int t2 = 0;
                for (int i = 0; i < sz1; ++i)
                {
                    if (vfix[i] == 0 || vi[i] == vfix[i])
                        ++t2;
                }
                ans = max(ans, t2);
            }
            return;
        }
        if (remain > (sz2 - idx))
        {
            return;
        }

        dfsa2(vvi, idx + 1, sz1, sz2, remain, vi, ans, vfix);

        if (remain > 0)
        {
            for (int i = 0; i < sz1; ++i)
            {
                if (vvi[i][idx])
                {
                    vi[i]++;
                }
            }
            dfsa2(vvi, idx + 1, sz1, sz2, remain - 1, vi, ans, vfix);
            for (int i = 0; i < sz1; ++i)
            {
                if (vvi[i][idx])
                    --vi[i];
            }
        }
    }
    

    // ... error
    void dfsa1(vector<int>& vi, int idx, int remain, int sz2, int valor, int valand, int& ans, int& sz1)
    {
        if (idx == vi.size())
        {
            if (remain == 0)
            {
                int t2 = 0;
                
                for (int i = 0; i < sz1; i += 1)
                {
                    if ((valor & (1 << i)) == 0)
                    {
                        t2++;
                    }
                }

                while (valand > 0)
                {
                    t2++;
                    valand = valand - (valand & (-valand));
                }
                ans = max(ans, t2);
            }
            return;
        }
        if (remain > sz2)
        {
            return;
        }

        dfsa1(vi, idx + 1, remain, sz2 - 1, valor, valand, ans, sz1);

        if (remain > 0)
            dfsa1(vi, idx + 1, remain - 1, sz2 - 1, valor | vi[idx], valand & vi[idx], ans, sz1);

    }

};

int main()
{

    LT2397 lt;

    //myvvi vv = { {0,0,0},{1,0,1},{0,0,1} };
    //myvvi vv = { {0,0,0},
    //             {1,0,1},
    //             {0,1,1},
    //             {0,0,1} };
    //int ns = 2;

    //myvvi vv = { {1},{0} };
    //int ns = 1;

    myvvi vv = { {1,0},{0,1},{1,1} };
    int ns = 1;

    cout << lt.lt2397a(vv, ns) << endl;

    return 0;
}
