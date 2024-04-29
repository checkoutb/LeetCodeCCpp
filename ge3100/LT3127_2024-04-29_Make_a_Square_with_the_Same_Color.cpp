
#include "../header/myheader.h"

class LT3127
{
public:




// Runtime
// 8ms
// Beats50.00%of users with C++
// Memory
// 19.68MB
// Beats50.00%of users with C++
    bool canMakeSquare(vector<vector<char>>& grid)
    {
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                if (can_same(grid[i][j], grid[i + 1][j], grid[i][j + 1], grid[i + 1][j + 1]))
                    return true;
            }
        }
        return false;
    }

    bool can_same(char ch1, char ch2, char ch3, char ch4)
    {
        int t2 = cvt(ch1) + cvt(ch2) + cvt(ch3) + cvt(ch4);
        return t2 != 2;
    }

    int cvt(char ch)
    {
        return ch == 'W' ? 0 : 1;
    }
};

int main()
{

    LT3127 lt;


    return 0;
}
