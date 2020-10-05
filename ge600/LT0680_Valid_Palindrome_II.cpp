
#include "../header/myheader.h"

class LT0680
{
public:


// D D

//    while (++l < --r)
//        if (s.charAt(l) != s.charAt(r)) return isPalindromic(s, l, r+1) || isPalindromic(s, l-1, r);
// 只需要判断 l - r,  +-1


//            if (s[i] != s[j]) {
//                int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
//                while (i1 < j1 && s[i1] == s[j1]) {i1++; j1--;};
//                while (i2 < j2 && s[i2] == s[j2]) {i2++; j2--;};
//                return i1 >= j1 || i2 >= j2;
//            }



//Runtime: 56 ms, faster than 99.38% of C++ online submissions for Valid Palindrome II.
//Memory Usage: 24.1 MB, less than 26.36% of C++ online submissions for Valid Palindrome II.
    bool lt0680a(string s)
    {
        int st = 0;
        int en = s.size() - 1;
        while (st < en)
        {
            if (s[st] == s[en])
            {
                st++;
                en--;
                continue;
            }
            if (st + 1 == en)
            {
                st++;
                en--;
                continue;
            }
            if (isValida1(s, st) || isValida1(s, en))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool isValida1(string s, int i)
    {
        int st = 0;
        int en = s.size() - 1;
        while (st < en)
        {
            if (st == i)
                st++;
            if (en == i)
                en--;
            if (s[st] != s[en])
                return false;
            st++;
            en--;
        }
        return true;
    }

};

int main()
{

    string s[] = {"aba","abca"};

    LT0680 lt;

    for (string s1 : s)
    {
        cout<<lt.lt0680a(s1)<<endl;
    }

    return 0;
}
