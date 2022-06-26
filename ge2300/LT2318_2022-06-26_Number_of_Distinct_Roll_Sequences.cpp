
#include "../header/myheader.h"

class LT2318
{
public:

    // D D

    //int dp[10001][7][7] = {};
    //int distinctSequences(int n, int p = 0, int pp = 0) {
    //    if (n == 0)
    //        return 1;
    //    if (dp[n][p][pp] == 0)
    //        for (int d = 1; d < 7; ++d)
    //            if (d != p && d != pp && (p == 0 || gcd(d, p) == 1))
    //                dp[n][p][pp] = (dp[n][p][pp] + distinctSequences(n - 1, d, p)) % 1000000007;
    //    return dp[n][p][pp];
    //}


    //int dp[6][6] = { {0, 1, 1, 1, 1, 1}, {1, 0, 1, 0, 1, 0}, {1, 1, 0, 1, 1, 0},
    //            {1, 0, 1, 0, 1, 0}, {1, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 1, 0} }, dp1[6][6] = {};
    //int distinctSequences(int n) {
    //    if (n == 1)
    //        return 6;
    //    for (int i = 3; i <= n; ++i) {
    //        for (int d = 0; d < 6; ++d)
    //            for (int p = 0; p < 6; ++p) {
    //                dp1[d][p] = 0;
    //                if (dp[d][p])
    //                    for (int pp = 0; pp < 6; ++pp)
    //                        if (d != pp)
    //                            dp1[d][p] = (dp1[d][p] + dp[p][pp]) % 1000000007;
    //            }
    //        swap(dp, dp1);
    //    }
    //    return accumulate(begin(dp), end(dp), 0LL, [](long long s, const auto& n)
    //        { return (s + accumulate(begin(n), end(n), 0LL)) % 1000000007; });
    //}



    // 看到 votrubac 的discuss下，有人问 for (1..6) 为什么不对。。
    // 我是因为 vi2[(t2 % 6) * 6 + i]， 当lastlast 是 5， last是6 时， t2 是 36， 会找 vi2[i] 。。。
    // 但是他们是 [5][6] 的应该没有问题 。。。 他们的不是 三维的， 就是二维。。 所以和我完全不一样。。


    // 用42算，导致。。。 改正太难了。
//Runtime: 430 ms, faster than 100.00 % of C++ online submissions for Number of Distinct Roll Sequences.
//Memory Usage : 43.5 MB, less than 100.00 % of C++ online submissions for Number of Distinct Roll Sequences.
    // 只需要前2个值的状态个数。// 100
    // 只和 前2个数字 有关。
    // 6*6+6 42     // ... 36...
    int lt2318b(int n)
    {
        if (n == 1)
            return 6;
        vector<int> vi(43);
        for (int i = 0; i < 6; ++i)
            vi[i] = 1;

        vector<int> vi3(43);

        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                if (i == j)
                    continue;
                int t2 = gcda1(max(i + 1, j + 1), min(i + 1, j + 1));
                if (t2 == 1)
                {
                    vi3[i * 6 + j] += vi[i];
                }
            }
        }
        swap(vi, vi3);

#ifdef __test
        showVectorInt(vi);
#endif

        //vector<vector<int>> vvi = { {},{},{},{},{},{},{} };

        const int MOD = 1e9 + 7;

        unordered_map<int, vector<int>> map2;           // roll, lstllst * 6 + lst

        for (int a = 0; a < 6; ++a)        // now roll
        {
            for (int i = 0; i < 6; ++i)        // lst lst
            {
                for (int j = 0; j < 6; ++j)        // lst
                {
                    if (a == i || a == j || i == j)
                        continue;
                    if (gcda1(max(i + 1, j + 1), min(i + 1, j + 1)) != 1)
                        continue;
                    if (gcda1(max(j + 1, a + 1), min(j + 1, a + 1)) == 1)
                    {
                        map2[a].push_back(i * 6 + j);
                    }
                }
            }
        }
