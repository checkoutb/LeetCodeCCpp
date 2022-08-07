
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //long long int a = 1, e = 1, i = 1, o = 1, u = 1, mod = 1e9 + 7;

    //def count_vowel_permutations(n) :
    //    a, e, i, o, u = 1, 1, 1, 1, 1
    //    for _ in range(n - 1) :
    //        a, e, i, o, u = e + i + u, a + i, e + o, i, i + o
    //        return (a + e + i + o + u) % (10 * *9 + 7)


    //vector<vector<int>> moves = { {1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, { 0 } }, v(2, vector<int>(5, 1));
    //while (--n > 0) {
    //    for (auto i = 0; i < 5; ++i)
    //        v[(n + 1) % 2][i] = accumulate(begin(moves[i]), end(moves[i]), 0,
    //            [&](int s, int j) {return (s + v[n % 2][j]) % 1000000007; });
    //}
    //return accumulate(begin(v[0]), end(v[0]), 0, [](int s, int n) { return (s + n) % 1000000007; });
    // ... n 是 倒序，所以 最后肯定保存在 v[0] 上，  只不过 第一次 可能在 v[0] ，也可能在 v[1] 。。。。都初始化成了 1.



//Runtime: 88 ms, faster than 48.60 % of C++ online submissions for Count Vowels Permutation.
//Memory Usage : 147 MB, less than 5.29 % of C++ online submissions for Count Vowels Permutation.
    int lta(int n)
    {
        const int MOD = 1e9 + 7;

        vector<int> vi(123, 0);
        string s = "aeiou";
        //for (char ch : "aeiou")               // 结尾的 \\0 ...  c的string。
        for (char ch : s)
        {
#ifdef __test
            //cout << vi[0] << " === " << (int)ch << endl;
#endif
            vi[ch] = 1;
        }

#ifdef __test
        //showVectorInt(vi);
#endif

        while (n-- > 1)
        {
            vector<int> v2(123);
            v2['a'] = ((vi['e'] + vi['i']) % MOD + vi['u']) % MOD;
            v2['e'] = (vi['a'] + vi['i']) % MOD;
            v2['i'] = (vi['e'] + vi['o']) % MOD;
            v2['o'] = vi['i'];
            v2['u'] = (vi['i'] + vi['o']) % MOD;

            swap(vi, v2);
        }

        int ans = 0;
        for (int i : vi)
            ans = (ans + i) % MOD;
        return ans;
    }

};

int main()
{

    LT lt;

    int n = 5;

    cout << lt.lta(n) << endl;

    return 0;
}
