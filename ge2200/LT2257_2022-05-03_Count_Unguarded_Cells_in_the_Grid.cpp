
#include "../header/myheader.h"

class LT2257
{
public:

// D D

//    int not_guarded = m * n - walls.size();
//    vector<vector<int>> g(m, vector<int>(n));
//    for (const auto &wall : walls)
//        g[wall[0]][wall[1]] = 15;
//    for (const auto &gd : guards)
//        for (int d = 0; d < 4; ++d)
//            for (int i = gd[0], j = gd[1]; min(i, j) >= 0 && i < m && j < n && (g[i][j] & (1 << d)) == 0; ) {
//                not_guarded -= g[i][j] == 0;
//                g[i][j] += (1 << d);
//                i += dir[d];
//                j += dir[d + 1];
//            }
//    return not_guarded;






//Runtime: 599 ms, faster than 84.88% of C++ online submissions for Count Unguarded Cells in the Grid.
//Memory Usage: 154 MB, less than 64.52% of C++ online submissions for Count Unguarded Cells in the Grid.
// guard 看到 guard continue， 如果 已经水平被看过，那么本次水平 continue
// guard is wall
// 0 1 水平
// 1 2 垂直
// 2 4 guard  4&2&1
// 3 8 wall   8&2&1
    int lt2257a(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        vector<vector<int>> vvi(m, vector<int>(n, 0));
        for (vector<int>& vi : guards)
            vvi[vi[0]][vi[1]] |= 7;
        for (vector<int>& vi : walls)
            vvi[vi[0]][vi[1]] |= 11;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (vvi[i][j] & (1 << 2))
                {
                    int i2(i + 1), j2(j);
                    while (i2 < m && ((vvi[i2][j2] & 2) == 0))
                    {
                        vvi[i2][j2] |= 2;
                        i2++;
                    }
                    i2 = i - 1;
                    while (i2 >= 0 && ((vvi[i2][j2] & 2) == 0))
                    {
                        vvi[i2][j2] |= 2;
                        i2--;
                    }
                    i2 = i, j2 = j + 1;
                    while (j2 < n && ((vvi[i2][j2] & 1) == 0))
                    {
                        vvi[i2][j2] |= 1;
                        j2++;
                    }
                    j2 = j - 1;
                    while (j2 >= 0 && ((vvi[i2][j2] & 1) == 0))
                    {
                        vvi[i2][j2] |= 1;
                        j2--;
                    }
                }
            }
        }
        #ifdef __test
        for (myvi& v : vvi)
        {
            for (int i : v)
            {
                cout<<i<<", ";
            }
            cout<<endl;
        }
        #endif // __test
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (vvi[i][j] == 0)
                    ans++;
            }
        }
        return ans;
    }

};

int main()
{

    LT2257 lt;

//    int m = 4, n = 6;
//    myvvi v1 = {{0,0},{1,1},{2,3}};
//    myvvi v2 = {{0,1},{2,2},{1,4}};

    int m = 3, n(3);
    myvvi v1{{1,1}};
    myvvi v2{{0,1},{1,0},{2,1},{1,2}};

    cout<<lt.lt2257a(m,n,v1,v2)<<endl;

    return 0;
}
