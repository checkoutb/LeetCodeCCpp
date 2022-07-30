
#include "../header/myheader.h"

class LT2045
{
public:

    // D D

    //while (q.size()) {
    //    auto p = q.front(); q.pop();
    //    int node = p[0], t = p[1];
    //    for (int next : adj[node]) {
    //        int t2 = t;
    //        bool isRed = (t2 / change) % 2;
    //        if (isRed) t2 += change - t2 % change;
    //        t2 += time;
    //        if (next == n && firstArrivedTime == INT_MAX) firstArrivedTime = t2;
    //        if (next == n && t2 > firstArrivedTime) return t2;
    //        if (visTime[next] != t2 && visCount[next] <= 1) { //at most revisit one time.
    //            visTime[next] = t2;
    //            visCount[next]++;
    //            q.push({ next, t2 });
    //        }
    //    }
    //}


    //queue<pair<int, int>> pq;
    //pq.emplace(t, v);

    //vector<vector<int>> adj;
    //adj.resize(n + 1);


    // Dijkstra (variant)




//Runtime: 999 ms, faster than 68.07 % of C++ online submissions for Second Minimum Time to Reach Destination.
//Memory Usage : 199 MB, less than 50.66 % of C++ online submissions for Second Minimum Time to Reach Destination.

    //int lt2045b(int n, vector<vector<int>>& edges, int time, int change)
    //{
    //    vector<long long> tmmn(n + 1, -1LL);
    //    vector<long long> tmse(n + 1, -1LL);

    //    unordered_map<int, vector<int>> map2;
    //    for (vector<int>& vi : edges)
    //    {
    //        map2[vi[0]].push_back(vi[1]);
    //        map2[vi[1]].push_back(vi[0]);
    //    }

    //    priority_queue<pair<long long, int>> priq;
    //    priq.push({ 0LL,1 });

    //    while (!priq.empty())
    //    {
    //        pair<long long, int> p = priq.top();
    //        long long sttm = -p.first;
    //        int node = p.second;
    //        priq.pop();

    //        for (int nxt : map2[node])
    //        {
    //            long long t2 = sttm + time;
    //            if (tmmn[nxt] == -1LL)
    //            {
    //                tmmn[nxt] = t2;
    //            }
    //            else
    //            {
    //                if (tmse[nxt] == -1LL)
    //                {
    //                    tmse[nxt] = t2;
    //                }
    //                else
    //                {
    //                    if (tmmn)
    //                }
    //            }
    //        }

    //    }

    //    return tmse[n];
    //}
    



    // ... strictly
    // g。。
    // 溢出了？
    // 每条边耗时 time。
    // 开始时，刚变成绿灯。
    int lt2045a(int n, vector<vector<int>>& edges, int time, int change)
    {
        vector<long long> tmmn(n + 1, -1LL);        // time min
        vector<long long> tmse(n + 1, -1LL);        // time second min

        unordered_map<int, vector<int>> map2;
        for (vector<int>& vi : edges)
        {
            map2[vi[0]].push_back(vi[1]);
            map2[vi[1]].push_back(vi[0]);
        }

        priority_queue<pair<long long, int>> priq;            // start_time, index

        priq.push({ 0, 1 });

        while (!priq.empty())
        {
            pair<long long, int> p = priq.top();
            long long sttm = -p.first;
            int node = p.second;
            priq.pop();

            for (int nxt : map2[node])
            {
                long long t2 = sttm + time;       // arrive time

                if (t2 == tmmn[nxt] || t2 == tmse[nxt])             // ..strictly
                    continue;

                if (tmmn[nxt] == -1LL)
                {
                    tmmn[nxt] = t2;
                }
                else
                {
                    if (tmse[nxt] == -1LL)
                    {
                        tmse[nxt] = t2;
                        if (nxt == n)
                        {

//#ifdef __test
//                            showVectorInt(tmmn);
//                            showVectorInt(tmse);
//#endif

                            return t2;          // .
                        }
                    }
                    else
                    {
                        continue;       // .
                    }
                }

                long long st2 = (t2 / change) % 2 ? ((t2 / change) + 1) * change : t2;           // true:red
                priq.push({ -st2, nxt });
            }
        }
        return -1;
    }

};

int main()
{

    LT2045 lt;

    int n = 2;
    myvvi vv = { {1,2} };
    int tm = 3;
    int chg = 2;

    //int n = 5;
    //myvvi vv = { {1,2},{1,3},{1,4},{3,4},{4,5} };
    //int tm = 3;
    //int chg = 5;

    cout << lt.lt2045a(n, vv, tm, chg) << endl;

    return 0;
}
