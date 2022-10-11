
#include "../header/myheader.h"

class LT2428
{
public:

    // D D

    // for(int i=0; i<row-2;i++)



//Runtime: 87 ms, faster than 49.27 % of C++ online submissions for Maximum Sum of an Hourglass.
//Memory Usage : 13.3 MB, less than 11.65 % of C++ online submissions for Maximum Sum of an Hourglass.
    int lt2428a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        int ans = 0;
        int t2 = 0;
        for (int i = 1; i < sz1 - 1; ++i)
        {
            for (int j = 1; j < sz2 - 1; ++j)
            {
                t2 = grid[i][j] + grid[i - 1][j] + grid[i - 1][j - 1] + grid[i - 1][j + 1] + grid[i + 1][j] + grid[i + 1][j - 1] + grid[i + 1][j + 1];
                ans = max(ans, t2);
            }
        }
        return ans;
    }

};

int main()
{

    LT2428 lt;


    return 0;
}
