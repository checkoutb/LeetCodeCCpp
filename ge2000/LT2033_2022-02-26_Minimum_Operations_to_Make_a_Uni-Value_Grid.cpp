
#include "../header/myheader.h"

class LT2033
{
public:

// D D

//        sort(nums.begin(),nums.end());
//        int target=nums[m*n/2],ans=0;
// 中位数。



//f(i)-f(i-1) = i*(a[i]-a[i-1])+(n-i)*(a[i-1]-a[i])=(2*i-n)(a[i]-a[i-1])
//Since a[i] > a[i-1], we can get
//if 2*i<n, f(i)>f(i-1);
//if 2*i>n, f(i)<f(i-1)
//the minimun result is f(n/2) or f((n-1)/2).



//Runtime: 303 ms, faster than 67.09% of C++ online submissions for Minimum Operations to Make a Uni-Value Grid.
//Memory Usage: 73.8 MB, less than 95.69% of C++ online submissions for Minimum Operations to Make a Uni-Value Grid.
// 感觉是一条 开口向上的 抛物线。 所以二分的话，需要计算2个，来获得趋势。
    int lt2033b(vector<vector<int>>& grid, int x)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        int ans = -1;
        int t2 = grid[0][0];
//        int sum2 = 0;
        int mx = t2, mn = t2;
        for (int i = 0; i < sz1; i++)
            for (int j = 0; j < sz2; j++)
            {
                mx = max(mx, grid[i][j]);
                mn = min(mn, grid[i][j]);
//                sum2 += (grid[i][j] - t2);
                if (abs(t2 - grid[i][j]) % x != 0)
                    return ans;     // -1
            }
        int l = 0;
        int r = (mx - mn) / x;
//        cout<<l<<", "<<r<<", "<<mx<<", "<<mn<<endl;
        ans = 0;            // 1*1
        while (l < r)
        {
            int mid = (l + r) / 2;
            int mid2 = mid + 1;
            int t2 = 0;
            int t3 = 0;
            mid *= x;
            mid2 *= x;
            mid += mn;
            mid2 += mn;
            for (vector<int>& vi : grid)
                for (int i : vi)
                {
                    t2 += abs(i - mid) / x;
                    t3 += abs(i - mid2) / x;
                }
            #ifdef __test
            cout<<t2<<", "<<t3<<", "<<mid<<endl;
            #endif // __test
            if (t2 == t3)
            {
                l = r;
                ans = t2;
            }
            else if (t2 > t3)
            {
                ans = t3;
                l = (mid - mn) / x + 1;
            }
            else
            {
                ans = t2;
                r = (mid - mn) / x;
            }
        }
        return ans;
    }


// ....
// .....error  avg(2,4,6,8) == 5...
// avg 然后找个数 + x，使得 最接近这个avg？ 然后看是否每个数都可以？
// 想起来 二分了。
// 应该是 2个数的差 是否是 x的 倍数，是就肯定有解，不是就肯定无解。 然后用最大差 / x 来 作为 r ？
// 感觉还是 avg 最快。avg 代表 所有数到avg 的距离和 最短 的一种。 但不知道怎么证明。
    int lt2033a(vector<vector<int>>& grid, int x)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        int ans = -1;
        int t2 = grid[0][0];
        int sum2 = 0;
        int mn = t2;
        for (int i = 0; i < sz1; i++)
            for (int j = 0; j < sz2; j++)
            {
                mn = min(mn, grid[i][j]);
                sum2 += (grid[i][j] - t2);
                if (abs(t2 - grid[i][j]) % x != 0)
                    return ans;     // -1
            }
        int avg = sum2 / (sz1 * sz2) + t2;

        t2 = mn + (avg - mn) / x * x;       // <= avg
        #ifdef __test
        cout<<avg<<", "<<sum2<<", "<<t2<<", "<<mn<<endl;
        #endif // __test
        t2 -= x;
        ans = 112312313;
        for (int i = 0; i < 3; i++)
        {
            int t3 = 0;
            for (vector<int>& vi : grid)
            {
                for (int i : vi)
                {
                    t3 += abs(i - t2) / x;
                }
            }
            t2 += x;
            ans = min(ans, t3);
        }
        return ans;

//
//        int t3 = 0;
//        for (vector<int>& vi : grid)            // 需要&的。
//        {
//            #ifdef __test
//            cout<<&vi<<", "<<&grid[0]<<endl;
//            #endif // __test
//            for (int i : vi)
//            {
//                t3 += abs(i - t2) / x;
//            }
//        }
//        t2 -= x;
//        ans = 0;
//        for (vector<int>& vi : grid)
//        {
//            for (int i : vi)
//                ans += abs(i - t2) / x;
//        }
//        #ifdef __test
//        cout<<ans<<", "<<t3<<endl;
//        #endif // __test
//        ans = min(ans, t3);
//        return ans;
    }

};

int main()
{

    LT2033 lt;

//    myvvi vv = {{2,4},{6,8}};
//    int x = 2;

//    myvvi vv = {{1,5},{2,3}};
//    int x = 1;

//    myvvi vv = {{1,2},{3,4}};
//    int x = 2;

//    myvvi vv = {{529,529,989},{989,529,345},{989,805,69}};      // 25
//    int x = 92;

    myvvi vv = {{596,904,960,232,120,932,176},{372,792,288,848,960,960,764},{652,92,904,120,680,904,120},{372,960,92,680,876,624,904},{176,652,64,344,316,764,316},{820,624,848,596,960,960,372},{708,120,456,92,484,932,540}};
    int x = 28;     // 473

    cout<<lt.lt2033b(vv, x)<<endl;

//    int t3 = 0;
//    for (myvi& vi : vv)
//    {
//        for (int i : vi)
//        {
//            t3 += abs(i - 552) / x;
//        }
//    }
//    cout<<t3<<endl;

    return 0;
}
