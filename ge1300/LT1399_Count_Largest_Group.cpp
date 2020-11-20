
#include "../header/myheader.h"

class LT1399
{
public:

// D D

//int dsum(int n) {
//    return n == 0 ? 0 : n % 10 + dsum(n / 10);
//}
//int countLargestGroup(int n) {
//    int cnt[37] = {}, mx = 0;
//    for (auto i = 1; i <= n; ++i)
//        mx = max(mx, ++cnt[dsum(i)]);
//    return count_if(begin(cnt), end(cnt), [&mx](int n) { return n == mx; });
//}


//    return len(multimode(sum(map(int, str(i))) for i in range(1, n+1)))


//        for (int i = 1; i <= n; i++) {
//            dp[i] = i % 10 + dp[i / 10];
//            map.put(dp[i], map.getOrDefault(dp[i], 0) + 1);
//        }
// .. dp[i] = i % 10 + dp[i / 10];



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Largest Group.
//Memory Usage: 6.4 MB, less than 35.52% of C++ online submissions for Count Largest Group.
// 9999 36
    int lt1399a(int n)
    {
        int map2[40] = {0};
        int arr[5] = {0};
        int sum2 = 0;
        for (int i = 1; i <= n; ++i)
        {
            int idx = 4;
            while (idx >= 0)
            {
                if (arr[idx] < 9)
                {
                    arr[idx]++;
                    sum2++;
                    break;
                }
                else
                {
                    arr[idx] = 0;
                    sum2 -= 9;
                }
                idx--;
            }
            map2[sum2]++;
        }
        int ans = -1;
//        #ifdef __test
//        for (int i = 0; i < 40; ++i)
//        {
//            cout<<i<<" : "<<map2[i]<<endl;
//        }
//        #endif // __test
        map<int, int> map3;
        for (int i = 0; i < 40; i++)
        {
            if (map2[i])
                map3[map2[i]]++;
        }
        return map3.rbegin()->second;
    }

};

int main()
{

//    int n = 13;
    vector<int> v = {13,2,15,24};

    LT1399 lt;

    for (int n : v)
        cout<<lt.lt1399a(n)<<endl;

    return 0;
}
