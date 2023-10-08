
#include "../header/myheader.h"

class LT2830
{
public:

// D D

//        vector<int> dp(n + 1);
//        vector<vector<vector<int>>> m(n);
//        for (auto& a : offers) {
//            m[a[1]].push_back(a);
//        }
//        for (int e = 1; e <= n; e++) {
//            dp[e] = dp[e - 1];
//            for (auto& a : m[e - 1]) {
//                dp[e] = max(dp[e], dp[a[0]] + a[2]);
//            }
//        }
//        return dp[n];





//Runtime342 ms
//Beats
//97.15%
//Memory94.6 MB
//Beats
//97.18%
    // [st, en, gold]
    int maximizeTheProfit(int n, vector<vector<int>>& offers)
    {
        sort(begin(offers), end(offers), [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] < v2[1];
        });

        vector<int> vi(n, 0);
        int idx = 0;
        int st, en, gd;
        for (int i = 0; i < n; ++i)
        {
            vi[i] = i == 0 ? 0 : vi[i - 1];

            while (idx < offers.size() && offers[idx][1] == i)
            {
                st = offers[idx][0];
//                en = offers[idx][1];
                gd = offers[idx][2];
                vi[i] = max(vi[i], gd + (st == 0 ? 0 : vi[st - 1]));
                ++idx;
            }

            if (idx == offers.size())
            {
                return vi[i];
            }
        }
        return vi[vi.size() - 1];
    }

};

int main()
{

    LT2830 lt;

    int n = 5;
    myvvi vv = {{0,0,1},{0,2,2},{1,3,2}};

    cout<<lt.maximizeTheProfit(n, vv)<<endl;

    return 0;
}
