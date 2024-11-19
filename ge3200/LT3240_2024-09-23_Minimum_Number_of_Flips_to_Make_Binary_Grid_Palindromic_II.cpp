
#include "../header/myheader.h"

class LT3240
{
public:





// Runtime
// 303ms
// Beats81.98%
// Analyze Complexity
// Memory
// 193.47MB
// Beats98.93%

    

    // all row, all column, palindromic,
    // cnt1 % 4 == 0
    // 遍历 1/4 矩形，
    // 偶数*偶数  遍历1/4 就可以了
    // 如果 有奇数，那么需要 cnt1 % 4 。
    //   奇数*偶数， 奇数的 中位边 需要注意
    //   奇数*奇数，
    // 奇数长度，需要注意 中间边的 对称。
    int minFlips(vector<vector<int>>& grid) {
        int ans = 0;
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        int ni, nj, t2;
        for (int i = 0; i < sz1 >> 1; ++i) {
            for (int j = 0; j < sz2 >> 1; ++j) {
                ni = sz1 - 1 - i;
                nj = sz2 - 1 - j;

                t2 = grid[i][j] + grid[i][nj] + grid[ni][j] + grid[ni][nj];
                ans += std::min(t2, 4 - t2);
            }
        }

        int cntr = 0; // odd, the middle row, how many diff
        int cntc = 0; // column
        int cntr1 = 0; // middle row, how many 1
        int cntc1 = 0;
        if (sz1 % 2 == 1) {
            for (int j = 0; j < sz2 >> 1; ++j) {
                if (grid[sz1 / 2][j] != grid[sz1 / 2][sz2 - 1 - j])
                    ++cntr;
                else
                    cntr1 += grid[sz1 / 2][j] * 2;
            }
        }
        if (sz2 % 2 == 1) {
            for (int i = 0; i < sz1 >> 1; ++i) {
                if (grid[i][sz2 >> 1] != grid[sz1 - 1 - i][sz2 >> 1])
                    ++cntc;
                else
                    cntc1 += grid[i][sz2 >> 1] * 2;
            }
        }

        if (sz1 % 2 == 1 && sz2 % 2 == 1) {
            ans += grid[sz1 / 2][sz2 / 2];
        }

        ans += cntr + cntc;

        if ((cntr1 + cntc1) % 4 == 0) {
            ;
        } else {
            // == 2
            if ((cntr + cntc) != 0) {
                ;
            } else {
                ans += 2;
            }
        }
        
        return ans;
    }


};

int main()
{

    LT3240 lt;


    return 0;
}
