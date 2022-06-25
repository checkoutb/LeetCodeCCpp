
#include "../header/myheader.h"

class LT1569
{
public:



    // gg

    // combination， 除法 不能使用 % 来缩小范围。  但是现在 312049055023946856 * 52 cannot be represented in type 'long long' 

//    For computing the combinatorial, we can use the property: x ^ (-1) = x ^ (m - 2) % m(See this for more detail : https://en.wikipedia.org/wiki/Modular_multiplicative_inverse)
    //long comb(int m, int n) {
    //    int mod = 1e9 + 7;
    //    long num = 1, dem = 1;
    //    for (int i = m; i >= m - n + 1; --i)
    //        num = (num * i) % mod;
    //    for (int i = 1; i <= n; ++i)
    //        dem = (dem * mypow(i)) % mod;
    // 
    //    return (num * dem) % mod;
    //}


    // 1/x = x^(1-2)%1
    // 1/x = x^(2-2)%2      这个公式是什么？ 感觉不对啊。。 主要是 不知道 %m 是 指数的 还是最终结果的。




    // 下面是从discuss 复制的。
    //int dp123a[1001][1001] = { {0} };         // 这个有毒，[1001][1001]， main方法第一行报错：StackOverFlow .. [101][101] 可以。。。
    vector<vector<int>> dp = vector<vector<int>>(1001, vector<int>(1001, 0));

    int comb(int n, int m) {
        return n == 0 || m == 0 ? 1 :
            dp[n][m] ? dp[n][m] :
            dp[n][m] = (comb(n - 1, m) + comb(n, m - 1)) % 1000000007;
    }

    long long dfs(vector<int>& n) {
        if (n.size() <= 1)
            return 1;
        vector<int> n1, n2;
        copy_if(begin(n), end(n), back_inserter(n1), [&](int i) { return i < n.front(); });
        copy_if(begin(n), end(n), back_inserter(n2), [&](int i) { return i > n.front(); });
        //return dfs(n1) * dfs(n2) % 1000000007 * comb(n1.size(), n2.size()) % 1000000007;
        return dfs(n1) * dfs(n2) % 1000000007 * 
            comb(n1.size(), n2.size())              // 正确
            //combination(n1.size() + n2.size(), n1.size())           // 用了这个，结果和我一样了
            //combination(max(n1.size(), n2.size()), min(n1.size(), n2.size()))  // ... 完全不一样
            % 1000000007;
    }
    int numOfWays_discuss_votrubac(vector<int>& n) { return dfs(n) - 1; }

    // gg

    // 看了discuss。  感觉唯一的区别就是，他们都是重新构建了 vector<int>。



    // 在 自己的 祖先路径上的 节点全部存在后， 任何时间insert， 都可以。
    // 那就是看 父节点 有多少种可能。
    // 从上往下， 从下往上，感觉都算力爆炸啊
    // 从上往下，root肯定是第一个，root有几个子节点，第二个就有 几种可能性。  然后就必须 dfs分支了。 肯定不行
    // 从下往上，最后一个insert 的 可能性 == 叶子节点的个数。 倒数第二个 也要根据 最后一步的选择 而不同。
    // 
    // 从最小的树 开始算。
    // (left * right) * 2   左子树的可能 * 右子树的可能 * {先左后右，先右后左}
    //     但是这个公式 不知道怎么证明。。不清楚是否对。  非常的牵强。
    // 错的， Example 2 ，root节点的时候，不对的。
    // 就是说，一个长度5的有序的数组， 一个长度3的有序的数组， 合并后，要让 元素 依然满足 之前的 有序。 右几种可能。
    // 1 1 - 2
    // 1 2 - 3   . 第一个元素 可以插入到 第二个数组中， 有 3种 插入的方法。
    // 1 3 - 4 .        1 * (3 + 1) ...   有3+1 个空位可以插入。
    // 2 2 -    C4取2 ?   一共4个格子，取2个，给第一组放，  由于 顺序无法改变，所以 C4取2   4*3/2 = 6  。。 这个就是 Example 2 吧
    // 
    // 需要计算出 每个节点 的 left right。  或者说 树的结构。
    // 就是 在后面 出现的， 并且小于 自己的 就必然是 。。。不， 可能是 父节点的 左子树的 节点，而不是 自己(右子树)的 节点。 需要一个范围。
    int lt1569a(vector<int>& nums)
    {
        //int ans = dfsa1(nums, 0, 0, 1001);
        //return ans - 1;

        const int MOD = 1e9 + 7;
        //int ans = dfsa2(nums, 0, 0, 1001).second % MOD - 1;
        long long ans = dfsa2(nums, 0, -12, 3001).second % 1000000007;
        return ans - 1;
    }






