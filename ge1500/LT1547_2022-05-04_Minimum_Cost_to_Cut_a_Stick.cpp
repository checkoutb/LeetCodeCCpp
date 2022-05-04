
#include "../header/myheader.h"

class LT1547
{
public:

// D D

//        if(cs > ce  ){
//            return 0;
//        }
//        if(dp[cs][ce] != -1){
//            return dp[cs][ce];
//        }
//        int res = INT_MAX;
//        for(int i = cs ; i <= ce ; i++){
//            int left = helper(cuts,   cs ,    i-1 ,      s , cuts[i] );
//            int right = helper(cuts , i+1 ,    ce ,   cuts[i] , e );
//            int ans = left + right + (e - s);
//            res = min(ans , res);
//        }
//        return  dp[cs][ce] = res;
// 。。top-down


//    int dp[102][102] = {};
//    int dfs(vector<int>& cuts, int i, int j) {
//        if (j - i <= 1)
//            return 0;
//        if (!dp[i][j]) {
//            dp[i][j] = INT_MAX;
//            for (auto k = i + 1; k < j; ++k)
//                dp[i][j] = min(dp[i][j],
//                    cuts[j] - cuts[i] + dfs(cuts, i, k) + dfs(cuts, k, j));
//        }
//        return dp[i][j];
//    }
//    int minCost(int n, vector<int>& cuts) {
//        cuts.push_back(0);
//        cuts.push_back(n);
//        sort(begin(cuts), end(cuts));
//        return dfs(cuts, 0, cuts.size() - 1);
//    }


//        A.push_back(0);
//        A.push_back(n);
//        sort(A.begin(), A.end());
//        int k = A.size();
//        vector<vector<int>> dp(k, vector<int>(k));
//        for (int d = 2; d < k; ++d) {
//            for (int i = 0; i < k - d; ++i) {
//                dp[i][i + d] = 1e9;
//                for (int m = i + 1; m < i + d; ++m) {
//                    dp[i][i + d] = min(dp[i][i + d], dp[i][m] + dp[m][i + d] + A[i + d] - A[i]);
//                }
//            }
//        }
//        return dp[0][k - 1];



//Runtime: 120 ms, faster than 31.55% of C++ online submissions for Minimum Cost to Cut a Stick.
//Memory Usage: 10.2 MB, less than 58.65% of C++ online submissions for Minimum Cost to Cut a Stick.
// 从最后一刀开始算
    int lt1547a(int n, vector<int>& cuts)
    {
        int sz1 = cuts.size();
        sort(begin(cuts), end(cuts));
        vector<vector<int>> vvi(sz1, vector<int>(sz1, INT_MAX));
        for (int i = 0; i < sz1; ++i)
        {
            vvi[i][i] = ((i == sz1 - 1) ? n : cuts[i + 1]) - (i == 0 ? 0 : cuts[i - 1]);
        }
        for (int len2 = 1; len2 <= sz1; ++len2)
        {
            for (int i = 0; i < sz1 - len2; ++i)
            {
                int t3 = ((i + len2 == sz1 - 1) ? n : cuts[i + len2 + 1]) - (i == 0 ? 0 : cuts[i - 1]);
                for (int j = i; j <= i + len2; j++)
                {
                    int t2 = t3 + (i < j ? vvi[i][j - 1] : 0) + ((j < i + len2) ? vvi[j + 1][i + len2] : 0);
                    vvi[i][i + len2] = min(vvi[i][i + len2], t2);
                }
            }
        }
        return vvi[0][sz1 - 1];
    }

};

int main()
{

    LT1547 lt;

//    int n(7);
//    myvi v{1,3,4,5};

    int n(9);
    myvi v{5,6,1,4,2};

    cout<<lt.lt1547a(n, v)<<endl;

    return 0;
}
