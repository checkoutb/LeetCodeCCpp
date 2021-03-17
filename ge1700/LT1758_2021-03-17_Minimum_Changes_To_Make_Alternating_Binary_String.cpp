
#include "../header/myheader.h"

class LT1758
{
public:

// D D

//        int res = 0, n = s.length();
//        for (int i = 0; i < n; ++i)
//            if (s[i] - '0' != i % 2)
//                res++;
//        return min(res, n - res);
// yes, cnt0 + cnt1 == s.size.

//    int f1 = 1, f0 = 0, cnt1 = 0, cnt2 = 0;
//    for (auto ch : s) {
//        cnt1 += ch - '0' != f1;
//        cnt2 += ch - '0' != f0;
//        swap(f1, f0);
//    }


//Runtime: 4 ms, faster than 92.50% of C++ online submissions for Minimum Changes To Make Alternating Binary String.
//Memory Usage: 6.9 MB, less than 87.08% of C++ online submissions for Minimum Changes To Make Alternating Binary String.
    int lt1758a(string s)
    {
        int cnt0 = 0;           // 010101..
        int cnt1 = 0;           // 1010....
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] - '0' != i % 2)
            {
                cnt0++;
            }
            else
            {
                cnt1++;
            }
        }
        return min(cnt0, cnt1);
    }

};

int main()
{
//    string s = "0100";
//    string s = "10";
    string s = "1111";

    LT1758 lt;

    cout<<lt.lt1758a(s)<<endl;

    return 0;
}
