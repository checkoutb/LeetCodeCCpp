
#include "../header/myheader.h"

class LT1997
{
public:

    // D 

        //Let dp[i] be the number of days needed to jump from room 0 to room i.The answer is dp[N - 1].

        //For dp[i], on top of the days needed for reaching room i - 1, i.e.dp[i - 1], we need these extra days to go from room i - 1 to room i.

        //If A[i - 1] == i - 1, we just need 2 days
        //Otherwise, we need to jump to room A[i - 1] first, taking 1 day.Then spent dp[i - 1] - dp[A[i - 1]] days to go from room A[i - 1] to room i - 1 again.Lastly, take 1 day to go from room i - 1 to room i.So in total, we need extra 2 + dp[i - 1] - dp[A[i - 1]] days.

    // .?



    // g


    // 初始 day 0 , visit room 0
    // 奇数次(包含本次)， 下一次 你可以访问 <= nxtVst[room] 的 root
    // 偶数次， (room+1) % n
    // 返回 第一天你访问完 所有room， 1e9+7
    // dfs 肯定不行， 1e9+7 的 stack
    // bfs 应该也不行， 毕竟一层层 加到 1e9。。。
    // nxtVst <= i， 所以 想要 往后走，只有 偶数次时 才可以。
    // 要 让 这个room 是 偶数次， 那么 room-1 也必须是偶数次， 这样 才会从 room-1 走到 room ，然后再走到 room+1
    // room-1偶数，room-2 ..-3...   
    // (room+1)%n 是永远用不到的， 到达 n 的时候，就 return了。
    // 而且， 当你是 偶数次 进入 room 时，  前面的 room-1,room-2...-3 也都是 偶数次进入，  所以下次进入 就是 奇数次进入了。
    // 所以找 前面 连续的奇数次， 这样 进入就是 偶数， 就可以往后。
    // 。。不， 就是看 nxtVst 到当前  是不是 全是 奇数， 使得话， 就 到 nxtVst， 然后 一路偶数次， 直到 room+1
    // 如果 nxtVst 是 偶数，      如果 nxtVst 到 当前  中存在 偶数。
    // 如果 nxtVst 是偶数， 只能 直接 nxtVst， 然后 奇数次， 然后 继续 nxtVst 。  没有办法的。
    // 如果 nxtVst 到 当前 中 存在 偶数， 那也没有办法， 还是 得  走到 那个 偶数，然后 继续 nxtVst。。。
    // 所以 无论如何 都是 跳到 nxtVst 的， 而不会 更早。
    // 所以是 奇数次 跳到 nxtVst， 偶数次+1 ？
    // 但是，这还是 brute-force， 不可能的 1e9 ..
    // 
    int lt1997a(vector<int>& nextVisit)
    {

    }

};

int main()
{

    LT1997 lt;


    return 0;
}
