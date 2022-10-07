
#include "../header/myheader.h"

class LT2398
{
public:


    // D D

    // deque

    // multiset
    // ms.erase(ms.find(times[j]));



//Runtime: 534 ms, faster than 68.76 % of C++ online submissions for Maximum Number of Robots Within Budget.
//Memory Usage : 118.7 MB, less than 69.16 % of C++ online submissions for Maximum Number of Robots Within Budget.
    int lt2398a(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget)
    {
        priority_queue<pair<int, int>> priq;        // <value, index>
        int st = 0;
        int en = 0;
        
        int sz1 = chargeTimes.size();

//        priq.push(std::make_pair(changeTimes[0], 0));
//        int sum2 = runningCosts[0];
        long long sum2 = 0LL;
        int ans = 0;
        for (; en < sz1; ++en)
        {
            priq.push({chargeTimes[en], en});
            sum2 += runningCosts[en];
            while (st <= en)
            {
                while ((!priq.empty()) && (priq.top().second < st))
                {
                    priq.pop();
                }
                long long t2 = priq.top().first + 1LL * (en - st + 1) * sum2;
                if (t2 > budget)
                {
                    sum2 -= runningCosts[st];
                    ++st;
                }
                else
                {
                    ans = max(ans, en - st + 1);
                    break;
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT2398 lt;

    myvi v1 = { 3,6,1,3,4 };
    myvi v2 = { 2,1,3,4,5 };
    int bg = 25;

    cout << lt.lt2398a(v1, v2, bg) << endl;

    return 0;
}
