
#include "../../header/myheader.h"

class LT6359
{
public:



    // AC
    // ????
    int minimizeMax(vector<int>& nums, int p) {

        int sz1 = nums.size();

        sort(begin(nums), end(nums));

        int st = 0;
        int en = nums[sz1 - 1] - nums[0];     // gap / diff
        int ans = -1;
        int cnt = 0;
        while (st <= en)
        {
            int md = (st + en) / 2;
            cnt = 0;
            for (int i = 1; i < sz1 && cnt < p; ++i)
            {
                if (nums[i] - nums[i - 1] <= md)
                {
                    ++cnt;
                    ++i;
                }
            }
            if (cnt >= p)
            {
                ans = md;
                en = md - 1;
            }
            else
            {
                st = md + 1;
            }
        }
        return ans;
    }
};

int main()
{

    LT6359 lt;

    myvi v = { 10,1,2,7,1,3 };
    int p = 2;


    cout << lt.minimizeMax(v, p) << endl;

    return 0;
}
