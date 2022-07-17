
#include "../header/myheader.h"

class LT0815
{
public:

    // D D

    //unordered_map<int, vector<int>> to_routes;
    //for (int i = 0; i < routes.size(); ++i)
    //    for (int j : routes[i])
    //        to_routes[j].push_back(i);
    //queue<pair<int, int>> bfs;
    //bfs.push({ source, 0 });
    //unordered_set<int> seen = { source };
    //while (!bfs.empty()) {
    //    int stop = bfs.front().first, bus = bfs.front().second;
    //    bfs.pop();
    //    if (stop == target)
    //        return bus;
    //    for (int i : to_routes[stop]) {
    //        for (int j : routes[i]) {
    //            if (seen.find(j) == seen.end()) {
    //                seen.insert(j);
    //                bfs.push({ j, bus + 1 });
    //            }
    //        }
    //        routes[i].clear();
    //    }
    //}
    //return -1;



//Runtime: 247 ms, faster than 86.67 % of C++ online submissions for Bus Routes.
//Memory Usage : 63.9 MB, less than 58.82 % of C++ online submissions for Bus Routes.
    // 如何快速找到 这个车站 的所有bus呢？ 感觉这个内存有点大。。
    int lt0815a(vector<vector<int>>& routes, int source, int target)
    {
        unordered_set<int> vst;
        queue<int> que1;
        que1.push(source);
        vst.insert(source);

        unordered_set<int> rvst;
        
        unordered_map<int, vector<int>> map2;
        for (int i = 0; i < routes.size(); ++i)
        {
            for (int n : routes[i])
            {
                map2[n].push_back(i);
            }
        }
        int ans = 0;
        while (!que1.empty())
        {
            for (int m = que1.size(); m > 0; --m)
            {
                int t2 = que1.front();
                que1.pop();
                if (t2 == target)
                    return ans;
                for (int route : map2[t2])
                {
                    if (rvst.find(route) == rvst.end())
                    {
                        rvst.insert(route);

                        for (int r : routes[route])
                        {
                            if (vst.find(r) == vst.end())
                            {
                                que1.push(r);
                                vst.insert(r);
                            }
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }

};

int main()
{

    LT0815 lt;

    myvvi vv = { {1,2,7},{3,6,7} };
    int s = 1, t = 6;

    cout << lt.lt0815a(vv, s, t) << endl;

    return 0;
}
