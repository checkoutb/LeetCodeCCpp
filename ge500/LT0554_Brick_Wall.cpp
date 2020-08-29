
#include "../header/myheader.h"

class LT0554
{
public:

// D D

// 最后一块砖头 不累加，就不需要 p.first == sum.

//    unordered_map<int, int> edges;
//    auto min_bricks = wall.size();
//    for (auto row : wall)
//        for (auto i = 0, width = 0; i < row.size() - 1; ++i) // skip last brick
//            min_bricks = min(min_bricks, wall.size() - (++edges[width += row[i]]));
//    return min_bricks;



//Runtime: 96 ms, faster than 82.99% of C++ online submissions for Brick Wall.
//Memory Usage: 22.2 MB, less than 35.47% of C++ online submissions for Brick Wall.
// 每行前N个的*和*， *和*最多次发生的地方 砖头劈的越少。
    int lt0554a(vector<vector<int>>& wall)
    {
        unordered_map<int, int> map2;
        int sum = 0;
        for (vector<int>& v : wall)
        {
            sum = 0;
            for (int t : v)
            {
                sum += t;
                map2[sum]++;
            }
        }
        int ans = 0;
        for (auto& p : map2)
        {
            #ifdef __test
            cout<<p.first<<" : "<<p.second<<endl;
            #endif // __test
            if (p.first == sum)
                continue;
            if (p.second > ans)
                ans = p.second;
        }
        return wall.size() - ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{1,2,2,1},
//        {3,1,2},
//        {1,3,2},
//        {2,4},
//        {3,1,2},
//        {1,3,1,1}};

    vector<vector<int>> vv = {{1},{1},{1}};         // int ans = -1; ...

    LT0554 lt;

    cout<<lt.lt0554a(vv)<<endl;

    return 0;
}
