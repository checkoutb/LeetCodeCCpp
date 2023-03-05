
#include "../header/myheader.h"

class LT2585
{
public:

    // D D

    //vector<int> dp(target + 1);
    //dp[0] = 1;
    //int mod = 1e9 + 7;
    //for (auto& t : types)
    //    for (int i = target; i > 0; --i)
    //        for (int k = 1; k <= t[0] && i - t[1] * k >= 0; ++k)
    //            dp[i] = (dp[i] + dp[i - t[1] * k]) % mod;
    //return dp[target];

    //Note that dp[big] depends on dp[small],
    //    if you change dp[small]first, we need to update dp[big] from old dp[small].
    //        So here I iterative from dp[big] to dp[small].


    // Just found that ChatGPT can crack this question ...
    // ...



    // 但是， 我认为 vi[target] 是答案，但是 不是。 

    //Runtime237 ms
    //    Beats
    //    100 %
    //    Memory14.5 MB
    //    Beats
    //    33.33 %
    int lt2585a(int target, vector<vector<int>>& types)
    {
        vector<int> vi(target + 1, 0);
        vi[0] = 1;
        const int MOD = 1e9 + 7;

        int ans = 0;
        for (vector<int>& v2 : types)
        {
            vector<int> v3(target + 1, 0);
            for (int i = 0; i < target; ++i)
            {
                if (vi[i] != 0)
                {
                    for (int j = 1; j <= v2[0]; ++j)
                    {
                        if (j * v2[1] + i <= target)
                            v3[j * v2[1] + i] = (vi[i] + v3[j * v2[1] + i]) % MOD;
                        else
                            break;
                    }
                }
                v3[i] = (v3[i] + vi[i]) % MOD;
            }

#ifdef __test
            showVectorInt(vi);
            showVectorInt(v3);
            cout << " =========== " << endl;
#endif
            ans = (ans + v3[target]) % MOD;
            swap(vi, v3);
        }

        return ans;
        //return vi[target];
    }

};

int main()
{

    LT2585 lt;

    //int tar = 6;
    //myvvi vv = { {6,1},{3,2},{2,3} };

    int tar = 5;
    myvvi vv = { {50,1},{50,2},{50,5} };

    cout << lt.lt2585a(tar, vv) << endl;

    return 0;
}
