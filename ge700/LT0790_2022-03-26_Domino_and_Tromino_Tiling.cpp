
#include "../header/myheader.h"

class LT0790
{
public:

// D D


//    v[1]=1;
//    v[2]=2;
//    v[3]=5;
//    if(N<=3)
//        return v[N];
//    for(int i=4;i<=N;++i){
//        v[i]=2*v[i-1]+v[i-3];
//        v[i]%=md;
//    }


//dp[n]=dp[n-1]+dp[n-2]+ 2*(dp[n-3]+...+d[0])
//=dp[n-1]+dp[n-2]+dp[n-3]+dp[n-3]+2*(dp[n-4]+...+d[0])
//=dp[n-1]+dp[n-3]+(dp[n-2]+dp[n-3]+2*(dp[n-4]+...+d[0]))
//=dp[n-1]+dp[n-3]+dp[n-1]
//=2*dp[n-1]+dp[n-3]




//Runtime: 11 ms, faster than 15.70% of C++ online submissions for Domino and Tromino Tiling.
//Memory Usage: 7.4 MB, less than 18.09% of C++ online submissions for Domino and Tromino Tiling.
    int lt0790a(int n)
    {
        vector<vector<int>> vvi(n, vector<int>(3, 0));      // 0: 上， 1：都有，2：下
//        vai[0][1] = 1;
//        vai[]
        const int MOD = 1E9 + 7;
        for (int i = 0; i < n; ++i)
        {
            int t2 = i - 2;
            if (t2 < 0)
            {
                if (t2 == -2)
                {
                    vvi[i][1] = 1;  // vvi[0][1]
                }
                else if (t2 == -1)
                {
                    vvi[i][1] = 2;
                    vvi[i][0] = 1;
                    vvi[i][2] = 1;
                }
            }
            else
            {
                vvi[i][1] = ((vvi[i - 1][1] + vvi[i - 1][0]) % MOD + vvi[i - 1][2]) % MOD + vvi[i - 2][1];
                vvi[i][1] %= MOD;
                vvi[i][0] = vvi[i - 2][1] + vvi[i - 1][2];
                vvi[i][2] = vvi[i - 2][1] + vvi[i - 1][0];
                vvi[i][0] %= MOD;
                vvi[i][2] %= MOD;
            }
        }
        return vvi[n - 1][1];
    }

};

int main()
{

    LT0790 lt;

//    int n = 3;
    int n = 1;

    cout<<lt.lt0790a(n)<<endl;

    return 0;
}
