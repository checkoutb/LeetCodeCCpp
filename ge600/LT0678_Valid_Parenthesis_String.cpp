
#include "../header/myheader.h"

class LT0678
{
public:

// D D
//        int lo = 0, hi = 0;
//
//        for(char c : s) {
//            lo += c == '(' ? 1 : -1;
//            hi += c != ')' ? 1 : -1;
//
//            if(hi < 0)  break;
//            lo = max(lo, 0);
//        }
//
//        return lo == 0;

//        int openCount = 0;
//        for (char c : s.toCharArray()) {
//            if (c == '(') {
//                openCount++;
//            } else if (c == ')') {
//                openCount--;
//            }
//            if (openCount < 0) return false;    // Currently, don't have enough open parentheses to match close parentheses-> Invalid
//                                                // For example: ())(
//        }
//        return openCount == 0; // Fully match open parentheses with close parentheses


//        for (int i = start; i < s.length(); i++) {
//            char c = s.charAt(i);
//            if (c == '(') {
//                count++;
//            }
//            else if (c == ')') {
//                if (count <= 0) return false;
//                count--;
//            }
//            else if (c == '*') {
//                return check(s, i + 1, count + 1) || check(s, i + 1, count - 1) || check(s, i + 1, count);
//            }
//        }

//        int cmin = 0, cmax = 0;
//        for (char c : s) {
//            if (c == '(')
//                cmax++, cmin++;
//            if (c == ')')
//                cmax--, cmin = max(cmin - 1, 0);
//            if (c == '*')
//                cmax++, cmin = max(cmin - 1, 0);
//            if (cmax < 0) return false;
//        }
//        return cmin == 0;



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parenthesis String.
//Memory Usage: 6.3 MB, less than 26.68% of C++ online submissions for Valid Parenthesis String.
    bool lt0678c(string s)
    {
        int n1{0}, n2{0}, na{0};
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                n1++;
            else if (s[i] == ')')
                n2++;
            else
                na++;
            if (n1 + na < n2)
            {
                return false;
            }
        }
        for (int i = 0; i < s.size() / 2; i++)
        {
            char ch = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - 1 - i] = ch;
        }
        n1 = n2 = na = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
                n1++;
            else if (s[i] == '(')
                n2++;
            else
                na++;
            if (n1 + na < n2)
                return false;
        }
        return true;
    }

    bool lt0678b(string s)
    {
        int sz1 = s.size();
        vector<int> v1(sz1, 0);
        vector<int> v2(sz1, 0);
        vector<int> a1(sz1, 0);
        vector<int> a2(sz1, 0);
        int cnt = 0;
        int ca = 0;
        for (int i = 0; i < sz1; i++)
        {
            if (s[i] == '(')
            {
                cnt++;
            }
            else if (s[i] == '*')
            {
                ca++;
            }
            v1[i] = cnt;
            a1[i] = ca;
        }
        cnt = 0;
        ca = 0;
        for (int i = sz1 - 1; i >= 0; i--)
        {
            if (s[i] == ')')
            {
                cnt++;
            }
            else if (s[i] == '*')
            {
                ca++;
            }
            v2[i] = cnt;
            a2[i] = ca;
        }
        int af = 0;
        int ab = 0;
        for (int i = 0; i < sz1; i++)
        {
            if (s[i] == '(')
            {

            }
            else if (s[i] == ')')
            {

            }
        }
        return true;
    }

    // wrong
    bool lt0678a(string s)
    {
        if (s.empty())
            return true;
        vector<int> v1(s.size(), 0);       // (
        vector<int> v2(s.size(), 0);
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                cnt++;
            v1[i] = cnt;
        }
        cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                cnt++;
            v2[i] = cnt;
        }
        int any = 0;
        int fut = 0;
        int v1d = 0;
        cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
//                if (fut < 0)
//                    fut++;
//                else
                    any++;
            }
            else if (s[i] == ')')
            {
                cnt++;
                v1d++;
                if (cnt > v1[i])
                {
                    if (v1[i] + any >= cnt)
                    {
                        any -= (cnt - v1[i]);
                        cnt = v1[i];
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else if (s[i] == '(')
            {
                if (v1[i] + v1d > v2[i])
                {
                    fut -= (v1[i] + v1d - v2[i]);
                    v1d -= (v1[i] + v1d - v2[i]);
                }
            }
        }
        #ifdef __test
        cout<<fut<<", "<<any<<", "<<cnt<<", "<<any<<endl;
        #endif // __test
        if (0 - fut > any)
            return false;
        if (abs(cnt - v1[v1.size() - 1]) <= any)
            return true;
        return false;
    }

};

int main()
{

//    string arr[] = {"()","(*)))","(*)"};
//    string arr[] = {"(())((())()()(*)(*()(())())())()()((()())((()))(*"};
//    string arr[] = {"()()"};

    LT0678 lt;

    for (string& s : arr)
    {
        cout<<lt.lt0678c(s)<<endl;
    }

    return 0;
}
