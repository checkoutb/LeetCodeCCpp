
#include "../header/myheader.h"

class LT2014
{
public:




// 暴力： dfs 取或不取，组成 subseq，然后 尝试 从后续的 string中 找到 另外 k-1 个 subseq 。。 必然tle。
// dp： [最后idx][重复次数]={"xx","xxx","xxxx"}.. 长度。  加入一个字符 Z，如果存在 aaaaZ 重复了 n次 且 存在 aaaa重复了 n+1次， 那么加入Z后， 会导致 aaaaZ 重复n+1次。
// letsleetcode
// 初始，全空， 第一个char后 [0][1]={"l"}
// 第二个char , 遍历[][]， 对比 次数 和 次数+1 ， 看下 次数 中的 有没有 str 是 次数+1 中的str的 前缀。 有就 ++++
//          [0][1]={"l"} [1][1]={"l","e","le"}          // .. le
// 3: [2][1]={l,e,le,lt,et,let,t}
// 4。。。。 [][1] 是 dfs 取或不取了。。

// hint  Find the characters that could be included in the potential answer. A character occurring more than or equal to k times can be used in the answer up to (count of the character / k) times.
//Try all possible candidates in reverse lexicographic order, and check the string for the subsequence condition.
。
    string lt2014a(string s, int k)
    {

    }

};

int main()
{

    LT2014 lt;


    return 0;
}
