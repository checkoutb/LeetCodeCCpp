
#include "../header/myheader.h"

class LT1641
{
public:

// D D

//    for (int i = 1; i <= n + 1; ++i) {
//        sum += i * (i + 1) / 2;
//        res += sum;
//    }
//    1 + (1 + 2) | + 1
//    1 + (1 + 2) + (1 + 2 + 3) | + 1 + (1 + 2) | + 1
//    1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 + 4) | + 1 + (1 + 2) + (1 + 2 + 3) | + 1 + (1 + 2) | + 1
//    1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 + 4) + (1 + 2 + 3 + 4 + 5)| + (#3)
//
//    or
//
//    5 * (5 + 1) / 2 + #3
//    6 * (6 + 1) /2 + #4



//        vector<vector<int>>dp(n + 1, vector<int>(6));
//        for (int i = 1; i <= n; ++i)
//            for (int k = 1; k <= 5; ++k)
//                dp[i][k] = dp[i][k - 1] + (i > 1 ? dp[i - 1][k] : 1);
//        return dp[n][5];
//If k = 1, use only u
//If k = 2, use only o,u
//If k = 3, use only i,o,u
//If k = 4, use only e,i,o,u
//If k = 5, use only a,e,i,o,u


//return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;






//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Sorted Vowel Strings.
//Memory Usage: 6.1 MB, less than 99.75% of C++ online submissions for Count Sorted Vowel Strings.

//"aa","ae","ai","ao","au",
//"ee","ei","eo","eu",
//"ii","io","iu",
//"oo","ou",
//"uu"
// 111 112 113 114 115 122 123 124 125 133 134 135 144 145 155               15, 等于长度2的 前面加个1。。
// 222 223 224 225 233 234 235 244 245 255          10      1 + 2 + 3 + 4
// 333 334 334 344 345 355      6           1 + 2 + 3
// 444 445 455      3                       1 + 2
// 555      1                               1

// 555555
// 444444 444445 444455         // 4的次数     长度
// 333333 333334 333335 333344 333345 333355 333444 333445 333455 333555

// ... 好吧，递推。。  而不是 直接一个公式。。
    int lt1641a(int n)
    {
        int arr[] = {1,1,1,1,1};
        while (n-- > 1)
        {
            for (int i = 3; i >= 0; --i)
            {
                arr[i] += arr[i + 1];
            }
        }

        return arr[4] + arr[3] + arr[2] + arr[1] + arr[0];

//        return std::accumulate(arr, arr + 5);

//        int ans = 5;
//        while (n-- > 1)
//        {
//
//        }
//        return ans;
    }

};

int main()
{

    LT1641 lt;

    cout<<lt.lt1641a(33);

    return 0;
}
