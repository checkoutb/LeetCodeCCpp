
#include "../header/myheader.h"

class LT0546
{
public:


    // D

    // for for for for ...

// public int removeBoxes(int[] boxes) {
//     int n = boxes.length;
//     int[][][] dp = new int[n][n][n];
//     return removeBoxesSub(boxes, 0, n - 1, 0, dp);
// }
//
// private int removeBoxesSub(int[] boxes, int i, int j, int k, int[][][] dp) {
//     if (i > j) return 0;
//     if (dp[i][j][k] > 0) return dp[i][j][k];
//
//     int i0 = i, k0 = k; // Need to record the intial values of i and k in order to apply the following optimization
//     for (; i + 1 <= j && boxes[i + 1] == boxes[i]; i++, k++); // optimization: all boxes of the same color counted continuously from the first box should be grouped together

//     int res = (k + 1) * (k + 1) + removeBoxesSub(boxes, i + 1, j, 0, dp);
//
//     for (int m = i + 1; m <= j; m++) {
//         if (boxes[i] == boxes[m]) {
//             res = Math.max(res, removeBoxesSub(boxes, i + 1, m - 1, 0, dp) + removeBoxesSub(boxes, m, j, k + 1, dp));
//         }
//     }
//
//     dp[i0][j][k0] = res; // When updating the dp matrix, we should use the initial values of i, j and k
//     return res;
// }



    // g

    // 1,1,2,1,2
    // sz1 -> x1 + x2 + x3 +...
    // x1*x1 + x2*x2 + x3*x3 +...
    // 7, 1112222  2221112 2212121  2121212  贪心可能吗？
    // n <= 100 for for for ?
    int removeBoxes(vector<int>& boxes)
    {
        int sz1 = boxes.size();
        std::vector<std::vector<int>> vvi(sz1, std::vector<int>(sz1, 0));
        for (int i = 0; i < sz1; ++i)
            vvi[i][i] = 1;

        for (int len = 1; len < sz1; ++len)
        {
            for (int i = 0; i + len < sz1; ++i)
            {
                int j = i + len;
                int cnt = 0;
                vvi[i][j] = vvi[i][j - 1] + 1;
                int t2 = boxes[j];
                int pre = 0;
                int st = i;
                for (int k = i; k < j; ++k)       // [i, j] = max([i,k] + [k, j) + x*x)  x = cnt [j]==[k]  no
                {
                    if (boxes[k] == t2)
                    {
                        if (k > 0)
                            pre += vvi[st][k - 1];
                        ++cnt;
                        st = k + 1;
                    }

                    // if (boxes[k] == t2)
                    // {
                    //     ++cnt;
                    // }
                    // else
                    // {
                    //     cnt = 0;
                    //     pre = vvi[i][k];
                    // }
                    // vvi[i][j] = max(vvi[i][j], pre + (cnt + 1) * (cnt + 1) + vvi[k + 1][j - 1]);
                }
                pre += vvi[st][j - 1];
                ++cnt;
                vvi[i][j] = max(vvi[i][j], pre + cnt * cnt);

            }
        }
#ifdef __test
        for (auto& vi : vvi)
        {
            showVectorInt(vi);
        }
#endif
        return vvi[0][sz1 - 1];
    }
};

int main()
{

    LT0546 lt;

    // myvi v {1,3,2,2,2,3,4,3,1};
    // myvi v {3,2,3,3};
    // myvi v {6,10,1,7,1,3,10,2,1,3}; // 16   (3*3) + 7
    myvi v {1,2,2,1,1,1,2,1,1,2,1,2,1,1,2,2,1,1,2,2,1,1,1,2,2,2,2,1,2,1,1,2,2,1,2,1,2,2,2,2,2,1,2,1,2,2,1,1,1,2,2,1,2,1,2,2,1,2,1,1,1,2,2,2,2,2,1,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,1,1,1,1,2,2,1,1,1,1,1,1,1,2,1,2,2,1};   // 2758

    std::cout<<lt.removeBoxes(v)<<std::endl;

    return 0;
}
