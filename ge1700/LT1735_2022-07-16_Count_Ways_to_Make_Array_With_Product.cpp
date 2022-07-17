
#include "../header/myheader.h"

class LT1735
{
public:

    // D

    // 分解到质因数，个数x
    // (x+n-1) C (n-1)   。 ？？？



    // g


    // tle。
    // 本地测试 {73，660} 都可以看到 速度慢。。。
    vector<int> lt1735a(vector<vector<int>>& queries)
    {
        const int MOD = 1e9 + 7;
        int sz1 = queries.size();
        vector<int> ans(sz1);

        unordered_map<int, unordered_map<int, int>> map2;

        for (int i = 0; i < sz1; ++i)
        {
            int sz3 = queries[i][0];
            int prd = queries[i][1];

            ans[i] = dfsa1(sz3, prd, map2);
        }

#ifdef __test
        for (auto& p : map2)
        {
            for (auto& p2 : p.second)
            {
                cout << p.first << " + " << p2.first << " -> " << p2.second << endl;
            }
        }
#endif

        return ans;
    }

    int dfsa1(int sz3, int prd, unordered_map<int, unordered_map<int, int>>& map2)
    {
#ifdef __test
        cout << sz3 << " - " << prd << endl;
#endif

        if (map2[sz3].find(prd) != map2[sz3].end())
            return map2[sz3][prd];

        if (prd == 1 || sz3 == 1)
            return 1;

        const int MOD = 1e9 + 7;
        int ans = 0;
        for (int i = 1; i * i <= prd; ++i)
        {
            if (prd % i == 0)
            {
                ans = (ans + dfsa1(sz3 - 1, prd / i, map2)) % MOD;
                if (i * i != prd)
                    ans = (ans + dfsa1(sz3 - 1, i, map2)) % MOD;
            }
        }
        map2[sz3][prd] = ans;
        return ans;
    }

};

int main()
{

    LT1735 lt;

    myvvi vv = { {2,6},{5,1},{73,660} };
    // myvvi vv = { {1,1},{2,2},{3,3},{4,4},{5,5} };
    //myvvi vv = { {3,3} };

    myvi v = lt.lt1735a(vv);

    showVectorInt(v);

    return 0;
}
