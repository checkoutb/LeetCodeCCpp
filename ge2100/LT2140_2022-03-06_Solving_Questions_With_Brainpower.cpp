
#include "../header/myheader.h"

class LT2140
{
public:

// D D


//We calculate it going right to left, and the answer for position i is the maximum of:
//
//    Take: points[i] + dp[i + 1 + brainpower[i]],
//    Skip: dp[i + 1].
//
//    long long dp[200001] = {};
//    for (int i = q.size() - 1; i >= 0; --i)
//        dp[i] = max(q[i][0] + dp[q[i][1] + i + 1], dp[i + 1]);
//    return dp[0];





//Runtime: 512 ms, faster than 57.55% of C++ online submissions for Solving Questions With Brainpower.
//Memory Usage: 115.2 MB, less than 73.13% of C++ online submissions for Solving Questions With Brainpower.
// 好费脑子。。
    long long lt2140a(vector<vector<int>>& questions)
    {
        int sz1 = questions.size();
        vector<long long> vll(sz1, 0LL);
        if (questions[0][1] + 1 < sz1)
        {
            vll[questions[0][1] + 1] = questions[0][0];
        }
        long long ans = questions[0][0];
        for (int i = 1; i < sz1; ++i)
        {
            vll[i] = max(vll[i], vll[i - 1]);
            ans = max(vll[i] + questions[i][0], ans);
            if (i + 1 + questions[i][1] < sz1)
            {
                vll[i + 1 + questions[i][1]] = max(vll[i + 1 + questions[i][1]], vll[i] + questions[i][0]);
            }
        }
        return ans;
    }

};

int main()
{

    LT2140 lt;

//    myvvi vv = {{3,2},{4,3},{4,2},{2,5}};
    myvvi vv = {{1,1},{2,2},{3,3},{4,4},{5,5}};

    cout<<lt.lt2140a(vv)<<endl;

    return 0;
}
