
#include "../../header/myheader.h"

class LT
{
public:

// D

//Alex can always pick odd piles or always pick even piles!

//dp[i][j] means the biggest number of stones you can get more than opponent picking piles in piles[i] ~ piles[j].
//You can first pick piles[i] or piles[j].
//
//    If you pick piles[i], your result will be piles[i] - dp[i + 1][j]
//    If you pick piles[j], your result will be piles[j] - dp[i][j - 1]

//dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])

//        for (int i = 0; i < n; i++) dp[i][i] = p[i];
//        for (int d = 1; d < n; d++)
//            for (int i = 0; i < n - d; i++)
//                dp[i][i + d] = max(p[i] - dp[i + 1][i + d], p[i + d] - dp[i][i + d - 1]);
//        return dp[0][n - 1] > 0;

//        for (int d = 1; d < p.size(); d++)
//            for (int i = 0; i < p.size() - d; i++)
//                dp[i] = max(p[i] - dp[i + 1], p[i + d] - dp[i]);
//        return dp[0] > 0;


//dp[i][j] actually means maximum(alex stone - lee stone) and maximum(lee stone - alex stone) alternatively, depending on who picks from piles[i]~piles[j] first.
//If alex picks from piles[i]~piles[j] first, then dp[i][j] means maximum(alex stone - lee stone);
//If Lee pick from piles[i]~piles[j] frist, then dp[i][j] means maximum(lee stone - alex stone) .






// g

// 记得是先手必胜. 1,1000,1,1  1,100,101,1
// 只有2个，肯定去大的。
// 4个，
// 知道了。  3个。    一方取 一个以后，另一方是2个选择。 所以这是3个。如果第一次。。。
//
    bool lta(vector<int>& piles)
    {

    }

};

int main()
{

    LT lt;


    return 0;
}
