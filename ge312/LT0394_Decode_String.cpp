
#include "../header/myheader.h"

class LT0394
{
public:



// discuss
// 1. 遇见数字以后，可以while把数字一次解码，而不必t1 = t1 * 10 + x
// 2. stack 是边解码，边pop/push，而不是push完，然后pop解码。


//        string res;
//
//        while (i < s.length() && s[i] != ']') {
//            if (!isdigit(s[i]))
//                res += s[i++];
//            else {
//                int n = 0;
//                while (i < s.length() && isdigit(s[i]))
//                    n = n * 10 + s[i++] - '0';
//
//                i++; // '['
//                string t = decodeString(s, i);
//                i++; // ']'
//
//                while (n-- > 0)
//                    res += t;
//            }
//        }
//
//        return res;


//            else if (s.charAt(idx) == '[') {
//                resStack.push(res);                   // 。。。
//                res = "";
//                idx++;
//            }
//            else if (s.charAt(idx) == ']') {
//                StringBuilder temp = new StringBuilder (resStack.pop());
//                int repeatTimes = countStack.pop();
//                for (int i = 0; i < repeatTimes; i++) {
//                    temp.append(res);         // temp + res + res
//                }
//                res = temp.toString();                // 。。。。
//                idx++;
//            }
//            else {
//                res += s.charAt(idx++);
//            }


//Runtime: 4 ms, faster than 77.84% of C++ online submissions for Decode String.
//Memory Usage: 8.8 MB, less than 69.53% of C++ online submissions for Decode String.
// 基本都是0/4ms
//

    string lt0394b(string s)
    {
        string ans = recursionb1(s);
        return ans;
    }

    string recursionb1(string s, int start = 0)
    {
        int dep = -1;
        int t1 = 0;
        string ans;
        while (start < s.size())
        {
            char ch = s[start];
            if (ch == '[')
            {
                dep++;
                if (dep == 0)
                {
                    string s3 = recursionb1(s, start + 1);
                    for (int i = 0; i < t1; i++)
                    {
                        ans += s3;
                    }
                }
            }
            else if (ch == ']')
            {
                t1 = 0;         // ...不是 [ 中。。
                dep--;
                if (dep == -2)
                    return ans;
            }
            else if (ch >= '0' && ch <= '9')
            {
                t1 = t1 * 10 + ch - '0';
                #ifdef __test
                cout<<"... t1 == "<<t1<<endl;
                #endif // __test
            }
            else
            {
                if (dep == -1)
                    ans += ch;
            }
            start++;
        }
        return ans;
    }

    // error
    string lt0394a(string s)
    {
        stack<string> stk1;
        stack<int> stk2;

        stk1.push(s);
        stk2.push(1);

        string ans;

        int t1 = 0;
        int t2 = 0;
        int sz1 = s.length();
        char ch;
        int t3 = 0;
        while (t1 < sz1)
        {
            ch = s[t1];
            if (ch >= '0' && ch <= '9')
            {
                if (t3 == 0 && !stk2.empty())
                {
                    t2 = stk2.top();
                    stk2.pop();
                    stk1.push(s.substr(t2, t1 - t2));
                }
                t3 = (t3 * 10 + ch - '0');
            }
            else if (ch == '[')
            {
                stk1.push("[");
                stk1.push(to_string(t3));
                t2 = t1 + 1;
                stk2.push(t2);
                t3 = 0;
            }
            else if (ch == ']')
            {
                t2 = stk2.top();
                stk2.pop();
                stk1.push(s.substr(t2, t1 - t2));

                #ifdef __test
                cout<<"      "<<s.substr(t2, t1 - t2)<<endl;
                #endif // __test

                stk1.push("]");
            }
            t1++;
        }

        #ifdef __test
        stack<string> stkq(stk1);
        while (!stkq.empty())
        {
            cout<<stkq.top()<<endl;
            stkq.pop();
        }
        cout<<"..........."<<endl;
        #endif // __test

        return ans;
    }

//    string recursiona1(string s)
//    {
//
//    }
};

int main()
{
//    string s = "3[a2[c]]";
//    string s = "3[a]2[bc]";

    string arr[] = {
        "3[a]2[bc]", "3[a2[c]]", "2[abc]3[cd]ef",
        "2[ab3[cd]]4[xy]"

        };

    LT0394 lt;
    for (auto p : arr)
        cout<<lt.lt0394b(p)<<endl;

    return 0;
}
