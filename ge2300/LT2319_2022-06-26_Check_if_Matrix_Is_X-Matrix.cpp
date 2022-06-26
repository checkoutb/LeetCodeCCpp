
#include "../header/myheader.h"

class LT2319
{
public:

    // D D

    //if (i == j || i == n - 1 - j) {
    //    if (grid[i][j] == 0)
    //        return false;
    //}
    //else {
    //    if (grid[i][j] != 0)
    //        return false;
    //}



//Runtime: 63 ms, faster than 33.33 % of C++ online submissions for Check if Matrix Is X - Matrix.
//Memory Usage : 16.4 MB, less than 33.33 % of C++ online submissions for Check if Matrix Is X - Matrix.
    // ¶Ô½ÇÏß¡£¡£ x == y or x + y == sz1
    bool lt2319a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {
                if (grid[i][j] == 0)
                {
                    if (i == j || (i + j == sz1 - 1))
                        return false;
                }
                else
                {
                    if (i != j && (i + j != sz1 - 1))
                        return false;
                }
            }
        }
        return true;
    }

};

int main()
{

    LT2319 lt;


    return 0;
}
