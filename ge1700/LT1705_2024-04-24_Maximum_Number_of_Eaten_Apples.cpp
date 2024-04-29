
#include "../header/myheader.h"

class LT1705
{
public:

    // D D


        // for(int day=0; day<n || !avail.empty(); day++){
        //     while(!avail.empty() && (avail.begin()->first <= day || avail.begin()->second==0)) avail.erase(avail.begin());
        //     if(day<n && apples[day]) avail[day+days[day]]+=apples[day];
        //     if(!avail.empty()){
        //         avail.begin()->second--;
        //         ans++;
        //     }
        // }



        // while (i < n || !pq.empty()){
        //     if (i < n && apples[i] > 0)
        //         pq.push({i + days[i] - 1, apples[i]});
        //     while (!pq.empty() && pq.top().first < i)
        //         pq.pop();
        //     if (!pq.empty()){
        //         auto cur = pq.top();
        //         pq.pop();
        //         ans++;
        //         if (cur.second > 1)
        //             pq.push({cur.first, cur.second - 1});
        //     }
        //     i++;
        // }




    // hint: priq...
    // 看了hint后，返回去看 priq 的实现了。 代码错误导致的 死循环。。



    // error 70/73
    // <-
    int eatenApples(vector<int>& apples, vector<int>& days)
    {
        int sz1 = apples.size();
        int lst = INT_MAX;
        vector<pair<int, int>> vp;
        // for (int i = sz1 - 1; i >= 0; --i)
        // {
        //     vp.push_back(std::make_pair());
        // }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (apples[i] == 0)
                continue;
            vp.push_back(std::make_pair(i + days[i] - 1, i));   // enddate, startdate/index
        }
        sort(begin(vp), end(vp));
        for (int i = vp.size() - 1; i >= 0; --i)
        {
            lst = std::min(lst, vp[i].first);
            int t2 = lst - vp[i].second + 1;    // days
            if (t2 <= 0)
                continue;
            if (t2 >= apples[vp[i].second])
            {
                lst -= apples[vp[i].second];
                ans += apples[vp[i].second];
            }
            else
            {
                // apple > day(t2)
                ans += t2;
                lst = vp[i].second - 1;
            }
        }
        return ans;
    }



// Runtime
// 63ms
// Beats100.00%of users with C++
// Memory
// 50.83MB
// Beats44.14%of users with C++

    // tle
    // priq?
    int eatenApples___eee(vector<int>& apples, vector<int>& days)
    {
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> priq;
        int sz1 = apples.size();

        int ans = 0;
        pair<int, int> p {-1,-1};
        for (int i = 0; i < sz1; ++i)
        {
            // if (apples[i] == 0)
            //     continue;

            if (apples[i] != 0)
                priq.push(std::make_pair(i + days[i] - 1, apples[i]));

            while (p.second == 0 || p.first < i)            // while.. not if
            {
                if (!priq.empty())
                {
                    p = priq.top();
                    priq.pop();
                }
                else
                {
                    break;      // ..
                }
            }
            if (p.first >= i && p.second > 0)
            {
                if (!priq.empty() && p.first > priq.top().first)
                {
                    priq.push(p);
                    p = priq.top();
                    priq.pop();
                }
                p.second--;
                ans++;
            }
            else
            {
#ifdef __test
                cout<<"? "<<i<<", "<<p.first<<", "<<endl;
                if (!priq.empty())
                {
                    cout<<priq.top().first<<", -- "<<priq.top().second<<endl;
                }
                else
                {
                    cout<<"priq empty\n";
                }
#endif
            }
        }
        int day = sz1;
        if (p.second > 0 && p.first >= day)
            priq.push(p);

#ifdef __test
        cout<<ans<<", "<<day<<endl;
#endif

        while (!priq.empty())
        {
            while (!priq.empty() && priq.top().first < day)             // no !priq.empty()  will endless loop.
            {
                priq.pop();
            }
            if (priq.empty())
                break;

            p = priq.top();
            priq.pop();

            // cout<<p.first<<", "<<p.second<<endl;

            int endday = p.first;
            int cnt = p.second;
            if (day + cnt <= endday)
            {
                ans += cnt;
                day += cnt;
            }
            else
            {
                ans += endday - day + 1;
                day = endday + 1;
            }
        }
        return ans;

        // priority_queue<>

//         map<int, int> map2; // last day can eat, count // day from 0
//         int sz1 = apples.size();
//         for (int i = 0; i < sz1; ++i)
//         {
//             if (apples[i] == 0)
//                 continue;
//             map2[i + days[i] - 1] += apples[i];
//         }
//
//         // priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> priq;
//         // for (pair<int, int> p : map2)
//         // {
//         //     priq.push
//         // }
//
//         int ans = 0;
//         int day = 0;
//         for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
//         {
//
//         }

    }
};

int main()
{

    LT1705 lt;

    // myvi v = {3,0,0,0,0,2};
    // myvi v2 = {3,0,0,0,0,2};

    // myvi v = {1,2,3,5,2};
    // myvi v2 = {3,2,1,4,2};

    myvi v = {0,37,0,59,11,63,4,0,0,26,12,66,34,32,33,33,21,18,0,0,6,66,32,48,0,0,45,20,59,57,34,0,17,0,0,46,11,32,22,58,13,47,54,67,34,32,41,61,52,40,54,0,0,19,0,0,17,12,11,52,20,58,42,62,26,50,66,0,62,0,6,50,63,17,41,59,37,43,0,16,56,37,36,5,23,10,57,18,32,64,0,0,18,0,18,60,41,0,61,41,0,30,25,0,0,63,26,0,0,22,65,30,51,35,0,0,52,40,52,41,5,10,26,41,6,0,37,45,0,22,54,26,59,24};
    myvi v2 = {0,66,0,22,13,92,7,0,0,15,8,62,37,41,14,45,24,6,0,0,1,132,35,56,0,0,51,28,30,70,17,0,31,0,0,10,16,39,22,38,13,43,46,122,25,12,3,77,5,48,32,0,0,21,0,0,11,10,14,11,7,93,33,39,35,78,26,0,61,0,6,100,78,29,50,30,68,14,0,29,7,4,59,2,45,11,86,17,29,46,0,0,25,0,19,51,68,0,110,12,0,24,50,0,0,66,2,0,0,37,42,59,38,44,0,0,47,39,35,82,10,1,33,23,11,0,52,81,0,39,8,20,23,18};

    std::cout<<lt.eatenApples___eee(v, v2)<<endl;

    return 0;
}
