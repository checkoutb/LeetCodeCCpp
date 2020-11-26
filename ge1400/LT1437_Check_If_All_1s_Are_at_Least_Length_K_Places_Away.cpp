
#include "../header/myheader.h"

class LT1437
{
public:

// D D





//Runtime: 124 ms, faster than 91.12% of C++ online submissions for Check If All 1's Are at Least Length K Places Away.
//Memory Usage: 57.9 MB, less than 69.01% of C++ online submissions for Check If All 1's Are at Least Length K Places Away.
    bool lt1437a(vector<int>& nums, int k)
    {
        int lst1 = -k - 1;
        for (int i = 0, mxi = nums.size(); i < mxi; ++i)
        {
            if (nums[i])
            {
                if (i - lst1 <= k)
                    return false;
                lst1 = i;
            }
        }
        return true;
    }

};

int main()
{
//    vector<int> v = {1,0,0,1,0,1};
//    int k{2};

    vector<int> v = {1,1,1,1,1};
    int k{0};

    LT1437 lt;

    cout<<lt.lt1437a(v, k)<<endl;

    return 0;
}
