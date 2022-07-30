
#include "../header/myheader.h"

class LT0850
{
public:

    // D D


    //vector<int> x;
    //for (auto r : rectangles) {
    //    x.push_back(r[0]);
    //    x.push_back(r[2]);
    //}
    //sort(x.begin(), x.end());
    //vector<int>::iterator end_unique = unique(x.begin(), x.end());
    //x.erase(end_unique, x.end());


        //Collectand sort all unique xand y coordinates from all rectangles.
        //I use set for that, and then move coordinates to a vector for a random access.

        //Create a square matrix(our canvas); the size of x axis is number of unique x coordinates, y axis - unique y coordinates.
        //The matrix size will not exceed 400 x 400, since the number of rectangles is limited to 200.

        //Go through all rectangles again, translate coordinates into matrix indices, drawand increment the total area.
        //Use binary search to map a coordinate to the matching matrix index.
        //When calculating the area, we need to use the actual size of the covered rectangle.



    // 应该是 set<x,y,bool>  bool: 是不是上边
    // set 没有太大的意义。最终还是用 vector。
//Runtime: 24 ms, faster than 43.42 % of C++ online submissions for Rectangle Area II.
//Memory Usage : 10.7 MB, less than 24.88 % of C++ online submissions for Rectangle Area II.
    int lt0850b(vector<vector<int>>& rectangles)
    {
        sort(begin(rectangles), end(rectangles));
        int sz1 = rectangles.size();
        vector<int> vx;
        for (vector<int>& vi : rectangles)
        {
            vx.push_back(vi[0]);
            vx.push_back(vi[2]);
        }
        //sort(begin(vx), end(vx));
        set<int> set5(begin(vx), end(vx));
        vx = vector<int>(begin(set5), end(set5));

        int idx = 0;
        int ans = 0;
        const int MOD = 1e9 + 7;
        //multiset<int> mset;
        set<pair<int, int>> set2;           // <y, idx>

        for (int i = 0; i < vx.size(); ++i)
        {
            int x = vx[i];
            //if (i == 0)
            //{
            //    while (idx < sz1 && rectangles[idx][0] <= x)
            //    {
            //        //mset.insert(rectangles[idx][1]);
            //        //mset.insert(rectangles[idx][3]);
            //        set2.insert({ rectangles[idx][1], idx });
            //        set2.insert({ rectangles[idx][3], idx });
            //        idx++;
            //    }
            //}
            //else
            {
                while ((!set2.empty()) && (rectangles[set2.begin()->second][2] < x))
                {
                    //rectangles.erase(rectangles.begin());
                    set2.erase(set2.begin());
                }
//#ifdef __test
//                if (!set2.empty())
//                {
//                    cout << set2.rbegin()->second << " -- " << sz1 << " ?? " << endl;
//                    cout << " ?------ " << rectangles.size() << ", " << rectangles[0].size() << endl;
//                    cout << rectangles[1][2] << endl;
//                    int t2 = set2.rbegin()->second;
//                    cout << " ?????? " << rectangles[t2][2] << endl;
//                }
//#endif
                while ((!set2.empty()) && (rectangles[set2.rbegin()->second][2] < x))
                {
                    //rectangles.erase(rectangles.rbegin());
                    //rectangles.erase(prev(rectangles.end()));

                    //set2.erase(set2.rbegin());
                    set2.erase(prev(set2.end()));

//#ifdef __test
//                    if (!set2.empty())
//                    {
//                        cout << set2.rbegin()->second << " -- " << sz1 << endl;
//                    }
//#endif

                }

                if (!set2.empty())
                {
//                    ans = (ans + 1LL * (set2.rbegin()->first - set2.begin()->first) * (x - vx[i - 1])) % MOD;
//
//#ifdef __test
//                    cout << vx[i - 1] << " -> " << x << " * " << set2.rbegin()->first << " - " << set2.begin()->first << endl;
//#endif

                    // y 升序
                    vector<pair<int, int>> vp(begin(set2), end(set2));
                    int st = vp[0].first;
                    int en = rectangles[vp[0].second][3];
                    for (int j = 1; j < vp.size(); ++j)
                    {
                        if (rectangles[vp[j].second][2] < x)                // ..
                            continue;

                        if (vp[j].first <= en)
                        {
                            en = max(en, rectangles[vp[j].second][3]);
                        }
                        else
                        {
                            ans = (ans + 1LL * (en - st) * (x - vx[i - 1])) % MOD;
                            st = vp[j].first;
                            en = rectangles[vp[j].second][3];
#ifdef __test
                            cout << " ======= " << ans << endl;
#endif
                        }
                    }

#ifdef __test
                    cout << st << " -|---- " << en << endl;
#endif

                    ans = (ans + 1LL * (en - st) * (x - vx[i - 1])) % MOD;

#ifdef __test
                    for (pair<int, int>& p : vp)
                    {
                        cout << p.first << " - " << p.second << endl;
                    }

                    cout << ans << endl;
#endif

                }

                while (idx < sz1 && rectangles[idx][0] <= x)
                {
                    set2.insert({ rectangles[idx][1], idx });
                    set2.insert({ rectangles[idx][3], idx });
                    idx++;
                }
            }
        }
        return ans;
    }


    //error
    // 需要最高 和 最低。
    int lt0850a(vector<vector<int>>& rectangles)
    {
        sort(begin(rectangles), end(rectangles));
        priority_queue<pair<int, int>> priq;            // <height, idx>
    //    priority_queue<pair<int, int>>        // 
        vector<int> vx;
        for (vector<int>& vi : rectangles)
        {
            vx.push_back(vi[0]);
            vx.push_back(vi[2]);
        }
        sort(begin(vx), end(vx));

        int idx = 0;
        int sz1 = rectangles.size();
        int ans = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < vx.size(); ++i)
        {
            if (i == 0)
            {
                while (idx < sz1 && rectangles[idx][0] <= vx[i])
                {
                    //priq.push({ rectangles[3] - rectangles[1], idx });
                    idx++;
                }
            }
            else
            {
                while (rectangles[priq.top().second][2] < vx[i])
                    priq.pop();

                pair<int, int> p = priq.top();

            }
        }
        return ans;
    }

};

int main()
{

    LT0850 lt;

    //myvvi vv = { {0,0,2,2},{1,0,2,3},{1,0,3,1} };

    //myvvi vv = { {0,0,1000000000,1000000000} };

    myvvi vv = { {25, 20, 70, 27}, { 68, 80, 79, 100}, { 37, 41, 66, 76} };     // 1550

    //myvvi vv = { {0, 0, 3, 3},{2, 0, 5, 3},{1, 1, 4, 4} };      // 18

    cout << lt.lt0850b(vv) << endl;

    return 0;
}
