
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        int a, b, c, d;
//        sscanf(x.c_str(), "%d+%di", &a, &b);
//        sscanf(y.c_str(), "%d+%di", &c, &d);
//        return to_string(a * c - b * d) + "+" + to_string(a * d + b * c) + "i";


//        int ra, ia, rb, ib;
//        char buff;
//        stringstream aa(a), bb(b), ans;
//        aa >> ra >> buff >> ia >> buff;
//        bb >> rb >> buff >> ib >> buff;
//        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
//        return ans.str();




// 1+-1i .. 不知道有没有  1-1i 。。。 应该没有吧。
    string lta(string num1, string num2)
    {
        pair<int, int> p1 = converta1(num1);
        pair<int, int> p2 = converta1(num2);
        int a = p1.first * p2.first - p1.second * p2.second;
        int b = p1.first * p2.second + p1.second * p2.first;

        return std::to_string(a) + "+" + to_string(b) + "i";
    }

    pair<int, int> converta1(string& num)
    {
        int a = 0;
        int b = 0;
        int idx = 0;
        bool isNeg = false;
        if (num[idx] == '-')
        {
            isNeg = true;
            idx++;
        }

        while (num[idx] != '+')
        {
            a *= 10;
            a += num[idx] - '0';
            idx++;
        }
        if (isNeg)
        {
            a *= -1;
            isNeg = false;
        }

        idx++;
        if (num[idx] == '-')
        {
            isNeg = true;
            idx++;
        }
        while (num[idx] != 'i')
        {
            b *= 10;
            b += num[idx] - '0';
            idx++;
        }
        if (isNeg)
        {
            b *= -1;
        }
        return {a, b};
    }

};

int main()
{
    string s1 = "1+-1i";
    string s2 = "1+-1i";

    LT lt;

    cout<<lt.lta(s1, s2);

    return 0;
}
