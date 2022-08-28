
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //int res = INT_MIN, rows = m.size(), cols = m[0].size();
    //for (int l = 0; l < cols; ++l) {
    //    vector<int> sums(rows);
    //    for (int r = l; r < cols; ++r) {
    //        for (int i = 0; i < rows; ++i)
    //            sums[i] += m[i][r];
    //        set<int> s = { 0 };
    //        int run_sum = 0;
    //        for (int sum : sums) {
    //            run_sum += sum;
    //            auto it = s.lower_bound(run_sum - k);
    //            if (it != end(s))
    //                res = max(res, run_sum - *it);
    //            s.insert(run_sum);
    //        }
    //    }
    //}
    //return res;
    //
    // l - r ÁÐ ¡£ ËÑË÷ res¡£


    //for (int r = l; r < cols; ++r) {
    //    int kadane = 0, max_kadane = INT_MIN;
    //    for (int i = 0; i < rows; ++i) {
    //        sums[i] += m[i][r];
    //        kadane = max(kadane + sums[i], sums[i]);
    //        max_kadane = max(max_kadane, kadane);
    //    }
    //    if (max_kadane <= k) {
    //        res = max(res, max_kadane);
    //        continue;
    //    }
    //    set<int> s = { 0 };



//Runtime: 1983 ms, faster than 34.35 % of C++ online submissions for Max Sum of Rectangle No Larger Than K.
//Memory Usage : 10.4 MB, less than 97.15 % of C++ online submissions for Max Sum of Rectangle No Larger Than K.
    int lta(vector<vector<int>>& matrix, int k)
    {
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();
        int ans = INT_MIN;          // .
        for (int i = 0; i < sz1; ++i)
        {
            int pfx = 0;
            for (int j = 0; j < sz2; ++j)
            {
                if (matrix[i][j] <= k && matrix[i][j] > ans)
                    ans = matrix[i][j];

                pfx += matrix[i][j];
                matrix[i][j] = (i > 0 ? matrix[i - 1][j] : 0) + pfx;
                
                if (pfx <= k && pfx > ans)
                    ans = pfx;
                
                if (matrix[i][j] <= k && matrix[i][j] > ans)
                    ans = matrix[i][j];
            }
        }

#ifdef __test
        for (myvi& v : matrix)
        {
            for (int i : v)
                cout << i << ", ";
            cout << endl;
        }
#endif

        if (ans == k)
            return ans;

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                for (int m = i; m < sz1; ++m)
                {
                    for (int n = j; n < sz2; ++n)
                    {
                        int t2 = matrix[m][n] - (i > 0 ? matrix[i - 1][n] : 0) - (j > 0 ? matrix[m][j - 1] : 0) + ((i > 0 && j > 0) ? matrix[i - 1][j - 1] : 0);
                        if (t2 <= k && t2 > ans)
                        {
#ifdef __test
                            cout << i << ", " << j << ", " << m << ", " << n << " --- " << t2 << endl;
#endif
                            ans = t2;
                            if (ans == k)
                                return k;
                        }
                    }
                }
            }
        }

        return ans;
    }

};

int main()
{

    LT lt;

    //myvvi vv = { {1,0,1},{0,-2,3} };
    //int k = 2;

    myvvi vv = { {5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4} };
    int k = 3;

    cout << lt.lta(vv, k) << endl;

    return 0;
}
