
#include "../header/myheader.h"

class LT0139
{
public:

// D D

//        int n = s.size();
//        vector<bool> dp(n+1, false);
//        // dp[i] - tells us the break status of s[0...i-1]
//        dp[0] = true;
//        for(int i=0; i<n; i++) {
//            if(dp[i]) {
//                for(auto x:wordDict) {
//                    if(s.substr(i, x.size())==x) dp[i+x.size()]=true;
//                }
//            }
//        }
//        return dp[n];
// . 思路和 我的bfs 差不多。。 可惜， dp >> bfs >= dfs




// 时过境迁。 还真dfs。 还有 试图 找到所有 划分，然后找一条路。 可惜 tle。。
// https://github.com/checkoutb/leetcodejava/blob/master/src/ge100/LT0139.java
// ... 大意了，没看submission 就提交了，吓自己了。。 但是之前为什么会  tle 呢。估计是 dfs暴力？
//12/18/2020 10:51	Accepted	24 ms	13.8 MB	cpp
//10/23/2018 15:18	Time Limit Exceeded	N/A	N/A	java
//10/23/2018 14:41	Time Limit Exceeded	N/A	N/A	java
//10/23/2018 14:39	Runtime Error	N/A	N/A	java
//10/23/2018 14:37	Time Limit Exceeded	N/A	N/A	java
//10/23/2018 14:30	Time Limit Exceeded	N/A	N/A	java
//10/23/2018 14:22	Time Limit Exceeded	N/A	N/A	java
//10/23/2018 14:21	Time Limit Exceeded	N/A	N/A	java
//10/23/2018 14:04	Wrong Answer	N/A	N/A	java
//10/23/2018 13:56	Wrong Answer	N/A	N/A	java
//10/23/2018 13:21	Time Limit Exceeded	N/A	N/A	java
//10/22/2018 10:53	Time Limit Exceeded	N/A	N/A	java
//10/22/2018 10:46	Wrong Answer	N/A	N/A	java
//10/22/2018 10:42	Time Limit Exceeded	N/A	N/A	java
    bool lt0139a(string s, vector<string>& wordDict)
    {
        unordered_set<string> set2(begin(wordDict), end(wordDict));
        unordered_set<int> set3;
        queue<int> que1;
        que1.push(0);
        int sz1 = s.size();
        while (!que1.empty())
        {
            int sz2 = que1.size();
            while (sz2-- > 0)
            {
                int st = que1.front();
                if (st == sz1)
                    return true;
                que1.pop();
                for (int i = 1; i + st <= sz1; ++i)
                {
                    if (set3.find(st + i) != set3.end())
                        continue;
                    string s2 = s.substr(st, i);
                    if (set2.find(s2) != set2.end())
                    {
                        que1.push(st + i);
                        set3.insert(st + i);
                    }
                }
            }
        }
        return false;
    }

};

int main()
{
//    string s = "leetcode";
//    vector<string> vs = {"leet", "code"};
//    string s = "applepenapple";
//    vector<string> vs = {"apple", "pen"};
    string s = "catsandog";
    vector<string> vs = {"cats", "dog", "sand", "and", "cat"};


    LT0139 lt;

    cout<<lt.lt0139a(s, vs);

    return 0;
}
