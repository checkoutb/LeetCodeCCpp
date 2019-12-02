
#include "../header/myheader.h"

class LT0453
{
public:

// discuss:

// 数学。。  最终的和 与 最小数每次都会移动。  2个未知变量，最终的和，增加次数。 2元一次。


// gg...

//    int lt0453c(vector<int>& nums)
//    {
//
//    }

    // 每次增加n-1,直到变成矩形(能被整除)。...error
    int lt0453b(vector<int>& nums)
    {
        int sz1 = nums.size();
        if (sz1 == 1)
            return 0;
        vector<long> nums2(nums.begin(), nums.end());
        std::sort(nums2.begin(), nums2.end());
        if (nums2[0] < 0)
        {
            int d = std::abs(nums2[0]);
            for (int i = 0; i < sz1; i++)
                nums2[i] += d;
        }

//        for_each(nums2.begin(), nums2.end(), fun_cout);
//        cout<<endl<<endl;

        long sum1 = std::accumulate(nums2.begin(), nums2.end(), 0L);
        long max1 = nums2[sz1 - 1];
        long area = max1 * sz1;
        long a1 = area - sum1;

        return (int) (a1 / (sz1 - 1) + (a1 % (sz1 - 1) == 0 ? 0 : 1 + ((sz1 - 1) - a1 % (sz1 - 1))));
    }

//    int lt0453a(vector<int>& nums)
//    {
//        int sz1 = nums.size();
//        std::sort(nums);
//        int min1 = nums[0];
//        int max1 = nums[sz1 - 1];
//        int diff = max1 - min1 - 1;
//        int sum1 = std::accumulate(nums.begin(), nums.end(), 0);
//
//    }
};

int main()
{
//    vector<int> v = {1,2,3};
//    vector<int> v = {1,2};
//    vector<int> v = {1,1,1};
    vector<int> v = {-100,0,100};

    LT0453 lt;
    cout<<lt.lt0453b(v)<<endl;

    return 0;
}
