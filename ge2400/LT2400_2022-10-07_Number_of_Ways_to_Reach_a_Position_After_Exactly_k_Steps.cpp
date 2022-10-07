
#include "../header/myheader.h"

class LT2400
{
public:

    // D D

    // dp 的2个维度， k 和 距离 。。
    //return dfs(k, abs(startPos - endPos));



    //long inv(long a) {
    //    if (a == 1) return 1;
    //    return (p - p / a) * inv(p % a) % p;
    //}



    //long r = (diff + k) / 2;
    //return nCr(k, r);

    ////Function to calculate nCr 
    ////C(n, r) = C(n-1, r-1) + C(n-1, r)
    //int nCr(int n, int r) {
    //    if (r == 0) return 1;
    //    vector<int> v(r + 1, 0);
    //    v[0] = 1;
    //    for (int i = 1; i <= n; i++) {
    //        for (int j = r; j > 0; j--)
    //            v[j] = ((v[j] % mod) + (v[j - 1] % mod)) % mod;
    //    }
    //    return v[r];
    //}




//Runtime: 1315 ms, faster than 12.34 % of C++ online submissions for Number of Ways to Reach a Position After Exactly k Steps.
//Memory Usage : 98.8 MB, less than 46.42 % of C++ online submissions for Number of Ways to Reach a Position After Exactly k Steps.
    int lt2400a(int startPos, int endPos, int k)
    {
        int t2 = endPos - startPos;
        t2 = abs(t2);

        int t3 = k - t2;
        if (t3 < 0 || t3 & 1)
            return 0;

        const int MOD = 1e9 + 7;

        unordered_map<int, unordered_map<int, int>> map2;

        dfsa1(map2, startPos, k, endPos);

        return map2[startPos][k];

    }

    int dfsa1(unordered_map<int, unordered_map<int, int>>& map2, int pos, int k, int en)
    {
        if (k == 0)
        {
            return pos == en ? 1 : 0;
        }
        if (map2[pos].find(k) != map2[pos].end())
        {
            return map2[pos][k];
        }

        if (k < abs(pos - en))
            return 0;

        const int MOD = 1e9 + 7;
        long long ans = 0LL;

        ans = ((ans + dfsa1(map2, pos - 1, k - 1, en)) % MOD + dfsa1(map2, pos + 1, k - 1, en)) % MOD;

        map2[pos][k] = (int) ans;
        return ans;
    }

};

int main()
{

    LT2400 lt;

    int st = 1, en = 2, k = 1113;


    cout << lt.lt2400a(st, en, k) << endl;

    return 0;
}
