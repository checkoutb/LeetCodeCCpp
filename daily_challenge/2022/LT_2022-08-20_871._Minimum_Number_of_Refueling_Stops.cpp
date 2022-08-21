
#include "../../header/myheader.h"

class LT
{
public:

    // D D


    //long dp[501] = { startFuel };
    //for (int i = 0; i < s.size(); ++i)
    //    for (int t = i; t >= 0 && dp[t] >= s[i][0]; --t)
    //        dp[t + 1] = max(dp[t + 1], dp[t] + s[i][1]);
    //for (int t = 0; t <= s.size(); ++t)
    //    if (dp[t] >= target) return t;
    //return -1;


    //int i = 0, res;
    //priority_queue<int>pq;
    //for (res = 0; cur < target; res++) {
    //    while (i < s.size() && s[i][0] <= cur)
    //        pq.push(s[i++][1]);
    //    if (pq.empty()) return -1;
    //    cur += pq.top(), pq.pop();
    //}
    //return res;


//Runtime: 29 ms, faster than 92.38 % of C++ online submissions for Minimum Number of Refueling Stops.
//Memory Usage : 16.2 MB, less than 51.25 % of C++ online submissions for Minimum Number of Refueling Stops.
    int lta(int target, int startFuel, vector<vector<int>>& stations)
    {
        priority_queue<int> priq;
        int ans = 0;
        int arrive = startFuel;
        for (int i = 0; i < stations.size(); ++i)
        {
            //if (arrive >= target)
            //    return ans;

            while (arrive < stations[i][0] && !priq.empty())
            {
                arrive += priq.top();
                ++ans;
                priq.pop();
            }
            if (arrive < stations[i][0])
                return -1;
            priq.push(stations[i][1]);
        }
        while (arrive < target && !priq.empty())
        {
            arrive += priq.top();
            priq.pop();
            ++ans;
        }
        return arrive < target ? -1 : ans;
    }

};

int main()
{

    LT lt;

    //int t = 1, s = 1;
    //myvvi v = {};

    //int t = 100, s = 1;
    //myvvi v = { {10,100} };

    int t = 100, s = 10;
    myvvi v = { {10,60},{20,30},{30,30},{60,40} };

    cout << lt.lta(t, s, v) << endl;

    return 0;
}
