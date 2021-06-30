
#include "../header/myheader.h"

class LT0920
{
public:





// 。。。。。
// A song can only be played again only if k other songs have been played
// 。。。在 k首其他歌 播放后， 才能重复。。。
// 并不是 只要之前播放过k首， 就能重复。


    int lt0920a(int N, int L, int K)
    {
        const int MOD = (int) 1E9 + 7;
//        vector<int> vi(L);
        vector<vector<int>> vvi(L + 1, vector<int>(N + 1, 0));          // 第几首， 这首放了以后，已经播放几首(set),   多少种选择
        vvi[1][1] = N;
        for (int i = 0; i < L; ++i)
        {
            for (int j = 0; j <= N; ++j)
            {
                if (vvi[i][j] != 0)
                {
                    if (K < j)
                    {
                        // 重播
                        vvi[i + 1][j] = (vvi[i + 1][j] + vvi[i][j] * j % MOD) % MOD;
                    }
                    if (j + 1 <= N)
                        vvi[i + 1][j + 1] = (vvi[i + 1][j + 1] + vvi[i][j] * (N - j) % MOD) % MOD;
                }
            }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        }
        int ans = vvi[L][N];
        return ans;
    }

};

int main()
{
//    myvi v = {3,3,1};
//    myvi v = {2,3,0};
    myvi v = {2,3,1};       // 为什么 是2？   1-2-1  1-2-2  2-1-1  2-1-2 ？

    LT0920 lt;

    cout<<lt.lt0920a(v[0], v[1], v[2]);

    return 0;
}
