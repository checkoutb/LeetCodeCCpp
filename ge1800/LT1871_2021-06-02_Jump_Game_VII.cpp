
#include "../header/myheader.h"

class LT1871
{
public:


// D D

//        for (int i = 1; i < n; ++i) {
//            if (i >= minJ)
//                pre += dp[i - minJ];
//            if (i > maxJ)
//                pre -= dp[i - maxJ - 1];
//            dp[i] = pre > 0 && s[i] == '0';
//        }
// ?





// coooooool
//06/02/2021 17:03	Accepted	48 ms	15.8 MB	cpp
//06/02/2021 16:59	Wrong Answer	N/A	N/A	cpp
//06/02/2021 16:53	Time Limit Exceeded	N/A	N/A	cpp
//06/02/2021 16:50	Time Limit Exceeded	N/A	N/A	cpp
//06/02/2021 16:37	Time Limit Exceeded	N/A	N/A	cpp
//06/02/2021 16:35	Time Limit Exceeded	N/A	N/A	cpp
//06/02/2021 16:34	Time Limit Exceeded	N/A	N/A	cpp
//Runtime: 48 ms, faster than 91.04% of C++ online submissions for Jump Game VII.
//Memory Usage: 15.8 MB, less than 94.59% of C++ online submissions for Jump Game VII.
// 试下 保存上个0的位置。只看增量。
    bool lt1871c(string s, int minJump, int maxJump)
    {
        int sz1 = s.size();
        if (s[sz1 - 1] != '0')
            return false;
        for (int i = minJump, mxi = min(sz1 - 1, maxJump); i <= mxi; ++i)
        {
            if (s[i] == '0')
                s[i] = '2';
        }
        int lst0 = 0;
//        int gap = maxJump - minJump + 1;        // .
        for (int i = 1; i < sz1; ++i)
        {
            if (s[i] == '2')
            {
//                if ((i - lst0) > gap)         // 不需要，'2'必然在上个0 的范围内。
//                cout<<(lst0 + maxJump + 1)<<", "<<(i + minJump)<<endl;
                for (int j = max(lst0 + maxJump + 1, i + minJump), mxj = min(i + maxJump, sz1 - 1); j <= mxj; ++j)
                {
                    if (s[j] == '0')
                        s[j] = '2';
                }

                lst0 = i;
                #ifdef __test
                cout<<s<<endl;
                #endif // __test
                if (s[sz1 - 1] == '2')
                    return true;
            }
        }
        return s[sz1 - 1] == '2';
    }


// tle.
    bool lt1871b(string s, int minJump, int maxJump)
    {
        int sz1 = s.size();
        if (s[sz1 - 1] != '0')
            return false;
//        for (int i = 0; i < )     // 感觉 dp 也是tle啊。
//        for (int i = 0; i < sz1; ++i)
//        {
//            if (s[i] != '1')
//            {
//                // .. 保存和上个0 的距离，这样只需要 看下 新增的距离 中是否有 0.
//            }
//        }

//        int idx = 0;
//        for (int i = 0; i < sz1; ++i)
//        {
//            if (s[i] == '0')
//            {
//
//            }
//        }

        for (int i = minJump, mxi = min(sz1 - 1, maxJump); i <= mxi; ++i)
        {
            if (s[i] == '0')
            {
                s[i] = '2';
            }
        }

        for (int i = 1; i < sz1; ++i)
        {
            if (s[i] == '2')
            {
                for (int j = i + minJump, mxj = min(sz1 - 1, i + maxJump); j <= mxj; ++j)
                {
                    if (s[j] == '0')
                    {
                        s[j] = '2';
                    }
                }
            }
            if (s[sz1 - 1] == '2')
                return true;
        }
        #ifdef __test
        cout<<s<<endl;
        #endif // __test
        return s[sz1 - 1] == '2';
    }


// tle
    bool lt1871a(string s, int minJump, int maxJump)
    {
        int sz1 = s.size();
        if (s[sz1 - 1] != '0')
            return false;
        return dfsa1(s, sz1, minJump, maxJump, 0);
    }

    bool dfsa1(string& s, int sz1, int mn, int mx, int idx)
    {
        if (idx == sz1 - 1)
            return true;

//        for (int i = idx + mn, mxi = min(sz1 - 1, mx + idx); i <= mxi; ++i)       // tle.
        for (int i = min(sz1 - 1, mx + idx), mni = idx + mn; i >= mni; --i)     // tle.
        {
            if (s[i] == '0')
            {
                if (dfsa1(s, sz1, mn, mx, i))
                    return true;
                s[i] = '1';          // .  tle...
            }
        }
        return false;
    }


};

int main()
{
//    string s = "011010";
////    string s = "01101110";
//    int mn = 2;
//    int mx = 3;

    string s = "00111010";
    int mn = 3;
    int mx = 5;


    LT1871 lt;

    cout<<lt.lt1871c(s, mn, mx)<<endl;

    return 0;
}
