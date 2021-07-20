
#include "../header/myheader.h"

class LT1914
{
public:

// D D

//            vector<int> v;
//
//            for(int i = l; i < n - l - 1; ++i) // top row
//                v.push_back(grid[l][i]);
// ......
//            int start = k % v.size();
//
//            for(int i = l; i < n - l - 1; ++i) // top row
//                grid[l][i] = v[start++ % v.size()];






//Runtime: 20 ms, faster than 89.92% of C++ online submissions for Cyclically Rotating a Grid.
//Memory Usage: 12.9 MB, less than 53.94% of C++ online submissions for Cyclically Rotating a Grid.
    vector<vector<int>> lt1914a(vector<vector<int>>& grid, int k)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        int mxsz = min(sz1 / 2, sz2 / 2);
        vector<vector<int>> vvi = grid;             // copy or reference ?  it is copy ... & ref
        for (int i = 0; i < mxsz; ++i)
        {
            int len = (sz1 - i * 2) * 2 + (sz2 - 2 - i * 2) * 2;
            int mov = k % len;
            // ... 一次完成好像很难。。。 bu,  步长可以 计算出 最终位置。
            pair<int, int> pii = finalXY(sz1, sz2, i, i, i, mov);
            int orii = i;
            int orij = i;
            int tari = pii.first;
            int tarj = pii.second;
            grid[tari][tarj] = vvi[orii][orij];
            while (len-- > 1)
            {
                pair<int, int> p1 = nextXY(sz1, sz2, orii, orij, i);        // parameter should be pair....
                pair<int, int> p2 = nextXY(sz1, sz2, tari, tarj, i);
                orii = p1.first;
                orij = p1.second;
                tari = p2.first;
                tarj = p2.second;
                grid[tari][tarj] = vvi[orii][orij];
            }
        }
        return grid;
    }

    pair<int, int> nextXY(int sz1, int sz2, int x, int y, int i)
    {
        int xmn = i;
        int ymn = i;
        int xmx = sz1 - i - 1;          // can ==
        int ymx = sz2 - i - 1;
        if (x == xmn)
        {
            if (y == ymn)
            {
                return {x + 1, y};
            }
            else
            {
                return {x, y - 1};
            }
        }
        if (x == xmx)
        {
            if (y == ymx)
            {
                return {x - 1, y};
            }
            else
                return {x, y + 1};
        }
        if (y == ymn)
        {
            return {x + 1, y};
        }
        else
        {
            return {x - 1, y};
        }
    }

    // 不必每次计算，第一次计算，后续就是 第一次计算的后一位。
    pair<int, int> finalXY(int sz1, int sz2, int x, int y, int i, int mov)
    {
        int xmn = i;
        int ymn = i;
        int xmx = sz1 - i - 1;          // can ==
        int ymx = sz2 - i - 1;
        while (mov > 0)
        {
            if (y == ymn)       // down
            {
                while (mov > 0)
                {
                    if (x + 1 <= xmx)
                    {
                        mov--;
                        x += 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (x == xmx)       // right
            {
                while (mov > 0)
                {
                    if (y + 1 <= ymx)
                    {
                        mov--;
                        y += 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (y == ymx)       // up
            {
                while (mov > 0)
                {
                    if (x - 1 >= xmn)
                    {
                        mov--;
                        x -= 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (x == xmn)       // left
            {
                while (mov > 0)
                {
                    if (y - 1 >= ymn)
                    {
                        mov--;
                        y -= 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return {x, y};
    }

//    // [x][y]   z==i
//    void moveOne(vector<vector<int>>& vvi, int x, int y, int z)
//    {
//
//    }

};

int main()
{
//    myvvi vv = {{40,10},{30,20}};
//    int k = 1;

    myvvi vv = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int k = 2;

    myvvi v3 = vv;
//    v3[0][0] = 1234;
//    cout<<vv[0][0]<<", "<<v3[0][0]<<endl;

    LT1914 lt;

    lt.lt1914a(vv, k);

    for (myvi& vi : vv)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
