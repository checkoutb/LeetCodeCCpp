
#include "../header/myheader.h"

class LT0726
{
public:


// discuss，的都是从头遍历的。。不懂。


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Atoms.
//Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Number of Atoms.
    // 反向遍历，stack保存倍数。
    string lt0726b(string formula)
    {
        stack<int> stk1;
        map<string, int> map1;
        stk1.push(1);
        int multi = 1;
        int lastNum = 1;
        for (int i = formula.size() - 1; i >= 0; i--)
        {
            char ch = formula[i];
            if (ch == ')')
            {
                multi *= lastNum;
                stk1.push(lastNum);
                lastNum = 1;
            }
            else if (ch == '(')
            {
                int top = stk1.top();
                multi /= top;
                stk1.pop();
            }
            else if (std::isdigit(ch))
            {
                lastNum = ch - '0';
                int mul = 1;
                while (isdigit(formula[i - 1]))
                {
                    mul *= 10;
                    i--;
                    lastNum += (formula[i] - '0') * mul;
                }
            }
            else    // alpha
            {
                int j = i;
                while (std::isalpha(formula[j]) && formula[j] >= 'a')
                {
                    j--;
                }
                string s(formula, j, i - j + 1);
                map1[s] = map1[s] + multi * lastNum;

                lastNum = 1;
                i = j;
            }
        }

        string ans;
        for (auto p : map1)
        {
            ans += (p.first + (p.second > 1 ? std::to_string(p.second) : ""));
        }
        return ans;
    }


//// 用栈，从最内层出发，这样出括号时碰到的数字，直接乘在所有现有的个数上。
//// dfs找最内层。..但是每一层都需要新建map。((()()())).
//    string lt0726a(string formula)
//    {
//        int i = 0;
//        map<string, int> map1 = dfsa1(formula, i);
//    }
//
//    map<string, int> dfsa1(string formula, int& i)
//    {
//        if (i >= formula.size())
//            return map<string, int>();
//        if (formula[i] == '(')
//
//
//    }

};

int main()
{

    LT0726 lt;

//    string formula = "Mg(OH)2";

//    string formula = "H2O";

//    string formula = "K4(ON(SO3)2)2";

    string formula = "Be32";

    string ans = lt.lt0726b(formula);
    cout<<ans<<endl;
    return 0;
}
