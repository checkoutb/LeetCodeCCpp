
#include "../header/myheader.h"

class LT2232
{
public:

// D D


//    int plus = exp.find('+');
//    vector<int> v;
//    vector<pair<int, int>> lp, rp;
//    for (int l = stoi(exp.substr(0, plus)), mul = 10; l * 10 >= mul; mul *= 10)
//        lp.push_back({ l / mul, l % mul});
//    for (int r = stoi(exp.substr(plus + 1)), mul = 1; r / mul > 0; mul *= 10)
//        rp.push_back({ r % mul, r / mul });
//    for (auto [m1, s1] : lp)
//        for (auto [m2, s2]: rp)
//            if (v.empty() || max(1, m1) * (s1 + s2) * max(1, m2) < max(1, v[0]) * (v[1] + v[2]) * max(1, v[3]))
//                v = {m1, s1, s2, m2};
//    return (v[0] ? to_string(v[0]) : "") + "(" + to_string(v[1])
//        + "+" + to_string(v[2]) + ")" + (v[3] ? to_string(v[3]) : "");




//Runtime: 3 ms, faster than 36.11% of C++ online submissions for Minimize Result by Adding Parentheses to Expression.
//Memory Usage: 6 MB, less than 18.48% of C++ online submissions for Minimize Result by Adding Parentheses to Expression.
// 1-9.. no zero
    string lt2232a(string expression)
    {
        int sz1 = expression.size();
        int idx1 = 0, idx2 = sz1;           // insert ( or ) before idx
        int t22 = expression.find("+");

        string s1 = expression.substr(0, t22);
        string s2 = expression.substr(t22 + 1);

        int a = std::stoi(s1);
        int b = std::stoi(s2);

        int pre = 0;
        int suf = 0;
        int pw1 = 1;
        while (pw1 <= a)
            pw1 *= 10;
        pw1 /= 10;
        int pw2 = 1;
        int mx = INT_MAX;
        int t2 = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            t2 = b;
            suf = 0;
            pw2 = 1;
            for (int j = s2.size() - 1; j >= 0; --j)
            {
                int t21 = (pre == 0 ? 1 : pre) * (a + t2) * (suf == 0 ? 1 : suf);

                #ifdef __test
                cout<<i<<", "<<j<<", "<<t21<<", "<<mx<<", "<<pre<<" * ("<<a<<" + "<<t2<<") * "<<suf<<endl;
                #endif // __test

                if (t21 < mx)
                {
                    #ifdef __test
                    cout<<"             "<<i<<", "<<j<<" -----------"<<endl;
                    #endif // __test
                    mx = t21;
                    idx1 = i, idx2 = j;
                }
                suf += t2 % 10 * pw2;
                pw2 *= 10;
                t2 /= 10;
            }
            pre *= 10;
            pre += (a / pw1);
            a %= pw1;
            pw1 /= 10;
        }
        #ifdef __test
        cout<<s1<<", "<<s2<<"     "<<(t22 + idx2)<<endl;
        cout<<idx1<<", "<<idx2<<endl;
        #endif // __test
        expression.insert(idx1, "(").insert(t22 + idx2 + 3, ")");
        return expression;
    }

};

int main()
{

    LT2232 lt;

//    string s = "247+38";
//    string s = "12+34";
    string s = "999+999";

    cout<<lt.lt2232a(s)<<endl;

    return 0;
}
