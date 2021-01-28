
#include "../header/myheader.h"

class LT1559
{
public:

// D D

// BFS DFS

//        int n = grid.size(), m = grid[0].size();
//        vector<vector<bool>> visited(n, vector<bool>(m, false));
//        for(int i = 0; i < n; ++i)
//            for(int j = 0; j < m; ++j)
//                if(!visited[i][j] && isCyclic(grid, visited, i, j, -1, -1))
//                    return true;
//        return false;
//
//        visited[i][j] = true;
//        for(int d = 0; d < 4; ++d)
//        {
//            int a = i+dir[d];
//            int b = j+dir[d+1];
//            if(a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == grid[i][j] && !(x == a && y == b))
//                if(visited[a][b] || isCyclic(grid, visited, a,b,i,j))
//                    return true;
//        }
//        return false;


//    for (int i = 0; i < g.size(); ++i)
//        for (int j = 0; j < g[i].size(); ++j) {
//            if (g[i][j] >= 'a') {
//                char val = g[i][j];
//                vector<pair<int, int>> q = {{i, j}};
//                while (!q.empty()) {
//                    vector<pair<int, int>> q1;
//                    for (auto [x, y] : q) {
//                        if (g[x][y] < 'a')
//                            return true;
//                        g[x][y] -= 26;
//                        for (auto k = 0; k < 4; ++k) {
//                            int dx = x + d[k], dy = y + d[k + 1];
//                            if (dx >= 0 && dy >= 0 && dx < g.size() && dy < g[dx].size() && g[dx][dy] == val)
//                                q1.push_back({dx, dy});
//                        }
//                    }
//                    swap(q, q1);
//                }
//            }
//        }



//Runtime: 436 ms, faster than 67.11% of C++ online submissions for Detect Cycles in 2D Grid.
//Memory Usage: 51.9 MB, less than 95.11% of C++ online submissions for Detect Cycles in 2D Grid.
    bool lt1559b(vector<vector<char>>& grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (std::isalpha(grid[i][j]))
                {
                    char ch = grid[i][j];
                    #ifdef __test
                    cout<<"st : "<<i<<", "<<j<<", "<<ch<<endl;
                    #endif // __test
                    grid[i][j] = '1';
                    for (int k = 0; k < 4; ++k)
                    {
                        if (dfsb1(grid, i + arr[k][0], j + arr[k][1], 3 - k, ch))
                            return true;
                    }
                    grid[i][j] = '2';
                }
            }
        }
        return false;
    }
    int arr[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    bool dfsb1(vector<vector<char>>& g, int i, int j, int pre, char ch)
    {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size())
            return false;
        #ifdef __test
        cout<<i<<", "<<j<<", "<<ch<<", "<<g[i][j]<<endl;
        #endif // __test
        if (g[i][j] == '1')
            return true;
        if (g[i][j] != ch)
            return false;
        g[i][j] = '1';
        bool ans = false;
        for (int k = 0; k < 4; ++k)
        {
            if (k != pre)
            {
                ans = dfsb1(g, i + arr[k][0], j + arr[k][1], 3 - k, ch);
                if (ans)
                    break;
            }
        }
        g[i][j] = '2';
        return ans;
    }


// error
    bool lt1559a(vector<vector<char>>& grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (std::isalpha(grid[i][j]))
                {
                    char ch = grid[i][j];
                    grid[i][j] = '2';
                    if (dfsa1(grid, ch, i, j + 1, 0))
                        return true;
                    if (dfsa1(grid, ch, i, j - 1, 0))
                        return true;
                    if (dfsa1(grid, ch, i + 1, j, 0))
                        return true;
                    if (dfsa1(grid, ch, i - 1, j, 0))
                        return true;
                    grid[i][j] = '1';
                }
            }
        }
        return false;
    }

    bool dfsa1(vector<vector<char>>& g, char ch, int i, int j, int len)
    {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size())
            return false;
        #ifdef __test
        cout<<i<<", "<<j<<", "<<ch<<", "<<g[i][j]<<endl;
        #endif // __test
        len++;
        if (g[i][j] == '2')         // 2 is the begin
            return len > 2;
        if (g[i][j] != ch)
            return false;
        g[i][j] = '1';      // visited
        if (dfsa1(g, ch, i, j + 1, len))
            return true;
        if (dfsa1(g, ch, i, j - 1, len))
            return true;
        if (dfsa1(g, ch, i + 1, j, len))
            return true;
//        if (dfsa1(g, ch, i - 1, j))
//            return true;
        return dfsa1(g, ch, i - 1, j, len);
    }

};

int main()
{
//    vector<vector<char>> vvc = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    vector<vector<char>> vvc = {{'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}};
//    vector<vector<char>> vvc = {
//        {'a','b','b'},
//        {'b','z','b'},
//        {'b','b','a'}};
//    vector<vector<char>> vvc = {
//        {'c','a','d'},
//        {'a','a','a'},
//        {'a','a','d'},
//        {'a','c','d'},
//        {'a','b','c'}};

    LT1559 lt;

    cout<<lt.lt1559b(vvc)<<endl;

    return 0;
}
