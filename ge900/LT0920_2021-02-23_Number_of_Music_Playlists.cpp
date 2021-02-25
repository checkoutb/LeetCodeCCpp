
#include "../header/myheader.h"

class LT0920
{
public:

// D
// dp  [N][L]


// N 首歌， 听L次， 每首必须听一次，  其他K首歌，听过后，才能重复。
// 前 K 首必须唯一， N首必须听完， 一共听L次。
// C N取 K， 全排列，  后续每个时间点 N选1 首歌, 如果没有听过，则countN--，  如果当前index >= L-countN， 则后续就是 剩下的 没有听过的歌的全排列。
// 还有：
//Input: N = 2, L = 3, K = 1
//Output: 2
//Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
// [1,2,2] 为什么不行？
// A song can only be played again only if K other songs have been played ，  这种again 是 立刻重复，还是说以后 重复？
// only if .  有且只有？    k+1首 其他的歌 就不行了？

// discuss里没有， leetcode-cn 的评论里看到了。。  “题目意思是说两首相同歌之间必须至少间隔K首歌”

// N * (N-1) * (n-2) * (n-3) * (n-3) * (n-3). k = 3
// 全听完怎么弄。

    int lt0920a(int N, int L, int K)
    {

    }

};

int main()
{

    LT0920 lt;


    return 0;
}
