
#include "../header/myheader.h"

class LT1223
{
public:

// D D


// dfs + memo
//int[][][] dp = new int[5000][6][16];
// 百万级别(48万)。。的int数组。。



//dp[i][k] means after several rolls,
//the number of sequence that ends with k times i.



//DP[i][j] means how many choic for total i dices and the last number is j.
//For each DP[i][j] we need to remove some invalid choice since there is a restriction for consecutive times.
//long[][] dp = new long[n][7];
//            for(int j = 0; j < 6; j++) {
//                dp[i][j] = dp[i - 1][6];
//                if(i - rollMax[j] < 0) {
//                    sum = (sum + dp[i][j]) % divisor;
//                }
//                else {
//                    if(i - rollMax[j] - 1 >= 0) dp[i][j] = (dp[i][j] - (dp[i - rollMax[j] - 1][6] - dp[i - rollMax[j] - 1][j])) % divisor + divisor;
//                    else dp[i][j] = (dp[i][j] - 1) % divisor;
//                    sum = (sum + dp[i][j]) % divisor;
//                }
// 保存了所有的， 所以  dp[i - rollMax[j] - 1][6]  能计算出 连续到现在的。



//        for (int i = 1; i <= n; ++i)
//        {
//            for (int j = 0; j < 6; ++j)
//            {
//                for (int k = 1; k <= r[j] && i - k >= 0; ++k)
//                    dp[i][j] = (dp[i][j] + sum[i-k] - dp[i-k][j] + p) % p;
//
//                sum[i] = (sum[i] + dp[i][j]) % p;
//            }
//        }
// r 是 rollMax
// sum[i-k] - dp[i-k][j]    k从1到限制。     为什么不能自己到自己？
// 感觉重复很多的啊。




//Runtime: 20 ms, faster than 83.42% of C++ online submissions for Dice Roll Simulation.
//Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Dice Roll Simulation.
//
    int lt1223a(int n, vector<int>& rollMax)
    {
        int arr[7][17];         // die's number, consecutive times -> count
        int arrcp[7][17];       // copy
        int* arrp = &arr[0][0];
        int* arrcpp = &arrcp[0][0];
        const int MOD = (int) 1E9 + 7;
        memset(arr, 0, sizeof arr);
        memset(arrcp, 0, sizeof arr);
        for (int i = 1; i <= 6; ++i)
            arr[i][1] = 1;
        // swap?...
        while (n-- > 1)
        {
            for (int i = 1; i <= 6; ++i)
            {
                for (int j = 1; j <= 15; ++j)
                {
                    if (arrp[i * 17 + j] == 0)
                        continue;
                    for (int a = 1; a <= 6; ++a)
                    {
                        if (a == i)
                        {
                            if (j == rollMax[i - 1])
                                continue;
                            arrcpp[a * 17 + j + 1] = (arrp[i * 17 + j] + arrcpp[a * 17 + j + 1]) % MOD;
                        }
                        else
                        {
                            arrcpp[a * 17 + 1] = (arrp[i * 17 + j] + arrcpp[a * 17 + 1]) % MOD;
                        }
                    }
                }
            }
//            arrp = arrcp;         // buxing，  记得 int arr[][]  arr就是一个指针，所以想交换指针，但是 这里会说  int*  和 int*[] 不能交换。(好像是这种错误)
//            arrcp = arr;
//            arr = arrp;
//            arrp = &arrcp[0][0];
//            arrcp = arr;
//            arr = arrp;
            int* tp = arrp;
            arrp = arrcpp;
            arrcpp = tp;
            memset(arrcpp, 0, sizeof arrcp);           // 没有设置arrcpp的数组为0...不知道为什么。是因为 arrcpp是int* 的原因？  不 sizeof arrcpp..
            #ifdef __test
            // 字节数，   arrcpp要8个字节？   en，64位， 64bit/8 = 8byte.  .. 但是 怎么一个都没有设置。。 至少要设置2个int为0啊。
            // 改成 arrcp 就可以了。
            // 下面是从 i=1 开始打印的。。。
            cout<<".... "<<sizeof arrcpp<<", "<<sizeof arrcp<<endl;
            for (int i = 1; i <= 6; ++i)
            {
                for (int j = 1; j <= 15; ++j)
                    cout<<arrp[i * 17 + j]<<", ";
                cout<<endl;
            }
            #endif // __test
            #ifdef __test
            for (int i = 1; i <= 6; ++i)
            {
                for (int j = 1; j <= 15; ++j)
                    cout<<arrcpp[i * 17 + j]<<", ";
                cout<<endl;
            }
            #endif // __test
        }
        int ans = 0;
        for (int i = 1; i <= 6; ++i)
        {
            for (int j = 1; j <= 15; ++j)
            {
                ans = (ans + arrp[i * 17 + j]) % MOD;
            }
        }
        return ans;
    }

};

int main()
{

//    int n = 2;
////    myvi v = {1,1,2,2,2,3};
//    myvi v = {1,1,1,1,1,1};

    int n = 3;
    myvi v = {1,1,1,2,2,3};

    LT1223 lt;

    cout<<lt.lt1223a(n, v)<<endl;

    return 0;
}
