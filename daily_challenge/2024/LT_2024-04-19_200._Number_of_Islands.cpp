
#include "../../header/myheader.h"

class LT
{
public:





// Runtime
// 27ms
// Beats71.43%of users with C++
// Memory
// 15.84MB
// Beats67.22%of users with C++
    int numIslands(vector<vector<char>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfsa1(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }

    void dfsa1(vector<vector<char>>& vvc, int i, int j)
    {
        if (i < 0 || j < 0 || i == vvc.size() || j == vvc[0].size() || vvc[i][j] == '0')
            return;

        vvc[i][j] = '0';
        int arr[5] = {1,0,-1,0,1};
        for (int k = 1; k < 5; ++k)
        {
            dfsa1(vvc, i + arr[k - 1], j + arr[k]);
        }
    }

};

int main()
{

    LT lt;


    return 0;
}
