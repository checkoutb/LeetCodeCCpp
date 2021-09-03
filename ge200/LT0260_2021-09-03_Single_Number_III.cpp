
#include "../header/myheader.h"

class LT0260
{
public:

// D D

//long mask = (~axorb+1)&axorb ;

//int second = first^x;

//When diff == numeric_limits<int>::min(),
//-diff is also numeric_limits<int>::min().
//Therefore, the value of diff after executing diff &= -diff is still numeric_limits<int>::min(). The answer is still correct.
//diff &= -diff;





//Runtime: 4 ms, faster than 99.11% of C++ online submissions for Single Number III.
//Memory Usage: 10 MB, less than 76.65% of C++ online submissions for Single Number III.
// ^ , last bit. group.
    vector<int> lt0260a(vector<int>& nums)
    {
        int t2 = 0;
        for (int i : nums)
            t2 ^= i;
        int t3 = 1 << (__builtin_ctz(t2));      // count of suffix 0
//        cout<<t3<<", "<<t2<<endl;
        int ta = 0;
        int tb = 0;
        for (int i : nums)
        {
            if ((i & t3) != 0)
            {
                ta ^= i;
            }
            else
            {
                tb ^= i;
            }
        }
        return {ta, tb};
    }

};

int main()
{
//    myvi v = {1,2,1,3,2,5};
//    myvi v = {-1,0};
    myvi v = {-1,1};

    LT0260 lt;

    myvi v2 = lt.lt0260a(v);

    showVectorInt(v2);

    return 0;
}
