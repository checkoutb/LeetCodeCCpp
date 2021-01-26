
#include "../header/myheader.h"

class LT1696
{
public:

// D

//    vector<int> dp(nums.size(), INT_MIN);
//    dp[0] = nums[0];
//    for (auto i = 0; i < nums.size(); ++i)
//        for (auto j = 1; j <= k && i + j < nums.size(); ++j) {
//            dp[i + j] = max(dp[i + j], dp[i] + nums[i + j]);
//            if (nums[i + j] >= 0)
//                break;
//        }
//    return dp.back();
// tle


//DP + Monodeq
//    deque<int> d{0};
//    for (int i = 1; i < nums.size(); ++i) {
//        if (d.front() + k < i)
//            d.pop_front();
//        nums[i] += nums[d.front()];
//        while (!d.empty() && nums[d.back()] <= nums[i])
//            d.pop_back();
//        d.push_back(i);
//    }
//    return nums.back();
//For each step, the best value is the number at that step, plus the max value among the previous k steps.

// so some discuss's title contains "sliding window"



// 总不可能再加一个：如果后续K个值相等，就 正数拿第一个，非正数拿最远的。
// tle。  比上一个快，但是 还是 tle。 [1, -1*n , 1] + k{70000}
// 找到后续第一个正数， 如果后续k个全是负数：最大 还是 最后
// 1 -1 -2 -3 10        k=2
// 要看下一个 正数，。。 感觉是  找到下一个正数，然后 反推k个，直到 当前， 但是 反推k个里  都是负数，应该 最远 还是 最大。。。
// 难道局部dp？   现在 到 下一个正数， 这段距离dp
    int lt1696b(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int ans = nums[0];
        for (int i = 0; i < sz1;)
        {
//            cout<<i<<endl;
            int j = i + 1;
            bool flg = true;
            for (; j < sz1 && j <= (i + k); ++j)
            {
                if (nums[j] >= 0)
                {
                    ans += nums[j];
                    i = j;
                    flg = false;
//                    goto AAA;
                }
            }

            if (flg)
            {

                for (; j < sz1 && nums[j] < 0; ++j)
                    ;
    //            {
    //                if (nums[j] >)
    //            }
                if (j < sz1)
                    ++j;

//                    cout<<j<<", "<<i<<endl;
                vector<int> vi(j - i, INT_MIN);
                vi[0] = 0;
                for (int m = i; m < j; ++m)
                {
//                    cout<<" . . "<<m<<endl;
                    for (int n = m + 1; n <= m + k && n < j; ++n)
                    {
                        vi[n - i] = max(vi[n - i], vi[m - i] + nums[n]);
//                        cout<<(n - i)<<endl;
                    }
                }

                #ifdef __test
//                showVectorInt(vi);
                #endif // __test

                ans += vi[j - i - 1];
                i = j;
            }

//            AAA:
//            continue;
        }
        return ans;
    }



// tle....
    int lt1696a(vector<int>& nums, int k)
    {
        vector<int> vi(nums.size(), INT_MIN);
        vi[0] = nums[0];
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j <= i + k && j < nums.size(); ++j)
            {
                vi[j] = max(vi[j], vi[i] + nums[j]);
            }
        }
        return vi[nums.size() - 1];
    }

};

int main()
{
    myvi v = {1,-1,-2,4,-7,3};
    int k{2};

//    myvi v = {10,-5,-2,4,0,3};
//    int k{3};

//    myvi v = {1,-5,-20,4,-1,3,-6,-3};
//    int k{2};

    LT1696 lt;

    cout<<lt.lt1696b(v, k);

    return 0;
}
