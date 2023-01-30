
#include "../header/myheader.h"

class LT2503
{
public:


    // D D

    // priq




    //Runtime1117 ms
    //    Beats
    //    24.21 %
    //    Memory47.3 MB
    //    Beats
    //    55.54 %
    vector<int> lt2503a(vector<vector<int>>& grid, vector<int>& queries)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        int szq = queries.size();

        const int MOD = 10000;
        queue<int> que1;
        que1.push(0);

        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));
        vvi[0][0] = grid[0][0];

        int arr[] = { 1,0,-1,0,1 };
        int r, c, nr, nc;
        while (!que1.empty())
        {
            c = que1.front();
            que1.pop();
            r = c / MOD;
            c = c % MOD;

            for (int i = 0; i < 4; ++i)
            {
                nr = r + arr[i];
                nc = c + arr[i + 1];
                if (nr >= 0 && nr < sz1 && nc >= 0 && nc < sz2 && vvi[nr][nc] > vvi[r][c])
                {
                    if (vvi[nr][nc] <= max(vvi[r][c], grid[nr][nc]))
                    {
                        ;
                    }
                    else
                    {
                        vvi[nr][nc] = max(vvi[r][c], grid[nr][nc]);
                        que1.push(nr * MOD + nc);
                    }

                    //if (vvi[r][c] > grid[nr][nc])
                    //{
                    //    vvi[nr][nc] = vvi[r][c];
                    //    que1.push(nr * MOD + nc);
                    //}
                    //else
                    //{
                    //    if (vvi[nr][nc] == INT_MAX)
                    //    {
                    //        vvi[nr][nc] = grid[nr][nc];
                    //        que1.push(nr * MOD + ne);
                    //    }
                    //}
                }
            }

        }

        map<int, int> map2;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                map2[vvi[i][j]]++;
            }
        }

        int t2 = 0;
        for (auto& p : map2)
        {
            t2 += p.second;
            p.second = t2;
        }

        vector<int> ans(szq);

        for (int i = 0; i < szq; ++i)
        {
            auto it = map2.lower_bound(queries[i]);
            if (it == map2.begin())
            {
                ans[i] = 0;
            }
            else if (it == map2.end())
            {
                ans[i] = map2.rbegin()->second;
            }
            else
            {
                ans[i] = prev(it)->second;
            }
        }

        return ans;
    }

};

int main()
{

    LT2503 lt;

    myvvi vv = { {1,2,3},{2,5,7},{3,5,1} };
    myvi q = { 5,6,2,0,11 };

    myvi v2 = lt.lt2503a(vv, q);

    showVectorInt(v2);

    return 0;
}
