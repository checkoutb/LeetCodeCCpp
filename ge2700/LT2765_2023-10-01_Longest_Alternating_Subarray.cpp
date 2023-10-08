
#include "../header/myheader.h"

class LT2765
{
public:

// D D

//            while(curr+1<nums.size() && nums[curr+1]-nums[curr]==diff){
//                curr++;
//                diff= -diff;
//            }


//        for (int i = 0; i < n; ++i)
//            for (j = i + 1; j < n && A[j] == A[i] + (j - i) % 2; ++j)
//                res = max(res, j - i + 1);



//Runtime16 ms
//Beats
//77.84%
//Memory65.5 MB
//Beats
//19.9%

    // a, a+1, a, a+1 ...
    // sz1 <= 100
    int alternatingSubarray(vector<int>& nums)
    {
        int sz1 = nums.size();
        int ans = -1;
        int j = 0;
        for (int i = 0; i < sz1 - 1; ++i)
        {
            if (num[i + 1] != nums[i] + 1)
                continue;
            j = i + 2;
            while (j < sz1 && nums[j] == nums[j - 2])
            {
                ++j;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }

};

int main()
{

    LT2765 lt;


    return 0;
}
