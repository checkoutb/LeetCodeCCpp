
#include "../header/myheader.h"

class LT2482
{
public:





    //Runtime262 ms
    //    Beats
    //    100 %
    //    Sorry, there are not enough accepted submissions to show data
    //    Memory117.2 MB
    //    Beats
    //    100 %
    vector<vector<int>> lt2482a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        vector<vector<int>> vvi(sz1, vector<int>(sz2));

        vector<int> vr(sz1);
        vector<int> vc(sz2);

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                vr[i] += grid[i][j] << 1;
                vc[j] += grid[i][j] << 1;
            }
        }
        int t2 = sz1 + sz2;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                //vvi[i][j] = vr[i] + vc[j] - sz1 - sz2 + vr[i] + vr[j];
                vvi[i][j] = vr[i] + vc[j] - t2;
            }
        }

        return vvi;
    }

};

int main()
{

    LT2482 lt;


    return 0;
}
