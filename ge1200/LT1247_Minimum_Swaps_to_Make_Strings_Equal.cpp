
#include "../header/myheader.h"

class LT1247
{
public:


// D D

//Everytime there is a difference it is either an (x,y) pair or an (y,x) pair
//As seen in example 1, two pairs of (x,y) or two pairs of (y,x) can be fixed in one swap
//But one pair of (x,y) and one pair of (y,x) need two swaps to be fixed, as seen in example 2
//        if(s1.size() != s2.size()) return -1;
//        int xy=0, yx=0;
//        for(int i=0; i<s1.size(); i++){
//            if(s1[i]=='x' && s2[i]=='y') xy++;
//            else if(s1[i]=='y' && s2[i]=='x') yx++;
//        }
//        if(xy%2 != yx%2) return -1;
//        return xy/2 + yx/2 + (xy%2) * 2;

// ......




//Runtime: 4 ms, faster than 22.64% of C++ online submissions for Minimum Swaps to Make Strings Equal.
//Memory Usage: 6.5 MB, less than 58.49% of C++ online submissions for Minimum Swaps to Make Strings Equal.
// xxy
// yxy
    int lt1247b(string s1, string s2)
    {
        int ans = 0;
        int lstChg = -1;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                int k = -1;
                for (int j = i + 1; j < s1.size(); j++)
                {
                    if (s1[j] != s2[j] && s1[j] == s1[i])
                    {
                        k = j;
                        break;
                    }
                }
                if (k == -1)
                    for (int j = i + 1; j < s1.size(); j++)
                    {
                        if (s1[j] == s2[j] && s1[j] != s1[i])
                        {
                            k = j;
                            break;
                        }
                    }
                if (k == -1)
                {
                    if (lstChg == i)
                        return -1;
                    char ch2 = s1[i];
                    s1[i] = s2[i];
                    s2[i] = ch2;
                    lstChg = i;
                    ans++;
                    i--;
                }
                else
                {
                    char ch = s1[i];
                    s1[i] = s2[k];
                    s2[k] = ch;
                    ans++;
                }
            }
        }
        return ans;
    }


// error
// xx yy xx  yxyyxx
// yx xy xx  yxxxxx
// xxyyxy
// xxxyxx
    int lt1247a(string s1, string s2)
    {
        int en = s1.size() - 1;
//        for (int i = 0; i < s1.size(); i++)
//        {
//            if (s1[i] != s2[i])
//            {
//
//            }
//        }
        int st = 0;
        while (st <= en)
        {
            if (s1[st] == s2[st])
            {
                st++;
            }
            else
            {
                char c = s1[st];
                s1[st] = s1[en];
                s1[en] = c;
                c = s2[st];
                s2[st] = s2[en];
                s2[en] = c;
                en--;
            }
        }
        s1 = s1.substr(st);
        s2 = s2.substr(st);
        st = 0;
        en = s1.size() - 1;
        #ifdef __test
        cout<<s1<<endl<<s2<<endl;
        #endif // __test
        int ans = 0;
        while (st <= en)
        {
            if (s1[st] != s2[st])
            {
                while (en > st && (s1[en] == s2[en]))
                {
                    en--;
                }
                for (int j = en; j + st; j--)
                {
//                    if ()
//                    {
//
//                    }
                }
                ans++;
            }
        }
        if (st != en)
            return -1;
        return ans;
    }

};

int main()
{

//    string a = "xx";
//    string b{"yy"};

//    string a{"xy"};
//    string b{"yx"};

//    string a{"xx"};
//    string b{"xy"};

    string a{"xxyyxyxyxx"};
    string b{"xyyxyxxxyx"};

    LT1247 lt;

    cout<<lt.lt1247b(a, b);

    return 0;
}
