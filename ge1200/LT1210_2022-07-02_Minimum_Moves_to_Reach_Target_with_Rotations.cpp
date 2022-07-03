
#include "../header/myheader.h"

class LT1210
{
public:

    // D D




//Runtime: 36 ms, faster than 98.90 % of C++ online submissions for Minimum Moves to Reach Target with Rotations.
//Memory Usage : 12.7 MB, less than 97.80 % of C++ online submissions for Minimum Moves to Reach Target with Rotations.
    int lt1210a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<vector<short>> vst(sz1, vector<short>(sz2, 0));      // 1 - ...  2 |

        const int vertical = 100000000;     // |
        const int rmul = 1000;

        queue<int> que1;
        que1.push(0);
        int ans = 0;
        vst[0][0] = 0;
        int over = (sz1 - 1) * rmul + (sz2 - 2);
        while (!que1.empty())
        {
            for (int i = 0, mxi = que1.size(); i < mxi; ++i)
            {
                int t2 = que1.front();
                que1.pop();
                if (t2 == over)
                    return ans;
                if (t2 >= vertical)        // |
                {
                    t2 %= vertical;
                    int row = t2 / rmul;
                    int col = t2 % rmul;


                    if ((row + 2) < sz1 && grid[row + 2][col] == 0 && (vst[row + 1][col] & 2) == 0)
                    {
                        vst[row + 1][col] |= 2;
                        que1.push(vertical + (row + 1) * rmul + col);
                    }
                    if ((col + 1) < sz2 && grid[row][col + 1] == 0 && grid[row + 1][col + 1] == 0
                        // && (vst[row][col + 1] & 2) == 0
                        )
                    {
                        if ((vst[row][col + 1] & 2) == 0)
                        {
                            vst[row][col + 1] |= 2;
                            que1.push(vertical + row * rmul + col + 1);
                        }
                        if ((vst[row][col] & 1) == 0)
                        {
                            que1.push(row * rmul + col);
                            vst[row][col] |= 1;
                        }
                    }
                    
                }
                else    // --
                {
                    int row = t2 / rmul;
                    int col = t2 % rmul;

                    if ((col + 2) < sz2 && grid[row][col + 2] == 0 && (vst[row][col + 1] & 1) == 0)
                    {
                        vst[row][col + 1] |= 1;
                        que1.push(row * rmul + col + 1);
                    }
                    if ((row + 1) < sz1 && grid[row + 1][col] == 0 && grid[row + 1][col + 1] == 0)
                    {
                        if ((vst[row + 1][col] & 1) == 0)
                        {
                            vst[row + 1][col] |= 1;
                            que1.push(row * rmul + col + rmul);
                        }
                        if ((vst[row][col] & 2) == 0)
                        {
                            que1.push(vertical + row * rmul + col);
                            vst[row][col] |= 2;
                        }
                    }

                }

            }
            ans++;
        }
        return -1;
    }

};

int main()
{

    LT1210 lt;

    //myvvi vv = { {0,0,0,0,0,1},
    //           {1,1,0,0,1,0},
    //           {0,0,0,0,1,1},
    //           {0,0,1,0,1,0},
    //           {0,1,1,0,0,0},
    //           {0,1,1,0,0,0} };


    myvvi vv = { {0,0,1,1,1,1},
               {0,0,0,0,1,1},
               {1,1,0,0,0,1},
               {1,1,1,0,0,1},
               {1,1,1,0,0,1},
               {1,1,1,0,0,0} };


    cout << lt.lt1210a(vv) << endl;

    return 0;
}
