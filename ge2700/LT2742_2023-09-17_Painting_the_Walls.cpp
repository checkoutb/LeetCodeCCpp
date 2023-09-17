
#include "../header/myheader.h"

class LT2742
{
public:

// D

//        int n = cost.size();
//        vector<int> dp(n + 1, 1e9);
//        dp[0] = 0;
//        for (int i = 0; i < n; ++i)
//            for (int j = n; j > 0; --j)
//                dp[j] = min(dp[j], dp[max(j - time[i] - 1, 0)] + cost[i]);
//        return dp[n];
//
// 没有用到 size / 2
// 而且，总感觉不对，主要是 没有用到 个数。 感觉不对。比如， cost 500个1， time 1个499，其他全1
// 这样的话，应该是 1块钱画499天，  其他499个任务 全是 free 的干。
// 这个对的， 关键是 j-time[i]-1 的 -1。

//With cost cost[i],
//we buy time[i],
//and we can additionally finish time[i] walls,
//so actually can finish time[i] + 1 walls.
//
//So cost[i] to finish time[i] + 1 walls,






// g
// 还要一层： 个数。
// 看 hint， 不需要。

// 不还是需要的，： [1,1,1,1...] [1,1,1,1..., 500]
// 上面的情况下， 1块钱，让人画500天的，  其他的499个任务让free的做


    // > sz1 / 2      > 250
    //
    int paintWalls(vector<int>& cost, vector<int>& time)
    {
        int sz1 = cost.size();
        int t2 = (sz1 + 1) / 2;
//        int t2 = sz1;
        vector<int> vi(t2 + 1, INT_MAX);
        int t3 = INT_MAX;

        for (int i = 0; i < sz1; ++i)
        {

//            for (int j = 0; j < vi.size(); ++j)
            for (int j = vi.size() - 1; j >= 0; --j)
            {
                if (vi[j] != INT_MAX)
                {
                    if (j + time[i] < vi.size())
                    {
                        vi[j + time[i]] = min(vi[j + time[i]], vi[j] + cost[i]);
                    }
                    else
                    {
                        t3 = min(t3, vi[j] + cost[i]);
                    }
                }
            }
            if (time[i] < vi.size())
                vi[time[i]] = min(cost[i], vi[time[i]]);
            else
                t3 = min(t3, cost[i]);
        }
//        return t3;
//        cout<<t3<<endl;
        return min(vi.back(), t3);
    }

};

int main()
{

    LT2742 lt;

//    myvi v = {1,2,3,2};
//    myvi v2 = {1,2,3,2};

    myvi v = {2,3,4,2};
    myvi v2 = {1,1,1,1};

    cout<<lt.paintWalls(v, v2)<<endl;

    return 0;
}
