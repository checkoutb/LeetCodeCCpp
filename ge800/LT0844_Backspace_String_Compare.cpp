
#include "../header/myheader.h"

class LT0844
{
public:

// D D
// 反序，各自找到最终会存在的char，然后对比1位(不同则break)，然后，继续各自找最终存在的char。


//Runtime: 4 ms, faster than 38.67% of C++ online submissions for Backspace String Compare.
//Memory Usage: 6.3 MB, less than 64.35% of C++ online submissions for Backspace String Compare.
    bool lt0844a(string S, string T)
    {
        stack<char> stk1;
        stack<char> stk2;
        for (char& ch : S)
        {
            if (ch == '#')
            {
                if (!stk1.empty())
                    stk1.pop();
            }
            else
            {
                stk1.push(ch);
            }
        }
        for (char& ch : T)
        {
            if (ch == '#')
            {
                if (!stk2.empty())
                    stk2.pop();
            }
            else
            {
                stk2.push(ch);
            }
        }
        #ifdef __test
        cout<<stk1.size()<<" : sz : "<<stk2.size()<<endl;
        #endif // __test
        if (stk1.size() != stk2.size())
            return false;

        while (!stk1.empty())
        {
            char ch1 = stk1.top();
            char ch2 = stk2.top();

            #ifdef __test
            cout<<ch1<<" : "<<ch2<<endl;
            #endif // __test

            if (ch1 != ch2)
                return false;
            stk1.pop();
            stk2.pop();
        }
        return true;
    }

};

int main()
{

//    string s = "ab#c";
//    string t = "ad#c";

    string s = "y#fo##f";
    string t = "y#f#o##f";

    LT0844 lt;

    cout<<lt.lt0844a(s, t)<<endl;

    return 0;
}
