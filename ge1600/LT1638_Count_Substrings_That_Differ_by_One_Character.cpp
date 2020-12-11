
#include "../header/myheader.h"

class LT1638
{
public:

// D

// ... 遍历 。。forfor 如果不相等，就++， 如果2个不相等，就break。


//        for (int i = 0; i < s.length(); ++i)
//            res += helper(s, t, i, 0);
//        for (int j = 1; j < t.length(); ++j)
//            res += helper(s, t, 0, j);
//
//        int res = 0, pre = 0, cur = 0;
//        for (int n = s.length(), m = t.length(); i < n && j < m; ++i, ++j) {
//            cur++;
//            if (s[i] != t[j])
//                pre = cur, cur = 0;
//            res += pre;
//        }



// gg...
// 还是硬算吧。。
// 估计tle， 感觉要算 相等的 最长substring 有多少，然后头/尾 加一个 char 就满足 要求了。 还可以 2个 间隔1个char的 相连接, 2个长度相乘。
// 26 * n * m * m .....
    int lt1638a(string s, string t)
    {
        unordered_map<string, int> map2;
        int ans = 0;
        int mxsz1 = min(s.size(), t.size());
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 1; j <= mxsz1; ++j)
            {
                string ss = s.substr(i, j);
                if (map2.find(subs) != map2.end())
                {
                    ans += map2[subs];
                }
                else
                {

                }
            }
        }



////        unordered_set<string> can
//        unordered_map<string, int> map2;
//        int ans = 0;
//        int mxsz1 = min(s.size(), t.size());
//        for (int i = 0; i < s.size(); ++i)
//        {
//            for (int j = 1; j <= mxsz1; ++j)        // length
//            {
//                string subs = s.substr(i, j);
//                if (map2.find(subs) != map2.end())
//                {
//                    ans += map2[subs];
//                }
//                else
//                {
//                    int t2 = 0;
//                    vector<string> appear;
//                    vector<string> disappear;
//                    for (int k = 0; k < j; ++k)
//                    {
//                        char ori = subs[k];
//                        for (char m = 'a'; m <= 'z'; ++m)
//                        {
//
//                        }
//                    }
//                }
//            }
//        }
    }

};

int main()
{

    LT1638 lt;


    return 0;
}
