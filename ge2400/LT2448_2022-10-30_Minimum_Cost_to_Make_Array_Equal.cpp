
#include "../header/myheader.h"

class LT2448
{
public:


    // D D

    //long long minCost(vector<int>& A, vector<int>& cost) {
    //    long long l = 1, r = 1000000, res = f(A, cost, 1), x;
    //    while (l < r) {
    //        x = (l + r) / 2;
    //        long long y1 = f(A, cost, x), y2 = f(A, cost, x + 1);
    //        res = min(y1, y2);
    //        if (y1 < y2)
    //            r = x;
    //        else
    //            l = x + 1;
    //    }
    //    return res;
    //}

    //long long f(vector<int>& A, vector<int>& cost, int x) {
    //    long long res = 0;
    //    for (int i = 0; i < A.size(); ++i)
    //        res += 1L * abs(A[i] - x) * cost[i];
    //    return res;
    //}


    //If we sort the array, elements on the left of the pivot will increase, and on the right - decrease.
    //We go left - to - right in the sorted array, and compute cost for each pivot(cost_l[i]).
    //Then we do the same right - to - left, compute cost(cost_r), trackand the minimum total cost(min(cost_l[i], cost_r)).
    // 
    //vector<long long> id(n.size()), cost_l(n.size());
    //iota(begin(id), end(id), 0);
    //sort(begin(id), end(id), [&](int i, int j) {
    //    return n[i] < n[j];
    //    });
    //for (long long i = 0, psum = 0; i < n.size() - 1; ++i) {
    //    psum += cost[id[i]];
    //    cost_l[i + 1] = cost_l[i] + psum * (n[id[i + 1]] - n[id[i]]);
    //}
    //long long res = cost_l.back(), cost_r = 0;
    //for (long long j = n.size() - 1, psum = 0; j > 0; --j) {
    //    psum += cost[id[j]];
    //    cost_r += psum * (n[id[j]] - n[id[j - 1]]);
    //    res = min(res, cost_l[j - 1] + cost_r);
    //}
    //return res;



        //If the cost for all element is the same, then the minimum cost is when all numbers converge at the median.
        //Since the cost is not the same, we need to find a weighted median.
        //To find a weighted median, we sort elements, "repeating" each element based on its weight.
        //For[1, 3, 5, 2], [2, 3, 1, 4] case, the repeated array looks like this (median is in bold) : [1, 1, 2, 2, 2, 2, 3, 3, 3, 5] .
        //We do not need to actually generate that repeated array, we can just simulate it.
        //We find the total weight(10), aggregate the current weight going from one side, and stop when current >= total / 2.


    //long long minCost(vector<int>& n, vector<int>& cost) {
    //    vector<long long> id(n.size());
    //    iota(begin(id), end(id), 0);
    //    sort(begin(id), end(id), [&](int i, int j) { return n[i] < n[j]; });
    //    long long total = accumulate(begin(cost), end(cost), 0LL), j = 0;
    //    for (long long cur = 0; cur + cost[id[j]] < total / 2; ++j)
    //        cur += cost[id[j]];
    //    return accumulate(begin(id), end(id), 0LL, [&](long long sum, int i) {
    //        return sum + (long long)cost[id[i]] * abs(n[id[i]] - n[id[j]]);
    //        });
    //}




//Runtime: 259 ms, faster than 73.47 % of C++ online submissions for Minimum Cost to Make Array Equal.
//Memory Usage : 38.4 MB, less than 86.42 % of C++ online submissions for Minimum Cost to Make Array Equal.
    // total cost 应该是一个 开口向上 的抛物线。
    long long lt2448a(vector<int>& nums, vector<int>& cost)
    {
        int l = 0, r = 1000001;
        long long ans = 1LL << 62;
        int sz1 = nums.size();

        while (l <= r)
        {
            int md = l + (r - l) / 2;
            int md2 = md + 1;

            long long t2 = 0LL;
            long long t3 = 0LL;

            for (int i = 0; i < sz1; ++i)
            {
                t2 += 1LL * abs(md - nums[i]) * (cost[i]);
                t3 += 1LL * abs(md2 - nums[i]) * (cost[i]);
            }
            
#ifdef __test
            cout << ans << " : " << t2 << " - " << t3 << endl;
#endif

            if (t2 <= t3)
            {
                ans = min(ans, t2);
                r = md - 1;
            }
            else
            {
                ans = min(ans, t3);
                l = md + 2;
            }

        }
        return ans;
    }

};

int main()
{

    LT2448 lt;

    myvi v = { 1,3,5,2 };
    myvi v2 = { 2,3,1,14 };

    cout << lt.lt2448a(v, v2) << endl;

    return 0;
}
