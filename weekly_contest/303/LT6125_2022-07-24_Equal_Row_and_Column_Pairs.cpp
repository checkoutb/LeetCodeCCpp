
#include "../../header/myheader.h"

class LT6125
{
public:




// AC
    int equalPairs(vector<vector<int>>& grid) {

        int ans = 0;
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                for (int k = 0; k < sz1; ++k)
                {
                    #ifdef __test

                    #endif
                    if (grid[i][k] != grid[k][j])
                        goto AAA;
                }
                ans++;

                AAA:
                continue;
            }
        }
        return ans;
    }

};

int main()
{

    LT6125 lt;

    myvvi vv = {{3,2,1},{1,7,6},{2,7,7}};

    cout<<lt.equalPairs(vv)<<endl;

    return 0;
}
