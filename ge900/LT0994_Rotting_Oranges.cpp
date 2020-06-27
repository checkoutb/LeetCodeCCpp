
#include "../header/myheader.h"

class LT0994
{
public:

    int times = 0;

// D
// bfs, queue保存{x, y}



//Runtime: 12 ms, faster than 55.27% of C++ online submissions for Rotting Oranges.
//Memory Usage: 12.7 MB, less than 64.25% of C++ online submissions for Rotting Oranges.
    int lt0994a(vector<vector<int>>& grid)
    {
        bool rot = true;
        int ans = 2;
        while (rot)
        {
            rot = false;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[0].size(); j++)
                {
                    if (grid[i][j] == ans)
//                        if (rottinga1(grid, i + 1, j, ans) || rottinga1(grid, i - 1, j, ans) || rottinga1(grid, i, j + 1, ans) || rottinga1(grid, i, j - 1, ans))     // 短路了。。
                    {
//                        rot = rottinga1(grid, i + 1, j, ans) | rottinga1(grid, i - 1, j, ans) | rottinga1(grid, i, j + 1, ans) | rottinga1(grid, i, j - 1, ans);      // 这个好像也会短路。。？ 不短路， | 的问题。。但是| 好像也没问题。。
//                        bool b1 = rottinga1(grid, i + 1, j, ans);
//                        bool b2 = rottinga1(grid, i - 1, j, ans);
//                        bool b3 = rottinga1(grid, i, j + 1, ans);
//                        bool b4 = rottinga1(grid, i, j - 1, ans);
//                        cout<<b1<<", "<<b2<<", "<<b3<<", "<<b4<<endl;
//                        rot = b1 || b2 || b3 || b4;


                        rot = rottinga1(grid, i + 1, j, ans) || rot;        // 这4行是正确的。
                        rot = rottinga1(grid, i - 1, j, ans) || rot;
                        rot = rottinga1(grid, i, j + 1, ans) || rot;
                        rot = rottinga1(grid, i, j - 1, ans) || rot;

//                        bool b1 = rottinga1(grid, i + 1, j, ans);
//                        bool b2 = rottinga1(grid, i - 1, j, ans);
//                        bool b3 = rottinga1(grid, i, j + 1, ans);
//                        bool b4 = rottinga1(grid, i, j - 1, ans);
//                        cout<<b1<<" "<<b2<<" "<<b3<<" "<<b4<<endl;
//                        rot = b1 || b2 || b3 || b4;                   // .... 这种写法 只和 最后一次循环有关。。 应该要加上 || rot......


                    }
                }
            }
            #ifdef __test
            cout<<rot<<endl;
            #endif // __test

            if (rot)
                ans++;
        }

//        #ifdef __test
//        for (vector<int>& c : grid)
//        {
//            for_each(begin(c), end(c), fun_cout);
//            cout<<endl;
//        }
//        #endif // __test

        for (vector<int>& v : grid)
        {
            for (int& i : v)
            {
                if (i == 1)
                    return -1;
            }
        }

        return ans - 2;
    }

    bool rottinga1(vector<vector<int>>& grid, int i, int j, int ans)
    {
        times++;

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;

//        #ifdef __test
//        cout<<" .  "<<i<<", "<<j<<", "<<grid[i][j]<<endl;
//        #endif // __test

        if (grid[i][j] == 1)
        {
            grid[i][j] = ans + 1;
            return true;
        }
        return false;
    }

//    void dfsa1(vector<vector<int>>& grid, int cnt, int i, int j)
//    {
//        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
//            return;
//        if (grid[i][j] == 1)
//        {
//
//        }
//    }



    // test
    void test2()
    {
        bool ans = false;
        for (int i = 0; i < 10; i++)
        {
            ans = false;
//            ans = test3(i) || test3(i + 1) || test3(i + 2) || test3(i + 3);         // 15
//            ans = test3(i) | test3(i + 1) | test3(i + 2) | test3(i + 3);        // 40

            ans = test3(i) || ans;
            ans = test3(i + 1) || ans;
            ans = test3(i + 2) || ans;
            ans = test3(i + 3) || ans;          // 40

        }

    }

    bool test3(int n)
    {
        times++;
        if (n % 2 == 0)
            return true;
        return false;
    }

    void test5()
    {
        bool b1 = false | false | false | false;
        bool b2 = true || false || false || true;

        cout<<b1<<" : "<<b2<<endl;
    }

};

int main()
{

    vector<vector<int>> g = {{2,1,1},{1,1,0},{0,1,1}};
//    vector<vector<int>> g = {{2,1,1},{0,1,1},{1,0,1}};
//    vector<vector<int>> g ={{0, 2}};

    LT0994 lt;

    cout<<lt.lt0994a(g)<<endl;
    cout<<lt.times<<endl;

//    lt.test2();
//    cout<<lt.times<<endl;

//    lt.test5();

    return 0;
}
