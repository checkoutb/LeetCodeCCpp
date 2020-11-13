
#include "../header/myheader.h"

class LT1260
{
public:

// D D




//Runtime: 36 ms, faster than 94.12% of C++ online submissions for Shift 2D Grid.
//Memory Usage: 14.5 MB, less than 29.02% of C++ online submissions for Shift 2D Grid.
    vector<vector<int>> lt1260a(vector<vector<int>>& grid, int k)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<vector<int>> ans(sz1, vector<int>(sz2, 0));
        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz2; ++j)
            {
                int t1 = i * sz2 + j + k;
                int m = (t1 / sz2) % sz1;
                int n = t1 % sz2;
                ans[m][n] = grid[i][j];
            }
        }
        return ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{1,2,3},{4,5,6},{7,8,9}};
//    int k = 9;

    vector<vector<int>> vv = {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
    int k = 4;


    LT1260 lt;

    vector<vector<int>> vvi = lt.lt1260a(vv, k);

    for (vector<int>& vi : vvi)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
