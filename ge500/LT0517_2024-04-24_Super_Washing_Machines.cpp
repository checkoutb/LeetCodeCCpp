
#include "../header/myheader.h"

class LT0517
{
public:




    // 还是很模糊。
    // 主要就是 下面的那句， 每台机器 会有多少衣服经过
    // 开始为0,每次加上 (machines[i] - tar)， 负数 代表 缺少，需要从右侧补充。
                    /// 正数 代表多于， 会 往左侧发。
            // 无论是 从右侧补充，还是 往左侧发，都是 需要 move的，  每需要 补充/外发 一件，都需要一个 move， 所以 max(ans, ned)
        // 还有 030 这种，往前补完，还有多余的，还要往后发，所以就是 max(ans, t2)

// Runtime
// 3ms
// Beats92.36%of users with C++
// Memory
// 15.32MB
// Beats48.73%of users with C++

    // 0,0,11,5
    // [7,6,5,4,3,2,1]
    //
    // how many dresses will be passed through machine i
    //
    int findMinMoves(vector<int>& machines)
    {
        int sz1 = machines.size();
        int sum2 = std::accumulate(std::begin(machines), std::end(machines), 0);
        if (sum2 % sz1 != 0)
            return -1;

        int tar = sum2 / sz1;
        int ans = 0;

        int st = 0;
        int ned = 0;
        int t2 = 0;
        int remain = 0;

        for (int n : machines)
        {
            t2 = n - tar;
            ned += t2;
            ans = max(ans, abs(ned));
            ans = max(ans, t2);
        }

        // for (int i = 0; i < sz1; ++i)
        // {
        //     // t2 = machines[i] - tar;
        //     if (machines[i] < tar)
        //     {
        //         if (remain > tar - machines[i])
        //         {
        //             remain -= tar - machines[i];
        //             machines[i] = tar;
        //         }
        //         else
        //         {
        //             machines[i] += remain;
        //             remain = 0;
        //         }
        //     }
        //     else
        //     {
        //         remain += machines[i] - tar;
        //         machines[i] = tar;
        //     }
        //     ans = max(ans, remain);
        // }


        // int ned = 0;
        // int t2 = 0;
        // for (int n : machines)
        // {
        //     t2 = n - tar;   // 0 - tar
        //     ned -= t2;
        //     ans = max(ans, t2 + ned);
        //     ans = max(ans, t2);
        // }

        // for (int n : machines)
        // {
        //     ans = max(ans, n - tar);
        // }
        return ans;
    }

};

int main()
{

    LT0517 lt;


    return 0;
}
