
#include "../../header/myheader.h"

class LT
{
public:




// Runtime
// 356ms
// Beats90.73%of users with C++
// Memory
// 115.75MB
// Beats96.80%of users with C++
    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        size_t sz1 {grid.size()};
        size_t sz2 {grid[0].size()};
        std::queue<pair<int, int>> que;
        for (size_t i = 0; i < sz1; ++i)
        {
            for (size_t j = 0; j < sz2; ++j)
            {
                if (grid[i][j])
                    que.push(std::make_pair(i, j));
            }
        }
        int arr[] = {1,0,-1,0,1};
        int ni = 0, nj = 0; // na, nb ..
        int a = 0, b = 0, c = 0;
        while (!que.empty())
        {
            for (int i = que.size(); i > 0; --i)
            {
                a = que.front().first;
                b = que.front().second;
                c = grid[a][b];
                que.pop();
                for (int j = 0; j < 4; ++j)
                {
                    // ni = que.front().first + arr[j];
                    // nj = que.front().second + arr[j + 1];
                    ni = a + arr[j];
                    nj = b + arr[j + 1];
                    if (ni >= 0 && nj >= 0 && ni < sz1 && nj < sz2 && grid[ni][nj] == 0)
                    {
                        grid[ni][nj] = c + 1;
                        que.push(std::make_pair(ni, nj));
                    }
                }
                // que.pop();
            }
        }

        std::priority_queue<tuple<int, int, int>> priq;
        int ans = grid[0][0];
        grid[0][0] = -1;    // visited or in priq
        if (sz2 > 1)        // ...
        {
            priq.push(std::make_tuple(grid[0][1], 0, 1));
            grid[0][1] = -1;
        }
        if (sz1 > 1)
        {
            priq.push(std::make_tuple(grid[1][0], 1, 0));
            grid[1][0] = -1;
        }

        while (!priq.empty())
        {
            std::tie(c,a,b) = priq.top();
            priq.pop();
            ans = min(ans, c);
            if (a == sz1 - 1 && b == sz2 - 1)
                break;
            for (int i = 0; i < 4; ++i)
            {
                ni = a + arr[i];
                nj = b + arr[i + 1];
                if (ni >= 0 && nj >= 0 && ni < sz1 && nj < sz2 && grid[ni][nj] != -1)
                {
                    priq.push(std::make_tuple(grid[ni][nj], ni, nj));
                    grid[ni][nj] = -1;
                }
            }
        }

        return ans - 1;
    }
};

int main()
{

    LT lt;


    return 0;
}
