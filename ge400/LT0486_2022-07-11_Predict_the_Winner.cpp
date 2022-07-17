
#include "../header/myheader.h"

class LT0486
{
public:

    // D D


    //private int predictTheWinnerFrom(int[] nums, int i, int j, int[][] memo) {
    //    if (i > j) {
    //        return 0;
    //    }

    //    if (i == j) {
    //        return nums[i];
    //    }

    //    if (memo[i][j] != -1) {
    //        return memo[i][j];
    //    }

    //    int curScore = Math.max(
    //        nums[i] + Math.min(
    //            predictTheWinnerFrom(nums, i + 2, j, memo),
    //            predictTheWinnerFrom(nums, i + 1, j - 1, memo)
    //        ),
    //        nums[j] + Math.min(
    //            predictTheWinnerFrom(nums, i, j - 2, memo),
    //            predictTheWinnerFrom(nums, i + 1, j - 1, memo)
    //        )
    //    );

    //    return memo[i][j] = curScore;
    //}

    // max([i] + min([i+2...j], [i+1...j-1]), [j] + min([i...j-2], [i+1...j-1]))




    //for (int i = 0; i < n; i++) { dp[i][i] = nums[i]; }
    //for (int len = 1; len < n; len++) {
    //    for (int i = 0; i < n - len; i++) {
    //        int j = i + len;
    //        dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
    //    }
    //}
    //return dp[0][n - 1] >= 0;


    // When n is even, we can always consider the array [A B C D]. If A+C>=B+D, the first player will choose A ,else D. Thus the first player always wins.
    // ...更有印象了。。。

    //。。。所以这个，如果是奇数，那么 第一个人 取了以后，就变成偶数个数了，那么岂不是第二个人 。。 不， 主要是不知道 偶数情况下， 始终选择 奇数/偶数下标， 第一个人 是不是能拿到最多的分数。
    //      感觉是可以拿到最多的。。 那这样的话，  偶数情况下，第一个人直接赢，   奇数情况下， [0] + min({1,3,5...}, {2,4,6...})  or [sz1 - 1] + min({0,2,4..}, {1,3,5})   也是可以直接算出来 能不能赢的。
    //          所以 关键是， 只拿 偶数/奇数 下标的情况下， 是不是 最多的。  感觉是的，，因为是一个子问题。




    // 试一下。    不行。
    // [0,0,7,6,5,6,1]          false
    // odd 13, even 12
    // 0 + 12
    // 1 + 12
    // 13 * 2 >= 12+13
    // 1 5 7
    //  6 6
    // 1 5       6
    //  6 0       7
    bool lt0486b(vector<int>& nums)
    {
        if (nums.size() % 2 == 0)
            return true;

        int odd = 0;
        int even = 0;
        int sz1 = nums.size();
        for (int i = 0; i < sz1; ++i)
        {
            if (i % 2)
            {
                odd += nums[i];
            }
            else
            {
                even += nums[i];
            }
        }
        int t2 = nums[0] + min(even - nums[0], odd);
        int t3 = nums[nums.size() - 1] + min(even - nums[nums.size() - 1], odd);
        return max(t2, t3) * 2 >= odd + even;
    }



//Runtime: 6 ms, faster than 52.17 % of C++ online submissions for Predict the Winner.
//Memory Usage : 7.7 MB, less than 23.47 % of C++ online submissions for Predict the Winner.
    // 和最近几天做的一道一样。
    bool lt0486a(vector<int>& nums)
    {
        int sz1 = nums.size();

        vector<int> vi(begin(nums), end(nums));
        
        for (int i = 1; i < sz1; ++i)
        {
            vi[i] += vi[i - 1];
        }

        vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));

        for (int len = 1; len <= sz1; ++len)
        {
            for (int i = 0; i + len <= sz1; ++i)
            {
                if (len == 1)
                {
                    vvi[i][i] = nums[i];
                    continue;
                }
                vvi[i][i + len - 1] = max(nums[i] + (vi[i + len - 1] - (vi[i]) - vvi[i + 1][i + len - 1]), nums[i + len - 1] + (vi[i + len - 2] - (i == 0 ? 0 : vi[i - 1]) - vvi[i][i + len - 2]));
            }
        }
#ifdef __test
        cout << vvi[0][sz1 - 1] << endl;
#endif
        return vvi[0][sz1 - 1] >= (vi[sz1 - 1] - vvi[0][sz1 - 1]);
    }

};

int main()
{

    LT0486 lt;

    //myvi v = { 1,5,2 };
    //myvi v = { 1,3,2 };
    //myvi v = { 1,4,111,3 };

    myvi v = { 0,0,7,6,5,6,1 };

    cout << lt.lt0486a(v) << endl;

    return 0;
}
