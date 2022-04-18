
#include "../header/myheader.h"

class LT2245
{
public:

// D D


//array<int, 2> operator+(const array<int, 2> &l, const array<int, 2> &r) { return { l[0] + r[0], l[1] + r[1] }; }
//array<int, 2> operator-(const array<int, 2> &l, const array<int, 2> &r) { return { l[0] - r[0], l[1] - r[1] }; }
//int pairs(const array<int, 2> &p) { return min(p[0], p[1]); }
//
//class Solution {
//public:
//int factors(int i, int f) {
//    return i % f ? 0 : 1 + factors(i / f, f);
//}
//int maxTrailingZeros(vector<vector<int>>& grid) {
//    int m = grid.size(), n = grid[0].size(), res = 0;
//    vector<vector<array<int, 2>>> h(m, vector<array<int, 2>>(n + 1)), v(m + 1, vector<array<int, 2>>(n));
//    for (int i = 0; i < m; ++i)
//        for (int j = 0; j < n; ++j) {
//            array<int, 2> f25 = { factors(grid[i][j], 2), factors(grid[i][j], 5) };
//            v[i + 1][j] = v[i][j] + f25;
//            h[i][j + 1] = h[i][j] + f25;
//        }
//    for (int i = 0; i < m; ++i)
//        for (int j = 0; j < n; ++j) {
//            auto v1 = v[i + 1][j], v2 = v[m][j] - v[i][j];
//            auto h1 = h[i][j], h2 = h[i][n] - h[i][j + 1];
//            res = max({res, pairs(v1 + h1), pairs(v1 + h2), pairs(v2 + h1), pairs(v2 + h2)});
//        }
//    return res;
//}
//};





//Runtime: 1211 ms, faster than 33.33% of C++ online submissions for Maximum Trailing Zeros in a Cornered Path.
//Memory Usage: 289 MB, less than 33.33% of C++ online submissions for Maximum Trailing Zeros in a Cornered Path.
// L 型
// 那就是 一个点，{上,下} * {左,右}
// 怎么压缩。  需要记录 2,5,10 的个数。  10可以不记录，10=2*5 .. 还是记录 ... 不记录。。
// 还好没有0。。
    int lt2245a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<vector<vector<int>>> vvv1(sz1, vector<vector<int>>(sz2, vector<int>(2, 0)));         // row
        vector<vector<vector<int>>> vvv2(sz1, vector<vector<int>>(sz2, vector<int>(2, 0)));         // col
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                int t2 = grid[i][j];
                int cnt2 = 0;
                int cnt5 = 0;
                while (t2 > 0 && (t2 % 2 == 0))
                {
                    cnt2++;
                    t2 /= 2;
                }
                while (t2 > 0 && (t2 % 5 == 0))
                {
                    cnt5++;
                    t2 /= 5;
                }
                vvv1[i][j][0] = cnt2 + (j == 0 ? 0 : vvv1[i][j - 1][0]);
                vvv1[i][j][1] = cnt5 + (j == 0 ? 0 : vvv1[i][j - 1][1]);

                vvv2[i][j][0] = cnt2 + (i == 0 ? 0 : vvv2[i - 1][j][0]);
                vvv2[i][j][1] = cnt5 + (i == 0 ? 0 : vvv2[i - 1][j][1]);
            }
        }

        #ifdef __test
        for (myvvi& vv : vvv1)
        {
            for (myvi& v : vv)
            {
                cout<<"{"<<v[0]<<","<<v[1]<<"}, ";
            }
            cout<<endl;
        }
        cout<<endl;
        for (myvvi& vv : vvv2)
        {
            for (myvi& v : vv)
            {
                cout<<"{"<<v[0]<<","<<v[1]<<"}, ";
            }
            cout<<endl;
        }
        #endif // __test

        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                int tl[2] = {0};            // <= [j]
                int tr[2] = {0};            // >= [j]
                int tu[2] = {0};            // < [i]
                int td[2] = {0};            // > [i]

                vector<int> vi = vvv1[i][j];            // ... & 只能初始化一次， 后继续的  = 是赋值，不是重新初始化。
                tl[0] = vi[0];
                tl[1] = vi[1];

