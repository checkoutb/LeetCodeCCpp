
#include "../header/myheader.h"

class LT0523
{
public:


// d && d
// 一路sum，余数相同，意味着必然存在k的倍数。。。。n*k，n是integer，可以0.。。


//Runtime: 48 ms, faster than 22.76% of C++ online submissions for Continuous Subarray Sum.
//Memory Usage: 10.6 MB, less than 95.00% of C++ online submissions for Continuous Subarray Sum.
    bool lt0524b(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int sum = 0;
        for (int i = 0; i < sz1; i++)
        {
            sum = nums[i];
            for (int j = i + 1; j < sz1; j++)
            {
                sum += nums[j];
                if (sum == k || (k != 0 && sum % k == 0))
                    return true;
            }
        }
        return false;
    }

    // stack overflow
    bool lt0523a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int arr[sz1][sz1] = {{0}};
        for (int i = 0; i < sz1; i++)
        {
            arr[i][i] = nums[i];
        }
        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                arr[i][j] = arr[i][j - 1] + nums[j];
                if (arr[i][j] == k || (k != 0 && arr[i][j] % k == 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<int> v = {23,2,6,4,7};
    int k = 6;

    LT0523 lt;
    cout<<lt.lt0523a(v, k)<<endl;

    return 0;
}
