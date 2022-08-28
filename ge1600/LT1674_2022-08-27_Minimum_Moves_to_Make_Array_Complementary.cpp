
#include "../header/myheader.h"

class LT1674
{
public:

    // D D

    //int N = nums.size();
    //vector<int> memo(limit * 2 + 2, 0);
    //for (int i = 0; i < N / 2; ++i) {
    //    int l = nums[i], r = nums[N - 1 - i];
    //    --memo[min(l, r) + 1];
    //    --memo[l + r];
    //    ++memo[l + r + 1];
    //    ++memo[max(l, r) + limit + 1];
    //}
    //int ans = N, curr = N;
    //for (int i = 2; i <= limit * 2; ++i) {
    //    curr += memo[i];
    //    ans = min(ans, curr);
    //}
    //return ans;






//Runtime: 1046 ms, faster than 13.25 % of C++ online submissions for Minimum Moves to Make Array Complementary.
//Memory Usage : 140.4 MB, less than 21.69 % of C++ online submissions for Minimum Moves to Make Array Complementary.
//Runtime: 787 ms, faster than 14.46 % of C++ online submissions for Minimum Moves to Make Array Complementary.
//Memory Usage : 140.4 MB, less than 21.69 % of C++ online submissions for Minimum Moves to Make Array Complementary.
    // hint1,2,3
    // 2个数字 a,b (a<=b)， 组成 a+b 不需要修改，  组成 [a+1, a+b) U (a+b, b+limit] 只需要修改一个。
    // [0,a+1) U (b+limit, limit*2] 需要修改2个。
    // +2 +1 0 -1 -2 这种。
    // 0 ： +2
    // a+1: -1
    // a+b: -1
    // a+b+1: + 1
    // b+limit+1: + 1
    // 稀疏，稠密
    // [2, limit*2]  0 不可能 不过 无所谓的。
    int lt1674b(vector<int>& nums, int limit)
    {
        map<int, int> map2;
        int sz1 = nums.size();
        int ans = INT_MAX;
        int a, b;
        for (int i = 0; i < sz1 / 2; ++i)
        {
            a = nums[i];
            b = nums[sz1 - 1 - i];
            if (a > b)
                swap(a, b);

            map2[0] += 2;
            map2[a + 1] -= 1;
            map2[a + b] -= 1;
            map2[a + b + 1] += 1;
            map2[b + limit + 1] += 1;

        }

        int cnt = 0;
        for (auto& p : map2)
        {
            cnt += p.second;
            ans = min(ans, cnt);
        }

        return ans;
    }



    // tle。。
    int lt1674a(vector<int>& nums, int limit)
    {
        int sz1 = nums.size();
        unordered_map<int, int> map2;
        int ans = sz1 / 2;                  // nums[i] <= limit .. limit*2
        for (int i = 0; i < sz1 / 2; ++i)
        {
            map2[nums[i] + nums[sz1 - 1 - i]]++;
            if (nums[i] > nums[sz1 - 1 - i])
                swap(nums[i], nums[sz1 - 1 - i]);
            if (nums[i] == limit)
                ans++;
        }
        if (map2.size() == 1)
            return 0;
        for (auto& p : map2)
        {
            //if (p.first > limit * 2)              // nums[i] <= limit
            //    continue;

            int cnt = 0;
            for (int i = 0; i < sz1 / 2; ++i)
            {
                int t2 = nums[i] + nums[sz1 - 1 - i];
                if (t2 > p.first)
                {
                    cnt += 1 + ((nums[i] + 1) > p.first);
                }
                else if (t2 < p.first)
                {
                    cnt += 1 + ((nums[sz1 - 1 - i] + limit) < p.first);
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }

};

int main()
{

    LT1674 lt;

    myvi v = { 1,2,4,3 };
    int k = 4;

    //myvi v = { 1,2,2,1 };
    //int k = 2;

    //myvi v = { 1,2,1,2 };
    //int k = 2;

    //myvi v = { 11,22,44,1111 };
    //int k = 2;

    // 36465 11100 35938 12449
    //myvi v = { 20744, 7642, 19090, 9992, 2457, 16848, 3458, 15721 };
    //int k = 22891;          // 4


    cout << lt.lt1674b(v, k) << endl;

    return 0;
}
