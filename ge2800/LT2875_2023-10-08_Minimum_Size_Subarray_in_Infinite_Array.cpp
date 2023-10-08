
#include "../header/myheader.h"

class LT2875
{
public:

// D D

//        for (; right < N; right++) {
//            cur += nums[right];
//            while (left <= right && cur > newTarget) {
//                cur -= nums[left];
//                left++;
//            }
//            if (cur == newTarget) {
//                res = min(res, right - left + 1);
//            }
//        }


//        unordered_map<long, int> dp{{0L, -1}};
//        for (int i = 0; i < 2 * n; ++i) {
//            su += A[i % n];
//            if (dp.count(su - target))
//                res = min(res, i - dp[su - target]);
//            dp[su] = i;
//        }



//Runtime55 ms
//Beats
//55.59%
//Memory50.1 MB
//Beats
//41.20%
    int minSizeSubarray(vector<int>& nums, int target)
    {
        long long sum2 = reduce(begin(nums), end(nums), 0LL);
        int ans = -1;
        int ans2 = 0;
        if (sum2 <= target)
        {
            ans2 += nums.size() * (target / sum2);
            target = target % sum2;

            if (target == 0)
                return ans2;
        }

        #ifdef __test
        cout<<sum2<<", "<<target<<endl;
        #endif // __test

        vector<long long> vi(begin(nums), end(nums));           // ... long long
        vi.insert(vi.end(), begin(nums), end(nums));
        if (vi[0] == target)
            return ans2 + 1;

        for (int i = 1; i < vi.size(); ++i)
        {
            vi[i] += vi[i - 1];
            if (vi[i] == target)
                if (ans == -1)
                    ans = i + 1;
        }

        if (false && ans2 != 0)                 // ... this is error
        {
            int idx = vi.size() / 2 - 1;
            for (int i = 0, mxi = vi.size() / 2; i <= mxi; ++i)
            {
                while (vi[idx] - vi[i] < target)
                    ++idx;

                if (vi[idx] - vi[i] == target)
                {
                    if (ans == -1)
                        ans = idx - i;
                    else
                        ans = min(ans, idx - i);
                }
            }
        }
        else
        {
            int idx = 0;
            for (int i = 0, mxi = vi.size() / 2; i < mxi; ++i)
            {
                while (vi[idx] - vi[i] < target)
                {
                    ++idx;
                }
                if (vi[idx] - vi[i] == target)
                {
                    if (ans == -1)
                        ans = idx - i;
                    else
                        ans = min(ans, idx - i);
                }
            }
        }

        return ans == -1 ? -1 : (ans + ans2);
    }

};

int main()
{

    LT2875 lt;

//    myvi v = {1,2,3};
//    int t = 5;

//    myvi v = {1,1,1,2,3};
//    int t = 4;

//    myvi v = {2,4,6,8};
//    int t = 22;

    myvi v = {2,1,5,7,7,1,6,3};
    int t = 39;     // 9

    cout<<lt.minSizeSubarray(v, t)<<endl;

    return 0;
}
