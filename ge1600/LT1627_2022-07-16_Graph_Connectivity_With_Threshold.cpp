
#include "../header/myheader.h"

class LT1627
{
public:

    // D D

    //for (int i = k + 1; i <= n; i++) {
    //    for (int j = 2; i * j <= n; j++) {
    //        dsu.uni(i * (j - 1), i * j);
    //    }
    //}


    //for (int i = threshold + 1; 2 * i <= n; ++i) {
    //    if (ds[i] != -1)
    //        continue;
    //    int p1 = i;
    //    for (int j = 2 * i; j <= n; j += i) {
    //        int p2 = find(ds, j);
    //        if (p1 != p2) {
    //            if (ds[p1] > ds[p2])
    //                swap(p1, p2);
    //            ds[p1] += ds[p2];
    //            ds[p2] = p1;
    //        }
    //    }
    //}



//Runtime: 418 ms, faster than 19.94 % of C++ online submissions for Graph Connectivity With Threshold.
//Memory Usage : 65.2 MB, less than 85.84 % of C++ online submissions for Graph Connectivity With Threshold.
    vector<bool> lt1627a(int n, int threshold, vector<vector<int>>& queries)
    {
        int sz1 = queries.size();
        vector<int> uf(n + 1, -1);
        vector<bool> ans(sz1, false);
        for (int i = threshold + 1; i * 2 <= n; ++i)
        {
            int tp = ufa(uf, i);

            for (int j = i + i; j <= n; j += i)
            {
                int tp2 = ufa(uf, j);
                if (tp != tp2)
                {
                    uf[tp2] = tp;
                }
            }
        }

        for (int i = 0; i < sz1; ++i)
        {
            int tp = ufa(uf, queries[i][0]);
            int tp2 = ufa(uf, queries[i][1]);
            if (tp == tp2)
                ans[i] = true;
        }

        return ans;
    }

    int ufa(vector<int>& uf, int idx)
    {
        return uf[idx] == -1 ? idx : (uf[idx] = ufa(uf, uf[idx]));
    }

};

int main()
{

    LT1627 lt;

    //int n = 5;
    //int t = 0;
    //myvvi vv = { {4,5},{4,5},{3,2},{2,3},{3,4} };

    int n = 6;
    int t = 2;
    myvvi vv = { {1,4},{2,5},{3,6} };

    vector<bool> ans = lt.lt1627a(n, t, vv);

    for (bool b : ans)
    {
        cout << b << ", ";
    }
    cout << endl;

    return 0;
}
