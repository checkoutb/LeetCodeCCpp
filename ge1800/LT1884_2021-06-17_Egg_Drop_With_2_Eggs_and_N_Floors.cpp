
#include "../header/myheader.h"

class LT1884
{
public:

// D D

//        int i;
//        for(i=1; i*(i+1) < 2*n; i++);
//        return i;
// 就是 等差数列各项和的 等式 两边 *2


//        int k = 2;
//        vector<vector<int>> dp(k + 1, vector<int> (n + 1, 0));
//        int m = 0;
//        while (dp[k][m] < n) {
//            m++;
//            for (int i = 1; i <= k; i++) {
//                dp[i][m] = dp[i - 1][m - 1] + dp[i][m - 1] + 1;
//            }
//        }
//        return m;


//You can also solve this problem using recursion. Let's consider a more general problem when we have x eggs and n floors. If you drop an egg from i floor (1<=i<=n), then
//    If the egg breaks, the problem is reduced to x-1 eggs and i - 1 floors
//    If the eggs does not break, the problem is reduced to x eggs and n-i floors
//    int drop(int floors, int eggs, int[][] dp) {
//        if (eggs == 1 || floors <= 1)
//            return floors;
//        if (dp[floors][eggs] > 0)
//            return dp[floors][eggs];
//        int min = Integer.MAX_VALUE;
//        for (int f = 1; f <= floors; f++)
//            min = Math.min(min, 1 + Math.max(drop(f - 1, eggs - 1, dp), drop(floors - f, eggs, dp)));         ---------
//        dp[floors][eggs] = min;
//        return min;
//    }
// min(max({碎了，蛋-1,下面几层的层数}, {没碎，蛋不减，上面几层的层数}))
// 上面和下面 并没有区别，需要的只是 层数。
// max 是 在f层 扔的 最坏情况
// min 是 在[1, floors]中 扔 的最好情况。
// 这个应该是 top-down dp
// 通解！


//        int count = 1;
//        int pre = 1;
//        while(count < n) {
//            pre++;
//            count += pre;
//        }
//        return pre;
// 1 + 2 + 3 。。。


//int twoEggDrop(int n) {
//	if (dp[n] == 0)
//		for (int i = 1; i <= n; ++i)
//			dp[n] = min(dp[n] == 0 ? n : dp[n], 1 + max(i - 1, twoEggDrop(n - i)));
//	return dp[n];
//}
// i-1 就是这次(i层)碎了，所以只能 剩下的楼层一层层试。   后面就是 没有碎的时候 就转成了 2个蛋 n-i层

//    int res = 1;
//    while (n - res > 0)
//        n -= res++;
//    return res;

//    int dp[3] = {};
//    int m = 0;
//    while (dp[k] < n) {
//        ++m;
//        for (int j = k; j > 0; --j)
//            dp[j] += dp[j - 1] + 1;
//    }
//    return m;

//int dp[1001][3] = {};
//int twoEggDrop(int n, int k = 2) {
//    int m = 0;
//    while (dp[m][k] < n) {
//        ++m;
//        for (int j = 1; j <= k; ++j)
//            dp[m][j] = dp[m - 1][j - 1] + dp[m - 1][j] + 1;
//    }
//    return m;
//}



// x-a == 1
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Egg Drop With 2 Eggs and N Floors.
//Memory Usage: 6 MB, less than 39.23% of C++ online submissions for Egg Drop With 2 Eggs and N Floors.

// 挺有名的，扔鸡蛋和楼层。当不知道是不是这道。。
// 刚开始觉得是dp， 后来又觉得是二分，
//      假设x次，那么第一次就是x楼，如果碎了，就1,2,3,4...x-1楼一个个试。       1 + x-1 == x
//              第一次没有碎，就 x+(x-1)楼， 碎了，就 x+1,x+2...x+x-2     1+1 + (x-2)
//                      x+(x-1)+(x-2)                               1+1+1 + (x-3)
//           一直到 x+(x-1)...+(x-a) >= n
//   似乎是数学题目了。。  最好的情况 x-a == 1.      1+2+3+...+x >= n
// (1+x)*x/2 >= n
// x^2 + x -2n >= 0
// x = (-1 + sqrt(1+8n))/2  上界
// x-a == 1 or 2 ?
    int lt1884a(int n)
    {
        double sqr = std::sqrt(1 + 8 * n);
        double x = (sqr - 1) / 2;
        return std::ceil(x);
    }

};

int main()
{
//    int n = 2;
    int n = 100;

    LT1884 lt;

    cout<<lt.lt1884a(n)<<endl;

    return 0;
}
