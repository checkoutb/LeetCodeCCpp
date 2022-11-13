
#include "../header/myheader.h"

class LT2461
{
public:

    // D D

    // unordered_map ¸ü¿ì¡£

    // if (--mp[A[i - k + 1]] == 0) mp.erase(A[i - k + 1]);


    //Runtime794 ms
    //    Beats
    //    14.6 %
    //    Memory96 MB
    //    Beats
    //    40.40 %
    long long lt2461a(vector<int>& nums, int k)
    {
        long long ans = 0LL;
        long long sum2 = 0LL;
        map<int, int> map2;
        int cnt = 0;

        for (int i = 0; i < k - 1; ++i)
        {
            sum2 += nums[i];
            if (map2[nums[i]] == 1)
            {
                ++cnt;
            }
            map2[nums[i]]++;
        }

        int sz1 = nums.size();
        for (int i = k - 1; i < sz1; ++i)
        {
            sum2 += nums[i];
            if (map2[nums[i]] == 1)
            {
                ++cnt;
            }
            map2[nums[i]]++;
            if (cnt == 0)
            {
                ans = max(ans, sum2);
            }

            sum2 -= nums[i - (k - 1)];
            if (map2[nums[i - k + 1]] == 2)
            {
                --cnt;
            }
            map2[nums[i - k + 1]]--;
        }
        return ans;
    }

};

int main()
{

    LT2461 lt;

    myvi v = { 1,5,4,2,9,9,9 };
    int k = 3;


    cout << lt.lt2461a(v, k) << endl;

    return 0;
}