#ifdef __test
        for (auto& p : map2)
        {
            cout << p.first + 1 << " - ";
            for (int i : p.second)
                cout << "[" << i / 6 + 1 << ", " << i % 6 + 1 << "], ";
            cout << endl;
        }
#endif

        //vector<int> vi2(43);
        while (n-- > 2)
        {
            //vi2.clear();          // size == 0....

            vector<int> vi2(43);

            for (int i = 0; i < 6; ++i)
            {
                for (int t2 : map2[i])
                {
                    vi2[(t2 % 6) * 6 + i] = (vi[t2] + vi2[(t2 % 6) * 6 + i]) % MOD;
                }
            }
            swap(vi, vi2);
        }
        int ans = 0;
        for (int i = 0; i <= 42; ++i)
        {
            ans = (ans + vi[i]) % MOD;
        }
        return ans;
    }

    int gcda1(int a, int b)
    {
        return b == 0 ? a : gcda1(b, a % b);
    }


    //     tle。。。
    // roll n 次
    // 相邻 2 个，最大公约数是 1
    // 2次roll 的值 相差 2。。 不，是 roll得的 相同值 下标 需要 分开 2
    // 10^9 + 7 。。。 那就只有dp了。。 memo。
    // [AB][n] A:last last roll, B:last roll
    // [0][1]
    // [B][2]
    // [AB][3...]
    // 不，[AB][1] .
    // 公约数。
    int lt2318a(int n)
    {
        if (n == 1)
            return 6;
        unordered_map<int, unordered_map<int, int>> mmap2;
        int ans = 0;
        for (int i = 1; i <= 6; ++i)
        {
            for (int j = 1; j <= 6; ++j)
            {
                if (i == j)
                    continue;
                //if ((i % j == 0 && j != 1) || (j % i == 0 && i != 1))       // 1-6可以， {8,12} 就不行了。 // {4,6}
                //{
                //    ans = (ans + dfsa1(n - 2, j, i, mmap2)) % MOD;
                //}
                if ((min(i, j) == 1 || (max(i, j) % min(i, j) != 0)))
                {
                    if ((max(i, j) == 6 && min(i, j) == 4))
                        continue;
                    ans = (ans + dfsa1(n - 2, j, i, mmap2)) % MOD;
                }
                else
                {
#ifdef __test
                    cout << i << ", " << j << endl;
#endif
                }
            }
        }
        return ans;
    }

    const int MOD = 1e9 + 7;

    int dfsa1(int n, int lst, int lstlst, unordered_map<int, unordered_map<int, int>>& mmap2)
    {
        if (n == 0)
            return 1;

        if (mmap2[lstlst * 10 + lst].find(n) != mmap2[lstlst * 10 + lst].end())
        {
            return mmap2[lstlst * 10 + lst][n];
        }
        int llkey = lstlst * 10 + lst;
        int ans = 0;

        for (int a = 1; a <= 6; ++a)
        {
            if (a == lst || a == lstlst)
                continue;
            int i = lst;
            int j = a;

            if ((min(i, j) == 1 || (max(i, j) % min(i, j) != 0)))
            {
                if ((max(i, j) == 6 && min(i, j) == 4))
                    continue;
                ans = (ans + dfsa1(n - 1, j, i, mmap2)) % MOD;
            }
        }

        //for (int i = 1; i <= 6; ++i)
        //{
        //    if (i == lstlst || i == lst)
        //        continue;
        //    if ((lst % i == 0 && i != 1) || (i % lst == 0 && lst != 1))
        //    {
        //        ans = (dfsa1(n - 1, i, lst, mmap2) + ans) % MOD;
        //    }
        //}

        mmap2[llkey][n] = ans;
        return ans;
    }

};

int main()
{

    LT2318 lt;

    int n = 4;


    cout << lt.lt2318b(n) << endl;

    return 0;
}
