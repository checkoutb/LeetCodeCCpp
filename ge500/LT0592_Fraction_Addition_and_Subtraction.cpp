
#include "../header/myheader.h"

class LT0592
{
public:

// D D

//    int gcd(int a, int b) {
//        return (b == 0) ? a : gcd(b, a % b);
//    }


//    istringstream in(expression);
//    int A = 0, B = 1, a, b;
//    char _;
//    while (in >> a >> _ >> b) {
//        A = A * b + a * B;
//        B *= b;
//        int g = abs(__gcd(A, B));
//        A /= g;
//        B /= g;
//    }
//    return to_string(A) + '/' + to_string(B);




//Runtime: 4 ms, faster than 29.89% of C++ online submissions for Fraction Addition and Subtraction.
//Memory Usage: 6.2 MB, less than 22.51% of C++ online submissions for Fraction Addition and Subtraction.
// 最小公倍数。
    string lt0592a(string expression)
    {
        pair<int, int> p1 = std::make_pair(0, 1);
        int i = 0;
        while (i < expression.length())
        {
            int next1 = expression.find('/', i);
            int t1 = stoi(expression.substr(i, next1 - i));
            i = next1 + 1;
            next1 = expression.find_first_of("+-", i);
            if (next1 == std::string::npos)
                next1 = expression.length();
            int t2 = stoi(expression.substr(i, next1 - i));
            i = next1;
            pair<int, int> p2 = std::make_pair(t1, t2);
            p1 = adda1(p1, p2);
        }

        return to_string(p1.first) + "/" + to_string(p1.second);
    }

    pair<int, int> adda1(pair<int, int> p1, pair<int, int> p2, bool isAdd = true)
    {
        int t1 = p1.first;
        int t2 = p1.second;
        int t3 = p2.first;
        int t4 = p2.second;
        int a1 = t1 * t4 + t2 * t3;
        int a2 = t2 * t4;
        int g = gcda1(max(a1, a2), min(a1, a2));
        return std::make_pair(a1 / g, a2 / g);
    }

    int gcda1(int t1, int t2)
    {
        if (t2 == 0)                // t1 = 4, t2 = 0
            return t1;
        int t3 = t1 % t2;
        if (t3 != 0)
        {
            return gcda1(t2, t3);
        }
        return abs(t2);         // 1 / -6...
    }

};

int main()
{

//    string s = "1/3-1/2";
//    string s = "-1/2+1/2+1/3";
    string s = "-1/2+1/2";
//    string s = "5/3+1/3";
//    string s = "1/3-1/2";

    LT0592 lt;

    cout<<lt.lt0592a(s)<<endl;

    return 0;
}
