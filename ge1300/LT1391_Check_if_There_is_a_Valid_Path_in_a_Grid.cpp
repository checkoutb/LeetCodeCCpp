
#include "../header/myheader.h"

class LT1391
{
public:

// D D

// union find

// bfs

// dfs

// track



//Runtime: 264 ms, faster than 100.00% of C++ online submissions for Check if There is a Valid Path in a Grid.
//Memory Usage: 48.4 MB, less than 94.94% of C++ online submissions for Check if There is a Valid Path in a Grid.
//      0
//  1       2
//      3
// 是从外部驶入0,0 然后从 m,n 出去， 还是 从00出发，达到mn就可以。  不是从外部驶入的。。 到达mn就可以。
    bool lt1391a(vector<vector<int>>& grid)
    {
        vector<vector<int>> desc = {{-1,-1},{1,2},{0,3},{1,3},{2,3},{1,0},{0,2}};           // {in/out : out/in}
        int i = 0, j = 0;
        int sz1 = grid.size(), sz2 = grid[0].size();
        if (sz1 == 1 && sz2 == 1)
            return true;
        int dir = -1;
        switch (grid[0][0])
        {
        case 1:
            dir = 2;
            break;
        case 2:
            dir = 3;
            break;
        }
        #define isValid(i, j) (i >= 0 && j >= 0 && i < sz1 && j < sz2)
        for (int m = 0; m < 2; ++m)
        {
            dir = desc[grid[0][0]][m];
            i = j = 0;
            while (true)
            {
                #ifdef __test
                cout<<i<<" : "<<j<<", "<<dir<<endl;
                #endif // __test
                switch (dir)
                {
                case 0:
                    --i;
                    break;
                case 1:
                    --j;
                    break;
                case 2:
                    ++j;
                    break;
                case 3:
                    ++i;
                    break;
                }
                if (!isValid(i, j))
                    break;
                if (i == 0 && j == 0)
                    break;
                vector<int>& v = desc[grid[i][j]];
                int t = 3 - dir;
                dir = -1;
                if (v[0] == t)
                    dir = v[1];
                else if (v[1] == t)
                    dir = v[0];
                if (dir == -1)
                {
                    j--;
                    break;
                }

                if (i == (sz1 - 1) && j == (sz2 - 1))
                    break;
            }
            if (i == (sz1 - 1) && j == (sz2 - 1))
                return true;
        }
        #ifdef __test
        cout<<i<<", "<<j<<endl;
        #endif // __test
//        return i == (sz1 - 1) && j == (sz2 - 1);
        return false;
    }

//    bool dfsa1()

};

int main()
{

//    vector<vector<int>> vv = {{2,4,3},{6,5,2}};
//    vector<vector<int>> vv = {{1,2,1},{1,2,1}};
//    vector<vector<int>> vv = {{1,1,2}};
//    vector<vector<int>> vv = {{1,1,1,1,1,1,3}};
//    vector<vector<int>> vv = {{2},{2},{2},{2},{6}};
//    vector<vector<int>> vv = {{4,1},{6,1}};
//    vector<vector<int>> vv = {{2,4,3},{6,5,2}};

    LT1391 lt;

    cout<<lt.lt1391a(vv)<<endl;

    return 0;
}
