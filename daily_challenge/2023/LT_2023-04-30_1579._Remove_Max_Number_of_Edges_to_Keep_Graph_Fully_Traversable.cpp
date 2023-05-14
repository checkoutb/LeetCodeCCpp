
#include "../../header/myheader.h"

class LT
{
public:




    //Runtime1001 ms
    //    Beats
    //    9.6 %
    //    Memory137.9 MB
    //    Beats
    //    99.28 %
    int lta(int n, vector<vector<int>>& edges)
    {
        //vector<vector<pair<int, int>>> vp(n + 1);
        //for (int i = 0, mxi = edges.size(); i < mxi; ++i)
        //{
        //    vp[edges[i][1]].push_back(std::make_pair(edges[i][0], edges[i][2]));
        //    vp[edges[i][2]].push_back(std::make_pair(edges[i][0], edges[i][1]));
        //}
        //for (int i = 1; i <= n; ++i)
        //{
        //    sort(rbegin(vp[i]), rend(vp[i]));
        //}

        std::sort(std::rbegin(edges), std::rend(edges));

        vector<int> uf(n + 1, -1);
        int a, b;
        int i = 0;
        int mxi = edges.size();
        int ans = 0;    // edge used
        for (; i < mxi && edges[i][0] == 3; ++i)
        {
            a = ufa(uf, edges[i][1]);
            b = ufa(uf, edges[i][2]);
            if (a != b)
            {
                uf[a] = b;
                ++ans;
            }
        }

        vector<int> uf2(begin(uf), end(uf));

        // bob
        for (; i < mxi && edges[i][0] == 2; ++i)
        {
            a = ufa(uf2, edges[i][1]);
            b = ufa(uf2, edges[i][2]);
            if (a != b)
            {
                uf2[a] = b;
                ++ans;
            }
        }

        // alice
        for (; i < mxi; ++i)
        {
            a = ufa(uf, edges[i][1]);
            b = ufa(uf, edges[i][2]);
            if (a != b)
            {
                uf[a] = b;
                ++ans;
            }
        }

        a = ufa(uf, 1);
        b = ufa(uf2, 1);
        for (int i = 2; i <= n; ++i)
        {
            if (ufa(uf, i) != a || ufa(uf2, i) != b)
                return -1;
        }

        return mxi - ans;


        // 2 -> 3 -> 4 ..  uf[2] != uf[4]...  ufa(uf[2]) == ufa(uf[4])
        //a = ufa(uf, 1);
        //b = ufa(uf2, 1);

        //uf[0] = uf[a] = a;
        //uf2[0] = uf2[b] = b;

        //if (std::all_of(begin(uf), end(uf), [a](int i) {return i == a; })
        //    && std::all_of(begin(uf2), end(uf2), [b](int i) {return i == b; }))
        //{
        //    return mxi - ans;
        //}
        //return -1;
    }

    int ufa(vector<int>& uf, int idx)
    {
        return uf[idx] == -1 ? idx : (uf[idx] = ufa(uf, uf[idx]));
    }

};

int main()
{

    LT lt;

    int n = 4;
    //myvvi vv = { {3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4} };
    myvvi vv = { {3,2,3},{1,1,2},{2,3,4} };

    cout << lt.lta(n, vv) << endl;

    return 0;
}
