
#include "../header/myheader.h"

class LT0935
{
public:

// D D

//vector<vector<int>> ms = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
//int knightDialer(int N) {
//  vector<int> d1(10, 1), d2(10);
//  for (; --N > 0; swap(d1, d2))
//    for (auto i = 0; i < 10; ++i)
//        d2[i] = accumulate(begin(ms[i]), end(ms[i]), 0, [&](int s, int i) {return (s + d1[i]) % 1000000007;});
//  return accumulate(begin(d1), end(d1), 0, [](int s, int n) {return (s + n) % 1000000007;});
//}



//Runtime: 162 ms, faster than 67.94% of C++ online submissions for Knight Dialer.
//Memory Usage: 6.2 MB, less than 90.61% of C++ online submissions for Knight Dialer.
    int lt0935a(int N)
    {
//        if (N == 1)
//            return 10;

        const int MOD = 1e9 + 7;
        int arr[10] = {0};
//        std::fill(begin(arr) + 1, end(arr), 1);
        std::fill(begin(arr), end(arr), 1);
        int arr2[10] = {0};
        vector<vector<int>> vvi = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        while (N-- > 1)
        {
//            std::fill(begin(arr2), end(arr2), 0);
            for (int i = 0; i < 10; ++i)
            {
                for (int j = 0; j < vvi[i].size(); ++j)
                {
                    arr2[vvi[i][j]] = (arr[i] + arr2[vvi[i][j]]) % MOD;
                }
            }
            for (int i = 0; i < 10; ++i)
            {
                arr[i] = arr2[i];
                arr2[i] = 0;
            }
        }

        int ans = 0;
        for (int i = 0; i < 10; ++i)
            ans = (ans + arr[i]) % MOD;
        return ans;
    }

};

int main()
{

    LT0935 lt;

    int n = 3131;

    cout<<lt.lt0935a(n)<<endl;

    return 0;
}
