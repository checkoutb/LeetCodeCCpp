
#include "../header/myheader.h"

class LT2207
{
public:

// D D

//        long long res = 0, cnt1 = 0, cnt2 = 0;
//        for (char& c: text) {
//            if (c == pattern[1])
//                res += cnt1, cnt2++;
//            if (c == pattern[0])
//                cnt1++;
//        }
//        return res + max(cnt1, cnt2);


//    long long cnt0 = 1, cnt1 = 1, res0 = 0, res1 = 0;
//    for (int i = 0, j = t.size() - 1; j >= 0; ++i, --j) {
//        if (t[i] == pat[1])
//            res0 += cnt0;
//        if (t[j] == pat[0])
//            res1 += cnt1;
//        cnt0 += t[i] == pat[0];
//        cnt1 += t[j] == pat[1];
//    }
//    return max(res0, res1);


//Runtime: 142 ms, faster than 40.00% of C++ online submissions for Maximize Number of Subsequences in a String.
//Memory Usage: 26.6 MB, less than 40.00% of C++ online submissions for Maximize Number of Subsequences in a String.
    long long lt2207b(string text, string pattern)
    {
//        if (pattern[0] == pattern[1])
//        {
//            int cnt2 = std::count_if(begin(text), end(text), [&](char ch){ return ch == pattern[0]; });
//            return 1LL * cnt2 * (cnt2 + 1);
//        }
        int sz1 = text.size();
        vector<int> v1(sz1, 0);
        v1[sz1 - 1] = (text[sz1 - 1] == pattern[1]);
        int cnt1 = text[sz1 - 1] == pattern[0];
        int cnt2 = v1[sz1 - 1];
        for (int i = sz1 - 2; i >= 0; --i)
        {
            v1[i] = v1[i + 1] + (text[i] == pattern[1]);
            cnt1 += (text[i] == pattern[0]);
            cnt2 += (text[i] == pattern[1]);
        }
        #ifdef __test
        showVectorInt(v1);
        #endif // __test
        long long ans = 0LL;
        for (int i = 0; i < sz1 - 1; ++i)
        {
            if (text[i] == pattern[0])
            {
                ans += v1[i + 1];
            }
        }
//        int t2 = text[0] == pattern[0];
//        for (int i = 1; i < sz1; ++i)
//        {
////            ans += 1LL * t2 * v1[i];
//            ans += v1[i];
////            t2 += (text[i] == pattern[0]);
//            #ifdef __test
//            cout<<ans<<", "<<t2<<endl;
//            #endif // __test
//        }
        ans += max(cnt1, cnt2);
        return ans;
    }


// error。。。
// 就是要找到一个点， 这个点之前的 p0个数 * 之后的p1个数 最大。 更确切的说是 (p0+1) * p1 或 p0 * (p1+1) 。 而且 +1 应该是加到 小的那个上 能让乘积更大。
// 只是希望 p0 千万 。。。 本想说 不等于 p1， 但是 如果相等的话， 好像更简单。。
    long long lt2207a(string text, string pattern)
    {
        if (pattern[0] == pattern[1])
        {
            int cnt2 = std::count_if(begin(text), end(text), [&](char ch){ return ch == pattern[0]; });
            return 1LL * cnt2 * (cnt2 + 1);
        }
        int sz1 = text.size();
        vector<int> v1(sz1, 0);
        vector<int> v2(sz1, 0);
        v1[0] = (text[0] == pattern[0]);
        for (int i = 1; i < sz1; ++i)
        {
            v1[i] = v1[i - 1] + (text[i] == pattern[0]);
        }
        v2[sz1 - 1] = (text[sz1 - 1] == pattern[1]);
        for (int i = sz1 - 2; i >= 0; --i)
        {
            v2[i] = v2[i + 1] + (text[i] == pattern[1]);
        }
        long long ans = 0LL;

        #ifdef __test
        showVectorInt(v1);
        showVectorInt(v2);
        #endif // __test

        for (int i = 0; i <= sz1; i++)          // insert before [i]
        {
            int t2 = (i - 1 >= 0) ? v1[i - 1] : 0;
            int t3 = i < sz1 ? v2[i] : 0;
            if (t2 < t3)
            {
                ans = max(ans, 1LL * (t2 + 1) * t3);
            }
            else
            {
                ans = max(ans, 1LL * t2 * (t3 + 1));
            }
        }
        return ans;
    }

};

int main()
{

    LT2207 lt;

//    string s = "abdcdbc";
//    string p = "ac";

//    string s = "aabb";
//    string p = "ab";

    string s = "mpmp";  // ...  mpmpp   5个 mp。。  不能相乘，得分开计算。。 加最后 或最前？。。。这么简单？
    string p = "mp";


    cout<<lt.lt2207b(s, p)<<endl;

    return 0;
}
