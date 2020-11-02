
#include "../header/myheader.h"

class LT1021
{
public:

// D D

//        string res;
//        int opened = 0;
//        for (char c : S) {
//            if (c == '(' && opened++ > 0) res += c;
//            if (c == ')' && opened-- > 1) res += c;
//        }
//        return res;

// 没有看到 直接 + substr的 那种。 buzhidao youmeiyou.


// 可以用 int 来表示 stack。。 (就++，  )就--。
//Runtime: 4 ms, faster than 87.37% of C++ online submissions for Remove Outermost Parentheses.
//Memory Usage: 7.1 MB, less than 5.04% of C++ online submissions for Remove Outermost Parentheses.
// 直接stack？为空就跳过一个(？
    string lt1021a(string S)
    {
        stack<char> stk1;
        string ans;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '(')
            {
                if (!stk1.empty())
                {
                    ans += '(';
                }
                stk1.push('(');
            }
            else
            {
                stk1.pop();
                if (!stk1.empty())
                {
                    ans += ')';
                }
            }
        }
        return ans;
    }

};

int main()
{

//    string s = "(()())(())";
//    string s = "(()())(())(()(()))";
    string s = "()()";

    LT1021 lt;

    cout<<lt.lt1021a(s)<<endl;

    return 0;
}
