
#include "../header/myheader.h"

class LT2163
{
public:





    //Runtime337 ms
    //    Beats
    //    93.16 %
    //    Memory134.4 MB
    //    Beats
    //    82.11 %
    // 2 priq . 上次就这个，tle了。
    // topic: dp, priq.  可能是 priq 和 multiset 的区别？
    // 应该不太一样
    long long lt2163a(vector<int>& nums)
    {
        int sz1 = nums.size();
        long long ans = 1LL << 60;
        //vector<long long> vi(sz1 / 3, 0);         // < i
        vector<long long> vi(sz1);
        priority_queue<int> priq(begin(nums), begin(nums) + sz1 / 3);
        long long sum2 = accumulate(begin(nums), begin(nums) + sz1 / 3, 0LL);

        for (int i = sz1 / 3; i < sz1 / 3 * 2; ++i)
        {
            vi[i] = sum2;
            if (priq.top() > nums[i])
            {
                sum2 += nums[i] - priq.top();
                priq.pop();
                priq.push(nums[i]);
            }
        }
        //priq.~priority_queue();       // LeetCode: AddressSanitizer: attempting double-free

        priority_queue<int, vector<int>, std::greater<int>> priq2(begin(nums) + sz1 / 3 * 2, end(nums));
        long long sum3 = accumulate(begin(nums) + sz1 / 3 * 2, end(nums), 0LL);
        
        ans = min(ans, sum2 - sum3);
        for (int i = sz1 / 3 * 2 - 1; i >= sz1 / 3; --i)
        {
            if (priq2.top() < nums[i])
            {
                sum3 += nums[i] - priq2.top();
                priq2.pop();
                priq2.push(nums[i]);
            }
            ans = min(ans, vi[i] - sum3);
        }

        return ans;
    }

};

int main()
{

    LT2163 lt;

    //myvi v = { 3,1,2 };
    myvi v = { 7,9,5,8,1,3 };


    cout << lt.lt2163a(v) << endl;

    return 0;
}
