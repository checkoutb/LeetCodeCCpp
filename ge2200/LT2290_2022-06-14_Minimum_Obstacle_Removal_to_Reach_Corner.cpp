
#include "../header/myheader.h"

class LT2290
{
public:

    // D D

    //if (grid[nextR][nextC]) {
    //    dq.push_back({ nextR, nextC });
    //}
    //else {
    //    dq.push_front({ nextR, nextC });
    //}
    // deque<pair<int, int>> 优先遍历0

    //priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    //priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
    //q.push(pair<int, pair<int, int>>(0, pair<int, int>(0, 0)));
    // priq, 优先遍历路径短的。

    // 看下来，deque最快， priq 比 que 快一点。

    // Dijkstra



//Runtime: 1083 ms, faster than 55.19 % of C++ online submissions for Minimum Obstacle Removal to Reach Corner.
//Memory Usage : 161.4 MB, less than 25.26 % of C++ online submissions for Minimum Obstacle Removal to Reach Corner.
    int lt2290a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size(), sz2 = grid[0].size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));
        vvi[0][0] = 0;
        queue<pair<int, int>> que1;
        que1.push(make_pair(0, 0));
        int arr[5] = { 1,0,-1,0,1 };
        while (!que1.empty())
        {
            for (int i = 0, mxi = que1.size(); i < mxi; ++i)
            {
                pair<int, int> p = que1.front();
                que1.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int x = p.first + arr[i];
                    int y = p.second + arr[i + 1];
                    if (x >= 0 && y >= 0 && x < sz1 && y < sz2 && vvi[x][y] > vvi[p.first][p.second] + (grid[x][y] == 1))
                    {
                        que1.push({ x,y });
                        vvi[x][y] = vvi[p.first][p.second] + (grid[x][y] == 1);
                    }
                }
            }
#ifdef __test
            //cout << que1.size() << endl;
#endif
        }
        return vvi[sz1 - 1][sz2 - 1];
    }

};

int main()
{

    LT2290 lt;

    //myvvi vv = { {0,1,1},{1,1,0},{1,1,0} };

    myvvi vv = { {0,1,0,0,0}, {0,1,0,1,0},{0,0,0,1,0} };

    cout << lt.lt2290a(vv) << endl;

    return 0;
}
