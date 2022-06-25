
#include "../../header/myheader.h"

class LT
{
public:


    // D

    //while (true) {
    //    a = pq.top(); pq.pop();
    //    total -= a;
    //    if (a == 1 || total == 1)
    //        return true;
    //    if (a < total || total == 0 || a % total == 0)
    //        return false;
    //    a %= total;
    //    total += a;
    //    pq.push(a);
    //}


    // %= ， 就是 倍数最大

    // 但是不知道，为什么 非最高倍，肯定是错的。 不不不，应该是， 不知道 为什么 非最高倍的 结果 和 最高倍 是一样的 (所以就不需要计算非最高倍)。

    // 非最高倍，分为2种， init 依然是最大值， init 不是最大值。
    //      依然最大时，还是计算这个，还是要减去 相同的sum other 。。 所以最终 init 肯定不是最大值。。
    // 不是最大值， 那就肯定得用 最高倍 去减。 不是最高倍 就意味者， init = (Z+) + sum_other， 还是最大值。
    // 可惜。。。



    // 看了discuss，倍数最大。。  discuss的直接舍弃了 其它的倍数。。 
//Runtime: 162 ms, faster than 5.59 % of C++ online submissions for Construct Target Array With Multiple Sums.
//Memory Usage : 44.6 MB, less than 14.69 % of C++ online submissions for Construct Target Array With Multiple Sums.
    // tle。。。
    bool ltb(vector<int>& target)
    {
        if (target.size() == 1)
            return target[0] == 1;

        multiset<long long> mset(begin(target), end(target));

        long long sum2 = accumulate(begin(target), end(target), 0LL);

        return dfsb1(mset, sum2);
    }

    bool dfsb1(multiset<long long>& mset, int sum2)
    {
        if (*rbegin(mset) == 1LL)
            return true;

        long long mx = *rbegin(mset);
        mset.erase(prev(end(mset)));

        long long sumOther = sum2 - mx;

#ifdef __test
        cout << mx << "...." << sumOther << ", " << sum2 << endl;
#endif
        if (sumOther == 0LL)
            return false;

        int mul = mx / sumOther;

        while (mul > 0)
        {
            long long init = mx - sumOther * mul;
            if (init > 0LL)
            {
                mset.insert(init);
                long long diff = mx - init;
                sum2 -= diff;

                if (dfsb1(mset, sum2))
                    return true;
                else
                    return false;                               // add, after discuss 。。。。

                mset.erase(init);
                sum2 += diff;
            }
            mul--;
        }
        return false;
    }


    // 全1 变成 target
    // 肯定要先 构建 最小值，不然，最小值就无法再 构建了，因为 sum()
    // 那就只有一条路， bububu, sum 替换谁。 但无论如何都是要先构建小的。
    // 而且 还有 10^9 的数。。。 * 2 很快的。
    //
    // hint：反向，移除最大的。。 确实， 最大的数字 == sum(上一个状态的数组) 。 上一个状态，到现在的状态，只有最大的数字这个位置发生的变化。 可以计算出来值。
    // mx = sum(arr_last) = sum(arr_now) - diff(mx,lst) = sum(arr_now) - (mx - lst) = sum(arr_n) - mx + lst, lst = 2*mx - sum(arr_now)
    // [1, 10 0000 0000] tle。。。 等差数列。。 2 3 4 5 .... 1000000000  。。 init + mul*?
    // sum(other) + init. sum(other)*2 + init. sum(other)*? + init == mx ...倍数不同，init的值也不同。这。。取最高倍？优先最高倍啊。
    // sum(o) + init
    bool lta(vector<int>& target)
    {
        priority_queue<long long> priq(begin(target), end(target));

        long long sum2 = std::accumulate(begin(target), end(target), 0LL);

        while (!priq.empty())
        {
            long long mx = priq.top();
            if (mx == 1LL)
                break;
            priq.pop();
            long long t2 = 2LL * mx - sum2;
            if (t2 < 1LL)
                return false;

#ifdef __test
            cout << mx << " - " << t2 << endl;
#endif

            priq.push(t2);
            sum2 -= (mx - t2);
        }
        return true;
    }

};

int main()
{

    LT lt;

    //myvi vi = { 9,3,5 };

    //myvi vi = { 1,1,1,2 };

    //myvi vi = { 8,5 };

    //myvi vi = { 1,10'0000'0000 };

    //myvi vi = { 1,1,2 };

    myvi vi = { 2, 900000002 };

    cout << lt.ltb(vi) << endl;

    return 0;
}
