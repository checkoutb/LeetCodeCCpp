
#include "../header/myheader.h"

class LT2447
{
public:

    // D D

    //int res = 0;
    //unordered_map<int, int> gcds;
    //for (int i = 0; i < nums.size(); ++i) {
    //    unordered_map<int, int> gcds1;
    //    if (nums[i] % k == 0) {
    //        ++gcds[nums[i]];
    //        for (auto [prev_gcd, cnt] : gcds)
    //            gcds1[gcd(prev_gcd, nums[i])] += cnt;
    //    }
    //    res += gcds1[k];
    //    swap(gcds, gcds1);
    //}
    //return res;



//Runtime: 18 ms, faster than 91.77 % of C++ online submissions for Number of Subarrays With GCD Equal to K.
//Memory Usage : 8.9 MB, less than 73.74 % of C++ online submissions for Number of Subarrays With GCD Equal to K.
    int lt2447a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            int gd = nums[i];
            for (int j = i; j < sz1 && gd >= k; ++j)
            {
                gd = gcd(gd, nums[j]);
                if (gd == k)
                    ++ans;
            }
        }
        return ans;
    }

    int gcd(int a, int b)
    {
        return (b == 0) ? a : gcd(b, a % b);
    }

};

int main()
{

    LT2447 lt;

    myvi v = { 9,3,1,2,6,3 };
    int k = 3;

    cout << lt.lt2447a(v, k) << endl;

    return 0;
}
