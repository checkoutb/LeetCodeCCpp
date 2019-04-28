
#include "../header/myheader.h"

class LT0319
{
public:

    // 看来discuss。。。 return sqrt(n)...............................
    // 因子的个数，平方数的话，因子个数是基数，所以最后是on的。因为第一次是开，后面的成对出现，奇数的话，最终结果还是开。
    // 非平方数，因子个数总是偶数，初始状态关，偶数次，还是关。
    // bulb i ends up on if and only if i is a square.

    // 没办法，因子试试..好像不行，之前的方法是O(n^2), 即使因子可以动态规划，但是寻找因子这个没办法简略啊。还是得O(n^2)
    // 或者从大到小，递归找。
    int lt0319c(int n)
    {
        if (n <= 1)
            return n;
        int result = 0;
        int arr1[n] = {0};
#ifdef __test
        vector<int> v(arr1, arr1 + n);
        for_each(v.begin(), v.end(), fun_cout);
#endif // __test

//        for ()

        return result;
    }

    // 下标+1 所有可能的因子组成set的个数 就是 状态切换的次数。。但是 找到所有可能的因子 还不如暴力按呢。。不过因子也可以动态规划。
    // timeout 32/35 10000000
    int lt0319b(int n)
    {
        if (n <= 1)
            return n;
        int result = 0;
        bool arr1[n];
        for (auto&p : arr1)
            p = true;

        int t1 = 0;
        for (int i = 1; i < n; i++)
        {
            t1 = i + 1;
            for (int j = i; j < n; j += t1)
            {
                arr1[j] = !arr1[j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr1[i])
                result++;
        }
        return result;
    }

    // .. 质数？用质数暴力算？切换开关，不是关。是状态改变。这里>=1永远是返回1.
    // deprecated
    int lt0319a(int n) {
        if (n <= 1)
            return n;
        int result = 0;
        bool arr1[n] = {true};
        for (auto& p : arr1)
            p = true;
#ifdef __test
        for (auto& p : arr1)
        {
            cout<<p<<", ";
        }
#endif // __test

        for (int i = 2; i <= n; i++)
        {
            if (!arr1[i - 1])
                continue;
            for (int j = i; j <= n; j += i)
            {
                arr1[j - 1] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr1[i])
                result++;
        }
        return result;
    }
};


int main()
{
    LT0319 lt;
    int n = 3;

    cout<<endl<<lt.lt0319c(n);
    return 0;
}
