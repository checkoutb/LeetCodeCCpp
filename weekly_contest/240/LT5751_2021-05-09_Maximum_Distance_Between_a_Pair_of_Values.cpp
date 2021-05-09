
#include "../../header/myheader.h"

class LT5751
{
public:

// D

//if (i2 == n) break;

//            if (A[i] > B[j])
//                i++;
//            else
//                res = max(res, j++ - i);




// AC
    int lt5751a(vector<int>& nums1, vector<int>& nums2)
    {
        int i1 = 0, i2 = -1;
        int ans = 0;
        for (int i = 0; i < nums1.size(); ++i)
        {
            while (i2 + 1 < nums2.size() && nums2[i2 + 1] >= nums1[i])
            {
                ++i2;
            }
            #ifdef __test
            cout<<i<<", "<<i2<<endl;
            #endif // __test
            ans = max(i2 - i, ans);
//            if (i2 >= i1)
//            {
//                ans
//            }
        }
        return ans;
    }

};

int main()
{
//    myvi v1 = {55,30,5,4,2};
//    myvi v2 = {100,20,10,10,5};

//    myvi v1 = {2,2,2};
//    myvi v2 = {10,10,1};

//    myvi v1 = {30,29,19,5};
//    myvi v2 = {25,25,25,25,25};

    myvi v1 = {5,4};
    myvi v2 = {3,2};

    LT5751 lt;

    cout<<lt.lt5751a(v1, v2)<<endl;

    return 0;
}
