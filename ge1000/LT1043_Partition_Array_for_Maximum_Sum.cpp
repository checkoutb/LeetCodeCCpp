
#include "../header/myheader.h"

class LT1043
{
public:

// D D

//for(int j=1;j<=min(i,k);j++)

//            for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
//                curMax = Math.max(curMax, A[i - k + 1]);
//                dp[i] = Math.max(dp[i], (i >= k ? dp[i - k] : 0) + curMax * k);
//            }

// dfs + memo
//        for (int i = start; i < Math.min(n, start + K); i++) {
//            maxEle = Math.max(maxEle, A[i]);
//            maxSum = Math.max(maxSum, maxEle * (i - start + 1) + dfs(A, K, i + 1, dp));
//        }


//Runtime: 28 ms, faster than 65.35% of C++ online submissions for Partition Array for Maximum Sum.
//Memory Usage: 8.9 MB, less than 5.20% of C++ online submissions for Partition Array for Maximum Sum.
    int lt1043a(vector<int>& arr, int k)
    {
        vector<int> dp(arr.size(), 0);
        dp[0] = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            dp[i] = arr[i] + dp[i - 1];
            int mx = arr[i];
            for (int j = 1; j < k && i-j>=0; j++)
            {
                mx = max(mx, arr[i-j]);
                dp[i] = max(dp[i], (i-j-1 < 0 ? 0 : dp[i-j-1]) + mx * j + mx);
            }
        }
        return dp[dp.size() - 1];
    }

};

int main()
{

//    vector<int> v = {1,15,7,9,2,5,10};
//    int k = 3;

//    vector<int> v = {1,4,1,5,7,3,6,1,9,9,3};
//    int k = 4;

    vector<int> v = {1,2};
    int k = 2;

    LT1043 lt;

    cout<<lt.lt1043a(v, k)<<endl;

    return 0;
}
