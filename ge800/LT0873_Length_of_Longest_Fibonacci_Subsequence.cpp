
#include "../header/myheader.h"

class LT0873
{
public:


// D D
//b = a + b, a = b - a, l++;


//dp[a, b] represents the length of fibo sequence ends up with (a, b)
//dp[a, b] = (dp[b - a, a] + 1 ) or 2
//        for (int j = 0; j < N; ++j) {
//            m[A[j]] = j;
//            for (int i = 0; i < j; ++i) {
//                int k = m.find(A[j] - A[i]) == m.end() ? -1 : m[A[j] - A[i]];
//                dp[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? dp[k][i] + 1 : 2;
//                res = max(res, dp[i][j]);
//            }
//        }



//        for (int i = 2; i < n; i++) {
//            int l = 0, r = i - 1;
//	        while (l < r) {
//                int sum = A[l] + A[r];
//                if (sum > A[i]) {
//                    r--;
//                } else if (sum < A[i]) {
//                    l++;
//                } else {
//                    dp[r][i] = dp[l][r] + 1;
//                    max = Math.max(max, dp[r][i]);
//                    r--;
//                    l++;
//                }
//            }
//        }



//Runtime: 884 ms, faster than 5.05% of C++ online submissions for Length of Longest Fibonacci Subsequence.
//Memory Usage: 9.3 MB, less than 61.09% of C++ online submissions for Length of Longest Fibonacci Subsequence.
// 严格递增，不可能有1,1
// set包含(j-i),那么 i,(j-i),j 是有序的。
    int lt0873a(vector<int>& A)
    {
        unordered_set<int> set1(begin(A), end(A));
        unordered_set<long long> set2;
        long long ll1 = 1E9L;

        int ans = 2;
        for (int i = 0; i < A.size() - ans; i++)
        {
            for (int j = i + 1; j < A.size() - ans + 1; j++)
            {
                int t1 = A[i];
                int t2 = A[j];
                if (set2.find(ll1 * t1 + t2) != set2.end())
                    continue;
                int a3 = 2;
                int t3 = t1 + t2;

                while (set1.find(t3) != set1.end())
                {
                    set2.insert(ll1 * t1 + t2);
                    a3++;
                    t1 = t2;
                    t2 = t3;
                    t3 = t1 + t2;
                }
                ans = max(ans, a3);
            }
        }
        return ans > 2 ? ans : 0;
    }


    int test1(vector<int>& a)
    {
        unordered_set<int> set1(begin(a), end(a));
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = i + 1; j < a.size(); j++)
            {
                int t1 = a[i];
                int t2 = a[j];
                int ans2 = 2;
                while (set1.find(t1 + t2) != set1.end())
                {
                    ans2++;
                    int t3 = t1;
                    t1 = t2;
                    t2 = t2 + t3;
                }
                if (ans2 >= ans)
                {
                    cout<<ans2<<", "<<ans<<", "<<i<<", "<<j<<endl;
                    ans = ans2;
                }
            }
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {1,2,3,4,5,6,7,8};

//    vector<int> v = {1,3,7,11,12,14,18};

//    vector<int> v = {1,2,3};

    vector<int> v = {2,4,7,8,9,10,14,15,18,23,32,50};       // 5

    LT0873 lt;

    cout<<lt.lt0873a(v)<<endl;

    cout<<" ============== ="<<endl;
    cout<<lt.test1(v)<<endl;

    return 0;
}
