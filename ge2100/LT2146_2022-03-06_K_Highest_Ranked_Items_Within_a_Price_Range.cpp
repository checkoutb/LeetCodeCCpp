
#include "../header/myheader.h"

class LT2146
{
public:






// tle...
// bfs?
    vector<vector<int>> lt2146a(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k)
    {
//        queue<pair<int, int>> q;
        int sz1 = grid.size(), sz2 = grid[0].size();
        queue<vector<int>> q;       // path length, price, row, col
        q.push({0, 123, start[0], start[1]});
        vector<vector<int>> vvi;
        int len4 = -1;
        while (q.size() > 0)
        {
            vector<int> vi = q.front();
            q.pop();
            int ii = vi[2];
            int jj = vi[3];
//            if (ii < 0 || jj < 0 || ii == sz1 || jj == sz2 || grid[ii][jj] <= 0)
//                continue;

            vi[1] = grid[ii][jj];
            if (grid[ii][jj] >= pricing[0] && grid[ii][jj] <= pricing[1])
            {
                vvi.push_back(vi);
            }
            if (vvi.size() >= k)
            {
                if (len4 == -1)
                {
                    len4 = vi[0];
                }
                else
                {
                    if (vi[0] > len4)
                        break;
                }
            }

            grid[ii][jj] = -1;
            if (ii - 1 >= 0 && grid[ii - 1][jj] > 0)            // .. 这种更慢。。。
            {
                q.push({vi[0] + 1, 123, ii - 1, jj});
            }
            if (jj - 1 >= 0 && grid[ii][jj - 1] > 0)
                q.push({vi[0] + 1, 123, ii, jj - 1});
            if (jj + 1 < sz2 && grid[ii][jj + 1] > 0)
                q.push({vi[0] + 1, 123, ii, jj + 1});
            if (ii + 1 < sz1 && grid[ii + 1][jj] > 0)
                q.push({vi[0] + 1, 123, ii + 1, jj});
//            q.push({vi[0] + 1, 123, vi[2] - 1, vi[3]});
//            q.push({vi[0] + 1, 123, vi[2], vi[3] - 1});
//            q.push({vi[0] + 1, 123, vi[2], vi[3] + 1});
//            q.push({vi[0] + 1, 123, vi[2] + 1, vi[3]});
        }
        std::sort(begin(vvi), end(vvi));
        vector<vector<int>> ans(min((int) vvi.size(), k), vector<int>(2, 0));
        for (int i = 0; i < ans.size() && i < k; ++i)
        {
            ans[i][0] = vvi[i][2];
            ans[i][1] = vvi[i][3];
        }
        return ans;

//        q.push(make_pair(start[0], start[1]));
//        while (q.size() > 0)
//        {
//            pair<int, int> p = q.top();
//            q.pop();
//            int ii = p.first;
//            int jj = p.second;
//            if (ii < 0 || jj < 0 || ii == sz1 || j == sz2 || grid[ii][jj] < 0)
//            {
//                continue;
//            }
//            else if (grid[ii][jj] >= pricing[0] && grid[ii][jj] <= pricing[1])
//            {
//
//            }
//        }
    }

};

int main()
{

    LT2146 lt;

//    myvvi vv = {{1,2,0,1},{1,3,0,1},{0,2,5,1}};
//    myvi p = {2,5};
//    myvi st = {0,0};
//    int k = 3;

//    myvvi vv = {{1,2,0,1},{1,3,3,1},{0,2,5,1}};
//    myvi p = {2,3};
//    myvi st = {2,3};
//    int k = 2;

//    myvvi vv = {{1,1,1},{0,0,1},{2,3,4}};
//    myvi p = {2,3};
//    myvi st = {0,0};
//    int k = 3;


//[[4,2],[3,1],[5,1],[1,1]]
    myvvi vv = {{57,54,48},{652,572,990},{632,199,306},{38,702,263},{431,0,507},{673,570,750},{316,141,639}};
    myvi p = {475,745};
    myvi st = {3,2};
    int k = 4;

    myvvi vv2 = lt.lt2146a(vv, p, st, k);

    for (myvi& v : vv2)
    {
        cout<<v[0]<<" + "<<v[1]<<endl;
    }


    return 0;
}
