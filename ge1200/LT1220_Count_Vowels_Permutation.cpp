
#include "../header/myheader.h"

class LT1220
{
public:

// D D


//  // 'a', 'e', 'i', 'o', 'u'
//  vector<vector<int>> moves = { {1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, { 0 } }, v(2, vector<int>(5, 1));
//  while (--n > 0) {
//    for (auto i = 0; i < 5; ++i)
//      v[(n + 1) % 2][i] = accumulate(begin(moves[i]), end(moves[i]), 0,
//        [&](int s, int j) {return (s + v[n % 2][j]) % 1000000007; });
//  }
//  return accumulate(begin(v[0]), end(v[0]), 0, [](int s, int n) { return (s + n) % 1000000007; });


//    for(int i = 0; i < 5; i++)
//        dp[1][i] = 1;
//    for(int i = 1; i < n; i++)
//    {
//        dp[i+1][0] = (dp[i][1] + dp[i][2] + dp[i][4]) %MOD;
//        dp[i+1][1] = (dp[i][0] + dp[i][2]) % MOD;
//        dp[i+1][2] = (dp[i][1] + dp[i][3]) % MOD;
//        dp[i+1][3] = dp[i][2];
//        dp[i+1][4] = (dp[i][2] + dp[i][3]) % MOD;
//    }




//Runtime: 12 ms, faster than 67.82% of C++ online submissions for Count Vowels Permutation.
//Memory Usage: 6.2 MB, less than 5.18% of C++ online submissions for Count Vowels Permutation.
//  "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
// a:1{e}, e:2{a,i}, i:4{a,e,o,u}, o:2{ui}, u:1{a}
    int lt1220a(int n)
    {
        int arr[5] = {1,1,1,1,1};
        int arr2[5][5] = {{0,1,0,0,0},{1,0,1,0,0},{1,1,0,1,1},{0,0,1,0,1},{1,0,0,0,0}};
//        int arr3[5] = {1,2,4,2,1};
        int arr4[5] = {0};
        int ans = 0;
        int mod = 1E9 + 7;

        while (n-- > 1)
        {
            for (int i = 0; i < 5; i++)
                arr4[i] = 0;

            for (int i = 0; i < 5; i++)
            {
//                int t1 = arr[i] * arr3[i];
                for (int j = 0; j < 5; ++j)
                {
//                    arr[i] = (arr[i] ) % mod;
                    if (arr2[i][j] == 1)
                    {
                        arr4[j] = (arr4[j] + arr[i]) % mod;
                    }
                }
            }
            for (int i = 0; i < 5; i++)
            {
                arr[i] = arr4[i];
            }
        }

//        ans = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
        for (int i = 0; i < 5; i++)
        {
            ans = (ans + arr[i]) % mod;
        }
        return ans;
    }

};

int main()
{

    vector<int> v = {1,2,5};

    LT1220 lt;

    for (int i : v)
        cout<<lt.lt1220a(i)<<endl;

    return 0;
}
