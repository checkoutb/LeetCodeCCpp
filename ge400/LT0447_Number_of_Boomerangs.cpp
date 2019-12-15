
#include "../header/myheader.h"

class LT0447
{
public:


// discuss
//long long d[n][n];



    // c++ version of discuss, 720ms, 147mb
    int lt0447c(vector<vector<int>>& points)
    {
        int ans = 0;
        int sz1 = points.size();
        map<int, int> map2;
        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz1; j++)
            {
                if (j == i)
                    continue;
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int dist = x*x + y*y;
                map2[dist] = map2[dist] + 1;
            }
            for (auto p : map2)
            {
                ans += (p.second * (p.second - 1));
            }
            map2.clear();
        }
        return ans;
    }

    // after discuss... 1362ms....278mb
    int lt0447b(vector<vector<int>>& points)
    {
        int ans = 0;
        int sz1 = points.size();
        vector<map<int, int>> vmap(sz1);
        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int dist = x*x + y*y;
                vmap[i][dist] = vmap[i][dist] + 1;
                vmap[j][dist] = vmap[j][dist] + 1;
            }
        }
        for (int i = 0; i < sz1; i++)
        {
            map<int, int> map2 = vmap[i];
            for(auto p : map2)
            {
                ans += (p.second * (p.second - 1));
            }
        }
        return ans;
    }

    // 28/31 tle
    int lt0447a(vector<vector<int>>& points)
    {
        int ans = 0;
        int sz1 = points.size();
//        std::sort(points.begin(), points.end(), compa1);
        vector<map<int, set<int>>> vmap(sz1);        // distance^2 : indeies
        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int dist = x*x + y*y;
                vmap[i][dist].insert(j);
                vmap[j][dist].insert(i);
            }
        }
        for (int i = 0; i < sz1; i++)
        {
            map<int, set<int>> map2 = vmap[i];
            for (auto p : map2)
            {
                int sz4 = p.second.size();
                ans += sz4 * (sz4 - 1);          // 10！/(2!*8!) == 10*9/2 .... *2.
            }
        }
        return ans;
    }

    bool static compa1(vector<int>& v1, vector<int>& v2)
    {
        if (v1[0] != v2[0])
        {
            return v1[0] < v2[0];
        }
        else
        {
            return v1[1] < v2[1];
        }
    }
};

int main()
{
    vector<vector<int>> p = {{1,0},{0,0},{2,0}};

    LT0447 lt;
    cout<<"ans : "<<lt.lt0447c(p)<<endl;
    return 0;
}
