
#include "../header/myheader.h"

class LT1576
{
public:

// D D

//            if (s[i] == '?') {
//                for (int a=0; a<26; a++) {
//                    if (i==0 && ('a' + a) != s[i+1]) {
//                        s[i] = 'a' + a;
//                        break;
//                    } else if (i==N-1 && ('a' + a) != s[i-1]) {
//                        s[i] = 'a' + a;
//                        break;
//                    } else if (('a' + a) != s[i-1] && ('a' + a) != s[i+1]) {
//                        s[i] = 'a' + a;
//                        break;
//                    }
//                }
//            }

//            if (arr[i] == '?') {
//                for (char c = 'a'; c <= 'c'; c++) {
//                    if (i > 0 && arr[i-1] == c) continue;
//                    if (i + 1 < n && arr[i + 1] == c) continue;
//                    arr[i] = c;
//                    break;
//                }
//            }

//        if (s[i] == '?')
//            for (s[i] = 'a'; s[i] <= 'c'; ++s[i])
//                if ((i == 0 || s[i - 1] != s[i]) && (i == s.size() - 1 || s[i + 1] != s[i]))
//                    break;

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Replace All ?'s to Avoid Consecutive Repeating Characters.
//Memory Usage: 6.4 MB, less than 55.56% of C++ online submissions for Replace All ?'s to Avoid Consecutive Repeating Characters.
    string lt1576a(string s)
    {
        #define nextch(ch) ch == 'z' ? 'a' : (char) (ch + 1);
        int sz1 = s.size();
        if (sz1 == 1)
            return s == "?" ? "a" : s;

        if (s[0] == '?')
        {
            s[0] = s[1] == '?' ? 'a' : nextch(s[1]);
        }

        for (int i = 1; i < sz1 - 1; ++i)
        {
            if (s[i] != '?')
                continue;
            char pre = s[i - 1];
            char nxt = s[i + 1];
            if (max(pre, nxt) == 'z' && min(pre, nxt) == 'a')
                s[i] = 'b';
            else
                s[i] = nextch(max(pre, nxt));
        }

        if (s[sz1 - 1] == '?')
        {
            s[sz1 - 1] = nextch(s[sz1 - 2]);
        }

        return s;
    }

};

int main()
{

    string s = "ubv?w";

    LT1576 lt;

    cout<<lt.lt1576a(s)<<endl;

    return 0;
}
