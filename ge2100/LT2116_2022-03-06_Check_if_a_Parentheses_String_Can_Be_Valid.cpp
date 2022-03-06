
#include "../header/myheader.h"

class LT2116
{
public:


// D D

//        for(int i=0;i<n;i++){
//            if(locked[i]=='0'){
//                unlocked++;
//            }
//            else{
//                if(s[i]=='(')closed--;
//                else if(s[i]==')') closed++;
//            }
//            if(unlocked<closed)return false;
//        }

//        for (int i = 0; i < size(s); ++i) {
//            if (locked[i] == '0') --lo, ++hi;
//            else if (s[i] == '(') ++lo, ++hi; else --lo, --hi;
//            if (hi < 0) return false;
//            if (lo < 0) lo = 1;
//        }
//        return lo == 0;

//if (s.size() & 1) return false;
//        for (int i = 0, bal = 0; i < s.size(); ++i) {
//            if (locked[i] == '0' || s[i] == '(') bal += 1;
//            else bal -= 1;
//            if (bal < 0) return false;
//        }

// 一顿操作。。能用。。但。。
//Runtime: 92 ms, faster than 96.52% of C++ online submissions for Check if a Parentheses String Can Be Valid.
//Memory Usage: 27.2 MB, less than 41.96% of C++ online submissions for Check if a Parentheses String Can Be Valid.
    bool lt2116a(string& s, string& locked)
    {
        int sz1 = s.size();
        if (sz1 % 2 == 1)
            return false;

        int notSure = 0;
        int lidx = 0;
        int cnt2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == '(')
                cnt2++;
            else
                cnt2--;

            if (cnt2 < 0)
            {
                while (lidx <= i && (locked[lidx] != '0' || s[lidx] == '('))
                {
                    lidx++;
                }
                if (lidx > i)
                {
                    return false;
                }
                locked[lidx] = '2';
                s[lidx] = '(';
                cnt2 += 2;
            }
//            if (locked[i] == '1' && s[i] == ')')
//            {
//                while (locked[lidx] != '0')
//                {
//                    lidx++;
//                }
//
//            }
        }
        cnt2 = 0;
        lidx = sz1 - 1;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            if (s[i] == '(')
                cnt2++;
            else
                cnt2--;

            if (cnt2 > 0)
            {
                while (lidx >= i && (locked[lidx] != '0' || s[lidx] == ')'))
                {
                    lidx--;
                }
                if (lidx < i)
                    return false;
                locked[lidx] = '3';
                s[lidx] = ')';
                cnt2 -= 2;
            }
        }
        return true;
    }

};

int main()
{

    LT2116 lt;

//    string s = "))()))";
//    string l = "010100";
    string s = "()()";
    string l = "0011";

    cout<<lt.lt2116a(s, l)<<endl;
    cout<<s<<", "<<l<<endl;

    return 0;
}
