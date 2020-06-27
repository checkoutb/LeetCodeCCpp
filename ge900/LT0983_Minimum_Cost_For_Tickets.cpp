
#include "../header/myheader.h"

class LT0983
{
public:


// D D

//        const int n = days.back();
//        vector<int> dp(n + 1, INT_MAX);
//        dp[0] = 0;
//
//        for (int d : days) dp[d] = 0;
//
//        for (int i = 1; i <= n; ++i){
//            if (dp[i] == INT_MAX){
//                dp[i] = dp[i - 1];
//            }
//            else{
//                int curr = dp[i - 1] + costs[0];
//                curr = min(curr, dp[max(0, i - 7)] + costs[1]);
//                curr = min(curr, dp[max(0, i - 30)] + costs[2]);
//                dp[i] = curr;
//            }
//        }
//        return dp.back();


//        set<int> s(days.begin(), days.end());
//
//        vector<int> dp(366, 0);
//
//        for(int i = 1; i <=365; i++) {
//            if(s.count(i)) {
//                dp[i] = min( min ( dp[i-1] + costs[0], i-7>=0 ? dp[i-7] + costs[1]: costs[1]),
//                            i-30>=0 ? dp[i-30] + costs[2]:costs[2]);
//            } else {
//               dp[i] = dp[i-1];
//            }
//        }
//
//        return dp[365];

//        map<int, int> dp = {{-30,0}};
//        auto cost = [&](int day){return prev(dp.upper_bound(day))->second;};
//        for(int d:days) dp[d] = min({costs[0] + cost(d-1), costs[1] + cost(d-7), costs[2] + cost(d-30)});
//		// if you want O(N) solution, simply add one line in loop:  if(dp.size() > 31) dp.erase(dp.begin());
//        return dp[days.back()];



//        boolean[] dayIncluded = new boolean[366];
//        for (int day : days) {
//            dayIncluded[day] = true;
//        }
//        int[] minCost = new int[366];
//        minCost[0] = 0;
//        for (int day = 1; day <= 365; ++day) {
//            if (!dayIncluded[day]) {
//                minCost[day] = minCost[day-1];
//                continue;
//            }
//            int min;
//            min = minCost[day-1] + costs[0];
//            min =Math.min(min, minCost[Math.max(0, day-7)] + costs[1]);
//            min = Math.min(min, minCost[Math.max(0, day-30)] + costs[2]);
//            minCost[day] = min;
//        }
//
//        return minCost[365];





// dp还是好难啊。
//Runtime: 4 ms, faster than 89.43% of C++ online submissions for Minimum Cost For Tickets.
//Memory Usage: 9.5 MB, less than 66.51% of C++ online submissions for Minimum Cost For Tickets.
    int lt0983b(vector<int>& days, vector<int>& costs)
    {
        vector<int> vsum(days.size(), 0);
        int c1 = min(costs[0], min(costs[1], costs[2]));
        int c7 = min(costs[1], costs[2]);
        int c30 = costs[2];

        for (int i = 0; i < days.size(); i++)
        {
            vsum[i] = (i > 0 ? vsum[i - 1] : 0) + c1;
            bool u7 = true;
            bool u30 = true;
            int t2 = days[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (u7 && days[j] <= t2 - 7)
                {
                    u7 = false;
                    int m7 = vsum[j] + c7;
                    for (int k = j + 1; k <= i; k++)
                    {
                        vsum[k] = min(vsum[k], m7);
                    }
                }
                if (u30 && days[j] <= t2 - 30)
                {
                    u30 = false;
                    int m30 = vsum[j] + c30;
                    for (int k = j + 1; k <= i; k++)
                    {
                        vsum[k] = min(vsum[k], m30);
                    }

                    break;
                }
            }
            if (u7)
            {
                for (int k = 0; k <= i; k++)
                {
                    vsum[k] = min(vsum[k], c7);
                }

            }
            if (u30)
            {
                for (int k = 0; k <= i; k++)
                {
                    vsum[k] = min(vsum[k], c30);
                }
            }
        }
        return vsum[days.size() - 1];
    }


// error
    int lt0983a(vector<int>& days, vector<int>& costs)
    {
        vector<int> vsum(days.size(), 0);
        int c1 = costs[0];
        int c7 = costs[1];
        int c30 = costs[2];

        for (int i = 0; i < days.size(); i++)
        {
            int mcst = 0;
            int t2 = days[i];
            if (i > 0)
            {
                mcst = vsum[i - 1];
            }
            mcst += c1;

            int m7 = INT_MAX;
            int m30 = INT_MAX;
            for (int j = i - 1; j >= 0; j--)
            {
                if (days[j] >= t2 - 7)      // 应该用 <t2-7 的数。
                {
                    m7 = min(m7, vsum[j] + c7);
                }
                if (days[j] >= t2 - 30)
                {
                    m30 = min(m30, vsum[j] + c30);            // use map
                }
                else
                {
                    break;
                }
            }
            mcst = std::min(mcst, std::min(m7, m30));
            vsum[i] = mcst;

            #ifdef __test
            cout<<i<<", "<<days[i]<<" : "<<mcst<<", "<<m7<<", "<<m30<<endl;
            #endif // __test
        }
        return vsum[days.size() - 1];
    }

};

int main()
{

//    vector<int> d = {1,4,6,7,8,20};
//    vector<int> c = {2,7,15};         // 11

//    vector<int> d = {1,2,3,4,5,6,7,8,9,10,30,31};
//    vector<int> c = {2,7,15};     // 17

// 6
    vector<int> d = {1,4,6,7,8,20};
    vector<int> c = {7,2,15};

    LT0983 lt;

    cout<<lt.lt0983b(d, c)<<endl;

    return 0;
}
