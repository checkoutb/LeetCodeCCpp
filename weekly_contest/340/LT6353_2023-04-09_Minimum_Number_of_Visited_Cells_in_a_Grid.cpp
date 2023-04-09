
#include "../../header/myheader.h"

class LT6353
{
public:

    // D

    // ... BIT,计算前面的 最小值。


    // 832 / 16666	Ouha 	18	1:56:12	0:06:41 1	0:18:21 	0:29:41 	1:26:12 5
    // 。。第四道错了5次。
    // 333	Ouha  	18	1:56:12	0:06:41 1	0:18:21 	0:29:41 	1:26:12 5

    // 可惜，最开始选择 dfs，错了好几次。。
    // 11:55 AC 。 艹。
    int ltc(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));
        vector<int> mxr(sz2, -1);
        vector<int> mxc(sz1, -1);

        queue<pair<int, int>> que1;
        que1.push({ 0,0 });
        vvi[0][0] = 1;
        while (!que1.empty())
        {
            pair<int, int> p = que1.front();
            int r = p.first;
            int c = p.second;

#ifdef __test
            cout << r << " - " << c << endl;

            if (r == 3)
            {
                cout << "dd" << endl;
            }

#endif

            if (r == sz1 - 1 && c == sz2 - 1)
                break;

            que1.pop();
            int stp = vvi[r][c] + 1;
            int i = max(mxr[c] + 1, r + 1);
            int mxi = min(sz1 - 1, r + grid[r][c]);
            mxr[c] = max(mxi, mxr[c]);
            for (; i <= mxi; ++i)
            {
                if (stp < vvi[i][c])                // 不加这个， 是4， 但是无法理解，我都bfs了，怎么可能会变小。 而且就算变小，还是会计算一次的啊。 我把 r==sz1 c==sz2 删除后，还是4， 所以加了这个。 AC了，但不清楚哪一步有问题
                {

                    que1.push(std::make_pair(i, c));
                    vvi[i][c] = stp;
                }
            }

            int j = max(mxc[r] + 1, c + 1);
            int mxj = min(sz2 - 1, c + grid[r][c]);
            mxc[r] = max(mxj, mxc[r]);
            for (; j <= mxj; ++j)
            {
                if (stp < vvi[r][j])
                {

                    que1.push(std::make_pair(r, j));
                    vvi[r][j] = stp;
                }
            }

        }
        return vvi[sz1 - 1][sz2 - 1] == INT_MAX ? -1 : vvi[sz1 - 1][sz2 - 1];
    }


    // tle
    int ltb(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        
        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));
        vector<int> mxr(sz2, -1);
        vector<int> mxc(sz1, -1);
        dfsb1(grid, vvi, 1, 0, 0, mxr, mxc);

        return vvi[sz1 - 1][sz2 - 1] == INT_MAX ? -1 : vvi[sz1 - 1][sz2 - 1];
    }

    void dfsb1(vector<vector<int>>& gd, vector<vector<int>>& vvi, 
        int stp, int r, int c, vector<int>& mxr, vector<int>& mxc)
    {
        //if (r >= vvi.size() || c >= vvi[0].size())
        //    return;

        //if (stp >= vvi[r][c])
        //    return;

        vvi[r][c] = stp;

#ifdef __test
        cout << r << " - " << c << " : " << stp << endl;
#endif

        //for (int i = r + 1; i < vvi.size() && i <= r + gd[r][c]; ++i)
        for (int i = min(int(vvi.size()) - 1, r + gd[r][c]); i > r; --i)
        {
            if (stp + 1 < vvi[i][c])
                dfsb1(gd, vvi, stp + 1, i, c, mxr, mxc);
        }
        //for (int j = c + 1; j < vvi[0].size() && j <= c + gd[r][c]; ++j)
        for (int j = min(int(vvi[0].size()) - 1, c + gd[r][c]); j > c; --j)
        {
            if (stp + 1 < vvi[r][j])
                dfsb1(gd, vvi, stp + 1, r, j, mxr, mxc);
        }


        //if (r + gd[r][c] > mxr[c] && mxr[c] < int(vvi.size()) - 1)
        //{
        //    int i = mxr[c] + 1;
        //    mxr[c] = r + gd[r][c];
        //    int sz1 = min(int(vvi.size()), int(mxr[c] + 1));
        //    for (; i < sz1; ++i)
        //    {
        //        dfsb1(gd, vvi, stp + 1, i, c, mxr, mxc);
        //    }
        //}

        //if (c + gd[r][c] > mxc[r] && mxc[r] < int(vvi[0].size()) - 1)
        //{
        //    int j = mxc[r] + 1;
        //    mxc[r] = c + gd[r][c];
        //    int sz2 = min(mxc[r] + 1, int(vvi[0].size()));
        //    for (; j < sz2; ++j)
        //    {
        //        dfsb1(gd, vvi, stp + 1, r, j, mxr, mxc);
        //    }
        //}

    }



    // error ， 这个范围内的。。。。
    // 移动 vvi[][] 步
    int lta(vector<vector<int>>& grid) {

        int sz1 = grid.size();
        int sz2 = grid[0].size();
        int ans = -1;

        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));

        dfsa1(vvi, 1, 0, 0, grid);
        
        ans = vvi[sz1 - 1][sz2 - 1] == INT_MAX ? -1 : vvi[sz1 - 1][sz2 - 1];

        return ans;
    }

    // stp, 到达这个点，已经用了几步。
    void dfsa1(vector<vector<int>>& vvi, int stp, int r, int c, vector<vector<int>>& grid)
    {
        if (r >= vvi.size() || c >= vvi[0].size())
            return;
        if (stp >= vvi[r][c])
            return;

        vvi[r][c] = stp;

        dfsa1(vvi, stp + 1, r + grid[r][c], c, grid);

        dfsa1(vvi, stp + 1, r, c + grid[r][c], grid);
    }

};

int main()
{

    LT6353 lt;

    //myvvi vv = { {3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0} };

    // 3
    myvvi vv = {{7, 12, 11, 11, 4
            }, { 10, 5, 16, 15, 7
            }, { 7, 9, 6, 16, 7
            }, { 1, 13, 3, 16, 0
            }};


    cout << lt.ltc(vv) << endl;

    return 0;
}
