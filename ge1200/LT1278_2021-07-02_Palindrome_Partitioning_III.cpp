
#include "../header/myheader.h"

class LT1278
{
public:

// D D


//        for(int i=0;i<n;i++)dp[i][0]=op[0][i];
//        for(int j=1;j<k;j++){
//            for(int i=1;i<n;i++){
//                if(j>i)continue;
//                for(int l=0;l<i;l++){
//                    dp[i][j]=min(dp[i][j],dp[l][j-1]+op[l+1][i]);
//                }
//            }
//        }
// no t2


// dfs + memo


//Simple Knapsack problem, dp(i,k)=dp(j,k-1)+num_change(s[j+1....i]) for j<i and j+1>=k-1.
// 01 beibao? .. 差不多






//Runtime: 8 ms, faster than 81.23% of C++ online submissions for Palindrome Partitioning III.
//Memory Usage: 6.9 MB, less than 56.69% of C++ online submissions for Palindrome Partitioning III.
// hint 1 & 2
//For each substring calculate the minimum number of steps to make it palindrome and store it in a table.
//Create a dp(pos, cnt) which means the minimum number of characters changed for the suffix of s starting on pos
//        splitting the suffix on cnt chunks.
// 有了hint，简单很多。。
// 自己只想到：  一个回文，可以划分为 3个回文 而不需要任何的替换。 所以是对每个下标，计算下 以这个下标作为开始的最长的回文。
//          但是一个回文 划分为2个回文 就 可能需要替换很多了。
//      而且回文数量>k的时候，需要替换，然后合并，怎么弄。
    int lt1278a(string s, int k)
    {
        int sz1 = s.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i; j < sz1; ++j)
            {
                int chg = 0;
                for (int k = 0; k < (j - i + 1) / 2; ++k)
                {
                    if (s[i + k] != s[j - k])
                        chg++;
                }
                vvi[i][j] = chg;
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
        vector<vector<int>> dp(sz1, vector<int>(k + 1, 0));         // md也不简单。
        for (int i = 0; i < sz1; ++i)
        {
            dp[i][1] = vvi[0][i];
        }
        for (int i = 0; i < sz1; ++i)           // substring 最后一个char的下标
        {
            for (int j = 2; j <= min(i + 1, k); ++j)     // substring一共有 j个 回文
            {
                int t2 = INT_MAX;
                for (int k = 0; k < i; ++k)          // j-1个回文 的 k作为最后一个char的substr
                {
                    #ifdef __test
//                    cout<<"       i"<<i<<", j"<<j<<", k"<<k<<": "<<t2<<endl;
                    #endif // __test
                    if (k >= j-2)           // -1 -2     0>=2-2.  .. 这里的含义是： 开始算j个回文时， 由于3个char无法组成4个回文， 所以 j-1个回文，必须从j-2开始。
//                                j=5时， 4个回文的必须从下标3开始(这个3是作为最后一个元素的，下标4是新string的开始。0123,4个char，能找到4个回文。)
                    {
                        #ifdef __test
//                        cout<<endl<<"   . dp"<<dp[k][j-1]<<", vvi"<<vvi[k+1][i]<<endl;
                        #endif // __test
                        t2 = min(t2, dp[k][j - 1] + vvi[k + 1][i]);      // 3个char 肯定无法组成4个回文的。
                    }
                    #ifdef __test
//                    cout<<t2<<endl;
                    #endif // __test
                }
                dp[i][j] = t2;
                if (t2 == INT_MAX)
                    dp[i][j] = 0;
                #ifdef __test
//                for (myvi& vi : dp)
//                {
//                    for (int i : vi)
//                        cout<<i<<", ";
//                    cout<<endl;
//                }
//                cout<<" ---------- "<<endl;
                #endif // __test
            }
        }
        #ifdef __test
        cout<<endl<<endl;
        for (myvi& vi : dp)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return dp[sz1 - 1][k];
    }

};

int main()
{
//    string s = "abc";
//    int k = 2;

//    string s = "aabbc";
//    int k = 3;

    string s = "leetcode";
    int k = 6;

    LT1278 lt;

    cout<<lt.lt1278a(s, k);

    return 0;
}
