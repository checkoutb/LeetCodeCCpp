
#include "../header/myheader.h"

class LT1353
{
public:

    // D D

    //while (pq.size() > 0 || i < n) {
    //    if (pq.size() == 0)
    //        d = A[i][0];
    //    while (i < n && A[i][0] <= d)
    //        pq.push(A[i++][1]);
    //    pq.pop();
    //    ++res, ++d;
    //    while (pq.size() > 0 && pq.top() < d)
    //        pq.pop();
    //}


    //for (int d = 1; d <= 100000; ++d) {
    //    while (pq.size() && pq.top() < d)
    //        pq.pop();
    //    while (i < n && A[i][0] == d)
    //        pq.push(A[i++][1]);
    //    if (pq.size()) {
    //        pq.pop();
    //        ++res;
    //    }
    //}


    // segment tree




    // 主要是 tm， 要排除 那些 还没有开始的任务。 所以要保证 priq中的任务 都是 tm 之后启动的。
//Runtime: 402 ms, faster than 91.38 % of C++ online submissions for Maximum Number of Events That Can Be Attended.
//Memory Usage : 70.9 MB, less than 66.87 % of C++ online submissions for Maximum Number of Events That Can Be Attended.
    int lt1353b(vector<vector<int>>& events)
    {
        sort(begin(events), end(events));
        priority_queue<int, vector<int>, std::greater<int>> priq;
        int tm = events[0][0];
        int ans = 0;

        for (int i = 0; i < events.size(); ++i)
        {
            while (tm < events[i][0] && !priq.empty())
            {
                if (priq.top() >= tm)
                {
                    ++ans;
                    ++tm;
                }
                priq.pop();
            }

            tm = events[i][0];
            priq.push(events[i][1]);

        }
        while (!priq.empty())
        {
            if (priq.top() >= tm)
            {
                ans++;
                ++tm;
            }
            priq.pop();
        }
        return ans;
    }



    // error
    // 应该是优先参加 endDay 近的。
    int lt1353a(vector<vector<int>>& events)
    {
        sort(begin(events), end(events));
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> priq;
        int tm = events[0][0] + 1;          // tm is first free day
        int ans = 1;

#ifdef __test
        for (myvi& vi : events)
        {
            cout << vi[0] << ", " << vi[1] << endl;
        }
#endif

        for (int i = 1; i < events.size(); ++i)
        {
            while (!priq.empty() && priq.top().first < tm)
            {
                priq.pop();
            }
            //tm = max(tm, events[i][0]);
            for (int d = (events[i][0] - tm); d > 0 && !priq.empty(); --d)
            {

#ifdef __test
                cout << priq.top().first << ", " << priq.top().second << " - " << tm + d << endl;
#endif

                if (priq.top().first >= tm)
                {
                    ans++;
                    tm++;
                }
                priq.pop();
            }
            priq.push({ events[i][1], i });
            //tm = events[i][0] + 1;
        }
        while (!priq.empty())
        {
            if (priq.top().first >= tm)
            {
#ifdef __test
                cout << " ---  " << priq.top().first << " , " << priq.top().second << " - " << tm << endl;
#endif
                ans++;
                tm++;
            }
            priq.pop();
        }
        return ans;
    }

};

int main()
{

    LT1353 lt;

    //myvvi vv = { {1,2},{2,3},{3,4} };
    myvvi vv = { {1,2},{2,3},{3,4},{1,2} };

    // 21
    //myvvi vv = { {27,29},{28,32},{3,3},{24,25},{7,7},{22,25},{14,15},{13,17},{1,2},{7,7},{10,12},{9,13},{21,25},{20,21},{20,22},{19,20},{27,28},{9,9},{21,24},{18,21},{6,10},{29,30},{22,24} };


    cout << lt.lt1353b(vv) << endl;

    return 0;
}
