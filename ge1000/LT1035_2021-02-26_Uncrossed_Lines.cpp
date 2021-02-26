
#include "../header/myheader.h"

class LT1035
{
public:

// D D

//                if(A[i-1]==B[j-1])
//                {
//                    dp[i][j]=dp[i-1][j-1]+1;
//                }
//                else
//                {
//                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                }


//    private int helper(int[] A, int i, int[] B, int j){
//        if(i == A.length || j == B.length) return 0;
//        if(dp[i][j] != null) return dp[i][j];
//        if(A[i] == B[j])
//            dp[i][j] = 1+helper(A, i+1, B, j+1);
//        else
//        	dp[i][j] = Math.max(helper(A, i+1, B, j), helper(A, i, B, j+1));
//        return dp[i][j];
//    }


//int dfs(vector<int>& A, vector<int>& B, int i, int j, vector<vector<int>> &dp) {
//  if (i >= A.size() || j >= B.size()) return 0;
//  if (dp[i][j] != -1) return dp[i][j];
//  auto nj = j;
//  while (nj < B.size() && B[nj] != A[i]) ++nj;
//  return dp[i][j] = max(dfs(A, B, i + 1, j, dp), (nj < B.size() ? 1 : 0) + dfs(A, B, i + 1, nj + 1, dp));
//}
//int maxUncrossedLines(vector<int>& A, vector<int>& B) {
//  vector<vector<int>> dp(A.size(), vector<int>(B.size(), -1));
//  return dfs(A, B, 0, 0, dp);
//}


//Runtime: 16 ms, faster than 64.32% of C++ online submissions for Uncrossed Lines.
//Memory Usage: 13.1 MB, less than 39.20% of C++ online submissions for Uncrossed Lines.
    int lt1035a(vector<int>& A, vector<int>& B)
    {
        int sz1 = A.size();
        int sz2 = B.size();
        vector<vector<int>> vvi(sz1 + 1, vector<int>(sz2 + 1, 0));
        for (int i = 1; i <= sz1; ++i)
        {
            for (int j = 1; j <= sz2; ++j)
            {
                if (A[i - 1] == B[j - 1])
                {
                    vvi[i][j] = max(max(vvi[i - 1][j - 1] + 1, vvi[i - 1][j]), vvi[i][j - 1]);
                }
                else
                {
                    vvi[i][j] = max(vvi[i - 1][j], vvi[i][j - 1]);
                }
            }
        }
        #ifdef __test
        for (myvi& v : vvi)
        {
            for (int i : v)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[sz1][sz2];
    }

};

int main()
{
//    myvi v = {1,4,2};
//    myvi v2 = {1,2,4};

//    myvi v = {2,5,1,2,5};
//    myvi v2 = {10,5,2,1,5,2};

    myvi v = {1,3,7,1,7,5};
    myvi v2 = {1,9,2,5,1};

    LT1035 lt;

    cout<<lt.lt1035a(v, v2);

    return 0;
}
