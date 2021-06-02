
#include "../header/myheader.h"

class LT0327
{
public:



// gg ...

// ?得手动insert-sort？ lower_bound,
    int lt0327a(vector<int>& nums, int lower, int upper)
    {
        long sum2 = nums[0];
        int sz1 = nums.size();
        vector<long> vi(sz1, 0);
        int idx = 0;
        vi[0] = sum2;
        int ans = 0;
        int t1, t2, dis;
        if (sum2 >= lower && sum2 <= upper)
            ans++;

        for (int i = 1; i < sz1; ++i)
        {
//            cout<<sum2<<", "<<nums[i]<<endl;
            sum2 += nums[i];
//            cout<<" - ..  "<<sum2<<endl;
            if (sum2 >= lower && sum2 <= upper)
                ans++;

            /*
            // .. huaiyi renshengle...

            sum2 - x >= lower
            sum2 - x <= upper
            x <= sum2 - lower;
            x >= sum2 - upper

            */
            t1 = sum2 - upper;
            t2 = sum2 - lower;
//            t1 = lower + sum2;
//            t2 = upper + sum2;
//            vector<int>::iterator it = std::lower_bound(begin(vi), begin(vi) + idx, t1);
//            dis = std::distance(begin(vi), it);
            vector<long>::iterator it = std::lower_bound(begin(vi), begin(vi) + idx + 1, sum2);      // +1....
            dis = std::distance(begin(vi), it);
            for (int j = idx; j >= dis; --j)
            {
                vi[j + 1] = vi[j];
            }
            int cnt = 0;
            vi[dis] = sum2;
            idx++;
            #ifdef __test
            cout<<dis<<", "<<sum2<<endl;
            cout<<" - - show long "<<endl;
            for (long ab : vi)
                cout<<ab<<", ";
            cout<<endl;
//            showVectorInt(vi);
            #endif // __test
            for (int j = dis + 1; j <= idx && vi[j] <= t2; ++j)
            {
                #ifdef __test
                cout<<"@1  "<<vi[j]<<", "<<sum2<<", "<<t2<<endl;
                #endif // __test
                if (vi[j] >= t1)
                    cnt++;
            }
            for (int j = dis - 1; j >= 0 && vi[j] >= t1; --j)       // 太近 也不算的。
            {
                #ifdef __test
                cout<<"@2   "<<vi[j]<<", "<<j<<", "<<t1<<", "<<sum2<<endl;
                #endif // __test
                if (vi[j] <= t2)            // 也不对。。 加不加都不对。。。
                    cnt++;
            }
//            cout<<cnt<<endl;
            #ifdef __test
            cout<<". "<<cnt<<endl;
            #endif // __test
            ans += cnt;
        }
        return ans;

        // fangqile...
//        // 规模小，直接遍历
//        int i = 1;
//        int t1, t2;
//        for (int mxi = min(10, sz1); i < mxi; ++i)
//        {
//            sum2 += nums[i];
//            t1 = lower - sum2;
//            t2 = upper - sum2;
//            for (int j = 0; j <= idx; ++j)
//            {
//
//            }
//        }
    }

};

int main()
{
//    myvi v = {-2,5,-1};
//    int l{-2}, u{2};

//    myvi v = {0};
//    int l{0}, u{0};

//    myvi v = {0,0};
//    int l{0}, u{0};

//    // 4
//    myvi v = {2147483647,-2147483648,-1,0};
//    int l = -1;
//    int u = 0;

//    // 0
//    myvi v = {0,-1,-2,-3,0,2};
//    int l = 3;
//    int u = 5;

// 3
    myvi v = {-2147483647,0,-2147483647,2147483647};
    int l = -564;
    int u = 3864;


    LT0327 lt;

    cout<<lt.lt0327a(v, l, u)<<endl;

    return 0;
}
