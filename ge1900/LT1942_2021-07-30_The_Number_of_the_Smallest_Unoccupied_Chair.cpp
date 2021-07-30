
#include "../header/myheader.h"

class LT1942
{
public:

// D D

//    int t_arrival = times[targetFriend][0];
//    sort(begin(times), end(times));
//    multimap<int, int> reserved;
//    set<int> avail;
//    for (auto &t : times) {
//        while (!reserved.empty() && begin(reserved)->first <= t[0]) {
//            avail.insert(begin(reserved)->second);
//            reserved.erase(begin(reserved));
//        }
//        if (t[0] == t_arrival)
//            break;
//        if (avail.empty())
//            reserved.insert({t[1], reserved.size()});
//        else {
//            reserved.insert({t[1], *begin(avail)});
//            avail.erase(begin(avail));
//        }
//    }
//    return avail.empty() ? reserved.size() : (*begin(avail));
// 如果有一个 来的早，并且位置后，并且 一直不走呢。。。。有avail存在，所以 必然 会走 avail not empty 的。










//Runtime: 196 ms, faster than 92.01% of C++ online submissions for The Number of the Smallest Unoccupied Chair.
//Memory Usage: 51.2 MB, less than 91.99% of C++ online submissions for The Number of the Smallest Unoccupied Chair.
    int lt1942a(vector<vector<int>>& times, int targetFriend)
    {
        priority_queue<int, vector<int>, greater<int>> priq;        // unoccupied chair
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> leaveq;      // leave time, chair
        int nxtChair = 0;   // if priq.empty.  take nxtChair++
        int tm = 1;     // time
        int tarArrive = times[targetFriend][0];
        int ans = -1;
        std::sort(begin(times), end(times));
        int idx = 0;
        while (tm <= tarArrive)
        {
            #ifdef __test
//            cout<<tm<<endl;
            #endif // __test
            if (!leaveq.empty())
            {
                while (!leaveq.empty() && leaveq.top().first <= tm)     // arrive distinct.. leave not distinct..
                {
                    priq.push(leaveq.top().second);
                    leaveq.pop();
                }
            }
            if (times[idx][0] <= tm)        // distinct.
            {
                if (!priq.empty())
                {
                    int seat = priq.top();
                    priq.pop();
                    if (times[idx][0] == tarArrive)
                    {
                        ans = seat;
                        break;
                    }
                    leaveq.push(std::make_pair(times[idx][1], seat));
                }
                else
                {
                    int seat = nxtChair++;
                    if (times[idx][0] == tarArrive)
                    {
                        ans = seat;
                        break;
                    }
                    leaveq.push(make_pair(times[idx][1], seat));
                }
                idx++;
            }
            if (idx < times.size())
                tm = times[idx][0];     // ...上面白判断了。。
        }
        return ans;
    }

};

int main()
{
//    myvvi vv = {{1,4},{2,3},{4,6}};
//    int t = 1;

    myvvi vv = {{3,10},{1,5},{2,6}};
    int t = 0;

    LT1942 lt;

    cout<<lt.lt1942a(vv, t)<<endl;

    return 0;
}
