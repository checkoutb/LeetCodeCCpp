
#include "../header/myheader.h"

class LT1413
{
public:

// D D

// int mn = 0;   return 1-mn;




//Runtime: 4 ms, faster than 51.93% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
//Memory Usage: 7.5 MB, less than 87.88% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
    int lt1413a(vector<int>& nums)
    {
        int mn = 1;
        int sum2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum2 += nums[i];
            mn = min(mn, sum2);
        }
        return mn == 1 ? 1 : (1 - mn);
    }

};

int main()
{

//    vector<int> v = {-3,2,-3,4,2};
//    vector<int> v = {1,2};
    vector<int> v = {1,-2,-3};

    LT1413 lt;

    cout<<lt.lt1413a(v)<<endl;

    return 0;
}
