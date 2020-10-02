
#include "../header/myheader.h"

class LT0640
{
public:


// D D

//def solve_equation(equation)
//  a, x = eval('i = 1i;' + equation.gsub('x', 'i').sub('=', '-(') + ')').rect
//  "x=#{-a/x}" rescue a != 0 ? 'No solution' : 'Infinite solutions'
//end


//string solveEquation(string equation) {
//    // normalize the equation, add 1 for x's which have no coefficient: x => 1x
//    equation = regex_replace(equation, regex("(^|[+=-])x"), "$011x");
//
//    // calculate coefficients for both sides
//    auto pos = equation.find('=');
//    auto l = coef(equation.substr(0, pos));
//    auto r = coef(equation.substr(pos + 1));
//
//    // l.first x + l.second = r.first x + r.second => ax = b
//    int a = l.first - r.first, b = r.second - l.second;
//
//    return a != 0 ? "x=" + to_string(b/a) : b != 0 ? "No solution" : "Infinite solutions";
//}
//
//pair<int, int> coef(string s) {
//    // split the side into form of (+/-)123x
//    auto e = regex("(^|[+-])\\d+x?");
//    regex_token_iterator<string::iterator> it(s.begin(), s.end(), e), end;
//
//    int a = 0, b = 0;
//    for (; it != end; it++)
//        (it->str().back() == 'x' ? a : b) += stoi(*it);
//
//    return {a, b};
//}



// md, yibu yige keng.
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Solve the Equation.
//Memory Usage: 6.4 MB, less than 13.90% of C++ online submissions for Solve the Equation.
    string lt0640a(string equation)
    {
        int mid = equation.find('=');
        string left = equation.substr(0, mid);
        string right = equation.substr(mid + 1);

        pair<int, int> lp = converta1(left);
        pair<int, int> rp = converta1(right);

        #ifdef __test
        cout<<lp.first<<" "<<lp.second<<endl;
        cout<<rp.first<<" "<<rp.second<<endl;
        #endif // __test

        int nx = (lp.first == INT_MAX ? 0 : lp.first) - (rp.first == INT_MAX ? 0 : rp.first);
        int nn = (rp.second == INT_MAX ? 0 : rp.second) - (lp.second == INT_MAX ? 0 : lp.second);

        if (nx == 0)
        {
            if (nn == 0)
                return "Infinite solutions";
            else
                return "No solution";
        }
        return "x=" + to_string(nn / nx);
    }

//    x+5-3+x=6+x-2
// exist x+-4 ?   no.
    pair<int, int> converta1(string s)
    {
        s += '+';
        int nx = 0;
        int nn = 0;
        bool hasx = false;
        bool hasn = false;
        int t1 = 0;
        int flag2 = 1;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            switch(ch)
            {
            case '+':
                flag2 = 1;
                if (i != 0 && s[i - 1] != 'x')
                {
                    hasn = true;
                    nn += t1;
                }
                t1 = 0;
                break;
            case '-':
                flag2 = -1;
                if (i != 0 && s[i - 1] != 'x')
                {
                    hasn = true;
                    nn += t1;
                }
                t1 = 0;
                break;
            case 'x':
                hasx = true;
//                nx += t1 == 0 ? 1 * flag2 : t1;         // 0x=0
                if (t1 == 0)
                {
                    if (i != 0 && s[i - 1] == '0')
                    {

                    }
                    else
                    {
                        nx += t1 == 0 ? 1 * flag2 : t1;
                    }
                }
                else
                {
                    nx += t1;
                }
                break;
            default:        // 0-9
                t1 *= 10;
                t1 += flag2 * (ch - '0');
                break;
            }
        }
//        cout<<s<<" = "<<nx<<" : "<<nn<<endl;
        return {hasx ? nx : INT_MAX, hasn ? nn : INT_MAX};
    }

};

int main()
{

    string arr[] = {
//    "x+5-3+x=6+x-2","x=x","2x=x",
//    "2x+3x-6x=x+2"
//    ,"x=x+2"
//    "-x=-1"
    "0x=0"
    };

    LT0640 lt;

    for (string& s : arr)
    {
        cout<<lt.lt0640a(s)<<endl;
    }

    return 0;
}
