
#include "../header/myheader.h"

class LT0123
{
public:

    // D D

    //int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
    //int release1 = 0, release2 = 0;
    //for (int i : prices) {                              // Assume we only have 0 money at first
    //    release2 = Math.max(release2, hold2 + i);     // The maximum if we've just sold 2nd stock so far.
    //    hold2 = Math.max(hold2, release1 - i);  // The maximum if we've just buy  2nd stock so far.
    //    release1 = Math.max(release1, hold1 + i);     // The maximum if we've just sold 1nd stock so far.
    //    hold1 = Math.max(hold1, -i);          // The maximum if we've just buy  1st stock so far. 
    //}
    //return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.


    //dp[k, i] = max(dp[k, i - 1], prices[i] - prices[j] + dp[k - 1, j - 1]), j = [0..i - 1]
    // 
    //var dp = new int[3, prices.Length];
    //for (int k = 1; k <= 2; k++) {
    //    int min = prices[0];
    //    for (int i = 1; i < prices.Length; i++) {
    //        min = Math.Min(min, prices[i] - dp[k - 1, i - 1]);
    //        dp[k, i] = Math.Max(dp[k, i - 1], prices[i] - min);
    //    }
    //}
    // Ê²Ã´ÓïÑÔ£¿ c# ?


//Runtime: 196 ms, faster than 86.60 % of C++ online submissions for Best Time to Buyand Sell Stock III.
//Memory Usage : 78.4 MB, less than 66.26 % of C++ online submissions for Best Time to Buyand Sell Stock III.
    int lt0123a(vector<int>& prices)
    {
        int sz1 = prices.size();
        vector<int> vi(sz1, 0);
        int pfx = prices[0];
        for (int i = 1; i < sz1; ++i)
        {
            if (prices[i] >= pfx)
            {
                vi[i] = prices[i] - pfx;
            }
            else
            {
                pfx = prices[i];
            }
            vi[i] = max(vi[i], vi[i - 1]);
        }

        int ans = vi[sz1 - 1];
        int sfx = prices[sz1 - 1];
        for (int i = sz1 - 2; i > 0; --i)
        {
            if (sfx >= prices[i])
                ans = max(ans, vi[i - 1] + sfx - prices[i]);
            else
                sfx = max(prices[i], sfx);
        }
        return ans;
    }

};

int main()
{

    LT0123 lt;

    //myvi v = { 3,3,5,0,0,3,1,4 };
    //myvi v = { 1,2,3,4,5 };
    //myvi v = { 5,4,3,10,2,1 };
    myvi v = { 1,2 };

    cout << lt.lt0123a(v) << endl;

    return 0;
}
