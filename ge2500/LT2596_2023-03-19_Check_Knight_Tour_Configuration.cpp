
#include "../header/myheader.h"

class LT2596
{
public:




    //Runtime16 ms
    //    Beats
    //    66.67 %
    //    Memory28 MB
    //    Beats
    //    33.33 %
    // n <= 7
    bool lt2596a(vector<vector<int>>& grid)
    {
        if (grid[0][0] != 0)
            return false;

        int sz1 = grid.size();
        int sz2 = sz1 * sz1;
        //vector<pair<int, int>> vp(sz1 * sz1);
        vector<int> vi(sz2);
        vector<int> vj(sz2);

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {
                vi[grid[i][j]] = i;
                vj[grid[i][j]] = j;

                //vp[grid[i][j]].first = i;
                //vp[grid[i][j]].second = j;
            }
        }

        for (int i = 1; i < sz2; ++i)
        {
            if (abs(vi[i] - vi[i - 1]) == 1)
            {
                if (abs(vj[i] - vj[i - 1]) == 2)
                    continue;
            }
            else if (abs(vi[i] - vi[i - 1]) == 2)
            {
                if (abs(vj[i] - vj[i - 1]) == 1)
                    continue;
            }
            return false;
        }
        return true;
    }

};

int main()
{

    LT2596 lt;

    //myvvi vv = { {0, 11, 16, 5, 20},{17, 4, 19, 10, 15},{12, 1, 8, 21, 6},{3, 18, 23, 14, 9}, { 24, 13, 2, 7, 22} };

    myvvi vv = { 
        {24, 11, 22, 17, 4},
        {21, 16, 5, 12, 9},
        {6, 23, 10, 3, 18},
        {15, 20, 1, 8, 13},
        {0, 7, 14, 19, 2} };

    cout << lt.lt2596a(vv) << endl;

    return 0;
}