//                if (j != 0)
//                {
//                    vi = vvv1[i][j - 1];
//                    tr[0] = vvv1[i][sz2 - 1][0] - vi[0];
//                    tr[1] = vvv1[i][sz2 - 1][1] - vi[1];
//                }

                tr[0] = vvv1[i][sz2 - 1][0] - (j == 0 ? 0 : vvv1[i][j - 1][0]);
                tr[1] = vvv1[i][sz2 - 1][1] - (j == 0 ? 0 : vvv1[i][j - 1][1]);

                if (i > 0)
                {
                    vi = vvv2[i - 1][j];
                    tu[0] = vi[0];
                    tu[1] = vi[1];
                }
                td[0] = vvv2[sz1 - 1][j][0] - vvv2[i][j][0];
                td[1] = vvv2[sz1 - 1][j][1] - vvv2[i][j][1];

                int t2 = min(tl[0] + tu[0], tl[1] + tu[1]);
                if (t2 > ans)
                    ans = t2;

                t2 = min(tl[0] + td[0], tl[1] + td[1]);
                if (t2 > ans)
                    ans = t2;

                t2 = min(tr[0] + tu[0], tr[1] + tu[1]);
                if (t2 > ans)
                    ans = t2;

                t2 = min(tr[0] + td[0], tr[1] + td[1]);
                #ifdef __test
//                cout<<t2<<" - "<<tr[0]<<"+"<<td[0]<<", "<<tr[1]<<"+"<<td[1]<<endl;
                if ((i == 3) && (j == 2))
                {
                    cout<<tl[0]<<", "<<tl[1]<<endl;
                    cout<<tr[0]<<", "<<tr[1]<<endl;
                    cout<<tu[0]<<", "<<tu[1]<<endl;
                    cout<<td[0]<<", "<<td[1]<<endl;
                    cout<<" --- "<<vvv1[i][sz2 - 1][0]<<", "<<vvv1[i][j - 1][0]<<endl;
                    for (myvvi& vv : vvv1)
                    {
                        for (myvi& v : vv)
                        {
                            cout<<"{"<<v[0]<<","<<v[1]<<"}, ";
                        }
                        cout<<endl;
                    }
                    cout<<endl;
                }
                #endif // __test

                if (t2 > ans)
                    ans = t2;

                #ifdef __test
                cout<<i<<", "<<j<<", "<<ans<<endl;
                #endif // __test

//                vector<int>& vi = vvv1[i][j];
//                int tl = min(vi[0], vi[1]);             // tl, tr contain [i][j]
//
//                int tr = 0;
//                if (j != 0)
//                {
//                    vi = vvv1[i][j - 1];
//                    tr = min(vvv1[i][sz2 - 1][0] - vi[0], vvv1[i][sz2 - 1][1] - vi[1]);
//                }
//
//                int tu = 0;
//                if (i > 0)
//                {
//                    vi = vvv2[i - 1][j];
//                    tu = min(vi[0], vi[1]);
//                }
//
////                int td = 0;
////                if (i < sz1 - 1)
////                {
////                    vi = vvv2[i][j];
////                    td = min(vvv2[sz1 - 1][])
////                }
//                int td = min(vvv2[sz1 - 1][j][0] - vvv2[i][j][0], vvv2[sz1 - 1][j][1] - vvv2[i][j][1]);
//
//                tl = max(tl, tr);
//                tu = max(tu, td);
//                int t2 = (tl == 0 ? 1 :)
            }
        }
        return ans;
    }

};

int main()
{

    LT2245 lt;

//    myvvi vv = {{23,17,15,3,20},
//                {8,1,20,27,11},
//                {9,4,6,2,21},
//                {40,9,1,10,6},
//                {22,7,4,5,3}};

    myvvi vv = {{4,3,2},{7,6,1},{8,8,8}};

    cout<<lt.lt2245a(vv)<<endl;

    return 0;
}
