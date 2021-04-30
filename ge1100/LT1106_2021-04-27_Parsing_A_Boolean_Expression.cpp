
#include "../header/myheader.h"

class LT1106
{
public:

// D D

//return eval(S.replace('!', 'not |').replace('&(', 'all([').replace('|(', 'any([').replace(')', '])'))


// n-1 -> 0
//        for(int i=n-1;i>=0;i--){
//            if(exp[i]==')'||exp[i]=='t'||exp[i]=='f')
//                stk.push_back(exp[i]);
//            else if(exp[i]=='(')
// vector as stack


//    bool f(const string& s, int& i){
//        if(s[i] == 't'){
//            i++;
//            return true;
//        } else if(s[i] == 'f'){
//            i++;
//            return false;
//        } else if(s[i] == '!'){
//            return f_not(s,i);
//        } else if(s[i] == '&'){
//            return f_and(s,i);
//        } return f_or(s,i);
//    }


//    bool f_or(const string& s,int& i){
//        i+=2;
//        bool ret = false;
//        ret |= f(s,i);
//        while(s[i]!=')'){
//            i++;
//            ret |= f(s,i);
//        }
//        i++;
//        return ret;
//    }
// int& ....


// Polish Notation


//Runtime: 8 ms, faster than 60.25% of C++ online submissions for Parsing A Boolean Expression.
//Memory Usage: 7 MB, less than 79.50% of C++ online submissions for Parsing A Boolean Expression.
    bool lt1106a(string expression)
    {
        stack<char> stk;
//        vector<bool> vb;
        bool hasT = false;
        bool hasF = false;
        for (int i = 0; i < expression.size(); ++i)
        {
            char ch = expression[i];
            if (ch == ',')
                continue;
            if (ch == ')')
            {
                hasT = false;
                hasF = false;
//                vb.clear()
                while (!stk.empty())
                {
                    char c = stk.top();
                    stk.pop();
                    if (c == '(')
                    {
                        c = stk.top();
                        stk.pop();
                        bool ans = true;
                        switch(c)
                        {
                        case '!':
                            ans = hasF;
                            break;
                        case '|':
                            ans = hasT;
                            break;
                        case '&':
                            ans = !hasF;
                            break;
                        }
                        stk.push(ans ? 't' : 'f');
                        break;
                    }
                    else
                    {
                        if (c == 'f')
                        {
                            hasF = true;
                        }
                        else
                        {
                            hasT = true;
                        }
//                        vb.push()

                    }
                }
            }
            else
            {
                stk.push(ch);
            }
        }
        return stk.top() == 't' ? true : false;
    }

};

int main()
{
    vector<string> vs = {"!(f)", "|(f,t)", "&(t,f)", "|(&(t,f,t),!(t))"};

    LT1106 lt;

    for (string s : vs)
        cout<<lt.lt1106a(s)<<endl;

    return 0;
}
