
#include "../header/myheader.h"

class LT2258
{
public:

    // D D

    //int m = g.size(), n = g[0].size();
    //deque<pair<int, int>> fire, person({ {0, 0} });
    //for (int i = 0; i < m; ++i)
    //    for (int j = 0; j < n; ++j)
    //        if (g[i][j] == 1)
    //            fire.push_back({ i, j });
    //auto steps = [&](deque<pair<int, int>>& pos) {
    //    vector<vector<int>> st(m, vector<int>(n));
    //    while (!pos.empty()) {
    //        auto [i, j] = pos.front();
    //        pos.pop_front();
    //        for (auto [di, dj] : vector<pair<int, int>>{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} }) {
    //            int x = i + di, y = j + dj;
    //            if (min(x, y) >= 0 && x < m && y < n && g[x][y] == 0 && st[x][y] == 0) {
    //                st[x][y] = st[i][j] + 1;
    //                pos.push_back({ x, y });
    //            }
    //        }
    //    }
    //    return array<int, 3>{st[m - 1][n - 1], st[m - 2][n - 1], st[m - 1][n - 2]};
    //};
    //auto f = steps(fire), p = steps(person);
    //if (f[0] == 0 && p[0] != 0)
    //    return 1000000000;
    //if (int diff = f[0] - p[0]; p[0] != 0 && diff >= 0)
    //    return diff - (f[1] - p[1] <= diff && f[2] - p[2] <= diff);
    //return -1;





//Runtime: 79 ms, faster than 92.91 % of C++ online submissions for Escape the Spreading Fire.
//Memory Usage : 20.7 MB, less than 84.33 % of C++ online submissions for Escape the Spreading Fire.
    int lt2258a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        queue<pair<int, int>> que1;
        
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (grid[i][j] == 1)
                {
                    que1.push({ i, j });
                }
            }
        }

        int tm = 0;
        int arr[5] = { 1,0,-1,0,1 };
        while (!que1.empty())
        {
            tm--;
            for (int i = que1.size(); i > 0; --i)
            {
                pair<int, int> p = que1.front();
                int i2 = p.first;
                int j2 = p.second;
                que1.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int ni = i2 + arr[k];
                    int nj = j2 + arr[k + 1];
                    if (ni < 0 || nj < 0 || ni == sz1 || nj == sz2 || grid[ni][nj] != 0)
                    {
                        continue;
                    }
                    grid[ni][nj] = tm;
                    que1.push({ ni, nj });
                }
            }
        }

#ifdef __test
        for (myvi& vi : grid)
        {
            for (int i : vi)
                cout << i << ", ";
            cout << endl;
        }
#endif


        bool canReach = false;
        int ans = -1;

        que1.push({ 0,(int)1e9 });             // i * 1000 + j, min time gap

        const int MUL = 1000;
        unordered_map<int, int> map2;           // i * 1000 + j, min time
        map2[0] = 0;
        tm = 0;
        while (!que1.empty())
        {
            tm++;
            for (int i = que1.size(); i > 0; --i)
            {
                pair<int, int> p = que1.front();
                int i2 = p.first / MUL;
                int j2 = p.first % MUL;
                int tm2 = p.second;         // min time interval/gap
                que1.pop();
                if (ans != -1 && tm2 <= ans)
                    continue;
#ifdef __test
                cout << i2 << " - " << j2 << " ? " << tm2 << endl;
#endif

                if (i2 == sz1 - 1 && j2 == sz2 - 1)
                {
                    canReach = true;
                    ans = max(ans, tm2);
                    continue;
                }

                for (int k = 0; k < 4; ++k)
                {
                    int tm3 = tm2;                                      // ..
                    int ni = i2 + arr[k];
                    int nj = j2 + arr[k + 1];
                    if (ni < 0 || nj < 0 || ni == sz1 || nj == sz2 || grid[ni][nj] == 2)
                        continue;
                    if (grid[ni][nj] < 0 && tm > -grid[ni][nj])
                        continue;
                    if (grid[ni][nj] < 0 && tm == -grid[ni][nj] && ni != sz1 - 1 && nj != sz2 - 1)          // ..
                        continue;
                    if (map2.find(ni * MUL + nj) != map2.end() && map2[ni * MUL + nj] < tm)         // .. <= tm
                        continue;

                    tm3 = min(tm2, (grid[ni][nj] == 0 ? (int)1e9 : ( - grid[ni][nj] - tm - ((ni == sz1 - 1 && nj == sz2 - 1) ? 0 : 1))));       // ..
                    map2[ni * MUL + nj] = tm;
                    
#ifdef __test
                    cout << "              " << ni << ", " << nj << " --- " << tm << " ? " << tm2 << " --- " << grid[ni][nj] << " ... " << tm3 << endl;
#endif

                    que1.push({ ni * MUL + nj, tm3 });
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT2258 lt;

    //myvvi vv = { {0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0} };

    //myvvi vv = { {0,0,0,0},{0,1,2,0}, {0,2,0,0} };

    //myvvi vv = { {0,0,0},{2,2,0},{1,2,0} };

    //myvvi vv = { {0,2,0,0,1},{0,2,0,2,2},{0,2,0,0,0},{0,0,2,2,0},{0,0,0,0,0} };

    myvvi vv = { {0,2,1,0,0,0,0},{0,2,2,2,2,2,0},{0,2,0,0,0,0,0},{0,2,0,2,2,2,2},{0,2,0,0,0,0,0},{0,2,2,2,2,2,0},{0,2,0,0,0,0,0},{0,2,0,2,2,2,2},{0,0,0,0,0,0,0} };

    //myvvi vv = { {0,0,0,0,0,0},{0,2,2,2,2,0},{0,0,0,1,2,0},{0,2,2,2,2,0},{0,0,0,0,0,0} };


    cout << lt.lt2258a(vv) << endl;

    return 0;
}
