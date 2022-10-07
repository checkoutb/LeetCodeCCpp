
#include "../header/myheader.h"

class LT2402
{
public:

    // D D

    //int cnt[101] = {};
    //sort(begin(meets), end(meets));
    //priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    //for (int i = 0; i < n; ++i)
    //    pq.push({ meets[0][0], i });                      // 。。。。
    //for (auto& m : meets) {
    //    while (pq.top().first < m[0]) {
    //        pq.push({ m[0], pq.top().second });
    //        pq.pop();
    //    }
    //    auto [start, room] = pq.top(); pq.pop();
    //    pq.push({ start + m[1] - m[0], room });
    //    ++cnt[room];
    //}
    //return max_element(begin(cnt), end(cnt)) - begin(cnt);
    // 把 0 - n 房间全部入队了，利用priq，来获得 最早 值最小 的 room。



//Runtime: 1157 ms, faster than 34.93 % of C++ online submissions for Meeting Rooms III.
//Memory Usage : 96.8 MB, less than 51.93 % of C++ online submissions for Meeting Rooms III.
    int lt2402a(int n, vector<vector<int>>& meetings)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> priq1;       // end, room
        priority_queue<int, vector<int>, std::greater<int>> priq2;      // room
        //queue<pair<int, int>> que;      // delayed meeting  <duration>
        //queue<int> que;

        sort(begin(meetings), end(meetings));

        for (int i = 0; i < n; ++i)
        {
            priq2.push(i);
        }

        vector<int> vi(n);

        int sz1 = meetings.size();
        int idx = 0;
        while (idx < sz1)
        {
            int st = meetings[idx][0];
            int en = meetings[idx][1];

            while ((!priq1.empty()) && priq1.top().first <= st)
            {
                priq2.push(priq1.top().second);
                priq1.pop();
            }

            if (priq2.empty())
            {
                //int t2 = priq2.top().first;
                //while ((!priq1.empty()) && priq1.top().first <= t2)
                //{
                //    priq2.push(priq1.top().second);
                //    priq1.pop();
                //}

                long long t2 = priq1.top().first;
                int rom = priq1.top().second;
                
                priq1.pop();

                priq1.push(make_pair(t2 + en - st, rom));
                vi[rom]++;
            }
            else
            {
                priq1.push(make_pair(en, priq2.top()));
                vi[priq2.top()]++;
                priq2.pop();
            }
            ++idx;
        }

        int mx = 0;
        int ans = -1;
        for (int i = 0; i < n; ++i)
        {
            if (vi[i] > mx)
            {
                mx = vi[i];
                ans = i;
            }
        }
        return ans;
    }

};

int main()
{

    LT2402 lt;

    //int n = 2;
    //myvvi vv = { {0,10},{1,5},{2,7},{3,4} };

    int n = 3;
    myvvi vv = { {1,20},{2,10},{3,5},{4,9},{6,8} };

    cout << lt.lt2402a(n, vv) << endl;

    return 0;
}
