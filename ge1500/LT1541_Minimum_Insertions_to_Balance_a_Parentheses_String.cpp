
#include "../header/myheader.h"

class LT1541
{
public:

// D D


//        int res = 0, right = 0;
//        for (char &c: s) {
//            if (c == '(') {
//                if (right % 2 > 0) {
//                    right--;
//                    res++;
//                }
//                right += 2;
//            } else {
//                right--;
//                if (right < 0) {
//                    right += 2;
//                    res++;
//                }
//            }
//        }
//        return right + res;


//    int l = 0, r = 0, res = 0;
//    for (auto ch : s) {
//        if (ch == '(') {
//            if (r != 0) {
//                res += l > 0 ? 1 : 2;
//                l = max(0, l - 1);
//                r = 0;
//            }
//            ++l;
//        } else if (++r == 2) {
//            r = 0;
//            if (l > 0)
//                --l;
//            else
//                ++res;
//        }
//    }
//    if (l > 0)
//        return res + 2 * l - r;
//    return res + (r == 1 ? 2 : 0);




//Runtime: 36 ms, faster than 73.29% of C++ online submissions for Minimum Insertions to Balance a Parentheses String.
//Memory Usage: 12.7 MB, less than 72.44% of C++ online submissions for Minimum Insertions to Balance a Parentheses String.
    int lt1541a(string s)
    {
        int ans = 0;
        int cntl = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                cntl++;
            }
            else
            {
                if (i == s.size() - 1 || s[i + 1] != ')')
                {
                    ans++;
                }
                else
                {
                    i++;
                }
                cntl--;
                if (cntl < 0)
                {
                    ans++;
                    cntl++;
                }
            }
        }
        return ans + cntl * 2;
    }

};

int main()
{

    vector<string> vs = {"(()))", "())", "))())(", "((((((", ")))))))"};

    LT1541 lt;

    for (string& s : vs)
        cout<<lt.lt1541a(s)<<endl;

    return 0;
}
