
#include "../header/myheader.h"

class LT2556
{
public:

    // D 

    // 看了solution，我怎么觉得我这个可以呢，但是不知道为什么就是TLE。 25/41 TLE



    // tle. * 2
    bool lt2556a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        if (sz1 == 1 && sz2 == 2)
            return false;

        if (dfsa1(grid, 1, 0) && dfsa2(grid, 0, 1))
            return false;
        return true;
    }

    // first down, then left
    bool dfsa1(vector<vector<int>>& vvi, int r, int c)
    {
        if (r == vvi.size() || c == vvi[0].size() || vvi[r][c] != 1)
            return false;

        if (r == vvi.size() - 1 && c == vvi[0].size() - 1)
            return true;

        if (dfsa1(vvi, r + 1, c))
        {
            vvi[r][c] = -123;
            return true;
        }
        if (dfsa1(vvi, r, c + 1))
        {
            vvi[r][c] = -123;
            return true;
        }
        return false;
    }

    // first left, then down
    bool dfsa2(vector<vector<int>>& vvi, int r, int c)
    {
        if (r == vvi.size() || c == vvi[0].size() || vvi[r][c] != 1)
            return false;

        if (r == vvi.size() - 1 && c == vvi[0].size() - 1)
            return true;

        if (dfsa1(vvi, r, c + 1) || dfsa1(vvi, r + 1, c))
            return true;

        return false;
    }

};

int main()
{

    LT2556 lt;

    myvvi vv = { {1,1,1},{1,0,0},{1,1,1} };
    //myvvi vv = { {1,1,1},{1,0,1},{1,1,1} };

    cout << lt.lt2556a(vv) << endl;

    return 0;
}
