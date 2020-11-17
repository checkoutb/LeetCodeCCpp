
#include "../header/myheader.h"

class LT1317
{
public:

// D D

//        while(n!=0){
//            if(!hasZero(n-1) && !hasZero(i)){
//                v.push_back(i);
//                v.push_back(n-1);
//                break;
//            }
//            n--;
//            i++;
//        }

//        while (n>0) {
//            int d = n % 10; // digit
//            n /= 10;
//
//            if ((d == 0 || d == 1) && n>0) { // n>0 evades the case when 1 is the most significant digit
//                a += step*(1+d);
//                b += step*9;
//                n--; // handle carry
//            } else {
//                a += step*1;
//                b += step*(d-1);
//            }
//            step *= 10;
//        }

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert Integer to the Sum of Two No-Zero Integers.
//Memory Usage: 6.5 MB, less than 67.93% of C++ online submissions for Convert Integer to the Sum of Two No-Zero Integers.
    vector<int> lt1317a(int n)
    {
        int t1 = 0;
        int t2 = 0;
        int t = 0;
        int p = 1;
        while ((n + t) > 0)
        {
            int n2 = n % 10 + t;
            t = 0;
            if (n2 < 0)
            {
                n2 += 10;
                t = -1;
            }
            if (n2 == 1)
            {
                if (n >= 10)
                {
                    t = -1;
                    t1 += 4 * p;
                    t2 += (6 + (n2 == 1)) * p;
                }
                else
                {
                    t1 += p;
                }
            }
            else if (n2 == 0)
            {
                t = -1;
                t1 += 4 * p;
                t2 += (6 + (n2 == 1)) * p;
            }
            else
            {
                t1 += 1 * p;
                t2 += (n2 - 1) * p;
            }
            p *= 10;
            n /= 10;
        }
        return {t1, t2};
    }

};

int main()
{

    int n = 2;
//    int n = 11;
//    int n = 10000;
//    int n = 69;
//    int n = 19;

    LT1317 lt;

    vector<int> v = lt.lt1317a(n);

    cout<<v[0]<<" + "<<v[1];

    return 0;
}
