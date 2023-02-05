
#include "../header/myheader.h"

class LT2532
{
public:

    // D D



    //Runtime192 ms
    //    Beats
    //    66.16 %
    //    Memory23.4 MB
    //    Beats
    //    47.19 %
    int lt2532a(int n, int k, vector<vector<int>>& time)
    {
        priority_queue<tuple<int, int, int>> pnew, pold;
        int tm = 0;

        vector<int> vi(k);
        std::iota(begin(vi), end(vi), 0);
        std::sort(begin(vi), end(vi), [&](int a, int b) {
            if (time[a][0] + time[a][2] == time[b][0] + time[b][2])
                return a > b;
            else
                return (time[a][0] + time[a][2]) > (time[b][0] + time[b][2]);
            });

        vector<int> v2(k);
        for (int i = 0; i < k; ++i)
        {
            v2[vi[i]] = -i;         // vi[0]最低效，低效先走，最大堆
        }

        for (int i = 0; i < k; ++i)
        {
            pnew.push(std::make_tuple(-tm, v2[i], i));
        }
        int tmnew, tmold;
        priority_queue<pair<int, int>> pwnew, pwold;      // priq wait new/old
        while (n > 0)
        {
            // 要4个 priq. 等待中 最低效的走， 而不是 等待中 最早来的走。
            while (!pold.empty() && (-get<0>(pold.top())) <= tm)
            {
                int idx = get<2>(pold.top());
                pold.pop();
                pwold.push(make_pair(v2[idx], idx));
            }
            // old=right, new=left
            if (!pwold.empty())
            {
                int idx = pwold.top().second;
                pwold.pop();
                tm += time[idx][2];
                pnew.push(make_tuple(-(tm + time[idx][3]), v2[idx], idx));
                continue;
            }

            // left/new -> right/old
            while (!pnew.empty() && (-get<0>(pnew.top())) <= tm)
            {
                int idx = get<2>(pnew.top());
                pnew.pop();
                pwnew.push(make_pair(v2[idx], idx));
            }
            if (!pwnew.empty())
            {
                int idx = pwnew.top().second;
                pwnew.pop();
                tm += time[idx][0];
                --n;
                pold.push(make_tuple(-(tm + time[idx][1]), v2[idx], idx));
                continue;
            }
            else
            {
                int a = pold.empty() ? INT_MAX : -get<0>(pold.top());
                int b = pnew.empty() ? INT_MAX : -get<0>(pnew.top());
                tm = min(a, b);
            }


            //while (!pold.empty() && (-pold.top().get<0>()) <= tm)
            //{
            //    int idx = pold.top().get<2>();
            //    pold.pop();
            //    tm += time[idx][2];
            //    pnew.push(make_tuple(-(tm + time[idx][3]), v2[idx], idx));
            //}
            //if (pnew.empty())
            //{
            //    tm = -pold.top().get<0>();
            //}
            //else
            //{
            //    int idx = pnew.top.get<2>();
            //    pnew.pop();
            //    tm += time[idx][0];
            //    pnew.push(make_tuple(-(tm + time[idx][1]), v2[idx], idx));

            //    --n;
            //}

            // 只要 right/old 有人等，那就 肯定 right/old 优先。
            // 
            //tmnew = pnew.empty() ? INT_MAX : -pnew.top().get<0>;
            //tmold = pold.empty() ? INT_MAX : -pold.top().get<0>;
            //if (tmnew < tmold)     // left is new
            //{

            //}
            //else
            //{
            //    
            //}
        }

        while (!pold.empty() || !pwold.empty())
        {
            while (!pold.empty() && (-get<0>(pold.top())) <= tm)
            {
                int idx = std::get<2>(pold.top());
                pold.pop();
                pwold.push(make_pair(v2[idx], idx));
            }
            // old=right, new=left
            if (!pwold.empty())
            {
                int idx = pwold.top().second;
                pwold.pop();
                tm += time[idx][2];
                //pnew.push(make_tuple(-(tm + time[idx][3]), v2[idx], idx));
                continue;
            }
            else
            {
                tm = -get<0>(pold.top());
            }
        }
        return tm;
    }

};

int main()
{

    LT2532 lt;

    //int n{ 1 }, k{ 3 };
    //myvvi vv = { {1,1,2,1},{1,1,3,1},{1,1,4,1} };

    int n{ 3 }, k{ 2 };
    myvvi vv = { {1,9,1,8},{10,10,10,10} };

    cout << lt.lt2532a(n, k, vv) << endl;

    return 0;
}
