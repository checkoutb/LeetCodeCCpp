
#include "../header/myheader.h"

class LT0778
{
public:


// discuss
//                    if (i < N-1 && grid[i+1][j]<=time) uf.union(i*N+j, i*N+j+N);
//                    if (j < N-1 && grid[i][j+1]<=time) uf.union(i*N+j, i*N+j+1);
// union-find。。。


//grid[i][j] is a permutation of [0, ..., N*N - 1].
// 。。。。。。。。。。。。。。。。 所以他们二分。。。
// bfs搜索是否能swim。queue保存pair保存下标。，vector<vector>保存是否被访问。



// 还是题目没完整了解，特别是dfs是4个方向的，lt0778a的时候只有右/下2个方向。特别是第二个例子就显示了会向左。。还有就是dfs应该return什么。

//Runtime: 20 ms, faster than 92.45% of C++ online submissions for Swim in Rising Water.
//Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Swim in Rising Water.
    int lt0778b(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int ans = max(grid[0][0], grid[sz1 - 1][sz1 - 1]);
        int t1 = ans;
        while (grid[sz1 - 1][sz1 - 1] >= 0)
        {
            ans = t1;
            t1 = dfsb1(grid, ans, 0, 0);
        }
        return ans;
    }

    int dfsb1(vector<vector<int>>& grid, int depth, int row, int col)
    {
        if (row >= grid.size() || col >= grid.size())
            return INT_MAX;
        if (grid[row][col] == (-depth))
            return INT_MAX;
        if (grid[row][col] > depth)
            return grid[row][col];

        grid[row][col] = -depth;

        int ans = std::min(dfsb1(grid, depth, row, col + 1), dfsb1(grid, depth, row, col - 1));
        ans = std::min(ans, dfsb1(grid, depth, row - 1, col));
        ans = std::min(ans, dfsb1(grid, depth, row + 1, col));
        return ans;
    }


    // error
    int lt0778a(vector<vector<int>>& grid)
    {
//        int ans = grid[grid.size() - 1][grid.size() - 1];
        int ans = 1;
        int t1 = max(grid[0][0], grid[grid.size() - 1][grid.size() - 1]) - 1;
        int t2 = t1;
        ans = t2;
        do
        {
            ans = t2;
            t2 = t1;
            t1 = dfsa1(grid, 0, 0, ans);
//            ans = std::abs(t1);
            cout<<ans<<", "<<t1<<",  "<<grid[grid.size() - 1][grid.size() - 1]<<endl;
            getchar();

        } while (grid[grid.size() - 1][grid.size() - 1] >= 0);
        return ans;
    }

    int dfsa1(vector<vector<int>>& grid, int row, int col, int depth)
    {

//    cout<<row<<" : "<<col<<endl;
//    getchar();

        if (row >= grid.size() || col >= grid.size())
            return INT_MAX;

        if (grid[row][col] == (-depth))
            return INT_MAX;
        if (grid[row][col] > depth)
            return grid[row][col];

        int ans = std::abs(grid[row][col]);
        grid[row][col] = -depth;

//        ans = std::min(grid[row][col], dfsa1(grid, row, col + 1, depth));
//        ans = std::min(ans, std::min(dfsa1(grid, row + 1, col, depth), dfsa1(grid, row + 1, col, depth)));

        ans = std::min(dfsa1(grid, row + 1, col, depth), dfsa1(grid, row, col + 1, depth));

//        cout<<ans<<" . "<<endl;

//        getchar();

        return ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{0,2},{1,3}};

    vector<vector<int>> vv = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};

    LT0778 lt;

    cout<<lt.lt0778b(vv)<<endl;

    return 0;
}
