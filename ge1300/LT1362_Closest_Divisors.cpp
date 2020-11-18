
#include "../header/myheader.h"

class LT1362
{
public:

// D D

//        for (int a = sqrt(x + 2); a > 0; --a) {
//            if ((x + 1) % a == 0)
//                return {a, (x + 1) / a};
//            if ((x + 2) % a == 0)
//                return {a, (x + 2) / a};
//        }
// kai gua le ba ......


//int largestDivisor(int num) {
//    int d = sqrt(num);
//    while (num % d != 0) --d;
//    return d;
//}



//Runtime: 12 ms, faster than 51.33% of C++ online submissions for Closest Divisors.
//Memory Usage: 6.6 MB, less than 23.95% of C++ online submissions for Closest Divisors.
    vector<int> lt1362a(int num)
    {
        int a1, a2;
        num++;
        int b1 = 1, b2 = num;

        for (int i = 2, mxi = (int) std::sqrt(num); i <= mxi; ++i)
        {
            if (num % i == 0)
            {
                b1 = i, b2 = num / i;
            }
        }
        a1 = b1, a2 = b2;

        num++;
        b1 = 1, b2 = num;
        for (int i = 2, mxi = (int) std::sqrt(num); i <= mxi; ++i)
        {
            if (num % i == 0)
            {
                b1 = i, b2 = num / i;
            }
        }
        if ((b2 - b1) < (a2 - a1))
        {
            a1 = b1, a2 = b2;
        }

        return {a1, a2};
    }

};

int main()
{

    vector<int> v = {8,123,999};

    LT1362 lt;

    for (int i : v)
    {
        vector<int> v2 = lt.lt1362a(i);
        cout<<v2[0]<<"   "<<v2[1]<<endl;;
    }

    return 0;
}
