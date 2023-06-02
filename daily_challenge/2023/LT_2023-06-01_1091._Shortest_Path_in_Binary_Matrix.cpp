
#include "../../header/myheader.h"

class LT
{
public:



    // // Dijkstra!!!
    // int ltb(vector<vector<int>>& grid)
    // {
    //     int sz1 = grid.size();
    //     if (grid[0][0] != 0 || grid[sz1 - 1][sz1 - 1] != 0)
    //         return -1;
    //     priority_queue<pair<int, int>> priq;
    // }

// D D

// queue is enough. level order, first meet is min length



// Runtime106 ms
// Beats
// 33.90%
// Memory19.2 MB
// Beats
// 85.79%
    // priq default is max-heap ... 
    // tle
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        if (grid[0][0] != 0 || grid[sz1 - 1][sz1 - 1] != 0)
            return -1;
        int ans = -1;
        vector<vector<int>> vvi(sz1, vector<int>(sz1 , INT_MAX));
        vvi[0][0] = 1;
        //priority_queue<pair<int, pair<int, int>>> priq;
        //priority_queue<pair<int, int>> priq;    // <path length, i*1000+j>
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> priq;
        priq.push(std::make_pair(1, 0));
        int arri[] = {-1,-1,-1,0,1,1,1,0};
        int arrj[] = {-1,0,1,1,1,0,-1,-1};
        while (!priq.empty())
        {
            int len = priq.top().first;
            int i = priq.top().second;
            priq.pop();
            int j = i % 1000;
            i /= 1000;

            if (i == sz1 - 1 && j == sz1 - 1)        // error
                return len;

            for (int m = 0; m < 8; ++m)
            {
                if (shouldGo(grid, vvi, i + arri[m], j + arrj[m], len + 1))
                {
                    vvi[i + arri[m]][j + arrj[m]] = len + 1;
                    priq.push(std::make_pair(len + 1, 1000 * (i + arri[m]) + j + arrj[m]));
                }
            }
        }

        return vvi[sz1 - 1][sz1 - 1] == INT_MAX ? -1 : vvi[sz1 - 1][sz1 - 1];
    }

    bool shouldGo(vector<vector<int>>& grid, vector<vector<int>>& vvi, int i, int j, int len)
    {
        if (i < 0 || j < 0 || i == grid.size() || j == grid.size())
            return false;
        return grid[i][j] == 0 && vvi[i][j] > len;
    }
};

int main()
{

    LT lt;

    myvvi vv = {{0,0,0},{1,1,0},{1,1,0}};

    cout<<lt.shortestPathBinaryMatrix(vv)<<endl;

    return 0;
}
