
#include "../header/myheader.h"

class LT0674
{
public:



//Runtime: 16 ms, faster than 95.74% of C++ online submissions for Longest Continuous Increasing Subsequence.
//Memory Usage: 11.4 MB, less than 5.74% of C++ online submissions for Longest Continuous Increasing Subsequence.
    int lt0674a(vector<int>& nums)
    {
        if (nums.empty())           // .
            return 0;
        int ans = 0;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                cnt++;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        return max(ans, cnt);           // .
    }

};

int main()
{

    LT0674 lt;


    return 0;
}
