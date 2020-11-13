
#include "../header/myheader.h"

class LT1281
{
public:

// D D

//  (d = n.digits).reduce(:*) - d.sum
//  n.digits.reduce(:*) - n.digits.sum
// 2ge ruby



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.
//Memory Usage: 6.3 MB, less than 32.10% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.
    int lt1281a(int n)
    {
        int pro = 1;
        int sum = 0;
        while (n > 0)
        {
            int t1 = n % 10;
            n /= 10;
            pro *= t1;
            sum += t1;
        }
        return pro - sum;
    }

};

int main()
{

//    int n = 234;
    int n = 4421;

    LT1281 lt;

    cout<<lt.lt1281a(n)<<endl;

    return 0;
}
