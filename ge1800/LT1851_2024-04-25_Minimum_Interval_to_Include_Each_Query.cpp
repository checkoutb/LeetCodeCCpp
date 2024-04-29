
#include "../header/myheader.h"

class LT1851
{
public:


    // D D

    // set<pair<int, int>> s;  保存 <q,qidx>， sort intervals by size, iterate interals, binary search s to find which q are in this interval, set ans, then erase q from s




// Runtime
// 306ms
// Beats76.99%of users with C++
// Memory
// 113.50MB
// Beats95.70%of users with C++
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries)
    {
        int sz1 = intervals.size();
        int szq = queries.size();

        vector<pair<int, int>> vp(szq);
        for (int i = 0; i < szq; ++i)
        {
            vp[i].first = queries[i];
            vp[i].second = i;
        }
        sort(begin(vp), end(vp));
        sort(begin(intervals), end(intervals));


        // <size, end>
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> priq;
        vector<int> ans(szq, -1);
        int idx = 0;
        int q, qi;
        for (int i = 0; i < szq; ++i)
        {
            q = vp[i].first;
            qi = vp[i].second;

            while (idx < sz1 && intervals[idx][0] <= q)
            {
                if (intervals[idx][1] >= q)
                {
                    priq.push(std::make_pair(intervals[idx][1] - intervals[idx][0] + 1, intervals[idx][1]));
                }
                ++idx;
            }
            while (!priq.empty() && priq.top().second < q)
            {
                priq.pop();
            }
            if (!priq.empty())
            {
                ans[qi] = priq.top().first;
            }
        }
        return ans;
    }
};

int main()
{

    LT1851 lt;


    return 0;
}
