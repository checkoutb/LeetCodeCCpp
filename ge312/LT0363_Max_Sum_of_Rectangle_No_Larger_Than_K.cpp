
#include "../header/myheader.h"

class LT0363
{
public:



// discuss
//For the solution below, I assume that the number of rows is larger than the number of columns.
//Thus in general time complexity is O[min(m,n)^2 * max(m,n) * log(max(m,n))], space O(max(m, n)).
// 这个是优化后的，无所谓的。普通的也能算。
//    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
//        if (matrix.empty()) return 0;
//        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
//        for (int l = 0; l < col; ++l) {
//            vector<int> sums(row, 0);
//            for (int r = l; r < col; ++r) {
//                for (int i = 0; i < row; ++i) {
//                    sums[i] += matrix[i][r];            // sums[i], r列，[0, i]行 的 行和。。。r的范围是[0,L]到最大列
//                                                // sums[i] 是 (0,L),(x,y)的矩阵的和
//                                                // 这样，问题就变成了  sums中 最接近k但小于k的 差。
//                                                // sums[i]  是 l到r列 i行 的和。
//                }
//
//                // Find the max subarray no more than K
//                set<int> accuSet;
//                accuSet.insert(0);
//                int curSum = 0, curMax = INT_MIN;
//                for (int sum : sums) {          // 外层for的sums。
//                    curSum += sum;              // (0,L)和(?,r)组成的矩阵和
//                    set<int>::iterator it = accuSet.lower_bound(curSum - k);        // 和-k...嗯,下面是 curSum - (curSum - k) == k, lower不小于curSum-k，能保证<=k
//                    if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
//                    accuSet.insert(curSum);
//                }
//                res = std::max(res, curMax);
//            }
//        }
//        return res;
//    }


//    Runtime: 1096 ms, faster than 24.62% of C++ online submissions for Max Sum of Rectangle No Larger Than K.
//    Memory Usage: 10.3 MB, less than 88.24% of C++ online submissions for Max Sum of Rectangle No Larger Than K.
    // 1s,,,,,,,,,
    // most are [400,550] ms....


    // 计算 点和(0,0)组成的矩形的数值和，然后再计算最大值。第二步得O(n*4)啊，或者O(n^2*logn*logn)。。。
    int lt0363a(vector<vector<int>>& matrix, int k)
    {
        int sz1 = matrix.size();
        if (sz1 == 0)
            return 0;
        int sz2 = matrix[0].size();
        if (sz2 == 0)
            return 0;

        int arr2[sz1][sz2] = {};
        arr2[0][0] = matrix[0][0];
        int result = (arr2[0][0] > k ? INT_MIN : arr2[0][0]);           // 不能0，，有负数。。

        for (int i = 1; i < sz2; i++)
        {
            arr2[0][i] = arr2[0][i - 1] + matrix[0][i];
            if (arr2[0][i] <= k)
                result = max(result, arr2[0][i]);
            if (matrix[0][i] <= k)
                result = max(result, matrix[0][i]);
        }

        for (int i = 1; i < sz1; i++)
        {
            arr2[i][0] = arr2[i - 1][0] + matrix[i][0];
            if (arr2[i][0] <= k)
                if (arr2[i][0] > result)
                    result = arr2[i][0];
            if (matrix[i][0] <= k)
                result = max(result, matrix[i][0]);
        }

        for (int i = 1; i < sz1; i++)
        {
            for (int j = 1; j < sz2; j++)
            {
                arr2[i][j] = arr2[i - 1][j] + arr2[i][j - 1] -  arr2[i - 1][j - 1] + matrix[i][j];
                if (arr2[i][j] <= k)
                    if (arr2[i][j] > result)
                        result = arr2[i][j];
                if (matrix[i][j] <= k)
                    result = max(result, matrix[i][j]);
            }
        }

        int t1 = 0;
        int t2 = 0;

        for (int i = 1; i < sz2; i++)
        {
            for (int j = 0; j < i; j++)
            {
                t1 = arr2[0][i] - arr2[0][j];
                if (t1 <= k)
                    result = max(t1, result);
            }
        }

        for (int i = 1; i < sz1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                t1 = arr2[i][0] - arr2[j][0];
                if (t1 <= k)
                    result = max(t1, result);
            }
        }

#ifdef __test
        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz2; j++)
            {
                cout<<arr2[i][j]<<", ";
            }
            cout<<endl;
        }
#endif // __test


        for (int i = 1; i < sz1; i++)
        {
            for (int j = 1; j < sz2; j++)
            {
                t1 = arr2[i][j];
                for (int m = 0; m < i; m++)
                {
                    for (int n = 0; n < j; n++)
                    {
//                        t2 = arr2[i][j] - arr2[i][n] - arr2[m][j] + arr2[m][n];
//                        if (t2 <= k)
//                            result = max(t2, result);

                        // (m,n)是在矩阵中的。
                        t2 = arr2[i][j] - (n > 0 ? arr2[i][n - 1] : 0) - (m > 0 ? arr2[m - 1][j] : 0) + ((n > 0 && m > 0) ? arr2[m - 1][n - 1] : 0);
                        if (t2 <= k)
                            result = max(t2, result);
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> vv = {{1,0,1},{0,-2,3}};
    int k = 2;
//    vector<vector<int>> vv = {{ 5,-4,-3, 4},
//                              {-3,-4, 4, 5},
//                              { 5, 1, 5,-4}};       // [-3,-4,4][5,1,5]
//    int k = 8;

    LT0363 lt;
    cout<<endl<<lt.lt0363a(vv, k)<<endl;
    return 0;
}
