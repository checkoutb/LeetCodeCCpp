
#include "../header/myheader.h"

class LT1616
{
public:

// D D

//    bool isPalin( string a , int i , int j )
//    {
//        while ( i < j && a [ i ] == a [ j ] )
//            i++,j--;
//        return i>=j;
//    }
//    bool check ( string a, string b )
//    {
//        int i = 0 , j = b.length () - 1 ;
//        while ( i < j && a [ i ] == b [ j ] )
//            i++, j--;
//        return isPalin ( a , i , j ) || isPalin ( b , i , j );
//    }
//    bool checkPalindromeFormation(string a, string b)
//    {
//       return check ( a , b ) || check ( b , a );
//    }


//    bool check(string s,string t)
//    {
//        if(s.size()==1 || t.size()==1)return 1;
//        int p1=0,p2=s.size()-1,cnt=0;
//        while(s[p1]==t[p2])
//        {
//            p1++;
//            p2--;
//            cnt++;
//        }
//        return cnt>1;
//    }
//    bool checkPalindromeFormation(string a, string b) {
//        return check(a,b)|check(b,a);
//    }


//    bool isPa(string& s, int i, int j) {
//        for (; i < j; ++i, --j)
//            if (s[i] != s[j])
//                return false;
//        return true;
//    }
//
//    bool check(string& a, string& b) {
//        for (int i = 0, j = a.size() - 1; i < j; ++i, --j)
//            if (a[i] != b[j])
//                return isPa(a, i, j) || isPa(b, i, j);
//        return true;
//    }
//
//    bool checkPalindromeFormation(string a, string b) {
//        return check(a, b) || check(b, a);
//    }



//Runtime: 120 ms, faster than 20.39% of C++ online submissions for Split Two Strings to Make Palindrome.
//Memory Usage: 37.6 MB, less than 14.44% of C++ online submissions for Split Two Strings to Make Palindrome.
// 优先使用 另一个string的 来匹配。
    bool lt1616b(string a, string b)
    {
//        int sz1 = a.size();
//        bool same = false;
//        // aprefix + bsuffix  ,  b[mxi] in palindrome    change a to b
//        for (int i = 0, mxi = sz1 / 2; i < mxi; i++)
//        {
//            if (!same)
//            {
//                if (a[i] != b[sz1 - 1 - i])
//                {
//                    same = true;
//                }
//            }
//            if (same)
//            {
//                if (b[i] != b[sz1 - 1 - i])
//                    goto AAA;
//            }
//        }
//        return true;
//
//        AAA:

// 使用 第二个形参 的middle 作为 palindrome的中心，所以需要 reverse ， 不， 是因为  回文的中心是 和 suffix 一起的。
        if (isPalindb1(a, b) || isPalindb1(b, a))
            return true;
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
        if (isPalindb1(a, b) || isPalindb1(b, a))
            return true;
        return false;
    }

    bool isPalindb1(string a, string b)
    {
        int sz1 = a.size();
        bool same = false;
        for (int i = 0, mxi = sz1 / 2; i < mxi; ++i)
        {
            if (!same)
                if (a[i] != b[sz1 - 1 - i])
                    same = true;
            if (same)
                if (b[i] != b[sz1 - 1 - i])
                    return false;
        }
        return true;
    }


// 无论怎么划分， 回文的中心 始终是 a或b 的中心。
    bool lt1616a(string a, string b)
    {
        int sz1 = a.size();
        if (isPalinda1(a) || isPalinda1(b))
            return true;

        std::reverse(begin(b), end(b));
        int mxi = 0;
        for (; mxi < sz1; mxi++)
        {
            if (a[mxi] != b[mxi])
            {
                break;
            }
        }
        int mni = sz1 - 1;
        for (; mni >= 0; --mni)
            if (a[mni] != b[mni])
                break;

        for (int i = 1; i < mxi; ++i)
        {
//            string s =
        }

        return false;
    }
    bool isPalinda1(string& s)
    {
        for (int i = 0, mxi = s.size() / 2; i < mxi; ++i)
        {
            if (s[i] != s[mxi - 1 - i])
                return false;
        }
        return true;
    }

};

int main()
{
//    string s1{"x"}, s2{"y"};
//    string s1 = "abdef", s2 = "fecab";
//    string s1 = "ulacfd", s2 = "jizalu";
//    string s1 = "xbdef", s2 = "xecab";

//               aejbaalflrmkswrydwdkdwdyrwskmrlf
    string s1 = "aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd";
    string s2 = "uvebspqckawkhbrtlqwblfwzfptanhiglaabjea";      // true


    LT1616 lt;

    cout<<lt.lt1616b(s1, s2);

    return 0;
}
