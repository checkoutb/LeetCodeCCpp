
#include "../header/myheader.h"

class LT1029
{
public:


// D D

//  sort(begin(cs), end(cs), [](vector<int> &v1, vector<int> &v2) {
//    return (v1[0] - v1[1] < v2[0] - v2[1]);
//  });
//  for (auto i = 0; i < cs.size() / 2; ++i) {
//    res += cs[i][0] + cs[i + cs.size() / 2][1];
//  }
//  return res;
// 前一半选a，后一半选b。。。 但是 这里好像没有处理距离差为负数啊。为什么？
// 。。。距离差为负数，说明前面的小，那么肯定选前面的。
// 我的是 abs距离差 越大，就越先作出选择。
// [[1,10000],[10,20],[20,10],[123,223]]
// 不需要处理 负数，或者说  前一半选a，后一半选b，就是在处理负数。  排序的时候 就已经做好选择了。

//  nth_element(begin(cs), begin(cs) + cs.size() / 2, end(cs), [](vector<int> &a, vector<int> &b) {
//    return (a[0] - a[1] < b[0] - b[1]);
//  });
//  for (auto i = 0; i < cs.size() / 2; ++i) {
//    res += cs[i][0] + cs[i + cs.size() / 2][1];
//  }
//  return res;


//        int N = costs.length / 2;
//        int[][] dp = new int[N + 1][N + 1];
//        for (int i = 1; i <= N; i++) {
//            dp[i][0] = dp[i - 1][0] + costs[i - 1][0];
//        }
//        for (int j = 1; j <= N; j++) {
//            dp[0][j] = dp[0][j - 1] + costs[j - 1][1];
//        }
//        for (int i = 1; i <= N; i++) {
//            for (int j = 1; j <= N; j++) {
//                dp[i][j] = Math.min(dp[i - 1][j] + costs[i + j - 1][0], dp[i][j - 1] + costs[i + j - 1][1]);
//            }
//        }
//        return dp[N][N];




// 应该能直接排序costs，不必vp。。 return abs(cost[1]-cost[0]) > abs(cost[1]-cost[0])
//Runtime: 4 ms, faster than 98.77% of C++ online submissions for Two City Scheduling.
//Memory Usage: 8.4 MB, less than 17.39% of C++ online submissions for Two City Scheduling.
    int lt1029a(vector<vector<int>>& costs)
    {
        vector<pair<int, int>> vp;
        for (int i = 0; i < costs.size(); i++)
        {
            vector<int>& v = costs[i];
            vp.push_back(std::make_pair(std::abs(v[1] - v[0]), i));
        }
        std::sort(begin(vp), end(vp), [](pair<int, int>& p1, pair<int, int>& p2) { return p1.first > p2.first; });

        #ifdef __test
        for (pair<int, int>& p : vp)
        {
            cout<<p.first<<", "<<p.second<<endl;
        }
        #endif // __test

        int ans = 0;
        int numa = 0;
        int numb = 0;
        int nummax = costs.size() / 2;
        for (pair<int, int>& p : vp)
        {
            vector<int> v = costs[p.second];
            if (v[0] == v[1])
            {
                ans += v[0];
                continue;
            }
            if (v[0] > v[1])
            {
                if (numb < nummax)
                {
                    numb++;
                    ans += v[1];
                }
                else
                {
                    numa++;
                    ans += v[0];
                }
            }
            else
            {
                if (numa < nummax)
                {
                    numa++;
                    ans += v[0];
                }
                else
                {
                    numb++;
                    ans += v[1];
                }
            }
        }

        return ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{10,20},{30,200},{400,50},{30,20}};
//    vector<vector<int>> vv = {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
    vector<vector<int>> vv = {{515,563},{451,713},{537,709},{343,819},{855,779},{457,60},{650,359},{631,42}};

    LT1029 lt;

    cout<<lt.lt1029a(vv)<<endl;

    return 0;
}
