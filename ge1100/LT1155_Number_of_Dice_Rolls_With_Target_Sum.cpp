
#include "../header/myheader.h"

class LT1155
{
public:

// D D

//  int dp[target + 1] = { 1 }, i, j, k;
//  for (i = 1; i <= d; ++i)
//    for (k = target; k >= (i == d ? target : 0); --k)
//      for (j = k - 1, dp[k] = 0; j >= max(0, k - f); --j)
//        dp[k] = (dp[k] + dp[j]) % 1000000007;
//  return dp[target];


//int dp[31][1001] = {};
//int numRollsToTarget(int d, int f, int target, int res = 0) {
//  if (d == 0 || target <= 0) return d == target;
//  if (dp[d][target]) return dp[d][target] - 1;
//  for (auto i = 1; i <= f; ++i)
//    res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
//  dp[d][target] = res + 1;
//  return res;
//}


//	final Map<String, Integer> memo = new HashMap<>();
//	final int MOD = 1000000007;
//
//	public int numRollsToTarget(int d, int f, int target) {
//		if (target > d * f || target < d) return 0;
//		if (d == 1) return (target <= f) ? 1 : 0;
//
//		final String key = "" + d + f + target;
//
//		if (! memo.containsKey(key)) {
//			int currentSum = 0;
//
//			for (int i = f; i > 0; i--) {
//				currentSum += numRollsToTarget(d - 1, f, target - i);
//				currentSum %= MOD;
//			}
//			memo.put(key, currentSum);
//		}
//		return memo.get(key);
//	}





//Runtime: 48 ms, faster than 44.44% of C++ online submissions for Number of Dice Rolls With Target Sum.
//Memory Usage: 8.9 MB, less than 5.92% of C++ online submissions for Number of Dice Rolls With Target Sum.
    int lt1155a(int d, int f, int target)
    {
        int ans = 0;
//        int arr[d + 1][target + 1] = {{0}};           // leetcode buzhichi zhezhong xiefa.
        vector<vector<int>> arr(d + 1, vector<int>(target + 1, 0));
        for (int i = 1; i <= target; i++)
            arr[0][i] = 0;

        int t2 = 0;
        int mod = 1E9 + 7;
        for (int j = 1; j <= f && j <= target; j++)
        {
            arr[1][j] = 1;
        }
        for (int i = 2; i <= d; i++)         // 第i个色子
        {
            for (int j = 1; j <= f; j++)        // 面
            {
//                arr[i][j] = 1;
                for (int k = 0; k <= target; k++)          // 截止上一个色子的值的次数。
                {
                    if (arr[i - 1][k] == 0)
                        continue;
                    t2 = k + j;
                    if (t2 <= target)
                    {
//                        cout<<t2<<endl;
                        arr[i][t2] = (arr[i][t2] + arr[i - 1][k]) % mod;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        #ifdef __test
        for (int i = 0; i <= d; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                cout<<arr[i][j]<<", ";
            }
            cout<<endl;
        }
        #endif // __test
        ans = arr[d][target];
        return ans;
    }

};

int main()
{
    int d{1}, f{6}, t{3};
//    int d{2}, f{6}, t{7};
//    int d{2}, f{5}, t{10};
//    int d{1}, f{2}, t{3};

    LT1155 lt;

    cout<<lt.lt1155a(d,f,t)<<endl;

    return 0;
}
