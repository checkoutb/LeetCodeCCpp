
#include "../header/myheader.h"

class LT0115
{
public:

// D D

//        for(int i=0;i<s.size();++i){
//            dp[0][i]=1;
//        }
//        for(int i=1;i<t.size()+1;++i){
//            for(int j=i;j<s.size()+1;++j){
//                dp[i][j]=dp[i][j-1];
//                if(t[i-1]==s[j-1]){
//                    dp[i][j]+=dp[i-1][j-1];
//                }
//            }
//        }
// dp是long
// 他们怎么不溢出的。


//        dp[0] = 1;
//
//        for (int i = 1; i <= m; i++) {
//            for (int j = n; j >= 1; j--) {
//                if (s[i - 1] == t[j - 1])
//                    dp[j] += dp[j - 1];
//            }
//        }


//            if(T.charAt(i) == S.charAt(j)) {
//                mem[i+1][j+1] = mem[i][j] + mem[i+1][j];
//            } else {
//                mem[i+1][j+1] = mem[i+1][j];
//            }


//        for (int j = 1; j <= n; j++) {
//            int pre = 1;
//            for (int i = 1; i <= m; i++) {
//                int temp = cur[i];
//                cur[i] = cur[i] + (t[i - 1] == s[j - 1] ? pre : 0);
//                pre = temp;
//            }
//        }



// so hard,  dynamic programming.
//06/22/2021 14:23	Accepted	4 ms	18.7 MB	cpp
//06/22/2021 14:15	Runtime Error	N/A	N/A	cpp
//06/22/2021 14:12	Runtime Error	N/A	N/A	cpp
//12/17/2020 17:59	Time Limit Exceeded	N/A	N/A	cpp
//10/08/2018 11:22	Wrong Answer	N/A	N/A	java
//10/08/2018 11:17	Runtime Error	N/A	N/A	java
//10/08/2018 11:17	Compile Error	N/A	N/A	java
//10/08/2018 11:14	Runtime Error	N/A	N/A	java
//10/08/2018 10:14	Time Limit Exceeded	N/A	N/A	java
//10/08/2018 10:13	Time Limit Exceeded	N/A	N/A	java
//09/29/2018 17:12	Time Limit Exceeded	N/A	N/A	java
//09/29/2018 15:34	Time Limit Exceeded	N/A	N/A	java
//09/29/2018 15:25	Time Limit Exceeded	N/A	N/A	java
//09/01/2018 17:30	Wrong Answer	N/A	N/A	java
//09/01/2018 17:01	Time Limit Exceeded	N/A	N/A	java
//09/01/2018 17:00	Time Limit Exceeded	N/A	N/A	java
//09/01/2018 16:50	Time Limit Exceeded	N/A	N/A	java
//Runtime: 4 ms, faster than 96.72% of C++ online submissions for Distinct Subsequences.
//Memory Usage: 18.7 MB, less than 23.73% of C++ online submissions for Distinct Subsequences.
    int lt0115d(string s, string t)
    {
        int sz1 = s.size();
        int sz2 = t.size();
        vector<vector<long>> vvi(sz1, vector<long>(sz2, 0));
        for (int i = 0; i < sz1; ++i)
            if (s[i] == t[0])
                vvi[i][0] = 1;
        for (int j = 1; j < sz2; ++j)
        {
            long t2 = 0;
            for (int i = j; i <= sz1 - (sz2 - j); ++i)      // ++++++   <= -(sz2-j)
            {
                t2 += vvi[i - 1][j - 1];            // long 也溢出了。。。
                if (s[i] == t[j])
                    vvi[i][j] = t2;
            }
        }
        #ifdef __test
//        for (myvi& v : vvi)
//        {
//            for (int i : v)
//                cout<<i<<", ";
//            cout<<endl;
//        }
        #endif // __test
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            ans += vvi[i][sz2 - 1];
        }
        return ans;
    }



    int lt0115c(string s, string t)
    {
        int sz1 = s.size();
        int sz2 = t.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, 0));
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == t[0])
            {
                vvi[i][0] = 1;
            }
        }
        for (int j = 1; j < sz2; ++j)
        {
            for (int i = j; i < sz1; ++i)
            {
                if (s[i] == t[j])
                {
                    vvi[i][j] = vvi[i - 1][j] + vvi[i - 1][j - 1];
                }
                else
                {
                    vvi[i][j] = vvi[i - 1][j];
                }
            }
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[sz1 - 1][sz2 - 1];
    }


// babgbag   bag
// 1010100
//  1   1     1  3(前面有3个b，可以和这个a组成3个ba)
//    1  1     1   4(前面有1+3 个 ba，所以可以有4个bag)
// 似乎悟了， 但是好像不用 二维数组。。  ok 也可以用的。  有些数据还是需要保存下的。
// 。。感觉写出来会有点不伦不类。。. 是否需要一个 int 来保存之前的和。
    int lt0115b(string s, string t)
    {
        int sz1 = s.size();
        int sz2 = t.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, 0));

        if (s[0] == t[0])
            vvi[0][0] = 1;
        for (int i = 1; i < sz1; ++i)
        {
            if (s[i] == t[0])
            {
                vvi[i][0] = 1 + vvi[i - 1][0];
            }
            else
            {
                vvi[i][0] = vvi[i - 1][0];
            }
        }
        for (int j = 1; j < sz2; ++j)
        {
            for (int i = j; i < sz1; ++i)
            {
                if (s[i] == t[j])
                {
                    vvi[i][j] = vvi[i - 1][j - 1] + vvi[i - 1][j - 1];
                }
                else
                {
                    vvi[i][j] = vvi[i - 1][j];
                }
            }
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[sz1 - 1][sz2 - 1];
    }


// 子问题应该是  s 和 t[1...,sz]
    int lt0115a(string s, string t)
    {
        int sz1 = s.size();
        int sz2 = t.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, 0));
//        for (int i = 0; i < sz1; ++i)
//        {
//            if (s[i] == t[0])
//            {
//                s[i]++;
//            }
//        }
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                int t2 = 0;

                if (s[i] == t[j])
                {
                    if (i > 0 && j > 0)
                        vvi[i][j] = vvi[i-1][j-1];
                    else
                        vvi[i][j] = 1;
                }
                else
                {
//                    if (i > 0 && j > 0)
//                        vvi[i][j] = vvi[i-1][j-1];
                    if (i > 0 && j > 0)
                        t2 += vvi[i - 1][j - 1];
//                    if (i > 0)
//                        t2 += vvi[i - 1][j];
                    if (j > 0)
                        t2 += vvi[i][j - 1];
                    vvi[i][j] = t2;
//                    vvi[i][j] = max()
                }

//                int t2 = 0;
//                if (i > 0)
//                    t2 += vvi[i - 1][j];
//                if (j > 0)
//                    t2 += vvi[i][j - 1];
//                if (s[i] == t[j])
//                {
//                    if (i > 0 && j > 0)
//                        t2 += vvi[i][j];
//                    vvi[i][j] += t2 + 1;
//                }
//                else
//                {
////                    int t2 = 0;
//                    vvi[i][j] += t2;
//                }
            }
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[sz1 - 1][sz2 - 1];
    }

};

int main()
{
//    string s = "rabbbit";
//    string t = "rabbit";

    string s = "babgbag";
    string t = "bag";

    LT0115 lt;

    cout<<lt.lt0115d(s, t)<<endl;

    return 0;
}
