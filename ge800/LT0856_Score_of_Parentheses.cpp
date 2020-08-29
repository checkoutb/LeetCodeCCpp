
#include "../header/myheader.h"

class LT0856
{
public:



// D D

//        for (int i=0;i<n;i++){
//            if (S[i]=='('){
//                l+=1;
//            }
//            else{
//                l--;
//            }
//            if (S[i]==')'&&S[i-1]=='('){
//                res+= (1<<l);
//            }
//
//        }
// 结果 拆解开来就是 () 代表的1，右移 前缀(的个数 个
// 加法不影响 乘二。


//        for (char i : S)
//            if (i == '(') {
//                stack.push(cur);
//                cur = 0;
//            }
//            else {
//                cur += stack.top() + max(cur, 1);
//                stack.pop();
//            }


//        int res[30] = {0}, i = 0;
//        for (char c : S)
//            if (c == '(') res[++i] = 0;
//            else res[i - 1] += max(res[i] * 2, 1), i--;
//        return res[0];



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Score of Parentheses.
//Memory Usage: 6.2 MB, less than 26.21% of C++ online submissions for Score of Parentheses.
// S.length S.length() S.size() ........
    int lt0856a(string S)
    {
        int score = 0;
        stack<int> stk1;
        for (int i = 0; i < S.size(); i++)
        {

            #ifdef __test
            show_stack_int(stk1);
            cout<<endl;
            #endif // __test

            if (S[i] == '(')
            {
                stk1.push(-1);
            }
            else
            {
                int tp = stk1.top();
                if (tp == -1)
                {
                    stk1.pop();
                    int t2 = 1;
                    while (!stk1.empty())
                    {
                        tp = stk1.top();
                        if (tp != -1)
                        {
                            t2 += tp;
                            stk1.pop();
                        }
                        else
                        {
                            break;
                        }
                    }
                    stk1.push(t2);
                }
                else
                {
                    // *2
                    int t2 = tp * 2;
                    stk1.pop();
                    stk1.pop();     // -1
                    while (!stk1.empty())
                    {
                        tp = stk1.top();
                        if (tp != -1)
                        {
                            t2 += tp;
                            stk1.pop();
                        }
                        else
                        {
                            break;
                        }

                    }
                    stk1.push(t2);
                }
            }
        }
        #ifdef __test
        cout<<" . . "<<stk1.size()<<endl;
        #endif // __test
        while (!stk1.empty())
        {
            #ifdef __test
            cout<<" stk1 "<<stk1.top()<<endl;
            #endif // __test
            score += stk1.top();
            stk1.pop();
        }
//        score = stk1.top();
        return score;
    }

};

int main()
{

    string arr[] = {
//    "()", "(())", "()()",
    "(()(()))"};

    LT0856 lt;

    for (string s: arr)
    {
        cout<<lt.lt0856a(s)<<endl;
    }

    return 0;
}
