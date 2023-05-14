
#include "../../header/myheader.h"

class LT6433
{
public:



    // AC
    int maxMoves(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        vector<int> vi(sz1, 0);
        int ni, nj;
        for (int j = sz2 - 1; j > 0; --j)
        {
            vector<int> v2(sz1, 0);
            nj = j - 1;
            for (int i = 0; i < sz1; ++i)
            {
                ni = i - 1;
                if (ni >= 0 && grid[ni][nj] < grid[i][j])
                {
                    v2[ni] = max(v2[ni], vi[i] + 1);
                }
                ni = i;
                if (grid[ni][nj] < grid[i][j])
                    v2[ni] = max(v2[ni], vi[i] + 1);
                ni = i + 1;
                if (ni < sz1 && grid[ni][nj] < grid[i][j])
                    v2[ni] = max(v2[ni], vi[i] + 1);
            }

            swap(vi, v2);
        }
        return *max_element(begin(vi), end(vi));
    }

};

int main()
{

    LT6433 lt;


    return 0;
}
