
#include "../header/myheader.h"

class LT1402
{
public:

// D D

//        for(int i = 1; i < n; ++i)
//            satisfaction[i] += satisfaction[i-1];
//        for(int i = 1; i < n; ++i)
//            satisfaction[i] += satisfaction[i-1];
//        int answer = 0;
//        for(int i = 0; i < n; ++i)
//            answer= max(answer,satisfaction[i]);
// 0,1,2,3,4
// 0,1,3,6,10
// 0,1,4,10,20
// 。。。 sort是 rbegin，rend，，，反序的。


//        sort(A.begin(), A.end());
//        int res = 0, total = 0, n = A.size();
//        for (int i = n - 1; i >= 0 && A[i] > -total; --i) {
//            total += A[i];
//            res += total;
//        }


//Approach 1: Knapsack 0-1
//This is just something that came to my mind initially. Just follow the DP pattern to pick or skip an item, and maximize the sum. Not very efficient for this problem though.
//int dp[501][501] = {};
//int dfs(vector<int>& sat, int p, int t) {
//    if (p >= sat.size())
//        return 0;
//    if (dp[p][t])
//        return dp[p][t];
//    return dp[p][t] = max(dfs(sat, p + 1, t), sat[p] * t + dfs(sat, p + 1, t + 1));
//}
//int maxSatisfaction(vector<int>& sat) {
//    sort(begin(sat), end(sat));
//    return dfs(sat, 0, 1);
//}

//    sort(begin(sat), end(sat));
//    int run_sum = accumulate(begin(sat), end(sat), 0), total_sum = 0;
//    for (auto i = 0; i < sat.size(); ++i)
//        total_sum += (i + 1) * sat[i];
//    for (auto i = 0; run_sum < 0 && i < sat.size(); ++i) {
//        total_sum -= run_sum;
//        run_sum -= sat[i];
//    }


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reducing Dishes.
//Memory Usage: 8.1 MB, less than 78.07% of C++ online submissions for Reducing Dishes.
// (1*1 + 2*2 + 3*3) -> 0*1 + 1*2 + 2*3 + 3*4  = 0*1 + (1*1 + 2*2 + 3*3) + (1+2+3)
    int lt1402a(vector<int>& satisfaction)
    {
        std::sort(begin(satisfaction), end(satisfaction));
        int ans = 0;
        int idx = satisfaction.size() - 1;
        int t2 = 0;
        int sum2 = 0;
        while (idx >= 0 && t2 >= 0)
        {
            t2 += satisfaction[idx];
            sum2 += t2;
            ans = max(ans, sum2);
            idx--;
        }
        return ans;
    }

};

int main()
{
//    myvi v = {-1,-8,0,5,-9};
//    myvi v = {2,3,4};
//    myvi v = {-1,-4,-5};
//    myvi v = {-2,5,-1,0,3,-3};
    myvi v = {0,1,2,3,4};

    myvi satisfaction = v;
    sort(satisfaction.rbegin(), satisfaction.rend());
    showVectorInt(satisfaction);                // ... 反序。。。
    int n = satisfaction.size();
    for(int i = 1; i < n; ++i)
        satisfaction[i] += satisfaction[i-1];
    showVectorInt(satisfaction);
    for(int i = 1; i < n; ++i)
        satisfaction[i] += satisfaction[i-1];
    showVectorInt(satisfaction);

    LT1402 lt;

    cout<<lt.lt1402a(v)<<endl;

    return 0;
}
