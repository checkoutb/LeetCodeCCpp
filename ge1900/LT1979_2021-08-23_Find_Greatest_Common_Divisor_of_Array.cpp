
#include "../header/myheader.h"

class LT1979
{
public:

// D D

//return __gcd(*min_element(begin(n), end(n)), *max_element(begin(n), end(n)));


//    int gcd(int a, int b){
//        for(int i = min(a, b); i > 0; i--){
//            if(a % i == 0 && b % i == 0){
//                return i;
//            }
//        }
//        return -1;
//    }


//    int gcd(int a, int b){
//        if(a == 0){
//            return b;
//        }
//        if(b == 0){
//            return a;
//        }
//        return gcd(b, a%b);
//    }



//Runtime: 4 ms, faster than 57.14% of C++ online submissions for Find Greatest Common Divisor of Array.
//Memory Usage: 12.4 MB, less than 23.81% of C++ online submissions for Find Greatest Common Divisor of Array.
    int lt1979a(vector<int>& nums)
    {
        int mn = nums[0];
        int mx = nums[0];
        for (int i : nums)
        {
            mn = min(i, mn);
            mx = max(i, mx);
        }
        return gcda(mx, mn);
    }

    int gcda(int a, int b)
    {
        if (a < b)
        {
            int t2 = a;
            a = b;
            b = t2;
        }
        int t2 = a % b;
        if (t2 == 0)
            return b;
        return gcda(b, t2);
    }

};

int main()
{
//    myvi v = {2,5,6,9,10};
//    myvi v = {7,5,6,8,3};
    myvi v = {3,3};

    LT1979 lt;

    cout<<lt.lt1979a(v)<<endl;

    return 0;
}
