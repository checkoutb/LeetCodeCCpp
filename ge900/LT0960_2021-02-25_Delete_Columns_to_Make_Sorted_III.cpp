
#include "../header/myheader.h"

class LT0960
{
public:

// D D

//        int m = A.size(), n = A[0].length(), res = n - 1, k;
//        vector<int>dp(n, 1);
//        for (int j = 0; j < n; ++j) {
//            for (int i = 0; i < j; ++i) {
//                for (k = 0; k < m; ++k) {
//                    if (A[k][i] > A[k][j]) break;
//                }
//                if (k == m && dp[i] + 1 > dp[j])
//                    dp[j] = dp[i] + 1;
//            }
//            res = min(res, n - dp[j]);
//        }
//        return res;


//  vector<int> dp(A[0].size(), 1);
//  for (auto i = 0; i < A[0].size(); ++i) {
//    for (auto j = 0; j < i; ++j)
//      for (auto k = 0; k <= A.size(); ++k) {
//        if (k == A.size()) dp[i] = max(dp[i], dp[j] + 1);
//        else if (A[k][j] > A[k][i]) break;
//      }
//  }
//  return A[0].size() - *max_element(begin(dp), end(dp));



//Runtime: 20 ms, faster than 78.10% of C++ online submissions for Delete Columns to Make Sorted III.
//Memory Usage: 10.3 MB, less than 93.43% of C++ online submissions for Delete Columns to Make Sorted III.
// dfs, index 选 或 不选
// dp， 前面所有 字典顺序 小于自己的 长度 + 1 的 max， 这列上所有的行 都是 小于 , 小于自己，大于碰到的。
    int lt0960a(vector<string>& strs)
    {
        int sz1 = strs.size();
        int sz2 = strs[0].size();
        vector<int> vi(sz2);

        for (int i = 0; i < sz2; ++i)       // col
        {
            int t2 = 1;
            for (int j = i - 1; j >= 0; --j)        // prev col
            {
                bool allless = true;
                for (int k = 0; k < sz1; ++k)       // row
                {
                    if (strs[k][i] < strs[k][j])
                    {
                        allless = false;
                        break;
                    }
                }
                if (allless)
                {
                    t2 = max(t2, vi[j] + 1);
                }
            }
            vi[i] = t2;
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test

        return sz2 - *std::max_element(begin(vi), end(vi));
    }

};

int main()
{
//    vector<string> vs = {"babca","bbazb"};
//    vector<string> vs = {"edcba"};
    vector<string> vs = {"ghi","def","abc"};

    LT0960 lt;

    cout<<lt.lt0960a(vs)<<endl;

    return 0;
}
