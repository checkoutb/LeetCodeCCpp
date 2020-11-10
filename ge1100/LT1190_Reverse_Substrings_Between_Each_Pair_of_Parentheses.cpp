
#include "../header/myheader.h"

class LT1190
{
public:


// D D

// stack 记录 ( 的 位置。
// vector 保存 char， 当遇到)时， reverse(vector.begin() + stack.top(), vector.end())。 pop。

//        int n = s.length();
//        vector<int> opened, pair(n);
//        for (int i = 0; i < n; ++i) {
//            if (s[i] == '(')
//                opened.push_back(i);
//            if (s[i] == ')') {
//                int j = opened.back();
//                opened.pop_back();
//                pair[i] = j;
//                pair[j] = i;
//            }
//        }
//        string res;
//        for (int i = 0, d = 1; i < n; i += d) {
//            if (s[i] == '(' || s[i] == ')')
//                i = pair[i], d = -d;
//            else
//                res += s[i];
//        }
// 记录 括号对，遇到括号时，从 设定的下标开始。


//Runtime: 4 ms, faster than 42.23% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.
//Memory Usage: 7.8 MB, less than 6.43% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.
    string lt1190a(string s)
    {
        stack<char> stk1;
//        stack<char> stk2;
        queue<char> que1;
        // a(zxc)b   (a(zxc)b)
//        string prefix = s.substr(0, s.find('('));

        for (char ch : s)
        {
            if (ch == ')')
            {
//                stk2.clear();         // meiyou..
                while (!stk1.empty() && stk1.top() != '(')
                {
//                    stk2.push(stk1.top());
                    que1.push(stk1.top());
                    stk1.pop();
                }
                if (!stk1.empty())
                    stk1.pop();
                while (!que1.empty())
                {
                    stk1.push(que1.front());
                    que1.pop();
                }
//                while (!stk2.empty())
//                {
//                    stk1.push(stk2.top());
//                    stk2.pop();
//                }
//                #ifdef __test
//                cout<<stk1.top()<<endl;
//                #endif // __test
            }
            else
            {
                stk1.push(ch);
            }
        }

        string ans;
        while (!stk1.empty())
        {
            ans = stk1.top() + ans;
//            ans += stk1.top();
            stk1.pop();
//            cout<<ans<<endl;
        }
        return ans;
    }

};

int main()
{

//    string s = "(abcd)";
//    string s = "(u(love)i)";
//    string s = "(ed(et(oc))el)";
    string s = "a(bcdefghijkl(mno)p)q";

    LT1190 lt;

    cout<<lt.lt1190a(s)<<endl;

    return 0;
}
