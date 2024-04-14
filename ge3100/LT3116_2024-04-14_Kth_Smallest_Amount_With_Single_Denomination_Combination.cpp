
#include "../header/myheader.h"

class LT3116
{
public:




    // vvi 的组建，我是根据数据猜的，就是 long long lcm = cal_lcm(t2, t3);  t2,t3的取值，还有后续的 *-1 。。根据2,5,7的结果，猜测的。


// Runtime
// 0ms
// Beats100.00%of users with C++
// Memory
// 20.08MB
// Beats6.67%of users with C++


    // k <= 2 * 10^9 ... 强度一下子上来了。
    // Accepted 739 Submissions 24.7K Acceptance Rate 3.0%
    // 去重的， 3: 3,6  6: 6  ->  3,6
    // 只能 二分吧。 k 20亿呢。
    // 3,6,9,  对3来说， 3的倍数，减去6的倍数，减去9的倍数，加18的倍数
    //         对6来说， 6的倍数，减去9的倍数    // ，不需要 加18的倍数
    //         对9来说， 9的倍数
    // 或者  直接3的倍数，    算6的时候，加上6的倍数，减去(3,6)最小公倍数的倍数，   算9的时候，加上9的倍数，减去(3,9)，(6,9)。。。
    // 倍数可以直接剔除掉。 所以3,6,9  直接 3 就可以了。
    // 非倍数，2 5 7  2,  5-10, 7,-2,-5+10
    // 1+15 / 2 * 15 = 120 *10
    long long findKthSmallest(vector<int>& coins, int k)
    {
        sort(begin(coins), end(coins));
        vector<int> coin2;
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (coins[i] % coins[j] == 0)
                {
                    goto AAA;
                }
            }
            coin2.push_back(coins[i]);
            AAA:
            continue;
        }
        coins = coin2;

        /////////////////////////

        vector<vector<long long>> vvi(coins.size());

        for (int i = 0; i < coins.size(); ++i)
        {
            vvi[i].push_back(coins[i]);
            long long t3 = coins[i];
            for (int j = 0; j < i; ++j)
            {
                for (int k = 0; k < vvi[j].size(); ++k)
                {
                    long long t2 = vvi[j][k];
                    long long lcm = cal_lcm(t2, t3);

                    lcm *= t2 < 0LL ? 1 : -1;
                    vvi[i].push_back(lcm);
                }
            }
        }

// #ifdef __test
//         showVectorInt(coins);
//         cout<<"----\n";
//
//         for (myvi& vi : vvi)
//         {
//             for (int i : vi)
//                 cout<<i<<", ";
//             cout<<endl;
//         }
// #endif

        long long st = coins[0];
        long long en = 1LL * coins[0] * k;
        long long ans = 0LL;
        while (st <= en)
        {
            long long md = (st + en) / 2;
            long long cnt = 0;
            for (int i = 0; i < vvi.size(); ++i)
            {
                for (int j = 0; j < vvi[i].size(); ++j)
                {
                    int t2 = vvi[i][j];
                    if (t2 < 0)
                    {
                        t2 = -t2;
                        cnt -= (md / t2);
                    }
                    else
                    {
                        cnt += md / t2;
                    }
                }
            }
#ifdef __test
            cout<<"md "<<md<<" , "<<st<<" , "<<en<<", "<<cnt<<endl;
#endif
            if (cnt < k)
            {
                st = md + 1;
            }
            else
            {
                ans = md;       // ..
                en = md - 1;
            }
        }
        return ans;
    }

    long long cal_lcm(long long a, long long b)
    {
        a = std::abs(a);
        b = std::abs(b);
        return a * b / cal_gcd(std::max(a, b), std::min(a, b));
    }

    long long cal_gcd(long long a, long long b)
    {
        return b == 0 ? a : cal_gcd(b, a % b);
    }

//     void dfsa1(vector<int>& vi, int multi)
//     {
//
//     }

};

int main()
{

    LT3116 lt;

    // myvi v {3,6,9};
    // int k {3};

    myvi v {2,5};
    int k{7};

    cout<<lt.findKthSmallest(v, k)<<endl;

    return 0;
}
