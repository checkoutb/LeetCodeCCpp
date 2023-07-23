
#include "../../header/myheader.h"

class LT6942
{
public:







// 326 / 24528	Ouha 	13	0:48:10	0:05:05 	0:10:16 	0:38:10 2

// 第三题 1.8% 的通过率，真刺激。
//Accepted
//258
//Submissions
//14K
//Acceptance Rate
//1.8%


//[-1,5,0,5,5,2]
//"xsbcqq"
//  0
//  2
//  5
// 1 3 4
// ans： 7   。 qq bqq

    // TLE。。。 gg
    // map, unordered_map , both tle
    // vector<pair<int, int>> ？？？？

    // palindrom .. 0 or 1 .
    long long countPalindromePaths(vector<int>& parent, string s)
    {
        int sz1 = parent.size();
        vector<vector<int>> vvi(sz1);       // [idx]'s children
        for (int i = 1; i < sz1; ++i)
        {
            vvi[parent[i]].push_back(i);
        }
        long long ans = 0LL;
        dfsa1(vvi, 0, s, ans);
        return ans;
    }

    unordered_map<int, int> dfsa1(vector<vector<int>>& vvi, int node, string& s, long long& ans)
    {
        unordered_map<int, int> map2;
//        int t2 = (1 << s[node])
        for (int nxt : vvi[node])
        {
            unordered_map<int, int> map3 = dfsa1(vvi, nxt, s, ans);
            for (auto& p3 : map3)
            {
                for (auto& p2 : map2)
                {
                    int t3 = p2.first ^ p3.first;
                    if (t3 == 0 || (t3 & (t3 - 1)) == 0)
                    {
                        ans += 1LL * p3.second * p2.second;
                    }
                }
            }
            for (auto& p3 : map3)
            {
                map2[p3.first] += p3.second;
            }
        }
        if (node == 0)
            return map2;

        int t2 = (1 << (s[node] - 'a'));
        unordered_map<int, int> map4;
        int t3 = 0;
        for (auto& p2 : map2)
        {
            t3 = p2.first ^ t2;
            if (t3 == 0 || (t3 & (t3 - 1)) == 0)
            {
                ans += p2.second;
            }
            map4[t3] = p2.second;
        }
        map4[t2] += 1;
        ans += 1;
        return map4;
    }

};

int main()
{

    LT6942 lt;


    return 0;
}
