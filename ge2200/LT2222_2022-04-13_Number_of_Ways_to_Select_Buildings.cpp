
#include "../header/myheader.h"

class LT2222
{
public:

// D D

// 不用辅助数组，直接4个int记录 前面 后面 1 0的个数， 2个for，第一个for找出 0，1的个数， 第二个开始计算ans及 0 1 的个数


// dp
//        for i in range(len(s)):
//            if s[i] == "0":
//                dp["0"] += 1
//                dp["10"] += dp["1"]
//                dp["010"] += dp["01"]
//            if s[i] == "1":
//                dp["1"] += 1
//                dp["01"] += dp["0"]
//                dp["101"] += dp["10"]

//        long dp[4][2] = {};
//        dp[0][0] = dp[0][1] = 1;
//        for (int i = 0; i < s.size(); ++i) {
//            for (int len = 1; len <= 3; ++len) {
//                dp[len][s[i] - '0'] += dp[len - 1][1 - (s[i] - '0')];
//            }
//        }
//        return dp[3][0] + dp[3][1];


//long long numberOfWays(string &s, char firstLast) {
//    long long first = 0, second = 0, comb = 0, res = 0;
//    for (char ch : s)
//        if (ch == firstLast) {
//            comb += first * second;
//            res += comb;
//            second = 0;
//            ++first;
//        }
//        else
//            ++second;
//    return res;
//}
//long long numberOfWays(string s) {
//    return numberOfWays(s, '0') + numberOfWays(s, '1');
//}


// ...? 怎么这么慢，这个是 O(N) 吧
//Runtime: 2264 ms, faster than 5.04% of C++ online submissions for Number of Ways to Select Buildings.
//Memory Usage: 487.7 MB, less than 5.02% of C++ online submissions for Number of Ways to Select Buildings.
    long long lt2222b(string s)
    {
        int sz1 = s.size();
        vector<vector<int>> vv1(sz1, vector<int>(2, 0));            // prefix
        vector<vector<int>> vv2(sz1, vector<int>(2, 0));        // suffix
        if (s[0] == '0')
            vv1[0][0] = 1;
        else
            vv1[0][1] = 1;
        for (int i = 1; i < sz1; ++i)
        {
            vv1[i][0] = vv1[i - 1][0];
            vv1[i][1] = vv1[i - 1][1];

            if (s[i] == '0')
            {
                vv1[i][0]++;
            }
            else
            {
                vv1[i][1]++;
            }
        }
        if (s[sz1 - 1] == '0')
            vv2[sz1 - 1][0] = 1;
        else
            vv2[sz1 - 1][1] = 1;
        for (int i = sz1 - 2; i >= 0; --i)
        {
            vv2[i][0] = vv2[i + 1][0];
            vv2[i][1] = vv2[i + 1][1];
            if (s[i] == '0')
                vv2[i][0]++;
            else
                vv2[i][1]++;
        }
        long long ans = 0LL;
        for (int i = 1; i < sz1 - 1; i++)
        {
            if (s[i] == '0')
            {
                ans += 1LL * vv1[i][1] * vv2[i][1];
            }
            else
                ans += 1LL * vv1[i][0] * vv2[i][0];
        }
        return ans;
    }


// error
    long long lt2222a(string s)
    {
        int sz1 = s.size();
        vector<vector<long long>> vvi(sz1, vector<long long>(2, 0LL));
        vvi[sz1 - 1][0] = s[sz1 - 1] == '0';
        vvi[sz1 - 1][1] = 1 - vvi[sz1 - 1][0];
        for (int i = sz1 - 2; i >= 0; --i)
        {
            vvi[i][0] = vvi[i + 1][0];
            vvi[i][1] = vvi[i + 1][1];
            if (s[i] == '0')
                vvi[i][0]++;
            else
                vvi[i][1]++;
        }
        #ifdef __test
        for (vector<long long>& vi : vvi)
        {
            cout<<vi[0]<<", ";
        }
        cout<<endl;
        for (vector<long long>& vi : vvi)
            cout<<vi[1]<<", ";
        cout<<endl;
        #endif // __test
        for (int i = 0; i < sz1; ++i)
        {
            swap(vvi[i][0], vvi[i][1]);         // 第二个选择这个，有多少种可能
        }
        for (int i = sz1 - 2; i >= 0; --i)
        {
            vvi[i][0] += vvi[i + 1][0];
            vvi[i][1] += vvi[i + 1][1];
        }
        long long ans = 0LL;
        for (int i = 0; i < sz1 - 2; ++i)
        {
            if (s[i] == '0')
            {
                ans += vvi[i][1];
            }
            else
            {
                ans += vvi[i][0];
            }
        }
        #ifdef __test
        for (vector<long long>& vi : vvi)
        {
            cout<<vi[0]<<", ";
        }
        cout<<endl;
        for (vector<long long>& vi : vvi)
            cout<<vi[1]<<", ";
        cout<<endl;
        #endif // __test
        return ans;

//        for (int i = sz1 - 2; i >= 0; --i)
//        {
//            vvi[i][0] = vvi[i + 1][0];
//            vvi[i][1] = vvi[i + 1][1];
//            if (s[i] == '0')
//                vvi[i][0] += vvi[i][1];
//            else
//                vvi[i][1] += vvi[i][0];
//        }
//        for (int i = 0)
    }

};

int main()
{

    LT2222 lt;

    string s = "001101";
//    string s = "111000";

    cout<<lt.lt2222b(s)<<endl;

    return 0;
}
