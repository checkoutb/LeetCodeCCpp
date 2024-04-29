
#include "../header/myheader.h"

class LT3128
{
public:

    // D D

        // fill(r, r+n+1, -1);
        // fill(c, c+m+1, -1);
    // 预先减好1


// Runtime
// 243ms
// Beats62.50%of users with C++
// Memory
// 113.04MB
// Beats25.00%of users with C++
    long long numberOfRightTriangles(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        vector<int> vrow(sz1, 0);
        vector<int> vcol(sz2, 0);

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (grid[i][j] == 1)
                    ++vrow[i], ++vcol[j];
            }
        }

#ifdef __test
        showVectorInt(vrow);
        showVectorInt(vcol);
#endif

        long long ans = 0LL;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (vrow[i] <= 1)
                continue;
            t2 = vrow[i] - 1;
            for (int j = 0; j < sz2; ++j)
            {
                if (grid[i][j] == 1 && vcol[j] > 1)
                    ans += t2 * (vcol[j] - 1);
            }
        }
        return ans;
    }
};

int main()
{

    LT3128 lt;

    myvvi vv {{0,1,0},{0,1,1},{0,1,0}};

    std::cout<<lt.numberOfRightTriangles(vv);

    return 0;
}
