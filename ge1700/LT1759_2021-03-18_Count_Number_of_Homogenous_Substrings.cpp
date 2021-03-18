
#include "../header/myheader.h"

class LT1759
{
public:

// D D

//        for(auto it : s){
//            if(it==x)
//                c++;
//            else{
//                c=1;
//                x=it;
//            }
//            ans=(ans+c)%1000000007;
//        }

//    for (int i = 0; i < s.length(); ++i) {
//        if (i > 0 && s[i - 1] == s[i])
//            ++cnt;
//        else
//            cnt = 1;
//        res = (res + cnt) % 1000000007;
//    }

//        for (int a: s) {
//            count = a == cur ? count + 1 : 1;
//            cur = a;
//            res = (res + count) % mod;
//        }


//Runtime: 28 ms, faster than 81.73% of C++ online submissions for Count Number of Homogenous Substrings.
//Memory Usage: 11.6 MB, less than 59.91% of C++ online submissions for Count Number of Homogenous Substrings.
// 1 3 6 (1 + 2 + 3 + 4 + ... + n)
    int lt1759a(string s)
    {
        int ans = 0;
        const int MOD = 1E9 + 7;
        long len = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                len++;
            }
            else
            {
                ans = (int) ((ans + (len * (len + 1) / 2)) % MOD);
                len = 1;
            }
        }
        ans = (int) ((ans + (len * (len + 1) / 2)) % MOD);
        return ans;
    }

};

int main()
{
//    string s = "abbcccaa";
//    string s = "xy";
    string s = "zzzzz";

    LT1759 lt;

    cout<<lt.lt1759a(s)<<endl;

    return 0;
}
