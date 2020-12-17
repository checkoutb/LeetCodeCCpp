
#include "../header/myheader.h"

class LT0096
{
public:

// D D





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
//Memory Usage: 6.3 MB, less than 77.69% of C++ online submissions for Unique Binary Search Trees.
// 1  1
// 2  2         1的上面或下面
// 1 2   2 1        每个子树的 最上面 最下面，     中间分割 只有一种。。
// 3
// 2* f(n-1) + n-1   ?         不， 有些子树没有办法 中间分割吧。。不，步步不，， 可以的，不
// 应该是   左侧x 的结点 可能的 全排列  *  右侧 y个结点 可能的全排列。。  memo。
// 。。。 恩  f(n-1)， 等于就是  一侧0个结点 一个n-1个结点， 然后 自己做根。
// 确实，全排列，   每个 值 都可以做根，  只要把 每个值做根 可能的子树 个数 相加，就是 所有。 不求所有。
    int lt0096a(int n)
    {
        int memo[20] = {0};
        memo[1] = 1;
        memo[0] = 1;    // 1,1,2,3,5,8...
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                memo[i] += memo[j] * memo[i - j - 1];
            }
        }
        return memo[n];
    }


};

int main()
{
    int n{3};

    LT0096 lt;

    cout<<lt.lt0096a(n);

    return 0;
}
