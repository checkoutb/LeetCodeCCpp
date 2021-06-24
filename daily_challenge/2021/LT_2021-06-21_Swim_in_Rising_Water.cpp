
#include "../../header/myheader.h"

class LT
{
public:

// D D


// Dijkstra
// priority_queue<pair<int, pair<int, int>>> q;

// UF

// binary search




// AC
// 二分
// dfs行不行？ 加一个memo，记录 通过时的水位，
// permutation 有什么用？
    int lta(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int st = 0;
        int en = sz1 * sz1;
        bitset<2500> bset;       // constant expression.
        while (st < en)
        {
            int mid = (st + en) / 2;
            if (canArrivea2(grid, mid, 0, 0, bset, grid[0][0] + mid))
            {
                en = mid;
            }
            else
            {
                st = mid + 1;
            }
            bset.reset();       // all false
            #ifdef __test
            cout<<st<<", "<<en<<", "<<mid<<endl;
            getchar();
            #endif // __test
        }
        return st;
    }
    int arr[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

    // 应该是求  是否存在一条路，这条路上的海拔都低于 time 。
    bool canArrivea2(vector<vector<int>>& vvi, int tm, int x, int y, bitset<2500>& bset, int mn)
    {
        if (x == vvi.size() || y == vvi.size() || x == -1 || y == -1 || (vvi[x][y] > tm))
        {
            return false;
        }
        if ((x == vvi.size() - 1) && (y == vvi.size() - 1))
        {
            return true;
        }
        if (bset.test(x * (int) vvi.size() + y))
        {
            return false;
        }
        bset.set(x * (int) vvi.size() + y);
        for (int i = 0; i < 4; ++i)
        {
            if (canArrivea2(vvi, tm, x + arr[i][0], y + arr[i][1], bset, mn))
                return true;
        }
        return false;
    }

    // 好像离题万里了。。
    bool canArrivea1(vector<vector<int>>& vvi, int tm, int x, int y, bitset<250>& bset, int mn)
    {
        if (x == vvi.size() || y == vvi.size() || x == -1 || y == -1 || (vvi[x][y] > mn))
        {
            #ifdef __test
//            cout<<x<<", "<<y<<", "<<(lst + tm)<<endl;
            #endif // __test
            return false;
        }
        if ((x == vvi.size() - 1) && (y == vvi.size() - 1))
        {
            #ifdef __test
//            cout<<"can "<<tm<<endl;
            #endif // __test
            return true;
        }
        if (bset.test(x * (int) vvi.size() + y))
        {
            #ifdef __test
//            cout<<",,, "<<x<<", "<<y<<endl;
            #endif // __test
            return false;
        }
        mn = min(mn, vvi[x][y] + tm);
//        mn = vvi[x][y] + tm;              // 是以起始
        bset.set(x * (int) vvi.size() + y);
        for (int i = 0; i < 4; ++i)
        {
//            if ()
            if (canArrivea1(vvi, tm, x + arr[i][0], y + arr[i][1], bset, mn))
                return true;
        }
        return false;
    }

};

int main()
{
//    myvvi vv = {{0,2},{1,3}};
    myvvi vv = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};

    LT lt;

    cout<<lt.lta(vv);

    return 0;
}
