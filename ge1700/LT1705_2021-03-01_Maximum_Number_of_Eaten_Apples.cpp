
#include "../header/myheader.h"

class LT1705
{
public:

// D

//PriorityQueue<int[]> queue = new PriorityQueue<>((a,b) -> a[1] - b[1]); //[]{apple count, expiry date}



// error, 中间会跳过的
    int lt1705b(vector<int>& apples, vector<int>& days)
    {
        map<int, int> map2;     // last day can eat : number of apples
        for (int i = 0; i < apples.size(); ++i)
        {
            if (apples[i] != 0)
            {
                map2[i + days[i] - 1] += apples[i];
            }
        }
        int ans = 0;
        int d2 = -1;
        for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            int day = it->first;
            int cnt = it->second;
            ans += min(day - d2, cnt);
            d2 = day;
            #ifdef __test
            cout<<ans<<", "<<d2<<", "<<day<<", "<<cnt<<endl;
            #endif // __test
        }
        return ans;
    }

//You need a structure to keep the apples sorted by their finish time


// tle.
// 肯定吃最容易烂的啊。pri_queue
// 好像数据量太大了。。预订tle。
// pri_que<pair<int, int>> ?
    int lt1705a(vector<int>& apples, vector<int>& days)
    {
        priority_queue<int, vector<int>, std::greater<int>> priq;
        int ans = 0;
        int d1 = 0;
        for (; d1 < days.size(); ++d1)
            if (days[d1] != 0)
                break;
        for (int i = 0; i < apples.size(); ++i)
        {
            while (!priq.empty() && priq.top() < i)
            {
                priq.pop();
            }
            if (apples[i] != 0)
            {
                int t2 = i + days[i] - 1;
                for (int j = 0; j < apples[i]; ++j)
                    priq.push(t2);
            }
            if (!priq.empty())
            {
                ans++;
                priq.pop();
            }
        }
        d1 = apples.size();
        while (!priq.empty())
        {
            while (!priq.empty() && priq.top() < d1)
            {
                priq.pop();
            }
            if (!priq.empty())
            {
                ans++;
                priq.pop();
            }
            d1++;
        }
        return ans;
    }

};

int main()
{
    myvi v1 = {1,2,3,5,2};
    myvi v2 = {3,2,1,4,2};

//    myvi v1 = {3,0,0,0,0,2};
//    myvi v2 = {3,0,0,0,0,2};

    LT1705 lt;

    cout<<lt.lt1705b(v1, v2)<<endl;

//    priority_queue<int> q;
//    priority_queue<int, vector<int>, std::greater<int>> q;
//    q.push(1);
//    q.push(12);
//    q.push(441);
//
//    cout<<q.top()<<endl;

    return 0;
}
