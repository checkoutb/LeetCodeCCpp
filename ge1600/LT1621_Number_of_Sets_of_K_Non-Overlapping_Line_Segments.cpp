
#include "../header/myheader.h"

class LT1621
{
public:

// D D

//    long comb(int n, int m) {
//        return n == 0 || m == 0 ? 1 :
//            dp_pascal[n][m] ? dp_pascal[n][m] :
//                dp_pascal[n][m] = (comb(n - 1, m) + comb(n, m - 1)) % 1000000007;
//    }
//    int numberOfSets(int n, int k) {
//        return comb(n - k - 1, k * 2);
//    }


//        for(i=1;i<=mx;i++)
//            dp[i][0]=1,dp[i][i]=1;
//        dp[1][1] =1;
//        for(i=2;i<=mx;i++){
//            for(j=1;j<i;j++){
//                dp[i][j] = (dp[i-1][j-1] +dp[i-1][j])%(int)(1e9+7);
//            }
//        }


//        for (int i = 1; i < n; ++i) {
//            res[i] = i + res[i-1];
//        }
//
//        for (int m = 2;  m <= k; ++m) {
//            vector<int> cur(n);
//            long long d = 0;
//            for (int i = m; i < n; ++i) {
//                d += res[i-1];
//                cur[i] = (d + cur[i-1])%mod;
//            }
//            swap(cur, res);
//        }


// O(n)
//    public static final int MOD = (int)(1e9 + 7);
//
//    public int numberOfSets(int n, int k) {
//        BigInteger res = BigInteger.valueOf(1);
//        for (int i = 1; i < k * 2 + 1; i++) {
//            res = res.multiply(BigInteger.valueOf(n + k - i));
//            res = res.divide(BigInteger.valueOf(i));
//        }
//        res = res.mod(BigInteger.valueOf(MOD));
//        return res.intValue();
//    }


//int dp[1001][1001] = {};
//class Solution {
//public:
//    int numberOfSets(int n, int k) {
//        if (n - k < 1 || k == 0)
//            return k == 0;
//        if (dp[n][k] == 0) {
//            dp[n][k] = 1 + numberOfSets(n - 1, k);
//            for (int i = n; i - k > 0; --i)
//                dp[n][k] = ((long)dp[n][k] + numberOfSets(i - 1, k - 1)) % 1000000007;
//        }
//        return dp[n][k] - 1;
//    }
//};

//int dp_pascal[2001][2001] = {};
//class Solution {
//public:
//long comb(int n, int m) {
//    return n == 0 || m == 0 ? 1 :
//        dp_pascal[n][m] ? dp_pascal[n][m] :
//            dp_pascal[n][m] = (comb(n - 1, m) + comb(n, m - 1)) % 1000000007;
//}
//int numberOfSets(int n, int k) {
//    return comb(n - k - 1, k * 2);
//}




// 不知道 第二个for中 并列的2个for 怎么合并成一个for。  如果 是 dp[][] 的话，应该可以合并成一个for的。
//Runtime: 56 ms, faster than 78.10% of C++ online submissions for Number of Sets of K Non-Overlapping Line Segments.
//Memory Usage: 6.8 MB, less than 88.45% of C++ online submissions for Number of Sets of K Non-Overlapping Line Segments.
// dp
// [起始，长度]
// 以 j 为起始，可以画(n-j)条线段。  m属于[j,n] 中每个下标作为终点 ，val是个数， 都是 +1。  <=>   vv[k][j] = vv[k][j - 1] + 1 + (en-st);  <=j 的所有 线段 数量。(不一定以j为结尾)
// 乘以 之前所有可能的  e-1条线段 的线段数量， 就是 以 j为终点 的 e 条线段 的数量。
// 推翻了。。。
    int lt1621a(int n, int k)
    {
        int mod = (int) 1E9 + 7;
        vector<int> v(n);
        for (int i = 1; i < n; ++i)
        {
            v[i] = (v[i - 1] + i) % mod;
        }
        #ifdef __test
        showVectorInt(v);
        #endif // __test
        for (int q = 1; q < k; ++q)
        {
            int sum2 = 0;
            for (int i = 1; i < n; ++i)
            {
                int t2 = v[i];
                v[i] = sum2;
                sum2 = (sum2 + t2) % mod;
            }
            for (int i = 1; i < n; ++i)
            {
                v[i] = (v[i - 1] + v[i]) % mod;
            }
            #ifdef __test
            showVectorInt(v);
            #endif // __test
        }
        return v[n - 1];

//        int mod = (int) 1E9 + 7;
//        vector<vector<int>> vv(k, vector<int>(n));
//        for (int i = 0; i < k; ++i)
//        {
//            for (int j = 1; j < n - (k - i) + 1; j++)
//            {
//                vv[k][j] = ((vv[k][j - 1] << 1 + 1) % mod) * ();
//            }
//        }
    }

};

int main()
{

//    int n{4}, k{2};     // 5
//    int n{3}, k{1};       // 3
//    int n{30}, k{7};      // 796297179
//    int n{5}, k{3};       // 7
    int n{3}, k{2};     // 1

    LT1621 lt;

    cout<<lt.lt1621a(n, k);

    return 0;
}
