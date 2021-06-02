
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        unordered_map<string, function<int (int, int) > > map = {
//            { "+" , [] (int a, int b) { return a + b; } },
//            { "-" , [] (int a, int b) { return a - b; } },
//            { "*" , [] (int a, int b) { return a * b; } },
//            { "/" , [] (int a, int b) { return a / b; } }
//        };
//        std::stack<int> stack;
//        for (string& s : tokens) {
//            if (!map.count(s)) {
//                stack.push(stoi(s));
//            } else {
//                int op1 = stack.top();
//                stack.pop();
//                int op2 = stack.top();
//                stack.pop();
//                stack.push(map[s](op2, op1));
//            }
//        }
//        return stack.top();


//    stack<int> s;
//    unordered_map<string, function<int(int,int)>> map {
//        { "+", std::plus<int>() },
//        { "-", std::minus<int>() },
//        { "*", std::multiplies<int>() },
//        { "/", std::divides<int>() }
//    };
//
//    for (const auto& token : tokens) {
//        const auto& op = map.find(token);
//        if (op != map.end()) {
//            assert(s.size() >= 2);
//            int rhs = s.top(); s.pop();
//            int lhs = s.top(); s.pop();
//            s.push((*op).second(lhs, rhs));               // .second? <-(?) std::plus<int>()
//        } else {
//            s.push(stoi(token));
//        }
//    }
//
//    assert(s.size() == 1);
//    return s.top();



// AC
// 逆波兰表达式
    int evalRPN(vector<string>& tokens)
    {
        stack<int> stk1;
        int a, b;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i][tokens[i].size() - 1] < '0')      // "-11"[0] < '0' or size==1&&[0]<'0'
            {
                b = stk1.top();
                stk1.pop();
                a = stk1.top();
                stk1.pop();
                switch(tokens[i][0])
                {
                case '+':
                    a = a + b;
                    break;
                case '-':
                    a = a - b;
                    break;
                case '*':
                    a = a * b;
                    break;
                case '/':
                    a = a / b;
                    break;
                }
                #ifdef __test
                cout<<" "<<a<<endl;
                #endif // __test
                stk1.push(a);
            }
            else
            {
                stk1.push(std::stoi(tokens[i]));
            }
        }
        return stk1.top();
    }

};

int main()
{
    vector<string> vs = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
//    vector<string> vs = {"2","1","+","3","*"};
//    vector<string> vs = {"4","13","5","/","+"};

    LT lt;

    cout<<lt.evalRPN(vs)<<endl;

    return 0;
}
