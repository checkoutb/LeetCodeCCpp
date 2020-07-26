
#include "../header/myheader.h"

class LT0885
{
public:


// D D
//    def spiralMatrixIII(self, R, C, r, c):
//        def key((x, y)):
//            x, y = x - r, y - c
//            return (max(abs(x), abs(y)), -((math.atan2(-1, 1) - math.atan2(x, y)) % (math.pi * 2)))
//        return sorted([(i, j) for i in xrange(R) for j in xrange(C)], key=key)


//        int[][] dirt = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // east, south, west, north
//        List<int[]> res = new ArrayList<>();
//        int len = 0, d = 0; // move <len> steps in the <d> direction
//        res.add(new int[]{r0, c0});
//        while (res.size() < R * C) {
//            if (d == 0 || d == 2) len++; // when move east or west, the length of path need plus 1
//            for (int i = 0; i < len; i++) {
//                r0 += dirt[d][0];
//                c0 += dirt[d][1];
//                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) // check valid
//                    res.add(new int[]{r0, c0});
//            }
//            d = (d + 1) % 4; // turn to next direction
//        }
//        return res.toArray(new int[R * C][2]);



//    int idx;
//    int[][] ret;
//
//    private void add (int r, int c, int R, int C) {
//        if (r >= R || r < 0 || c >= C || c < 0) return;
//        ret[idx][0] = r;
//        ret[idx++][1] = c;
//    }
//
//    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
//        int r = r0, c = c0, len = 1;
//        ret = new int[R * C][2];
//        while (idx < (R * C )) {
//            for (int k = 0; k < len; k++) add(r, c++, R, C);
//            for (int k = 0; k < len; k++) add(r++, c, R, C);
//            len++;
//            for (int k = 0; k < len; k++) add(r, c--, R, C);
//            for (int k = 0; k < len; k++) add(r--, c, R, C);
//            len++;
//        }
//        return ret;
//    }


// 去掉inline 后28 ms，不过不一定准确。
//Runtime: 24 ms, faster than 85.94% of C++ online submissions for Spiral Matrix III.
//Memory Usage: 12.4 MB, less than 36.67% of C++ online submissions for Spiral Matrix III.
// 1 1 2 2 3 3 4 4 5 5 6
    vector<vector<int>> lt0885b(int R, int C, int r0, int c0)
    {
        int x = r0;
        int y = c0;
        int len1 = 0;
        vector<vector<int>> ans;
        int arr[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int i2 = 0;
        int len2 = 0;
        ans.emplace_back(vector<int>({x, y}));

        while (ans.size() < R * C)
        {
            int i3 = (i2 + 1) % 4;
            if (len1 == len2)
            {
                len1++;
            }
            else
            {
                len2 = len1;
            }
            for (int i = 0; i < len1; i++)
            {
                x += arr[i2][0];
                y += arr[i2][1];
                if (isValid(R, C, x, y))
                {
                    ans.emplace_back(vector<int>({x, y}));
                }
            }
            i2 = (i2 + 1) % 4;
        }

        return ans;
    }


//    vector<vector<int>> lt0885a(int R, int C, int r0, int c0)
//    {
//        int x = r0;
//        int y = c0;
//        vector<vector<int>> ans;
//        int arr[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
//        int i2 = 0;
//        ans.emplace_back(vector<int>({x, y}));
//        while (ans.size() < R * C)
//        {
//            int i3 = (i2 + 1) % 4;
//            if (isValid(R, C, x+(arr[i3][0]), y+(arr[i3][1])))      // isValid need int&, x+arr[][] is temp.
//            {
//                x += arr[i2][0];
//                y += arr[i2][1];
//                ans.emplace_back({x, y});
//            }
//            else
//            {
//
//            }
//        }
//
//        return ans;
//    }

    inline bool isValid(int& R, int& C, int& r, int& c)
    {
        if (r < 0 || c < 0 || r >= R || c >= C)
            return false;
        return true;
    }
};

int main()
{

//    int r = 1, c = 4, r1 = 0, c1 = 0;
    int r = 5, c = 6, r1 = 1, c1 = 4;

    LT0885 lt;

    vector<vector<int>> vv = lt.lt0885b(r, c, r1, c1);

    for_each(begin(vv), end(vv), [](vector<int>& v){ for_each(begin(v), end(v), fun_cout); cout<<endl;});

    return 0;
}
