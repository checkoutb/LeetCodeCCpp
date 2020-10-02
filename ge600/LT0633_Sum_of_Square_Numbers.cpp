
#include "../header/myheader.h"

class LT0633
{
public:


// D D
//        for (int64_t i = 0, j = sqrt(c); i <= j; ) {
//            int64_t s = i*i + j*j;
//            if (s == c)
//                return true;
//            else if (s > c)
//                j--;
//            else
//                i++;
//        }


//        for (int i = 0; i <= Math.sqrt(c); i++) {
//            set.add(i * i);
//            if (set.contains(c - i * i)) {
//                return true;
//            }
//        }


//As said earlier, a natural number is a sum of two squares if and only if each prime factor that's 3 modulo 4 occurs to an even power in the number's prime factorization.
//
//require 'prime'
//
//def judge_square_sum(c)
//  c == 0 || c.prime_division.all? { |p, e| p % 4 != 3 || e.even? }
//end





//Runtime: 4 ms, faster than 73.47% of C++ online submissions for Sum of Square Numbers.
//Memory Usage: 6.3 MB, less than 12.43% of C++ online submissions for Sum of Square Numbers.
// ganjue zhineng yingsuan a
    bool lt0633a(int c)
    {
        int mxsq = (int) std::sqrt(c);
        if (mxsq * mxsq == c)
            return true;
        int lstMn = 0;
        while (mxsq >= lstMn)
        {
            int t1 = c - mxsq * mxsq;
            lstMn = (int) std::sqrt(t1);
            if (lstMn * lstMn == t1)
                return true;
            mxsq--;
        }
        return false;
    }

};

int main()
{

    int arr[] = {5,3,4,2,1};

    LT0633 lt;

    for (int i : arr)
        cout<<lt.lt0633a(i)<<endl;

    return 0;
}
