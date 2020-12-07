
#include "../header/myheader.h"

class LT1584
{
public:

// D D

// Kruskal  Prim
//https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/843940/C%2B%2B-MST%3A-Kruskal-%2B-Prim's-%2B-Complete-Graph


//Prim算法中寻找的是下一个与MST中任意顶点相距最近的顶点；
//Dijkstra算法寻找的是下一个离给定顶点（单源）最近的顶点。
// 2者 松弛的时候不同，其他一样。


// 起初，按 两点间距离 算。。所以 long 保存 x^2 + y^2 ...
//Runtime: 60 ms, faster than 99.62% of C++ online submissions for Min Cost to Connect All Points.
//Memory Usage: 10.6 MB, less than 89.12% of C++ online submissions for Min Cost to Connect All Points.
    int lt1584a(vector<vector<int>>& points)
    {
        int sz1 = points.size();
        vector<long> v(sz1, INT_MAX);            // length
        v[0] = -1;
        int x = points[0][0];
        int y = points[0][1];
        int ans = 0;
        while (true)
        {
            int mn = INT_MAX;
            int mnidx = -1;
            for (int i = 1; i < sz1; ++i)
            {
                if (v[i] == -1)
                    continue;
                v[i] = min((long) (abs(points[i][0] - x) + abs(points[i][1] - y)), v[i]);
                if (v[i] < mn)
                {
                    mn = v[i];
                    mnidx = i;
                }
            }
            if (mnidx == -1)
                break;
            ans += mn;
            x = points[mnidx][0];
            y = points[mnidx][1];
            v[mnidx] = -1;
        }
        return ans;
    }

};

int main()
{

    myvvi vv = {{0,0},{2,2},{3,10},{5,2},{7,0}};

    LT1584 lt;

    cout<<lt.lt1584a(vv)<<endl;

    return 0;
}
