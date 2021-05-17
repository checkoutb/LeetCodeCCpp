
#include "../header/myheader.h"

class LT1866
{
public:

// D

// DP

//For case that n stick to see k from left,
//we considering the last element in the list:
//case 1: if it's the largest,
//then n-1 stick to see k-1 (excluding the last).
//dp[n][k] += dp[n - 1][k - 1]
//
//case 2: if it's not the largest,
//n - 1 choices for the last elements
//then n-1 stick to see k (excluding the last).
//dp[n][k] += dp[n - 1][k] * (n - 1)
//
//Edge case 1
//if n == k, return 1;
//Edge case 2
//if k == 0, return 0;

// 考虑 最后一个元素：
// 如果是最大的，那么计算 n-1, k-1.
// 不是最大，最后一个元素有n-1种可能， n-1,k,      // 因为不是最大，就肯定被隐藏了。  并且n-1种可能。

// dp[n][k]  = (1L * rearrangeSticks(n - 1, k - 1) + 1L * rearrangeSticks(n - 1, k) * (n - 1)) % mod;
// 可能性相加。

// fix最后一个元素。  而不是 fix 最大的元素。


// 105,20   tle...   + memo
// 481,314  tle...
// 那就只能dp了啊。。
// x 1, 就是最大的放最前面， (x-1)!
// x 2, 最大+随机一个，。。
// gg
// 不
// 1 k      不可能
// k k      1
// k+1  k   n-1 + n-2 + n-3 ... + 1 .  在上面的基础上，插入一个值， 如果插入的值是最小的，那么可以插入n-1个位置，
//                          或者说，是在上面的基础上， 新增一个最大值 到 尾巴，这样就有 k+1个可见。 需要减少一个可见， 要让1不可见，可以和后面的n-1个位置替换。2不可见，可以和后面的n-2个位置swap
// k+2  k   在上面的基础上，新增一个最大值到尾巴， k+1个可见。 似乎也是n-1 + n-2 + n-3 ... + 1.  可以无视k+1,k时，被藏起来的那个数字。不，排列的话，无法无视。
//
// gg。。。hint说固定一个，所以上面的没有用。

// 最高的那个肯定能看到。
// 其他的每个，如果不想被看到，那么。。。 不，好多位置，而且可能 在 最高的前面，但是依然不被看到。
// 最高的后面的，都不可能被看到， 所以 [5,5] 的时候， 5只能放最后。 就变成了[4,4] ...
// n, k, 从n递归到1,  当前已有序的最低
// dp？  321  312

// hint 1 & 2
//Is there a way to build the solution from a base case?
//How many ways are there if we fix the position of one stick?
//
// 就是 差距无所谓的，  需要的只是 大小， 具体差多少，无所谓。
// 当最大的固定一个位置idx后， 该位置后的 都无法被看到， 就转成 [idx - 1, k - 1] * (C(n-1) 取 (n-idx)) * (n-idx)!       // A / P
// dfs
    int lt1866a(int n, int k)
    {
        int ans = dfsa1(n, k);
        return ans;
    }
    unordered_map<int, int> map2;
//    int ans = 0;
    int dfsa1(int n, int k)
    {
//        cout<<n<<", -- "<<k<<endl;
//        if (n < k)
//        {
////            cout<<n<<", "<<k<<endl;
//            return 0;
//        }
        if (n == k)
        {
            return 1;
        }
        if (k == 0)
        {
            return 0;
        }

        if (map2.find(n * 10000 + k) != map2.end())
            return map2[n * 10000 + k];

        int t2 = 0;
        for (int i = n; i >= 1; --i)
        {
            int t3 = dfsa1(i - 1, k - 1);
//            cout<<"a "<<t3<<endl;
//            if (t3 == 0)
//                break;

            t3 = ((long) t3) * funa1(n - 1, n - i) % mod;
            t2 = (t2 + t3) % mod;
        }
        #ifdef __test
//        cout<<t2<<endl;
        #endif // __test
        map2[n * 10000 + k] = t2;
        return t2;
    }
    const int mod = 1E9 + 7;
    // P a qu b
    long funa1(int a, int b)
    {
        long t2 = 1;
        int c = a - b + 1;
        for (; c <= a; ++c)
        {
            t2 = t2 * c % mod;
        }
        return t2;
    }

};

int main()
{
//    int n{3}, k{2};
//    int n{5}, k{5};
    int n{20}, k{11};

    LT1866 lt;

    cout<<lt.lt1866a(n, k)<<endl;

    return 0;
}
