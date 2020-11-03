
#include "../header/myheader.h"

class LT1071
{
public:

// D D

//        if ((str1+str2) != (str2+str1)) return "";
//        int s = gcd(str1.size(), str2.size());
//        return str1.substr(0, s);
// ....


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Greatest Common Divisor of Strings.
//Memory Usage: 7.3 MB, less than 5.07% of C++ online submissions for Greatest Common Divisor of Strings.
    string lt1071a(string str1, string str2)
    {
        if (str1.size() < str2.size())
        {
            string s = str1;
            str1 = str2;
            str2 = s;
        }
        int sz1 = str1.size();
        int sz2 = str2.size();
        int t2 = str2.size();
        string ans;
        for (; t2 > 0; t2--)
        {
            if (sz1 % t2 != 0 || sz2 % t2 != 0)
            {
                continue;
            }

            for (int i = 0; i < t2; i++)
            {
                for (int j = i + t2; j < sz2; j += t2)
                {
                    if (str2[j] != str2[i])
                    {
                        goto AAA;
                    }
                }
            }
            for (int i = 0; i < t2; i++)
            {
                for (int j = i; j < sz1; j += t2)
                {
                    if (str1[j] != str2[i])
                    {
                        goto AAA;
                    }
                }
            }
            ans = str2.substr(0, t2);
            break;

            AAA:
                continue;
        }
        return ans;
    }

};

int main()
{

//    string s1 = "ABCABC";
//    string s2 = "ABC";
//    string s1 = "ABABAB";
//    string s2 = "ABAB";

    string s1 = "LEET";
    string s2 = "CODE";

//    string s1 = "ABCDEF";
//    string s2 = "ABC";

    LT1071 lt;

    cout<<lt.lt1071a(s1, s2)<<endl;

    return 0;
}
