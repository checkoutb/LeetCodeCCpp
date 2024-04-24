
#include "../header/myheader.h"

class LT2662
{
public:










// Runtime
// 29ms
// Beats91.47%of users with C++
// Memory
// 77.13MB
// Beats87.68%of users with C++


    // A -> B |xdiff| + |ydiff|
    // road cost ,  one time is enough?
    // 200 road
    // 要么直接 start - target
    // 要么 走某条路 然后 去 target
    // 所以 到达这条路的 入口的 最小时间。  出这条路的 最小时间
    //  priq  dijkstra ?
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads)
    {
        // <min time out, road's idx>
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> priq;
        int sz1 = specialRoads.size();
        vector<int> vi(sz1, INT_MAX);       // min time from start to out this road
        int outtm = 0;
        for (int i = 0; i < sz1; ++i)
        {
            outtm = distancea1(start, specialRoads[i]) + specialRoads[i][4];
            priq.push(std::make_pair(outtm, i));
            vi[i] = outtm;
        }

        while (!priq.empty())
        {
            pair<int, int> p = priq.top();
            priq.pop();
            if (p.first > vi[p.second])
                continue;

            // == vi[x]

            for (int i = 0; i < sz1; ++i)
            {
                if (p.first >= vi[i])
                    continue;
                outtm = p.first + endtostart(specialRoads[p.second], specialRoads[i]) + specialRoads[i][4];
                if (outtm < vi[i])
                {
                    priq.push(std::make_pair(outtm, i));
                    vi[i] = outtm;
                }
            }
        }
        int ans = distancea1(start, target);
        for (int i = 0; i < sz1; ++i)
        {
            ans = min(ans, endtostart(specialRoads[i], target) + vi[i]);
        }

        return ans;
    }

    int endtostart(const vector<int>& v1, const vector<int>& v2)
    {
        return abs(v1[2] - v2[0]) + abs(v1[3] - v2[1]);
    }

    int distancea1(const vector<int>& v1, const vector<int>& v2)
    {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }
};

int main()
{

    LT2662 lt;

    myvi st = {1,1};
    myvi en = {4,5};
    myvvi vv = {{1,2,3,3,2},{3,4,4,5,1}};

    cout<<lt.minimumCost(st, en, vv);

    return 0;
}
