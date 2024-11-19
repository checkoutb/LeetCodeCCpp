
#include "../header/myheader.h"

class LT3218
{
public:


    // D D

    // Lee 也只说了 2刀的情况， 没说3刀， 3刀是没有意义吗？
    // 就是 数学归纳法，1刀，2刀， 那么 n+1刀 对比 n刀 会发生什么？

    // 而且，发现一个现象，以example 1 为例，无论怎么切，都是 5个 cost的相加。就是 横横竖 的切法，就是 1次横 + 1次横 + 3次竖 的cost。 其他切法也都是 5次。 不知道什么原理。。
    // 似乎是： 每一刀 都会增加一块， 最终有6块，所以需要 5刀，所以5次。  就是 实际上是 5刀， 并不是 [1,3] [5] 这种 3刀。
    
    // 所以可以证明了， 最终切成 n 块，那么需要 n-1 刀，不同的切法，总刀数不变， 变的只是 序列。
    // 比如 example 1 的 横横竖，那么就是 1+3+5+5+5， 竖横横就是 5+1+1+3+3,  越先切，在 序列中的 次数越少， 所以可以 贪心。  。。 感觉还是缺点东西。  主要它有 横竖 2个方向。
    // 可以反证， 后切的 次数 必然 >= 先切。

    // Lee说了，但还是好模糊。
// If we cut horizontal k times,
// there is k + 1 parts in vertical direction,
// and each vertical cut need to make k + 1 times,
// k more times than once.
    
    
// Runtime
// 16ms
// Beats23.72%
// Analyze Complexity
// Memory
// 29.46MB
// Beats73.92%


    // II 的，只需要 ans 声明为 long long 其他不需要变化。
// Runtime
// 336ms
// Beats61.48%
// Analyze Complexity
// Memory
// 233.54MB
// Beats85.24%

    


    // m,n < 20,  so iterate.  II is 10^5
    // 竖刀 不会影响其他 竖刀， 但是会让 横刀 消耗 * 2
    // 每个 横刀，竖刀，都是必须切的，不可能跳过。
    // 先切 最高花费的？  [1,5] [3]  似乎是的，找不到反例。
    // 证明：最后只剩一刀，那么没有任何选择， 只剩2刀，如果同向，无所谓，不同项， 列*横刀 + (行+1)*竖刀  。 1是 横刀切出来的，    行*竖 + (列+1)*横
    // 列*横 + (行+1)*竖  <?> 行*竖 + (列+1)*横
    // == 列横 + 行竖 + 竖  vs.  行竖 + 列横 + 横
    // == 竖 vs. 横
    // 先横刀的 消耗 是 x + 竖， 先竖刀的消耗是 x + 横， 为了 最小消耗， 所以如果 竖 < 横，那么 先横刀
    // 。。突然发现 不认识 横 这个字了，好少用到。
    //
    // 那如果有 3刀呢？  不知道了。
    //
    // 每一横刀，会使得 后续的 所有竖刀 增加 原始的 消耗(sum(verticalcut))。
    // 先试下，优先最大消耗
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        long long ans = 0;
        int cnth = 0;
        int cntv = 0;

        std::sort(std::begin(horizontalCut), std::end(horizontalCut));
        std::sort(std::begin(verticalCut), std::end(verticalCut));

        int idxh = horizontalCut.size() - 1;
        int idxv = verticalCut.size() - 1;

        while (idxh >= 0 && idxv >= 0) {
            int th = horizontalCut[idxh];
            int tv = verticalCut[idxv];

            if (th > tv) {
                ans += th * (cntv + 1);
                cnth++;
                idxh--;
            } else if (th < tv) {
                ans += tv * (cnth + 1);
                cntv++;
                idxv--;
            } else {
                // ???
                ans += tv * (cnth + 1);
                cntv++;
                idxv--;
            }
        }
        while (idxh >= 0) {
            ans += horizontalCut[idxh--] * (cntv + 1);
        }
        while (idxv >= 0) {
            ans += verticalCut[idxv--] * (cnth + 1);
        }
        return ans;
    }


};

int main()
{

    LT3218 lt;


    return 0;
}
