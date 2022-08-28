
#include "../header/myheader.h"

class LT1499
{
public:

    // D D

    //priority_queue<pair<int, int>> q;
    //for (int i = 0; i < points.size(); i++)
    //{
    //    while ((!q.empty()) && (-q.top().second + points[i][0] > k))q.pop();
    //    if (!q.empty())
    //    {
    //        ans = max(ans, points[i][1] + points[i][0] + q.top().first);
    //    }
    //    q.push({ points[i][1] - points[i][0], points[i][0] });
    //}


    //deque<int> d;
    //for (int j = 0; j < p.size(); ++j) {
    //    while (!d.empty() && p[j][0] - p[d.front()][0] > k)
    //        d.pop_front();
    //    if (!d.empty())
    //        res = max(res, p[d.front()][1] - p[d.front()][0] + p[j][1] + p[j][0]);
    //    while (!d.empty() && p[d.back()][1] - p[d.back()][0] < p[j][1] - p[j][0])
    //        d.pop_back();
    //    d.push_back(j);
    //}


//Runtime: 525 ms, faster than 38.71 % of C++ online submissions for Max Value of Equation.
//Memory Usage : 94.9 MB, less than 20.04 % of C++ online submissions for Max Value of Equation.
//Runtime: 790 ms, faster than 7.64 % of C++ online submissions for Max Value of Equation.
//Memory Usage : 94.9 MB, less than 20.04 % of C++ online submissions for Max Value of Equation.
    // 就是把 绝对值 去掉。 因为 sort && for (int j = i + 1; j < sz1; ++j) 能保证 xj > xi
    // -xi+yi + xj+yj   。。 最开始写反了。。所以。。。下面的 va  vm 反了，  vadd   vminus...
    int lt1499a(vector<vector<int>>& points, int k)
    {
        int sz1 = points.size();
        vector<int> va(sz1);
        vector<int> vm(sz1);

        for (int i = 0; i < sz1; ++i)
        {
            va[i] = points[i][1] - points[i][0];
            vm[i] = points[i][1] + points[i][0];
        }

#ifdef __test
        showVectorInt(va);
        showVectorInt(vm);
#endif

        priority_queue<pair<int, int>> priq;

        int fst = sz1 - 2;
        int ans = INT_MIN;
        for (int i = sz1; --i; )            // no 0
        {
            while (fst >= 0 && points[fst][0] + k >= points[i][0])
            {
                priq.push({ va[fst], points[fst][0]});
                fst--;
            }
            while (!priq.empty() && (priq.top().second >= points[i][0]))
                priq.pop();

#ifdef __test
            cout << i << " -- idx --- " << priq.size() << endl;
#endif

            if (!priq.empty())
            {
                int t2 = priq.top().first + vm[i];

#ifdef __test
                cout << t2 << ", " << priq.top().first << " + " << vm[i] << " --- " << i << endl;
#endif

                ans = max(t2, ans);
            }

            //while (fst >= 0 && (fst + k) > i)
            //{
            //    priq.push(std::make_pair(va[fst], fst));
            //    fst--;
            //}
            //while (priq.top().second >= i)
            //    priq.pop();

            //int t2 = priq.top().first + vm[i];
            //ans = max(t2, ans);
        }
        return ans;
    }

};

int main()
{

    LT1499 lt;

    //myvvi vv = { {1,3},{2,0},{5,10},{6,-10} };
    //int k = 1;

    myvvi vv = { {0,0},{3,0},{9,2} };
    int k = 3;

    cout << lt.lt1499a(vv, k) << endl;

    return 0;
}
