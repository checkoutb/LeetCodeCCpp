
#include "../header/myheader.h"

class LT0892
{
public:

// D D
//        for (int i = 0; i < m; ++i)
//            for (int j = 0; j < n; ++j)
//            {
//                if (A[i][j]) res += A[i][j] * 4 + 2;
//                if(i) res -= 2 * min(A[i][j], A[i - 1][j]);
//                if(j) res -= 2 * min(A[i][j], A[i][j - 1]);
//            }



//Runtime: 44 ms, faster than 5.01% of C++ online submissions for Surface Area of 3D Shapes.
//Memory Usage: 9.6 MB, less than 42.10% of C++ online submissions for Surface Area of 3D Shapes.
    int lt0892a(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            grid[i].push_back(0);
            grid[i].insert(grid[i].begin(), 0);
        }
        n += 2;
        grid.emplace_back(vector<int>(n, 0));
        grid.insert(grid.begin(), vector<int>(n, 0));
        int n1 = n - 1;
        for (int i = 1; i < n1; i++)
        {
            for (int j = 1; j < n1; j++)
            {
                int t2 = grid[i][j];
                if (t2 == 0)
                    continue;
                ans += 2;
                ans += max(0, t2 - grid[i][j-1]);
                ans += max(0, t2 - grid[i][j+1]);
                ans += max(0, t2 - grid[i-1][j]);
                ans += max(0, t2 - grid[i+1][j]);
            }
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> vv = {{1,0},{0,2}};

    LT0892 lt;

    cout<<lt.lt0892a(vv)<<endl;

    return 0;
}
