
#include "../header/myheader.h"

class LT2501
{
public:





    //Runtime174 ms
    //    Beats
    //    98.95 %
    //    Memory83.1 MB
    //    Beats
    //    92.15 %
    int lt2501a(vector<int>& nums)
    {
        int arr[100001] = { 0 };
        std::sort(begin(nums), end(nums));
        int ans = -1;
        int sz1 = nums.size();
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = nums[i];
            if (arr[t2] != 0)
            {
                ans = max(ans, arr[t2] + 1);
            }
            if (t2 < 317)
            {
                arr[t2 * t2] = arr[t2] + 1;
            }
        }

        return ans;
    }

};

int main()
{

    LT2501 lt;


    return 0;
}
