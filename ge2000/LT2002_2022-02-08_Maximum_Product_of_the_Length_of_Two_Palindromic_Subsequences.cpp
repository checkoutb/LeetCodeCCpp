
#include "../header/myheader.h"

class LT2002
{
public:



// D

// 2 ^ 12 = 4096
// 1-4095 作为key 根据int 转bit，判断这个bit 回文长度。

// 然后 k1 & k2 == 0 说明 disjoint。。


//    int p1 = 0, p2 = s.size(), res = 0;
//    while (p1 <= p2) {
//        if ((mask & (1 << p1)) == 0)
//            ++p1;
//        else if ((mask & (1 << p2)) == 0)
//            --p2;
//        else if (s[p1] != s[p2])
//            return 0;
//        else
//            res += 1 + (p1++ != p2--);
//    }

//    for (int m1 = mask; m1; --m1)
//        if (dp[m1] * (s.size() - dp[m1]) > res)       // 最大可能 大于 res
//            for(int m2 = mask ^ m1; m2; m2 = (m2 - 1) & (mask ^ m1))          // 。。在搜索，但是不理解。。
//                res = max(res, dp[m1] * dp[m2]);





// tle.....
// [2, 12]  brute-force
// ..... bujiandan.. 后续有没有这个char， 计算出所有 回文，然后匹配？
    int lt2002a(string s)
    {
        int sz1 = s.size();
//        vector<bool> vb = vector<bool>(sz1, false);     // used?              // bit
        int ans = dfsa(s, -1, s.size(), 0, 0);
        return ans;
    }

    // (st, en)
    // 调用的时候，必须是 偶数长度的回文
    // 1 used
    int dfsa(string s, int st, int en, int sz2, int used)
    {
        int t2 = 0;
        if (st + 1 >= en)
        {
            t2 = dfsa2(s, -1, s.size(), 0, used) * sz2;
            #ifdef __test
//            cout<<t2<<",,,,,"<<sz2<<endl;
            #endif // __test
            return t2;
//            return sz2;
        }
//        if (st + 2 == en)
//        {
//            t2 =
////            return 1 + sz2;
//        }

        int ans = 0;
        if (sz2 != 0)
        {
            t2 = dfsa2(s, -1, s.size(), 0, used);
            if (t2 * sz2 > ans)
                ans = t2 * sz2;
        }
        #ifdef __test
//        cout<<"----2222--- "<<ans<<endl;
        #endif // __test
        for (int i = st + 1; i < en; i++)
        {
            t2 = dfsa2(s, -1, s.size(), 0, used | (1 << i));
            if (t2 * (sz2 + 1) > ans)
            {
//                cout<<" ?? "<<t2<<", "<<i<<", "<<used<<", "<<(used | (1 << i))<<endl;
                ans = t2 * (sz2 + 1);
            }
        }
//        #ifdef __test
//        cout<<"---------- "<<ans<<endl;
//        #endif // __test
        for (int i = st + 1; i < en; i++)
        {
            t2 = dfsa(s, i, en, sz2, used);         // skip
            if (t2 > ans)
            {
                ans = t2;
            }
            if ((used & (1 << i)) == 0)
            {
                for (int j = en - 1; j > i; j--)
                {
                    if (((used & (1 << j)) == 0) && s[i] == s[j])
                    {
//                        #ifdef __test
//                        cout<<i<<", "<<j<<endl;
//                        #endif // __test
                        t2 = dfsa(s, i, j, sz2 + 2, used | (1 << i) | (1 << j));
                        if (t2 > ans)
                            ans = t2;
                        break;
                    }
                }
            }
        }
//        #ifdef __test
//        cout<<", "<<st<<"- "<<en<<". "<<ans<<endl;
//        #endif // __test
        return ans;
    }

    int dfsa2(string s, int st, int en, int sz2, int used)
    {
        if (st + 1 >= en)
        {
            return sz2;
        }
        if (st + 2 == en)
        {
            if ((used & (1 << (st + 1))) == 0)
            {
                return sz2 + 1;
            }
            return sz2;
        }
        int ans = 0;
        int t2 = 0;
        for (int i = st + 1; i < en; i++)
        {
            t2 = dfsa2(s, i + 1, en, sz2, used);         // skip
            ans = max(t2, ans);
            if ((used & (1 << i)) == 0)
            {
                t2 = -1;
                for (int j = en - 1; j > i; j--)
                {
                    if (((used & (1 << j)) == 0) && s[j] == s[i])
                    {
                        t2 = dfsa2(s, i, j, sz2 + 2, used | (1 << i) | (1 << j));
                        if (t2 > ans)
                        {
                            ans = t2;
                        }
                        break;
                    }
                }
                if (t2 == -1)
                {
                    if (sz2 + 1 > ans)
                    {
                        ans = sz2 + 1;
                    }
                }
            }
        }
//        #ifdef __test
//        cout<<ans<<endl;
//        #endif // __test
        return ans;
    }

};

int main()
{

    LT2002 lt;

//    string s = "leetcodecom";
//    string s = "abacba";
//    string s = "accbcaxxcxx";
    string s = "xtoctqctnoxt";


    cout<<lt.lt2002a(s)<<endl;

    return 0;
}
