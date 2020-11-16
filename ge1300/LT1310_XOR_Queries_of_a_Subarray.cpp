
#include "../header/myheader.h"

class LT1310
{
public:


// D

// ^ ^ 能还原。。

//        for (int i = 1; i < A.size(); ++i)
//            A[i] ^= A[i - 1];
//        for (auto &q: queries)
//            res.push_back(q[0] > 0 ? A[q[0] - 1] ^ A[q[1]] : A[q[1]]);



// tle...
    vector<int> lt1310a(vector<int>& arr, vector<vector<int>>& queries)
    {
        vector<int> ans(queries.size(), 0);
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

        for (int i = 0; i < queries.size(); ++i)
        {
            int st = queries[i][0];
            int en = queries[i][1];
            int t2 = en;
            while (t2 > st && dp[st][t2] == 0)
            {
                t2--;
            }
            if (dp[st][t2] == 0)
                dp[st][t2] = arr[st];
            while (t2++ < en)
            {
                dp[st][t2] = dp[st][t2 - 1] ^ arr[t2];
            }
            ans[i] = dp[st][en];
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {1,3,4,8};
//    vector<vector<int>> qvv = {{0,1},{1,2},{0,3},{3,3}};

    vector<int> v = {4,8,2,10};
    vector<vector<int>> qvv = {{2,3},{1,3},{0,0},{0,3}};

    LT1310 lt;

    vector<int> vi = lt.lt1310a(v, qvv);

    showVectorInt(vi);

    return 0;
}
