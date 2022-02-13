
#include "../header/myheader.h"

class LT2008
{
public:


// D D

//        for(int i = 0 ; i < rides.size(); i++)
//        {
//            mp[rides[i][0]].push_back({rides[i][1], rides[i][1] - rides[i][0] + rides[i][2]});
//        }
//
//        for(int i = 1 ; i <= n ; i++) {
//            dp[i] = max(dp[i], dp[i-1]);
//            for(int j = 0 ; j < mp[i].size(); j++)
//            {
//                dp[mp[i][j].first] = max(dp[mp[i][j].first], dp[i] + mp[i][j].second);
//            }
//        }



//    sort(rides.begin(), rides.end(), [](auto &f, auto&s)->bool { return f[1] < s[1]; });
//    for (int i = 1, j = 0; i <= n; ++i) {
//      dp[i] = dp[i - 1];
//      while (j < rides.size() && i == rides[j][1]) {
//        int s = rides[j][0], t = rides[j][2];
//        dp[i] = max(dp[i], dp[s] + i - s + t);
//        ++j;
//      }
//    }



//    long long dp[100001] = {}, pos = 0;
//    sort(begin(rides), end(rides));
//    for (const auto &r : rides) {
//        for (; pos < r[0]; ++pos)
//            dp[pos + 1] = max(dp[pos + 1], dp[pos]);
//        dp[r[1]] = max(dp[r[1]], dp[r[0]] + r[1] - r[0] + r[2]);
//    }
//    return *max_element(begin(dp), begin(dp) + n + 1);


//        sort(A.begin(), A.end());
//        vector<long long> dp(n+1);
//        int j = 0;
//        for(int i = 1; i <= n; ++i) {
//            dp[i] = max(dp[i], dp[i - 1]);
//            while (j < A.size() && A[j][0] == i)
//                dp[A[j++][1]] = max(dp[A[j][1]], dp[i] + A[j][1] - A[j][0] + A[j][2]);
//        }
//        return dp[n];

//。。。。 dp 到 n。。。



// for -> lower_bound
//Runtime: 528 ms, faster than 77.14% of C++ online submissions for Maximum Earnings From Taxi.
//Memory Usage: 98.3 MB, less than 94.88% of C++ online submissions for Maximum Earnings From Taxi.
//tle...
// sort, 从后往前。
    long long lt2008a(int n, vector<vector<int>>& rides)
    {
        int sz1 = rides.size();
        long long ans = 1LL;
        sort(begin(rides), end(rides)
//        , [](vector<int>& v1, vector<int>& v2){
//
//        }
        );      // order by start

        vector<long long> vi(sz1, 0);

        vi[sz1 - 1] = rides[sz1 - 1][1] - rides[sz1 - 1][0] + rides[sz1 - 1][2];
        for (int i = sz1 - 2; i >= 0; i--)
        {
            int en = rides[i][1];
            long long t2 = 0;
            int j = i + 1;

            vector<vector<int>>::iterator it = lower_bound(begin(rides) + i + 1, end(rides), en, [](const vector<int>& vi, int en){
                return vi[0] < en;
            });
            if (it != end(rides))
            {
                #ifdef __test

                #endif // __test
                t2 = vi[std::distance(begin(rides), it)];
//                t2 = (long long) it->operator[](1) - it->operator[](0) + it->operator[](2);
            }
//            for (; j < sz1; j++)
//            {
//                if (rides[j][0] >= en)
//                {
//                    t2 = vi[j];
//                    break;
//                }
//            }
            t2 += (long long) rides[i][1] - rides[i][0] + rides[i][2];
            if (vi[i + 1] > t2)
                vi[i] = vi[i + 1];
            else
                vi[i] = t2;
//            vi[i] = max(t2, vi[i + 1]);
        }
        ans = vi[0];
        return ans;
    }

};

int main()
{

    LT2008 lt;

    myvvi vv = {{2,5,4},{1,5,1}};
    int n = 5;

//    myvvi vv = {{1,6,1},{3,10,2},{10,12,3},{11,12,2},{12,15,2},{13,18,1}\
//    ,{1,19,22000}
//    };
//    int n = 20;

    cout<<lt.lt2008a(n, vv)<<endl;

    return 0;
}
