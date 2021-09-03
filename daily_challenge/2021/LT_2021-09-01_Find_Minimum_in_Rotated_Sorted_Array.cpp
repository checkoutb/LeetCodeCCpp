
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        while (start<end) {
//            if (num[start]<num[end])
//                return num[start];
//            int mid = (start+end)/2;
//            if (num[mid]>=num[start]) {
//                start = mid+1;
//            } else {
//                end = mid;
//            }
//        }






// AC
    int lta(vector<int>& nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int t1 = nums[l];
            int t2 = nums[mid];
            int t3 = nums[r];
            if (t1 > t3)        // 左高右低
            {
                if (t2 > t3)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            else
            {
                // ..
                r = l;
            }
        }
        return nums[l];
    }

};

int main()
{
//    myvi v = {3,4,5,1,2};
//    myvi v = {4,5,6,7,0,1,2};
    myvi v = {11,13,15,17};

    LT lt;

    cout<<lt.lta(v)<<endl;

    return 0;
}