    // count of node, combination
    pair<int, long> dfsa2(vector<int>& vi, int idx, int st, int en)
    {
        if (idx >= vi.size())
            return make_pair(0, 1LL);

        const int MOD = 1e9 + 7;

        for (int i = idx; i < vi.size(); ++i)
        {
            if (vi[i] > st && vi[i] < en)
            {
                //pair<int, long long> p1 = dfsa2(vi, i + 1, st, vi[i]);
                //pair<int, long long> p2 = dfsa2(vi, i + 1, vi[i], en);

                vector<int> va;
                vector<int> vb;
#ifdef __test
                //cout << i << endl;              // all 0
#endif


                for (int j = 0; j < vi.size(); ++j)
                {
                    if (vi[j] > vi[i])
                        vb.push_back(vi[j]);
                    else if (vi[j] < vi[i])
                        va.push_back(vi[j]);
                }

                pair<int, long long> p1 = dfsa2(va, 0, st, vi[i]);
                pair<int, long long> p2 = dfsa2(vb, 0, vi[i], en);


                long long t2 = combination(p1.first + p2.first, p1.first) % MOD;

#ifdef __test
                //cout << "??" << endl;
                long long t5 = comb(p1.first + p2.first, p2.first);
                cout << "          comb " << t2 << " : " << t5 << endl;
#endif

#ifdef __test
                //cout << vi[i] << " ? " << t2 << ".." << p1.second << ", " << p2.second << endl;
                //cout << " ???? " << t2 * p2.second << endl;
                //cout << " .1.. " << (1LL * t2 * (p1.second % MOD)) << endl;
#endif
                t2 = (((t2 * (p1.second % 1000000007)) % 1000000007) * (p2.second % 1000000007)) % 1000000007;
#ifdef __test
                //cout << " ...... " << t2 << ".---- " << p1.first + p2.first + 1 << endl;
#endif
                return make_pair(p1.first + p2.first + 1, t2);
            }
        }

        return make_pair(0, 1LL);
    }


    // error
    int dfsa1(vector<int>& vi, int idx, int st, int en)
    {
        if (idx >= vi.size())
            return 0;

        for (int i = idx; i < vi.size(); ++i)
        {
            if (vi[i] > st && vi[i] < en)       // sub-tree's root
            {
                int lft = dfsa1(vi, i + 1, st, vi[i]);
                int rht = dfsa1(vi, i + 1, vi[i], en);

                //int t2 = combination(lft + rht, lft);
                int t2 = lft + rht;
                //if (idx == 0)
                //{
                    t2 = combination(t2, lft);
                //}
                //else
                //{
                //    t2++;
                //}

#ifdef __test
                cout << vi[i] << ", " << lft << ", " << rht << ", " << t2 << endl;
#endif

                return t2;
            }
        }
        return 0;
    }

    // a >= b
    // 
    long long combination(int a, int b)
    {
        b = min(b, a - b);
        //if (b == 0)
        //    return 1;
        //long t2 = 1L;
        //long t3 = 1L;
        const int MOD = 1e9 + 7;
        //long st2 = a;
        //long st3 = 1;
        long long ans = 1LL;
        for (int i = 1; i <= b; ++i)
        {
            //ans = ans * (a - i + 1) / i % MOD;
            ans = ans * (a - i + 1) / i;
            //if (ans > MOD)                                // for 循环里 不能MOD。。。 因为 有 除法。。。
            //    ans %= MOD;
        }

        //long long t2 = 1LL;
        //long long t3 = 1LL;
        //for (int i = 1; i <= b; ++i)
        //{
        //    t2 = t2 * (a - i + 1) % MOD;                // ggggggggggg.... 除法，不能使用 分配律。  10/4 % 3 = 2.5    (10%3)/(4%3) = 1
        //                                        // 但是这样的话，不会 溢出吗?
        //                                              // 312049055023946856 * 52 cannot be represented in type 'long long' 
        // 
        //    t3 = t3 * i % MOD;
        //}
#ifdef __test
        //cout << t2 << ", " << t3 << endl;
#endif
        //ans = t2 / t3;

#ifdef __test
        cout << a << "c" << b << " = " << ans << endl;
#endif
        return ans % MOD;

        //for (int i = 0; i < b; ++i)
        //{
        //    t2 = t2 * (st2--) % MOD;
        //    t3 = t3 * (st3++) % MOD;
        //}

    }

};

int main()
{

    LT1569 lt;

    //myvi v = { 1,2,3 };

    //myvi v = { 3, 4, 5, 1, 2 };

    //myvi v = { 2,1,3 };

    //myvi v = { 3,1,2,5,4,6 };       // 19


    // 137401437
    myvi v = { 30, 11, 46, 3, 29, 22, 37, 32, 13, 49, 48, 16, 40, 8, 24, 44, 9, 39, 25, 21, 41, 
        26, 43, 19, 47, 7, 10, 31, 45, 4, 35, 14, 20, 23, 15, 17, 38, 2, 6, 18, 5, 33, 27, 36, 42, 28, 12, 34, 1 };

    cout << lt.lt1569a(v) << endl;

    cout << "discuss:  " << lt.numOfWays_discuss_votrubac(v) << endl;


    cout << endl << endl;

    long asd = INT_MAX;
    asd++;
    cout << asd << endl;                // INT_MMMIIIIIIIINNNN ......

    return 0;
}
