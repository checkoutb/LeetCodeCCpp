
#include "../header/myheader.h"

class LT2509
{
public:

    // D D

    //while (1) {
    //    if (v == u) {
    //        now += 1;
    //        break;
    //    }
    //    now += 1;
    //    if (u > v) {
    //        u /= 2;
    //    }
    //    else {
    //        v /= 2;
    //    }
    //}


    //for (int i = 0; i < m; ++i) {
    //    int x = queries[i][0], y = queries[i][1];
    //    while (x != y) {
    //        if (x > y)
    //            x /= 2;
    //        else
    //            y /= 2;
    //        res[i]++;
    //    }
    //}



    //Runtime239 ms
    //    Beats
    //    100 %
    //    Memory64.6 MB
    //    Beats
    //    100 %
    vector<int> lt2509b(int n, vector<vector<int>>& queries)
    {
        int szq = queries.size();
        vector<int> ans(szq);

        for (int i = 0; i < szq; ++i)
        {
            ans[i] = funb1(queries[i][1], queries[i][0]);
        }
        return ans;
    }

    inline int funb1(int a, int b)
    {
        int ans = 0;
        while (a != b)
        {
            if (a == 1)
            {
                ++ans;
                b >>= 1;
            }
            else if (b == 1)
            {
                ++ans;
                a >>= 1;
            }
            else
            {
                if (a < b)
                {
                    ++ans;
                    b >>= 1;
                }
                else
                {
                    ++ans;
                    a >>= 1;
                }
            }
        }
        return ans + 1;
    }

    // ... root 不一定是 cycle 的一环。。
    vector<int> lt2509a(int n, vector<vector<int>>& queries)
    {
        int szq = queries.size();
        vector<int> ans(szq);

        for (int i = 0; i < szq; ++i)
        {
            int a = queries[i][0];
            int b = queries[i][1];
            ans[i] = deptha1(a) + deptha1(b) - 1;
        }

        return ans;
    }

    inline int deptha1(int a)
    {
        int ans = 1;
        while (a != 1)
        {
            a >>= 1;
            ++ans;
        }
        return ans;
    }

};

int main()
{

    LT2509 lt;


    return 0;
}
