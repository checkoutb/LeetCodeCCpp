
#include "../header/myheader.h"
#include <array>

class LT3071
{
public:



// Runtime
// 58ms
// Beats31.24%of users with C++
// Memory
// 41.07MB
// Beats79.49%of users with C++
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        std::array<int, 3> isy {0};
        std::array<int, 3> noty {0};
        int sz1 = grid.size(), sz2 {int(grid[0].size())};
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (iny(sz1, sz2, i, j))
                {
                    ++isy[grid[i][j]];
                }
                else
                {
                    ++noty[grid[i][j]];
                }
            }
        }
        int ans = std::min({
            isy[1] + isy[2] + min(noty[0] + noty[2], noty[0] + noty[1]),
            isy[0] + isy[2] + min(noty[1] + noty[0], noty[1] + noty[2]),
            isy[0] + isy[1] + min(noty[2] + noty[1], noty[2] + noty[0]),
        });
        return ans;
    }

    // sz1==sz2...
    bool iny(int sz1, int sz2, int i, int j) {
        return (i == j && i <= sz1 / 2) || (i + j + 1 == sz1 && i < sz1 / 2) || (j == sz2 / 2 && i > sz1 / 2);
    }

};

int main()
{

    LT3071 lt;

    myvvi vv = {{1,1,0},{1,2,2},{0,1,0}};

    cout<<lt.minimumOperationsToWriteY(vv);

    return 0;
}
