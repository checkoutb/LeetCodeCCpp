
#include "../header/myheader.h"

class LT2017
{
public:


// D D

// long top = Arrays.stream(g[0]).asLongStream().sum()

// long long top = accumulate(begin(g[0]), end(g[0]), 0ll)
// LLONG_MAX

//    for(int i = 0; i < g[0].size(); ++i) {
//        top -= g[0][i];
//        res = min(res, max(top, bottom));
//        bottom += g[1][i];
//    }


//Runtime: 231 ms, faster than 40.91% of C++ online submissions for Grid Game.
//Memory Usage: 75.1 MB, less than 5.45% of C++ online submissions for Grid Game.
// 2台机器人，都只能 往右 或往下。 都从0,0 到 1,n-1
// 第一台走过的 路径 被设置为 0
// 求第二台路径和。
// 第一台想让第二台最小，第二台想最大。
//
// 感觉2台 都是 找最大路径。 不
// 1 2 3 4 5
// 6 4 3 2 1
// 最大路径 是 1 6 4 3 2 1， 第二台可以 2 3 4 5
// 但如果第一台 1 2 3 3 2 1  第二台就 6 4
// 主要在于 右上 那块 不会被走。
//
// ok，  第一台走了以后，把 数组分成了2部分， 右上 和左下。  第二台 要么右上，要么左下。
// 所以要找到 一个划分，使得 max(右上，左下) 最小。
    long long lt2017a(vector<vector<int>>& grid)
    {
        int sz1 = grid[0].size();
        if (sz1 == 1)
            return 0LL;

        vector<vector<long long>> arr(2, vector<long long>(sz1, 0LL));
        arr[0][sz1 - 1] = grid[0][sz1 - 1];
        arr[1][0] = grid[1][0];
        for (int i = 1; i < sz1 - 1; i++)
        {
            arr[0][sz1 - 1 - i] = arr[0][sz1 - i] + grid[0][sz1 - 1 - i];
            arr[1][i] = grid[1][i] + arr[1][i - 1];
        }

        long long ans = arr[0][1] < arr[1][sz1 - 2] ? arr[0][1] : arr[1][sz1 - 2];
        for (int i = 1; i < sz1 - 1; i++)
        {
            long long t2 = arr[1][i - 1] > arr[0][i + 1] ? arr[1][i - 1] : arr[0][i + 1];
            if (t2 < ans)
                ans = t2;
        }
        return ans;
    }

};

int main()
{

    LT2017 lt;


    return 0;
}
