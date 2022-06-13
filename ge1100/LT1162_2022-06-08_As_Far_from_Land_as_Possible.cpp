
#include "../header/myheader.h"

class LT1162
{
public:

    // D D


    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < m; j++) {
    //        if (grid[i][j] == 1) continue;
    //        grid[i][j] = 201; //201 here cuz as the despription, the size won't exceed 100.
    //        if (i > 0) grid[i][j] = Math.min(grid[i][j], grid[i - 1][j] + 1);
    //        if (j > 0) grid[i][j] = Math.min(grid[i][j], grid[i][j - 1] + 1);
    //    }
    //}
    //
    //for (int i = n - 1; i > -1; i--) {
    //    for (int j = m - 1; j > -1; j--) {
    //        if (grid[i][j] == 1) continue;
    //        if (i < n - 1) grid[i][j] = Math.min(grid[i][j], grid[i + 1][j] + 1);
    //        if (j < m - 1) grid[i][j] = Math.min(grid[i][j], grid[i][j + 1] + 1);
    //        res = Math.max(res, grid[i][j]); //update the maximum
    //    }
    //}
    // dp，第一个for-for，是和前面，上面的进行 dp
    //      第二个 是和 后面，下面的进行dp。




//Runtime: 77 ms, faster than 73.74 % of C++ online submissions for As Far from Land as Possible.
//Memory Usage : 19.7 MB, less than 83.44 % of C++ online submissions for As Far from Land as Possible.
    int lt1162b(vector<vector<int>>& grid)
    {
        int sz1 = grid.size(), sz2 = grid[0].size();
        queue<pair<int, int>> que1;
        for (int i = 0; i < sz1; ++i)
            for (int j = 0; j < sz2; ++j)
                if (grid[i][j] == 1)
                    que1.push(std::make_pair(i, j));

        int ans = -1;
        int arr[] = {1,0,-1,0,1};
        int dis = 0;
        while (!que1.empty())
        {
            ans = dis;
            ++dis;
            for (int k = 0, mxk = que1.size(); k < mxk; ++k)
            {
                int x = que1.front().first;
                int y = que1.front().second;
                que1.pop();

                for (int i = 0; i < 4; ++i)
                {
                    int x2(x + arr[i]), y2{ y + arr[i + 1] };
                    if (x2 < 0 || x2 == sz1 || y2 < 0 || y2 == sz2)
                        continue;
                    if (grid[x2][y2] == 0)
                    {
                        grid[x2][y2] = dis;
                        que1.push({ x2, y2 });
                    }
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }



    // queue<array<int, 2>> .. 怎么使用。。。
    //int lt1162a(vector<vector<int>>& grid)
    //{
    //    int sz1 = grid.size();
    //    int sz2 = grid[0].size();
    //    queue<std::array<int, 2>> que1;
    //    for (int i = 0; i < sz1; ++i)
    //    {
    //        for (int j = 0; j < sz2; ++j)
    //        {
    //            if (grid[i][j] == 1)
    //            {
    //                que1.push({ i, j });
    //            }
    //        }
    //    }
    //    int ans = -1;
    //    int arr2[] = { 1,0,-1,0,1 };
    //    int dis = 1;
    //    while (!que1.empty())
    //    {
    //        int arr[] = que1.front();
    //        que1.pop();
    //        int x = arr[0];
    //        int y = arr[1];
    //        ans = dis;
    //        for (int i = 0; i < 4; ++i)
    //        {
    //            int x2 = x + arr2[i];
    //            int y2 = y + arr2[i + 1];
    //            if (grid[x2][y2] < dis)
    //            {
    //                grid[x2][y2] = dis;
    //                que1.push({ x2, y2 });
    //            }
    //        }
    //        ++dis;
    //    }
    //    return ans;
    //}

};

int main()
{

    LT1162 lt;

    //myvvi vv = { {1,0,1},{0,0,0},{1,0,1} };

    myvvi vv = { {1,0,0},{0,0,0},{0,0,0} };

    cout << lt.lt1162b(vv) << endl;

    return 0;
}
