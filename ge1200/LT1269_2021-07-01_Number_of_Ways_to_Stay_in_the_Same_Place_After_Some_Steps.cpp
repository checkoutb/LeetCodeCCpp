
#include "../header/myheader.h"

class LT1269
{
public:

// D D

//               dp[i][j] = (dp[i-1][j] + dp[i-1][j+1] + (j>0? dp[i-1][j-1]: 0)) % mod;
// 创建二维数组的时候，多一列， 计算的时候 < lie-1


//    int sz = min(steps / 2 + 1, arrLen);
//    vector<int> v1(sz + 2), v2(sz + 2);
//    v1[1] = 1;
//    while (steps-- > 0) {
//        for (auto i = 1; i <= sz; ++i)
//            v2[i] = ((long)v1[i] + v1[i - 1] + v1[i + 1]) % 1000000007;
//        swap(v1, v2);
//    }
//    return v1[1];





//Runtime: 28 ms, faster than 42.34% of C++ online submissions for Number of Ways to Stay in the Same Place After Some Steps.
//Memory Usage: 10.5 MB, less than 47.68% of C++ online submissions for Number of Ways to Stay in the Same Place After Some Steps.
//    1 <= steps <= 500
//    1 <= arrLen <= 10^6
// 每次走一步，10^6没有意义啊， 最多就250的长度。  不过当arrLen小的时候，那就可以限制step
    int lt1269a(int steps, int arrLen)
    {
        vector<vector<int>> vvi(steps + 1, vector<int>(min(255, arrLen)));      // arrLen / 2 + 1/2 ,, 当arrLen小的时候，这个值会大于arrLen，导致越界。。1的时候4,3有问题，2的时候4,2有问题。
        vvi[0][0] = 1;          // 已走0步，所在下标。
        const int MOD = (int) 1E9 + 7;
        #ifdef __test
        cout<<vvi[0].size()<<endl;
        #endif // __test
        for (int i = 0; i < vvi.size() - 1; ++i)
        {
            for (int j = 0; j < vvi[0].size(); ++j)
            {
                if (vvi[i][j] != 0)
                {
                    vvi[i + 1][j] = (vvi[i][j] + vvi[i + 1][j]) % MOD;
                    if (j - 1 >= 0)
                        vvi[i + 1][j - 1] = (vvi[i][j] + vvi[i + 1][j - 1]) % MOD;
                    if (j + 1 < vvi[0].size())
                        vvi[i + 1][j + 1] = (vvi[i][j] + vvi[i + 1][j + 1]) % MOD;
                }
            }
        }
        #ifdef __test
        for (myvi& v : vvi)
        {
            for (int i : v)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[steps][0];
    }

};

int main()
{

//    int a = 3, b = 2;
//    int a = 2, b = 4;
//    int a = 4, b = 2;
    int a = 4, b = 3;       // 9
        // 0000,  010-1, 01-10  11-1-1,  10-10  100-1  1-11-1

    LT1269 lt;

    cout<<lt.lt1269a(a, b)<<endl;

    return 0;
}
