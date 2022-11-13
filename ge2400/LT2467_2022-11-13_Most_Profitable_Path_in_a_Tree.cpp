
#include "../header/myheader.h"

class LT2467
{
public:

    // D D




    //RuntimeN / A
    //    Beats
    //    N / A
    //    MemoryN / A
    //    Beats
    //    N / A
    int lt2467a(vector<vector<int>>& edges, int bob, vector<int>& amount)
    {
        int sz1 = amount.size();
        vector<int> vp(sz1);        // vector parent
        vp[0] = -1;

        vector<vector<int>> chd(sz1);
        for (vector<int>& vi : edges)
        {
            chd[vi[0]].push_back(vi[1]);
            chd[vi[1]].push_back(vi[0]);
        }

        dfsa1(vp, -1, 0, chd);

        int len = 0;
        int t2 = bob;
        while (t2 != -1)
        {
            t2 = vp[t2];
            ++len;
        }
        t2 = bob;
        for (int i = 0; i < len / 2; ++i)
        {
            amount[t2] = 0;
            t2 = vp[t2];
        }
        if (len % 2)
        {
            amount[t2] /= 2;
        }

        int ans = dfsa2(chd, -1, 0, 0, amount);
        return ans;
    }

    int dfsa2(vector<vector<int>>& chd, int parent, int node, int sum2, vector<int>& amnt)
    {
        sum2 += amnt[node];
        int ans = INT_MIN;
        bool b2 = false;
        for (int ch2 : chd[node])
        {
            if (ch2 != parent)
            {
                b2 = true;
                ans = max(ans, dfsa2(chd, node, ch2, sum2, amnt));
            }
        }
        if (!b2)
        {
            //ans = amnt[node];
            ans = sum2;
        }
        return ans;
    }

    void dfsa1(vector<int>& vp, int parent, int node, vector<vector<int>>& chd)
    {
        vp[node] = parent;
        for (int chd2 : chd[node])
        {
            if (chd2 != parent)
            {
                dfsa1(vp, node, chd2, chd);
            }
        }
    }

};

int main()
{

    LT2467 lt;

    //myvvi vv = { {0,1},{1,2},{1,3},{3,4} };
    //int b = 3;
    //myvi v = { -2,4,2,-4,6 };

    myvvi vv = { {1,0} };
    int b = 1;
    myvi v = { -5555, 123 };

    cout << lt.lt2467a(vv, b, v);

    return 0;
}
