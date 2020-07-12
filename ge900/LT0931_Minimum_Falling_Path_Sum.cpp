
#include "../header/myheader.h"

class LT0931
{
public:


// D D
//  for (auto i = 1; i < A.size(); ++i)
//    for (auto j = 0; j < A.size(); ++j)
//      A[i][j] += min({ A[i-1][j], A[i-1][max(0,j-1)], A[i-1][min((int)A.size()-1,j+1)] });
//  return *min_element(begin(A[A.size() - 1]), end(A[A.size() - 1]));


//  for (int i = 1; i < A.length; ++i)
//    for (int j = 0; j < A.length; ++j)
//      A[i][j] += Math.min(A[i - 1][j], Math.min(A[i - 1][Math.max(0, j - 1)], A[i - 1][Math.min(A.length - 1, j + 1)]));
//  return Arrays.stream(A[A.length - 1]).min().getAsInt();
// 不需要额外的dp数组


//        auto dp = A;
//                dp[i][j] = dp[i-1][j];
//                if (j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
//                if (j < n-1 ) dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
//                dp[i][j] += A[i][j];
// 这个dp是引用还是单独的？结合代码，肯定是单独的。但是。。。估计是 拷贝构造函数吧。



//Runtime: 40 ms, faster than 13.32% of C++ online submissions for Minimum Falling Path Sum.
//Memory Usage: 9.4 MB, less than 97.38% of C++ online submissions for Minimum Falling Path Sum.
    int lt0931a(vector<vector<int>>& A)
    {
        vector<int> dp(begin(A[0]), end(A[0]));
        int t1 = 0;
        int t2 = 0;
        for (int i = 1; i < A.size(); i++)
        {
            t1 = 1000;
            for (int j = 0; j < A[0].size(); j++)
            {
                t2 = dp[j];
                dp[j] = min(min(A[i][j] + dp[j], A[i][j] + (j == 0 ? 1000 : t1)), A[i][j] + (j + 1 < A[0].size() ? dp[j + 1] : 1000));
                t1 = t2;
            }

            #ifdef __test
            for_each(begin(dp), end(dp), fun_cout);
            cout<<endl;
            #endif // __test

        }
        int ans = dp[0];
        for (int i = 1; i < dp.size(); i++)
        {
            ans = min(ans, dp[i]);
        }
        return ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{1,2,3},{4,5,6},{7,8,9}};

// -98
    vector<vector<int>> vv = {{-51,-35,74},{-62,14,-53},{94,61,-10}};

    LT0931 lt;

    cout<<lt.lt0931a(vv)<<endl;

    return 0;
}
