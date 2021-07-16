
#include "../header/myheader.h"

class LT1388
{
public:

// D D


//public int maxSizeSlices(int[] slices) {
//	int m = slices.length, n = m / 3;
//	int[] slices1 = Arrays.copyOfRange(slices, 0, m-1);
//	int[] slices2 = Arrays.copyOfRange(slices, 1, m);
//	return Math.max(maxSum(slices1, n), maxSum(slices2, n));
//}
//
//int maxSum(int[] arr, int n) { // max sum when pick `n` non-adjacent elements from `arr`
//	int m = arr.length;
//	int[][] dp = new int[m+1][n+1]; // dp[i][j] is maximum sum which we pick `j` elements from linear array `i` elements
//	// Case j = 0 (pick 0 elements): dp[i][0] = 0
//	// Case i = 0 (array is empty): dp[0][j] = 0
//	for (int i = 1; i <= m; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			if (i == 1) { // array has only 1 element
//				dp[i][j] = arr[0]; // pick that element
//			} else {
//				dp[i][j] = Math.max(
//					dp[i-1][j],             // don't pick element `ith`
//					dp[i-2][j-1] + arr[i-1] // pick element `ith` -> dp[i-2][j-1] means choose `j-1` elements from array `i-2` elements
//											//   because we exclude adjacent element `(i-1)th`
//				);
//			}
//		}
//	}
//	return dp[m][n];
//}


//        def dp(i, j, k, cycle=0):
//            if k == 1: return max(A[i:j + 1])
//            if j - i + 1 < k * 2 - 1: return -float('inf')
//            return max(dp(i + cycle, j - 2, k - 1) + A[j], dp(i, j - 1, k))
//        return dp(0, len(A) - 1, len(A) // 3, 1)




// 那么的难，却又那么的难。。。。。。
//Runtime: 20 ms, faster than 61.11% of C++ online submissions for Pizza With 3n Slices.
//Memory Usage: 14.3 MB, less than 43.05% of C++ online submissions for Pizza With 3n Slices.
// hint: Given an integer array with size 3N,
//        select N integers with maximum sum and any selected integers are not next to each other in the array.
// hint: dp
    int lt1388c(vector<int>& slices)
    {
        int sz1 = slices.size();
        int n3 = sz1 / 3;
        vector<vector<int>> vvi(sz1, vector<int>(n3 + 1, -1));       // 这个数字用了，并且已经用了几次的情况下，最大值多少。
        int ans = 0;
        vector<vector<int>> vv2(sz1, vector<int>(n3 + 1, -1));

        vvi[0][1] = slices[0];
        for (int i = 1; i < sz1 - 1; ++i)
            vvi[i][1] = max(slices[i], vvi[i - 1][1]);
        for (int i = 2; i <= n3; ++i)
            for (int j = i; j < sz1 - 1; ++j)
                vvi[j][i] = max(vvi[j - 2][i - 1] + slices[j], vvi[j - 1][i]);

        vv2[1][1] = slices[1];
        for (int i = 2; i < sz1; ++i)
            vv2[i][1] = max(slices[i], vv2[i - 1][1]);
        for (int i = 2; i <= n3; ++i)
            for (int j = i; j < sz1; ++j)
                vv2[j][i] = max(vv2[j - 2][i - 1] + slices[j], vv2[j - 1][i]);

        ans = max(vvi[sz1 - 2][n3], vv2[sz1 - 1][n3]);

        // 最后一个 和 第一个冲突
//        vvi[0][1] = slices[0];
//        for (int i = 1; i < sz1; ++i)
//        {
//            vvi[i][1] = max(slices[i], vvi[i - 1][1]);
//        }
//        for (int i = 2; i <= n3; ++i)
//        {
//            int mx = vvi[i - 1][0];
//            for (int j = i; j < sz1; ++j)
//            {
//                vvi[j][i] = max(vvi[j - 2][i - 1] + slices[j], vvi[j - 1][i]);
//            }
//        }


        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        cout<<" ========== "<<endl;
        for (myvi& vi : vv2)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test

//        ans = vvi[sz1 - 1][n3];
        return ans;
    }


// 剩3个的时候 max，其他的时候，选择一个以后， 2侧的就被其他人拿走， 剩下的就是上一层的dp结果。
// 还是哪个问题，  如果拿中间的， 那么前面 和后面 组合起来， 上一层并没有计算。
    int lt1388b(vector<int>& slices)
    {
        return -1;
    }



// error,  不能max，
// alice 前面一个， bob拿后面一个。  我最多拿多少。
// greedy，example 2 过不去。
// dp，好像可以， 比如只有3个， 那么肯定知道的， 6个，就是 某3个 + 另外3个，  由于之前已经算过所有3个的情况，所以很快能计算出来，不过更像
// 所以是第一个子问题， 3个3个的划分，3个里最大值，
//      第二个子问题，6个6个的划分，3个+3个 最大值。
//          9个9个， 3个+6个，或者6个+3个(还是3+6的划分)。
//          12，12, 3+9          6+6不需要。
    int lt1388a(vector<int>& slices)
    {
        int sz1 = slices.size();
        int n3 = sz1 / 3;        // 层数。      一维也可以       // 3个元素的时候  只需要0. ... 这个是长度。。
//        vector<int> vi(sz1, 0);
        vector<vector<int>> vvi(n3, vector<int>(sz1, 0));
        int t1 = slices[0], t2 = slices[1], t3 = slices[2];
        for (int i = 0; i < sz1; ++i)           // 以这个下标开始的3个的最大值，  就是只剩这3块的时候，我选什么。
        {
            vvi[0][i] = max(t1, max(t2, t3));
            t1 = t2;
            t2 = t3;
            t3 = slices[(i + 3) % sz1];
        }
        for (int i = 1; i < n3; ++i)
        {
            int len2 = (i + 1) * 3;
            for (int j = 0; j < sz1; ++j)       // 以j开始的 (i+1)*3 个批萨 的最大值。
            {
                int mx = 0;     // 应该只有3种可能。   .. 边界条件不对的。  每次都得自己算3,    另外的一部分用之前的结果。
                // 前3个， 前2个加最后一个， 前1个加最后2个。。  更多的可能呢？ 这样会拆分 另一部分，会非常。。  dp就无意义了。
                // bububu, 好像是每次都算3, 然后加上 另外一部分， 组成现在的长度。  不是。
                // 算3.。
                // 。。。。 你在中间拿3个，   剩下的是 前面和后面， 剩下的这些，它没有dp记录啊。  不过这种中间拿3个，是不是已经包含在 其他部分的最优中了。
                // 4种， 算3.   还是2种，算3
                mx = max(vvi[0][j] + vvi[i - 1][(j + 3) % sz1], vvi[0][(j + len2 - 3) % sz1] + vvi[i - 1][j]);
                int t3 = max(slices[j], max(slices[(j + 1) % sz1], slices[(j + len2 - 1) % sz1]));             // 0,1 + last
                int t4 = max(slices[j], max(slices[(j + len2 - 1) % sz1], slices[(j + len2 - 2) % sz1]));                  // 0 + last-1 + last
                mx = max(mx, max(t3, t4));
                vvi[i][j] = mx;

//                for (int k = 0; k < 3; ++k)
//                {
//
//                }
//                int mx = 0;
//                for (int k = 0; k < (i + 1) * 3; ++k)
//                {
//                    mx = max(mx, vvi[0][(j + k) % sz1] + vvi[i - 1][(j + k + 3) % sz1]);
//                }
//                vvi[i][j] = mx;
            }
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            ans = max(ans, vvi[n3 - 1][i]);
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,2,3,4,5,6};         // 10
//    myvi v = {8,9,8,6,1,1};       // 16
//    myvi v = {4,1,2,5,8,3,1,9,7};       // 21
//    myvi v = {3,1,2};

    myvi v = {9,5,1,7,8,4,4,5,5,8,7,7};     // 30



    showVectorInt(v);

    LT1388 lt;

    cout<<lt.lt1388c(v)<<endl;

    return 0;
}
