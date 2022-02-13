
#include "../header/myheader.h"

class LT2006
{
public:

// D D

//    int cnt[101] = {}, res = 0;
//    for (auto n : nums)
//        ++cnt[n];
//    for (int i = k + 1; i < 101; ++i)
//        res += cnt[i] * cnt[i - k];



//Runtime: 6 ms, faster than 96.05% of C++ online submissions for Count Number of Pairs With Absolute Difference K.
//Memory Usage: 12.4 MB, less than 40.76% of C++ online submissions for Count Number of Pairs With Absolute Difference K.
// ... array 都忘了。。。
    int lt2006a(vector<int>& nums, int k)
    {
        int arr[101] = {0};
        int ans = 0;
        for (int i : nums)
        {
            if (i + k <= 100)
            {
                ans += arr[i + k];
            }
            if (i - k >= 0)
            {
                ans += arr[i - k];
            }
            arr[i]++;
        }
        return ans;
    }

};

int main()
{

    LT2006 lt;


    return 0;
}
