
#include "../header/myheader.h"

class LT1888
{
public:

// g

//Sliding Window

//        int ans1 = 0, ans2 = 0, ans = INT_MAX;
//        for(int i = 0; i < 2 * n; i++) {
//            if(i < n) s[i] -= '0'; //make '1' and '0' to be integer 1 and 0.
//            if(i % 2 != s[i % n]) ++ans1;
//            if((i + 1) % 2 != s[i % n]) ++ans2;
//            if(i >= n) {
//                if((i - n) % 2 != s[i - n]) --ans1;
//                if((i - n + 1) % 2 != s[i - n]) --ans2;
//            }
//            if(i >= n - 1)
//                ans = min({ans1, ans2, ans});
//        }

//    for (int i = 0; i < 2 * sz; ++i) {
//        s0 += s[i % sz] != '0' + i % 2;
//        s1 += s[i % sz] != '0' + (1 - i % 2);
//        if (i >= sz - 1) {
//            if (i >= sz) {
//                s0 -= s[i - sz] != '0' + (i - sz) % 2;
//                s1 -= s[i - sz] != '0' + (1 - (i - sz) % 2);
//            }
//            res = min(res, min(s0, s1));
//        }
//    }


// 这个好绕啊。
    int lt1888b(string s)
    {
////        int t_should0_but1 = 0;
////        int t_should1_but0 = 0;
//        int t_st0_butNotMatch = 0;
//        int t_st1_butNotMatch = 0;
        for (int i = 0; i < s.size(); ++i)
        {

        }
    }


// 偶数长度的话，type1只需要执行2次
//
// tle.
// 这个type1    不执行 和 执行1次，  就是所有的可能了。 ... bu ..01001001101  01001101+010   01010101 + 101
    int lt1888a(string s)
    {
        int t2 = 0;     // 1st is 0
        int t3 = 0;     // 1st is 1
        bool is0 = true;
        int ans = s.size();
        for (int a = 0; a < s.size(); ++a)
        {
            t2 = t3 = 0;
            is0 = true;
            for (int i = 0; i < s.size(); ++i)
            {
                if (is0)
                {
                    if (s[i] == '0')
                    {
                        t3++;
                    }
                    else
                    {
                        t2++;
                    }
                }
                else
                {
                    if (s[i] == '1')
                    {
                        t3++;
                    }
                    else
                    {
                        t2++;
                    }
                }
                if (t2 >= ans && t3 >= ans)
                    break;
                is0 = !is0;
            }
            ans = min(ans, min(t2, t3));
            s = s.substr(1) + s[0];
        }
        return ans;
//        int ans = min(t2, t3);
//        t2 = t3 = 0;
//        s = s.substr(1) + s[0];
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (is0)
//            {
//                if (s[i] == '0')
//                {
//                    t3++;
//                }
//                else
//                {
//                    t2++;
//                }
//            }
//            else
//            {
//                if (s[i] == '1')
//                {
//                    t3++;
//                }
//                else
//                {
//                    t2++;
//                }
//            }
//            is0 = !is0;
//        }
//        ans = min(ans, min(t2, t3));
//        return ans;
    }

};

int main()
{
//    string s = "111000";
//    string s = "010";
//    string s = "1110";
    string s = "01001001101";       //      01001101010


    LT1888 lt;

    cout<<lt.lt1888a(s)<<endl;

    return 0;
}
