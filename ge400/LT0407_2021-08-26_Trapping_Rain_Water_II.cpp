
#include "../header/myheader.h"

class LT0407
{
public:

// D D

// 优先队列， 先计算 height低的 点。

// 先把边 全部加到 priq。
// 使用visited， 每个点只访问一次。
// 循环 priq。




//Runtime: 1224 ms, faster than 5.11% of C++ online submissions for Trapping Rain Water II.
//Memory Usage: 16.9 MB, less than 42.76% of C++ online submissions for Trapping Rain Water II.
// 水只可能从边上漏掉。 是不是 对每个边上的点， 扩展出来？
    int lt0407a(vector<vector<int>>& heightMap)
    {
        int sz1 = heightMap.size();
        int sz2 = heightMap[0].size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));
        int ans = 0;
        queue<pair<int, int>> que1;
        for (int i = 0; i < sz1; ++i)
        {
            dfsa1(heightMap, vvi, i, 0, 0);
            dfsa1(heightMap, vvi, i, sz2 - 1, 0);
        }
        for (int j = 1; j < sz2 - 1; ++j)
        {
            dfsa1(heightMap, vvi, 0, j, 0);
            dfsa1(heightMap, vvi, sz1 - 1, j, 0);
        }
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                ans += vvi[i][j] - heightMap[i][j];
            }
        }
        return ans;
    }

    int arr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfsa1(vector<vector<int>>& height, vector<vector<int>>& vvi, int a, int b, int h)
    {
        if (a < 0 || b < 0 || a >= vvi.size() || b >= vvi[0].size())
            return;
        if (h >= vvi[a][b])     // h 是 前一个点的   水平面。
            return;

        int t2 = vvi[a][b];     // 当前水平面， 必然高于h
        int t3 = height[a][b];

        if (t3 >= h)
        {
            vvi[a][b] = t3;
        }
        else
        {
            vvi[a][b] = h;
        }
        t2 = vvi[a][b];
        for (int i = 0; i < 4; ++i)
            dfsa1(height, vvi, a + arr[i][0], b + arr[i][1], t2);
    }

};

int main()
{
//    myvvi vv = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};           // 4
    myvvi vv = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};

    LT0407 lt;

    cout<<lt.lt0407a(vv)<<endl;

    return 0;
}
