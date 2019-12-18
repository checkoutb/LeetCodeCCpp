
#include "../header/myheader.h"

class LT0462
{
public:

// details
// nth_element..... java好惨，得自己写quick select.。。。

//        sort(nums.begin(), nums.end());
//        int m = 0;
//        for (int i=0, j=nums.size()-1; i<j; i++, j--) {
//            m += nums[j] - nums[i];
//        }
// numsj - numsi = (numsj - mid) + (mid - numi)


// 升序，以中位数为最终水平面。。如果选择的最终数比中位数小，则左侧少上升的部分 < 右侧多下降的部分，次数会大于中位数的次数。

//untime: 16 ms, faster than 85.69% of C++ online submissions for Minimum Moves to Equal Array Elements II.
//Memory Usage: 9.4 MB, less than 75.00% of C++ online submissions for Minimum Moves to Equal Array Elements II.

    int lt0462b(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        int ans = 0;
        for (int n : nums)
        {
            ans += (std::abs(n - mid));
        }
        return ans;
    }

    int lt0462a(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for (int n : nums)
        {
            sum += n;
        }
        int avg = sum / nums.size();
        long long a1 = 0;
        long long a2 = 0;
        long long a3 = 0;
        long long a4 = 0;
        vector<int>::iterator it3 = std::upper_bound(nums.begin(), nums.end(), avg);
        vector<int>::iterator it2 = std::lower_bound(nums.begin(), nums.end(), avg);
        int avg2 = it2 == nums.end() ? INT_MAX : *it2;
        int avg3 = it3 == nums.end() ? INT_MAX : *it3;
        for (int n : nums)
        {
            a1 += (std::abs(n - avg));
            a2 += (std::abs(n - avg - 1));
            a3 += (std::abs(n - avg2));
            a4 += (std::abs(n - avg3));
        }

        #ifdef __test
        cout<<a1<<","<<a2<<","<<a3<<","<<a4<<endl;
        #endif // __test

        long long ans = min(a1, min(a2, min(a3, a4)));

        return (int) ans;
    }
};

int main()
{
    LT0462 lt;
//    vector<int> v = {1,0,0,8,6};

    vector<int> v = {1};

    cout<<lt.lt0462b(v)<<endl;

    return 0;
}
