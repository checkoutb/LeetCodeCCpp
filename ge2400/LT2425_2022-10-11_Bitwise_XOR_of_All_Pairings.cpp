
#include "../header/myheader.h"

class LT2425
{
public:

    // D D

    //int x = 0, y = 0;
    //for (int a : A)
    //    x ^= a;
    //for (int b : B)
    //    y ^= b;
    //return (A.size() % 2 * y) ^ (B.size() % 2 * x);



//Runtime: 144 ms, faster than 95.99 % of C++ online submissions for Bitwise XOR of All Pairings.
//Memory Usage : 60.4 MB, less than 94.90 % of C++ online submissions for Bitwise XOR of All Pairings.
    int lt2425a(myvi& nums1, myvi& nums2)
    {
        int sz1 = nums1.size(), sz2 = nums2.size();
        int ans = 0;
        if (sz1 & 1)
        {
            for (int i = 0; i < sz2; ++i)
            {
                ans ^= nums2[i];
            }
        }
        if (sz2 & 1)
        {
            for (int i = 0; i < sz1; ++i)
                ans ^= nums1[i];
        }
        return ans;
    }

};

int main()
{

    LT2425 lt;


    return 0;
}
