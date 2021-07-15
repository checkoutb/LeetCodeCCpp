
#include "../header/myheader.h"

class LT1326
{
public:

// D D

//for (int i = 0; coveredTill < n; coveredTill = farthestReach)

//        vector<int> dp(n + 1, n + 2);
//        dp[0] = 0;
//        for (int i = 0; i <= n; ++i)
//            for (int j = max(i - A[i] + 1, 0); j <= min(i + A[i], n); ++j)
//                dp[j] = min(dp[j], dp[max(0, i - A[i])] + 1);
//        return dp[n]  < n + 2 ? dp[n] : -1;





//Runtime: 16 ms, faster than 77.11% of C++ online submissions for Minimum Number of Taps to Open to Water a Garden.
//Memory Usage: 16.1 MB, less than 19.95% of C++ online submissions for Minimum Number of Taps to Open to Water a Garden.
    int lt1326a(int n, vector<int>& ranges)
    {
        vector<pair<int, int>> vp;      // begin, index
        for (int i = 0; i < ranges.size(); ++i)
        {
            vp.push_back(std::make_pair(i - ranges[i], i));
        }
        std::sort(begin(vp), end(vp), [](pair<int, int>& p1, pair<int, int>& p2)
        {
            if (p1.first != p2.first)
                return p1.first < p2.first;
            else
                return p1.second > p2.second;
        });

//        #ifdef __test
//        for (pair<int, int>& p : vp)
//        {
//            cout<<p.first<<", "<<p.second<<endl;
//        }
//        #endif // __test

        int idx = 0;
        int beg = 0;
        int far = 0;
        int ans = 0;

        while (beg < n)
        {
            for (; idx <= n; idx++)
            {
                if (vp[idx].first > beg)
                {
                    idx--;
                    break;
                }
                far = max(far, vp[idx].second + ranges[vp[idx].second]);
            }
            ans++;
            if (beg == far)
            {
                break;
            }
            #ifdef __test
//            cout<<beg<<", "<<far<<endl;
            #endif // __test
            beg = far;
        }
        return beg < n ? -1 : ans;

//        vector<int> begn(n )

////        vector<int> vi(n + 1, 0);
//        vector<pair<int, int>> vp;
//        for (int i = 0; i < ranges.size(); ++i)
//        {
//            if (ranges[i] != 0)
//            {
//                vp.push_back(std::make_pair(i - ranges[i], i + ranges[i]));
//            }
//        }
//        int mx = 0;
//        int ans = 0;
//        while (mx < n)
//        {
//            for ()
//            {
//
//            }
//        }
    }

};

int main()
{
//    int n = 5;
//    myvi v = {3,4,1,1,0,0};

//    myvi v = {0,0,0,0};

    myvi v = {1,2,1,0,2,1,0,1};

//    myvi v = {4,0,0,0,0,0,0,0,4};

//    myvi v = {4,0,0,0,4,0,0,0,4};

    LT1326 lt;

    cout<<lt.lt1326a(v.size() - 1, v)<<endl;

    return 0;
}
