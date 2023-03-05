
#include "../header/myheader.h"

class LT1536
{
public:

    // D D





    

    //Runtime71 ms
    //    Beats
    //    47.78 %
    //    Memory25.6 MB
    //    Beats
    //    86.67 %
    int lt1536a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        vector<int> vi(sz1);        // idx + 1, length

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = sz1 - 1; j >= 0; --j)
            {
                if (grid[i][j] == 1)
                {
                    vi[i] = j + 1;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            int ned = i + 1;
            int j = 0;
            for (; j < sz1; ++j)
            {
                if (vi[j] == -1)
                    continue;
                if (vi[j] <= ned)
                {
                    break;
                }
                ++ans;
            }
            if (j == sz1)
            {
                return -1;
            }
            else
            {
                vi[j] = -1;        // chosen
            }
            //else
            //{
            //    ans += j - i;
            //}
        }
        return ans;
    }

};

int main()
{

    LT1536 lt;

    //myvvi vv = { {0,0,1},{1,1,0},{1,0,0} };
    myvvi vv = { {1,0,1},{1,1,0},{1,1,1} };

    cout << lt.lt1536a(vv) << endl;

    return 0;
}
