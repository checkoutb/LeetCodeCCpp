
#include "../header/myheader.h"

class LT2763
{
public:





// Runtime
// 87ms
// Beats59.66%of users with C++
// Memory
// 42.81MB
// Beats64.71%of users with C++
    int sumImbalanceNumbers(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<bool> vb(1001, false);
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            vb = vector<bool>(1002, false);
            vb[nums[i]] = true;
            int mx = nums[i];
            int mn = mx;
            int cnt = 0;
            for (int j = i + 1; j < sz1; ++j)
            {
                if (nums[j] > mx)
                {
                    mx = nums[j];
                    if (vb[nums[j] - 1] == false)
                        ++cnt;
                }
                else if (nums[j] < mn)
                {
                    mn = nums[j];
                    if (vb[nums[j] + 1] == false)
                        ++cnt;
                }
                else
                {
                    if (vb[nums[j]])
                    {
                        ;
                    }
                    else
                    {
                        if (vb[nums[j] - 1] == false && vb[nums[j] + 1] == false)
                            ++cnt;
                        else if (vb[nums[j] - 1] && vb[nums[j] + 1])
                            --cnt;
                    }
                    vb[nums[j]] = true;
                }
                vb[nums[j]] = true;
                ans += cnt;
            }
        }
        return ans;
    }
};

int main()
{

    LT2763 lt;


    return 0;
}
