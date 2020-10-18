
#include "../header/myheader.h"

class LT1030
{
public:

// D D

//        int[] counter = new int[R + C + 1];
//        for (int r = 0; r < R; r++) {
//            for (int c = 0; c < C; c++) {
//                int dist = Math.abs(r - r0) + Math.abs(c - c0);
//                counter[dist + 1] += 1;
//            }
//        }
//
//        for (int i = 1; i < counter.length; i++) {
//            counter[i] += counter[i - 1];
//        }
//
//        int[][] ans = new int[R * C][];
//        for (int r = 0; r < R; r++) {
//            for (int c = 0; c < C; c++) {
//                int dist = Math.abs(r - r0) + Math.abs(c - c0);
//                ans[counter[dist]] = new int[] { r, c };
//                counter[dist]++;
//            }
//        }
// 最远可能距离R+C(,实际上应该是R+C-1-1)，所以桶排序，记录下每种长度 的 point数量。
// [i] += [i-1]， 就知道 下标距离的点 在结果中的最后一个位置。   这个距离的点 放入结果中，这个距离的point数量就--， 结果中的位置就--。
// 这里是 dist + 1， 这样 第二个循环后， 距离i的点 就从 counter[i] 这个下标开始，所以第三个循环中 要++；
// 如果使用 dist，那么第二个循环后， counter[i] 是 距离i的最后一个点的下一个位置。 就是 下一个距离的开始位置。 这行2种解释，2种写法。


//  vector<vector<int>> res = { { r0, c0 } };
//  auto max_d = max({ r0 + c0, c0 + R - r0, r0 + C - c0, R - r0 + C - c0 });
//  for (auto d = 1; d <= max_d; ++d)
//    for (int x = d; x >= -d; --x) {
//      auto r1 = r0 + x, c1_a = c0 + d - abs(x), c1_b = c0 + abs(x) - d;
//      if (r1 >= 0 && r1 < R) {
//        if (c1_a >= 0 && c1_a < C)
//            res.push_back({ r1, c1_a });
//        if (c1_a != c1_b && c1_b >= 0 && c1_b < C)
//            res.push_back({ r1, c1_b });
//      }
//    }
//  return res;
// max_d .... 什么写法。。


//        map<int, vector<vector<int>>> dis;
//        for (int i = 0; i < R; ++i) {
//            for (int j = 0; j < C; ++j) {
//                int distance = abs(i - r0) + abs(j - c0);
//
//                dis[distance].push_back({i, j});
//            }
//        }


//    boolean[][] visited = new boolean[R][C];
//    int[][] result = new int[R * C][2];
//    int i = 0;
//    Queue<int[]> queue = new LinkedList<int[]>();
//    queue.offer(new int[]{r0, c0});
//    while (!queue.isEmpty()) {
// 每次移动一格。


// x,y 和 坐标系 意义相反。。。
//Runtime: 32 ms, faster than 100.00% of C++ online submissions for Matrix Cells in Distance Order.
//Memory Usage: 14.2 MB, less than 7.11% of C++ online submissions for Matrix Cells in Distance Order.
// 旋转45度 的正方形
    vector<vector<int>> lt1030a(int R, int C, int r0, int c0)
    {
        vector<vector<int>> ans(R * C, vector<int>(2, 0));
        int cnt = 1;
        ans[0][0] = r0;
        ans[0][1] = c0;
        int len = 1;
        int x,y,y2;
        while (cnt < R * C)
        {
            x = r0 + len;
            y = c0;
            y2 = c0;
            if (x >= 0 && y >= 0 && x < R && y < C)
            {
                if (cnt >= R * C)
                    goto AAA;
                ans[cnt][0] = x;
                ans[cnt][1] = y;
                cnt++;
            }
            for (int i = x - 1; i >= r0; i--)
            {
                x--;
                y++;
                y2--;
                if (x >= 0 && y >= 0 && x < R && y < C)
                {
                    if (cnt >= R * C)
                        goto AAA;
                    ans[cnt][0] = x;
                    ans[cnt][1] = y;
                    cnt++;
                }
                if (x >= 0 && y2 >= 0 && x < R && y2 < C)
                {
                    if (cnt >= R * C)
                        goto AAA;
                    ans[cnt][0] = x;
                    ans[cnt][1] = y2;
                    cnt++;
                }
            }
            for (int i = r0 - 1; i > r0 - len; i--)
            {
                x--;
                y--;
                y2++;
                if (x >= 0 && y >= 0 && x < R && y < C)
                {
                    if (cnt >= R * C)
                        goto AAA;
                    ans[cnt][0] = x;
                    ans[cnt][1] = y;
                    cnt++;
                }
                if (x >= 0 && y2 >= 0 && x < R && y2 < C)
                {
                    if (cnt >= R * C)
                        goto AAA;
                    ans[cnt][0] = x;
                    ans[cnt][1] = y2;
                    cnt++;
                }
            }
            x--;
            y--;
            if (x >= 0 && y >= 0 && x < R && y < C)
            {
                if (cnt >= R * C)
                    goto AAA;
                ans[cnt][0] = x;
                ans[cnt++][1] = y;
            }
            len++;
        }
        AAA:
        return ans;
    }

};

int main()
{

    int R = 2, C = 2, r0 = 0, c0 = 1;
//    int R = 2, C = 3, r0 = 1, c0 = 2;

    LT1030 lt;

    vector<vector<int>> vv = lt.lt1030a(R,C,r0,c0);

    for (int i = 0; i < vv.size(); i++)
    {
        cout<<vv[i][0]<<" : "<<vv[i][1]<<endl;
    }

    return 0;
}
