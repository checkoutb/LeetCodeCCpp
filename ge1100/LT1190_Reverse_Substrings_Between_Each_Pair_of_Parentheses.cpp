
#include "../header/myheader.h"

class LT1190
{
public:


    string lt1190a(string s)
    {
        stack<char> stk1;
        stack<char> stk2;
        // a(zxc)b   (a(zxc)b)
//        string prefix = s.substr(0, s.find('('));

        for (char ch : s)
        {
            if (ch == ')')
            {
//                stk2.clear();         // meiyou..
                while (!stk1.empty() && stk1.top() != '(')
                {
                    stk2.push(stk1.top());
                    stk1.pop();
                }
                if (!stk1.empty())
                    stk1.pop();
                while (!stk2.empty())
                {
                    stk1.push(stk2.top());
                    stk2.pop();
                }
            }
            else
            {
                stk1.push(ch);
            }
        }

        string ans;
        while (!stk1.empty())
        {
            ans += stk1.top();
            stk1.pop();
        }
        return ans;
    }

};

int main()
{

//    string s = "(abcd)";
    string s = "(u(love)i)";

    LT1190 lt;

    cout<<lt.lt1190a(s)<<endl;

    return 0;
}
