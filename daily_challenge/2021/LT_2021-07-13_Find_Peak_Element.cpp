
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        int r = nums.size()-1;
//        while (l < r) {
//            int mid = l + (r-l)/2;
//            if (nums[mid] > nums[mid+1]) {
//                r = mid;
//            } else {
//                l = mid+1;
//            }
//        }




// AC
    int lta(vector<int>& nums)
    {
        bool bigger = true;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (bigger)
            {
                bigger = nums[i] > nums[i + 1];
                if (bigger)
                {
                    return i;
                }
            }
            else
            {
                bigger = nums[i] > nums[i + 1];
            }
            bigger = !bigger;
        }
        return nums.size() - 1;
//        return -1;      // unreachable
    }

};

int main()
{
//    myvi v = {1,2,3,1};
//    myvi v = {1,2,1,3,5,6,4};
    myvi v = {1,2,3};

    LT lt;

    cout<<lt.lta(v)<<endl;

    return 0;
}
