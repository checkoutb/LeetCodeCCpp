
#include "../header/myheader.h"

class LT0749
{
public:

// D D

// 这个形参是 grid 还是 isInfected?




//Runtime: 69 ms, faster than 37.08% of C++ online submissions for Contain Virus.
//Memory Usage: 19.7 MB, less than 51.69% of C++ online submissions for Contain Virus.
// 且该感染区域对未感染区域的威胁最大且 保证唯一 。 。。。
// 1 0 1 这种算谁感染的？
    int lt0749a(vector<vector<int>>& grid)
    {
        int col = 2;        // colour
        int ans = 0;
        unordered_set<int> set2;
        unordered_map<int, int> map2;
        int sz1 = grid.size(), sz2 = grid[0].size();
        int mxeff = 0;
        int mxidx = 0;
        int mxwal = 0;
        bool b2 = true;
        while (b2)
        {
            b2 = false;
            mxeff = 0;
            mxwal = 0;
            mxidx = 0;
            map2.clear();
            for (int i = 0; i < sz1; ++i)
            {
                for (int j = 0; j < sz2; ++j)
                {
                    if (grid[i][j] == col - 1)
                    {
                        b2 = true;
                        set2.clear();
                        int wall = dfsa1(grid, i, j, set2, col);
                        for (int x : set2)
                            map2[x]++;
                        if (set2.size() >= mxeff)
                        {
                            mxeff = set2.size();
                            mxidx = i * 100 + j;
                            mxwal = wall;
                        }
                    }
                }
            }
            if (b2)
            {
                int i = mxidx / 100;
                int j = mxidx % 100;
                ans += mxwal;
                set2.clear();
                dfsa1(grid, i, j, set2, -1);
                for (int x : set2)
                    map2[x]--;
                for (auto& p : map2)
                {
                    if (p.second != 0)
                        grid[p.first / 100][p.first % 100] = col;
                }
            }
            #ifdef __test
            for (myvi& vi : grid)
            {
                for (int i : vi)
                    cout<<i<<", ";
                cout<<endl;
            }
            cout<<ans<<endl;
            cout<<endl;
//            getchar();
            #endif // __test

            col++;
        }
        return ans;
    }

    int dfsa1(vector<vector<int>>& grid, int i, int j, unordered_set<int>& set2, int col)
    {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == col)
            return 0;
        if (grid[i][j] == 0)
        {
            set2.insert(i * 100 + j);
            return 1;
        }
        if (grid[i][j] == -1)
            return 0;

        grid[i][j] = col;
        int ans = 0;
        ans += dfsa1(grid, i, j + 1, set2, col);
        ans += dfsa1(grid, i, j - 1, set2, col);
        ans += dfsa1(grid, i + 1, j, set2, col);
        ans += dfsa1(grid, i - 1, j, set2, col);
        return ans;
    }

//    void filla1(vector<vector<int>>& grid, int i, int j, int val)
//    {
//
//    }

};

int main()
{

    LT0749 lt;

//    myvvi vv = {{0,1,0,0,0,0,0,1},{0,1,0,0,0,0,0,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0}};
//    myvvi vv = {{1,1,1},{1,0,1},{1,1,1}};
//    myvvi vv = {{1,1,1,0,0,0,0,0,0},
//                {1,0,1,0,1,1,1,1,1},
//                {1,1,1,0,0,0,0,0,0}};

    myvvi vv = {{1,1,0,0,1,0,1,1,1,1,1,0,1,1,1,0,1,1,0,0},{1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,1,0,0},
    {1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,1},{1,1,0,1,1,0,1,0,1,1,0,0,0,0,0,1,1,1,0,1},
    {1,1,1,0,1,1,0,1,1,0,0,1,1,0,1,1,1,0,0,1},{0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,0,1,0,1,0},
    {1,0,1,1,1,0,0,0,1,1,0,1,1,0,1,1,1,0,1,1},{1,0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,0,0},
    {1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,1},{1,0,0,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1},
    {1,0,1,0,0,1,1,1,0,1,1,1,1,0,0,1,1,1,0,1},{1,0,1,1,1,0,1,1,1,1,0,1,0,0,1,1,0,1,1,1},
    {1,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,1,1,0,1},{1,1,0,0,0,1,0,0,1,1,1,0,0,0,0,1,0,1,0,1},
    {0,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,0,0},{1,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1,0,0,0,0},
    {0,1,0,0,0,1,1,0,0,1,1,1,1,1,1,0,1,0,0,1},{1,1,1,0,1,1,0,1,0,1,1,1,0,0,1,1,1,1,0,1},
    {0,0,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,1,1,1},{0,1,1,1,1,0,1,0,1,1,1,1,0,0,0,1,0,0,0,0}};

    cout<<lt.lt0749a(vv);

    return 0;
}
