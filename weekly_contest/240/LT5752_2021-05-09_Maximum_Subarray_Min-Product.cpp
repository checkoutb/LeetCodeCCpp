
#include "../../header/myheader.h"

class LT5752
{
public:


// D

// 借助stack 来完成下面：
// find the first element' value < nums[i] in the left
//  find the first element' value < nums[i] in the right





// tle 。。。。。。
// merge , 分治。。。
    int lt5752c(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<long> sum2(sz1, 0);
        sum2[0] = nums[0];
        int mn = nums[0];
//        vector<int> mnidx;
        for (int i = 1; i < sz1; ++i)
        {
            sum2[i] = sum2[i - 1] + nums[i];
//            if (nums[i] < mn)
//            {
////                mn = nums[i];
////                mnidx = {i};
//            }
//            else if (nums[i] == mn)
//            {
////                mnidx.push_back(i);
//            }
        }
//        long mxp = sum2[sz1 - 1] * mn;

        long ans = div_merge(nums, 0, sz1 - 1, sum2);

        return ans % ((long) 1E9 + 7);

    }

    long div_merge(vector<int>& nums, int st, int en, vector<long>& sum2)
    {
        #ifdef __test
//        getchar();
        cout<<st<<", "<<en<<endl;
        #endif // __test

        if (st > en)
            return 0L;
        if (st == en)
            return (long) nums[st] * nums[st];

        int mn = nums[st];
        vector<int> mnidx = {st};
        for (int i = st + 1; i <= en; ++i)
        {
            if (nums[i] < mn)
            {
                mn = nums[i];
                mnidx = {i};
            }
            else if (nums[i] == mn)
            {
                mnidx.push_back(i);
            }
        }
        long ans = (sum2[en] - (st == 0 ? 0 : sum2[st - 1])) * mn;
        int t2 = st;
        long t4 = 0L;
        for (int i = 0; i < mnidx.size(); ++i)
        {
            t4 = div_merge(nums, t2, mnidx[i] - 1, sum2);
            ans = max(ans, t4);
            t2 = mnidx[i] + 1;
        }
//        cout<<mnidx.size()<<", "<<st<<"," <<en<<endl;
        t4 = div_merge(nums, t2, en, sum2);     // ?
        ans = max(ans, t4);
        return ans;
    }


// 按 最小数  划分成几个块。
// tle
    int lt5752b(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<long> sum2(sz1, 0);
        sum2[0] = nums[0];
        for (int i = 1; i < sz1; ++i)
        {
            sum2[i] = sum2[i - 1] + nums[i];
        }
        #ifdef __test
        for (long a : sum2)
            cout<<a<<", ";
        cout<<endl;
        #endif // __test
        vector<int> mnarr(sz1, 0);
        long mxp = 0L;
        int mn = 0;
        long t2 = 0L;
        long stsum = 0L;
        for (int i = 0; i < sz1; ++i)
        {
            int st = i, en = i;
            int t4 = nums[i];
            while (st - 1 >= 0 && nums[st - 1] >= t4)
            {
                st--;
            }
            while (en + 1 < sz1 && nums[en + 1] >= t4)
                en++;
            mxp = max(mxp, (sum2[en] - (st == 0 ? 0 : sum2[st - 1])) * t4);
        }
        #ifdef __test
        cout<<mxp<<endl;
        #endif // __test
        return mxp % ((long) 1E9 + 7);
    }



// 对每个数，往前搜索，往后搜索，获得 以它为最小值的 最长数组， 这样会快吗？
// tle.
    int lt5752a(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<long> sum2(sz1, 0);
        sum2[0] = nums[0];
        for (int i = 1; i < sz1; ++i)
        {
            sum2[i] = sum2[i - 1] + nums[i];
        }
        #ifdef __test
        for (long a : sum2)
            cout<<a<<", ";
        cout<<endl;
        #endif // __test
        vector<int> mnarr(sz1, 0);
        long mxp = 0L;
        int mn = 0;
        long t2 = 0L;
        long stsum = 0L;
        for (int i = 0; i < sz1; ++i)
        {
            mn = nums[i];
            for (int j = i; j < sz1; ++j)
            {
                mn = min(mn, nums[j]);

                if (mnarr[j] >= mn)
                {
                    break;
                }
                mnarr[j] = mn;
                t2 = (sum2[j] - stsum) * mn;
                mxp = max(t2, mxp);
            }
            stsum = sum2[i];
        }
        #ifdef __test
        cout<<mxp<<endl;
        #endif // __test
        return mxp % ((long) 1E9 + 7);
    }

};

int main()
{
//    myvi v = {1,2,3,2};
//    myvi v = {2,3,3,1,2};
    myvi v = {3,1,5,6,4,2};

    LT5752 lt;

    cout<<lt.lt5752c(v)<<endl;

    return 0;
}
