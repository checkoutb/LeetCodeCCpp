
#include "../header/myheader.h"

class LT1750
{
public:

// D D

//    int i = 0, j = s.size() - 1;
//    while (i < j && s[i] == s[j]) {
//        auto ch = s[i];
//        while (i <= j && s[i] == ch)
//            ++i;
//        while (i < j && s[j] == ch)
//            --j;
//    }
//    return j - i + 1;




//Runtime: 24 ms, faster than 95.04% of C++ online submissions for Minimum Length of String After Deleting Similar Ends.
//Memory Usage: 12.6 MB, less than 96.25% of C++ online submissions for Minimum Length of String After Deleting Similar Ends.
// 贪心？
    int lt1750a(string s)
    {
        char ch = '1';
        int l = 0;
        int r = s.size() - 1;
        int t1 = 0;
        int t2 = 0;
        while (l < r)
        {
            t1 = l;
            t2 = r;
            ch = s[l];
            for (; l < r && s[l] == ch; ++l)
            {

            }
            for (; l <= r && s[r] == ch; --r)
            {

            }
            #ifdef __test
            cout<<t1<<", "<<l<<" ; "<<t2<<", "<<r<<endl;
            #endif // __test
            if (t1 == l || t2 == r)
            {
                l = t1;
                r = t2;
                break;
            }
//            l = t1;
//            r = t2;
        }
        return r - l + 1;
    }

};

int main()
{
//    string s = "ca";
//    string s = "cabaabac";
    string s = "aabccabba";

    LT1750 lt;

    cout<<lt.lt1750a(s)<<endl;

    return 0;
}
