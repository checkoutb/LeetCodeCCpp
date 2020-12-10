
#include "../header/myheader.h"

class LT1631
{
public:

// D

//    auto comp = [&](const array<int, 3> &p1, const array<int, 3> &p2) { return p1[0] >= p2[0]; };
//    priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)> pq(comp);
// 每次选 和 已走过的路 中的点 effort最小的。


//// 按列dp .. 能往左，上 走。。
//    int lt1631b(vector<vector<int>>& heights)
//    {
//        vector<int> vi(heights.size());
//        for (int j = 0; j < heights[0].size(); ++j)
//        {
//            for (int i = 0; i < heights.size(); ++i)
//            {
//                vi[i] = max()
//            }
//        }
//    }


// 15 / 75 tle...
    int lt1631a(vector<vector<int>>& heights)
    {
        dfsa1(heights, 0, 0, 0, heights[0][0]);
        return ans;
    }
    int ans = INT_MAX;
    void dfsa1(vector<vector<int>>& vv, int effort, int i, int j, int lst)
    {
        if (i < 0 || j < 0 || i >= vv.size() || j >= vv[0].size() || vv[i][j] < 0)
            return;
        if (effort >= ans)
            return;
        int diff = abs(lst - vv[i][j]);
        diff = max(effort, diff);
        if (i == (vv.size() - 1) && j == (vv[0].size() - 1))
        {
            ans = min(ans, diff);
            return;
        }
        int val = vv[i][j];
        vv[i][j] = -val;
        dfsa1(vv, diff, i + 1, j, val);
        dfsa1(vv, diff, i - 1, j, val);
        dfsa1(vv, diff, i, j + 1, val);
        dfsa1(vv, diff, i, j - 1, val);
        vv[i][j] = val;
    }

};

int main()
{
    myvvi vv = {{1,2,2},{3,8,2},{5,3,5}};

    LT1631 lt;

    cout<<lt.lt1631a(vv);

    return 0;
}
