
#include "../header/myheader.h"

class LT0064
{
public:

// D D

//            for (int row = 0; row < height; row++) {
//                for (int col = 0; col < width; col++) {
//                    if(row == 0 && col == 0) grid[row][col] = grid[row][col];
//                    else if(row == 0 && col != 0) grid[row][col] = grid[row][col] + grid[row][col - 1];
//                    else if(col == 0 && row != 0) grid[row][col] = grid[row][col] + grid[row - 1][col];
//                    else grid[row][col] = grid[row][col] + Math.min(grid[row - 1][col], grid[row][col - 1]);
//                }
//            }


//Runtime: 16 ms, faster than 86.15% of C++ online submissions for Minimum Path Sum.
//Memory Usage: 10.1 MB, less than 76.25% of C++ online submissions for Minimum Path Sum.
    int lt0064a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<int> vi(sz2);
//        const int cxm = 111;              // 60/61 ...  数据多了以后，  第一行， up 是111， 但是 fnt 可以大于 111。
        const int cxm = INT_MAX >> 1;
        vi[0] = grid[0][0];
        for (int i = 0; i < sz1; ++i)
        {
            int j = i == 0;
            for (; j < sz2; ++j)
            {
                int up = i == 0 ? cxm : vi[j];
                int fnt = j == 0 ? cxm : vi[j - 1];
                vi[j] = min(up, fnt) + grid[i][j];
            }
        }
        return vi[sz2 - 1];
    }

};

int main()
{

//    myvvi vv = {{1,3,1},{1,5,1},{4,2,1}};
    myvvi vv = {{1,2,3},{4,5,6}};

    LT0064 lt;

    cout<<lt.lt0064a(vv);

    return 0;
}
