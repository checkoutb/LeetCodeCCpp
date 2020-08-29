
#include "../header/myheader.h"

class LT0883
{
public:


// D D
//        for (int i = 0; i < n; ++i) {
//            x = 0, y = 0;
//            for (int j = 0; j < n; ++j) {
//                x = max(x, grid[i][j]);
//                y = max(y, grid[j][i]);
//                if (grid[i][j]) ++res;
//            }
//            res += x + y;
//        }
// 正方形，所以能 i j, j i



//Runtime: 48 ms, faster than 5.46% of C++ online submissions for Projection Area of 3D Shapes.
//Memory Usage: 9.6 MB, less than 27.50% of C++ online submissions for Projection Area of 3D Shapes.
    int lt0883a(vector<vector<int>>& grid)
    {
        int ans = 0;
        int sz1 = grid.size();
        vector<int> row(sz1, 0);
        vector<int> col(sz1, 0);
        for (int i = 0; i < sz1; i++)
        {
            vector<int>& v = grid[i];
            for (int j = 0; j < sz1; j++)
            {
                if (v[j] != 0)
                {
                    ans++;
                    row[i] = max(row[i], v[j]);
                    col[j] = max(col[j], v[j]);
                }
            }
        }
        #ifdef __test
        for_each(begin(row), end(row), fun_cout);
        cout<<endl;
        for_each(begin(col), end(col), fun_cout);
        cout<<endl;
        cout<<ans<<endl;
        #endif // __test
        ans = accumulate(begin(row), end(row), ans);
        ans = accumulate(begin(col), end(col), ans);
        return ans;
    }

};

int main()
{

    vector<vector<int>> vv = {{1,2},{3,4}};

    LT0883 lt;

    cout<<lt.lt0883a(vv)<<endl;

    return 0;
}
