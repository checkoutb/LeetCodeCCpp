
#include "../header/myheader.h"

class LT0823
{
public:

// D D

//        unordered_map<int, long> dp;
//        for (int i = 0; i < A.size(); ++i) {
//            dp[A[i]] = 1;
//            for (int j = 0; j < i; ++j)
//                if (A[i] % A[j] == 0)
//                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
//            res = (res + dp[A[i]]) % mod;
//        }
// j 作为 积，而不是 乘数。



//Runtime: 176 ms, faster than 13.09% of C++ online submissions for Binary Trees With Factors.
//Memory Usage: 9.2 MB, less than 61.73% of C++ online submissions for Binary Trees With Factors.
    int lt0823a(vector<int>& arr)
    {
        std::sort(begin(arr), end(arr));
        #ifdef __test
        showVectorInt(arr);
        #endif // __test
        int sz1 = arr.size();
        unordered_map<long, long> map2;
        const int MOD(1E9 + 7);
        for (int i = 0; i < sz1; ++i)
        {
            map2[arr[i]] = 1;       // 以arr[i] 为root 的树的数量。
        }

        for (int i = 0; i < sz1; ++i)
        {
//            for (int j = i; j < sz1; ++j)
            for (int j = 0; j <= i; ++j)            // zhege jiu kyi l .
            {
                long t2 = 1L * arr[i] * arr[j];         // 知道了，因为 j， 现在只能确保 < i的 是已经完整了，但是 j>i了，无法保证j是全的。
                if (map2.find(t2) != map2.end())
                {
                    if (i == j)
                        map2[t2] = (map2[t2] + map2[arr[i]] * map2[arr[j]] % MOD) % MOD;
                    else
                        map2[t2] = (map2[t2] + 2 * (map2[arr[j]] * map2[arr[i]] % MOD)) % MOD;
                }
            }
        }

        int ans = 0;
        for (unordered_map<long, long>::iterator it = begin(map2); it != end(map2); it++)
        {
            #ifdef __test
            cout<<it->first<<" : "<<it->second<<endl;
            #endif // __test
            ans = (ans + it->second) % MOD;
        }
        return ans;
    }

};

int main()
{
//    myvi v = {2,4,16};          // 22422416   4416   224416  422416  16
//    myvi v = {2,4,5,10};

// 777
    myvi v = {45,42,2,18,23,1170,12,41,40,9,47,24,33,28,10,32,29,17
    ,46,11,759,37,6,26,21,49,31,14,19,8,13,7,27,22,3,36,34,38,39,30,43,15,4,16,35,25,20,44,5,48};

    LT0823 lt;

    cout<<lt.lt0823a(v)<<endl;

    return 0;
}
