
#include "../header/myheader.h"

class LT0959
{
public:


// D D
//replace
//0 0 1
//0 1 0
//1 0 0
//
//1 0 0
//0 1 0
//0 0 1

// union 每合并一个，就cnt--。cnt初始为元素数。



//Runtime: 16 ms, faster than 69.26% of C++ online submissions for Regions Cut By Slashes.
//Memory Usage: 9.6 MB, less than 94.12% of C++ online submissions for Regions Cut By Slashes.
// \\ a b c    / A B c           a: bottom already be filled,  b top, c all
    int lt0959a(vector<string>& grid)
    {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {

                #ifdef __test
//                for (string s : grid)
//                {
//                    cout<<s<<endl;
//                }
//                cout<<" ----- "<<ans<<endl;
                #endif // __test

                if (grid[i][j] != 'c')
                {
                    if (grid[i][j] == '/' || grid[i][j] == '\\')
                    {
                        ans += 1;
                        char ch3 = grid[i][j];
                        grid[i][j] = grid[i][j] == '/' ? 'A' : 'a';
                        filla1(grid, i + 1, j, i, j);
                        filla1(grid, i, j + (ch3 == '/' ? 1 : -1), i, j);
                    }
                    if (grid[i][j] != 'c')
                    {
                        ans++;
                        char ch3 = grid[i][j];
                        grid[i][j] = 'c';
                        if (ch3 == ' ')
                        {
                            filla1(grid, i + 1, j, i, j);
                            filla1(grid, i - 1, j, i, j);
                            filla1(grid, i, j + 1, i, j);
                            filla1(grid, i, j - 1, i, j);
                        }
                        else if (ch3 == 'a')
                        {
                            filla1(grid, i - 1, j, i, j);
                            filla1(grid, i, j + 1, i, j);
                        }
                        else if (ch3 == 'A')
                        {
                            filla1(grid, i - 1, j, i, j);
                            filla1(grid, i, j - 1, i, j);
                        }
                        else if (ch3 == 'b')
                        {
                            filla1(grid, i + 1, j, i, j);
                            filla1(grid, i, j - 1, i , j);
                        }
                        else if (ch3 == 'B')
                        {
                            filla1(grid, i + 1, j, i, j);
                            filla1(grid, i, j + 1, i, j);
                        }
                    }
                }
            }
        }

        return ans;
    }

    void filla1(vector<string>& g, int i, int j, int i2, int j2)
    {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size())
            return;
        char ch = g[i][j];
        if (ch == 'c')
            return;
        if (ch == ' ')
        {
            g[i][j] = 'c';
            filla1(g, i + 1, j, i, j);
            filla1(g, i - 1, j, i, j);
            filla1(g, i, j + 1, i, j);
            filla1(g, i, j - 1, i, j);
            return;
        }
        // \\ a b c    / A B c           a: bottom already be filled,  b top, c all
        if (ch == 'a')
        {
            if (i2 < i || j2 > j)
            {
                g[i][j] = 'c';
                filla1(g, i - 1, j, i, j);      // one is repeat.
                filla1(g, i, j + 1, i, j);
            }
        }
        if (ch == 'b')
        {
            if (i2 > i || j2 < j)
            {
                g[i][j] = 'c';
                filla1(g, i + 1, j, i, j);
                filla1(g, i, j - 1, i, j);
            }
        }
        if (ch == 'A')
        {
            if (i2 < i || j2 < j)
            {
                g[i][j] = 'c';
                filla1(g, i, j - 1, i, j);
                filla1(g, i - 1, j, i, j);
            }
        }
        if (ch == 'B')
        {
            if (i2 > i || j2 > j)
            {
                g[i][j] = 'c';
                filla1(g, i + 1, j, i, j);
                filla1(g, i, j + 1, i, j);
            }
        }
        if (ch == '\\')
        {
            if (i2 < i || j2 > j)
            {
                g[i][j] = 'b';
                filla1(g, i, j + 1, i, j);
                filla1(g, i - 1, j, i, j);
            }
            else
            {
                g[i][j] = 'a';
                filla1(g, i, j - 1, i, j);
                filla1(g, i + 1, j, i, j);
            }
        }
        if (ch == '/')
        {
            if (i2 < i || j2 < j)
            {
                g[i][j] = 'B';
                filla1(g, i, j - 1, i, j);
                filla1(g, i - 1, j, i, j);
            }
            else
            {
                g[i][j] = 'A';
                filla1(g, i + 1, j, i, j);
                filla1(g, i, j + 1, i, j);
            }
        }
    }

};

int main()
{

//    vector<string> vs2 = {" /", "  "};

//    vector<string> vs2 = {"\\/", "/\\"};

    vector<vector<string>> vvs = {
        {" /", "/ "},
        {" /", "  "},
        {"\\/", "/\\"},
        {"/\\", "\\/"},
        {"//","/ "},
        {" /\\"," \\/","\\  "}      //

    };

    int anss[] = {2,1,4,5,3, 4};

    LT0959 lt;

    for (int i = 0; i < vvs.size(); i++)
    {
        int ans = lt.lt0959a(vvs[i]);
        cout<<"       "<<ans<<" is "<<anss[i]<<endl;
    }

    return 0;
}
