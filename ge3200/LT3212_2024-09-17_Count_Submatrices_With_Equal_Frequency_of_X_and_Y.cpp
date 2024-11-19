
#include "../header/myheader.h"

class LT3212
{
public:





// Runtime
// 402ms
// Beats68.26%
// Analyze Complexity
// Memory
// 101.34MB
// Beats87.42%

    

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int sz1 { static_cast<int>(grid.size()) }, sz2 { static_cast<int>(grid[0].size())};
        int ans = 0;
        std::vector<vector<int>> vvi(sz2, vector<int>(2, 0));  // {x, y}
        for (int i = 0; i < sz1; ++i) {
            int cntx = 0, cnty = 0;
            for (int j = 0; j < sz2; ++j) {
                if (grid[i][j] == 'X') {
                    ++cntx;
                } else if (grid[i][j] == 'Y') {
                    ++cnty;
                }
                vvi[j][0] += cntx;
                vvi[j][1] += cnty;
                if (vvi[j][0] == vvi[j][1] && vvi[j][0] != 0) {
                    ++ans;
                }
            }
        }
        return ans;
    }


};

int main()
{

    LT3212 lt;


    return 0;
}
