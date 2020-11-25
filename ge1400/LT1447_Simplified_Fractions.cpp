
#include "../header/myheader.h"
//#include <experimental/numeric>

class LT1447
{
public:

// D D

//return x == 0 ? y : gcd(y % x, x);


// gcd   __gcd....
//Runtime: 68 ms, faster than 83.62% of C++ online submissions for Simplified Fractions.
//Memory Usage: 22.4 MB, less than 46.69% of C++ online submissions for Simplified Fractions.
    vector<string> lt1447a(int n)
    {
        vector<string> ans;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
//                if (j != 1 && i % j == 0)
//                    continue;
//                if (std::gcd(i, j) != 1)
//                    continue;
                if (gcda1(i, j) != 1)
                    continue;
                ans.push_back(std::to_string(j) + "/" + to_string(i));
            }
        }
        return ans;
    }

    int gcda1(int a, int b)
    {
        if (b == 0)
            return a;
        int c = a % b;
        return gcda1(b, c);
    }

};

int main()
{
//    cout<<std::__gcd(6,4);

    int n{6};

    LT1447 lt;

    vector<string> vs = lt.lt1447a(n);

    for (string& s : vs)
        cout<<s<<", ";

    return 0;
}
