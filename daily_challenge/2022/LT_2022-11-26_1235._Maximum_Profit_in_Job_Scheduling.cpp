
#include "../../header/myheader.h"

class LT
{
public:





    //Runtime287 ms
    //    Beats
    //    64.66 %
    //    Memory46.8 MB
    //    Beats
    //    96.75 %
    // startTime is sorted ?
    int lta(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> priq;
        int ans = 0;

        int sz1 = startTime.size();
        vector<tuple<int, int, int>> vt(sz1 + 1);
        for (int i = 0; i < sz1; ++i)
        {
            vt[i] = std::make_tuple(startTime[i], endTime[i], profit[i]);
        }
        vt[sz1] = make_tuple(INT_MAX, INT_MAX, 0);

        sort(begin(vt), end(vt));

        int st, en, pf;
        int mx = 0;
        for (int i = 0; i <= sz1; ++i)
        {
            std::tie(st, en, pf) = vt[i];

            while ((!priq.empty()) && priq.top().first <= st)
            {
                mx = max(mx, priq.top().second);
                priq.pop();
            }

            priq.push(std::make_pair(en, mx + pf));
        }

        return ans = mx;
    }

};

int main()
{

    LT lt;
    
//    myvvi vv = { {1,2,3,3},{3,4,5,6},{50,10,40,70} };

    //myvvi vv = { {1,2,3,4,6},{3,5,10,6,9},{20,20,100,70,60} };
    myvvi vv = { {1,1,1},{2,3,4},{5,6,4} };

    cout << lt.lta(vv[0], vv[1], vv[2]) << endl;

    return 0;
}
