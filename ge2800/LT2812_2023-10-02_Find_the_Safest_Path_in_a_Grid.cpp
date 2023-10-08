
#include "../header/myheader.h"

class LT2812
{
public:

// D D

// bfs + dijkstra(priq)



// ..too slow..

//Runtime2584 ms
//Beats
//5%
//Memory205.8 MB
//Beats
//36.60%
    // 16 00 00
    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, std::greater<>> priq;   // <distance, row, col>
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {
                if (grid[i][j] == 1)
                {
                    priq.push({0, i, j});
                    grid[i][j] = 0;
                }
                else
                {
                    grid[i][j] = INT_MAX;
                }
            }
        }
        vector<int> vi;
        int dis, r, c, nr, nc;
        int arr[] = {1,0,-1,0,1};
        while (!priq.empty())
        {
            vi = priq.top();
            dis = vi[0];
            r = vi[1];
            c = vi[2];
            priq.pop();

            for (int i = 1; i < 5; ++i)
            {
                int nr = r + arr[i];
                int nc = c + arr[i - 1];
                if (nr >= 0 && nc >= 0 && nr < sz1 && nc < sz1)
                {
                    if (grid[nr][nc] > dis + 1)
                    {
                        grid[nr][nc] = dis + 1;
                        priq.push({dis + 1, nr, nc});
                    }
                }
            }
        }

        priority_queue<vector<int>> priq2;
        priq2.push({grid[0][0], 0, 0});

        vector<vector<bool>> vvb(sz1, vector<bool>(sz1, false));
        vvb[0][0] = true;

        while (!priq2.empty())
        {
            vi = priq2.top();
            dis = vi[0];
            r = vi[1];
            c = vi[2];
            priq2.pop();
            if (dis == 0)
                return 0;

            if (r == sz1 - 1 && c == sz1 - 1)
                return dis;

            for (int i = 1; i < 5; ++i)
            {
                nr = r + arr[i];
                nc = c + arr[i - 1];
                if (nr >= 0 && nc >= 0 && nr < sz1 && nc < sz1 && !vvb[nr][nc])
                {
                    priq2.push({min(dis, grid[nr][nc]), nr, nc});
                    vvb[nr][nc] = true;
                }
            }
        }
        return -1;
    }

};

int main()
{

    LT2812 lt;


    return 0;
}
