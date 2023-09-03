
#include "../../header/myheader.h"

class LT6952
{
public:


// AC  @ 11:55 ... 错了n次。  tle 的时候放弃了， 后来 tarjan 写不出，又回来了。 就想到了 后缀树。



// tle.. zha le

// you k ge %=k de
// [k]
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k)
    {
        int sz1 = nums.size();

        long long ans = 0LL;
        if (modulo == 1)
        {
            ans = 1LL * sz1 * (sz1 + 1) / 2;
            return ans;
        }

        vector<int> vi;       // idx of %MOD ==k
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] % modulo == k)
            {
                vi.push_back(i);
            }
        }
        if (k == 0)
        {
            int st = -1;
            for (int i = 0; i < vi.size(); ++i)
            {
                long long t2 = vi[i] - st - 1;

                ans += t2 * (t2 + 1) / 2;

                st = vi[i];
            }
            long long t2 = sz1 - st - 1;
            ans += t2 * (t2 + 1) / 2;
//            return ans;
        }
        if (vi.empty())
        {
            return ans;
        }
        // md, suffix array
        vector<long long> vll(vi.size(), 0LL);
        vll[vi.size() - 1] = sz1 - vi[vi.size() - 1];

        for (int i = vi.size() - 2; i >= 0; --i)
        {
            vll[i] = vi[i + 1] - vi[i];
            if (i + modulo < vi.size())
                vll[i] += vll[i + modulo];
        }
        for (int i = 0; i + k - 1 + (k == 0 ? modulo : 0) < vi.size(); ++i)
        {
            int j = i + k - 1 + (k == 0 ? modulo : 0);
            #ifdef __test
            cout<<i<<", "<<j<<", "<<vll.size()<<" -- "<<vi.size()<<endl;
            #endif // __test
            ans += 1LL * vll[j] * (i == 0 ? (vi[i] + 1) : (vi[i] - vi[i - 1]));
        }
        return ans;

////        for (int i = 0; i < vi.size(); ++i)
//        for (int i = 0; i < modulo; ++i)
//        {
//            int cnt = 1;
//            for (int j = i + k + (k == 0 ? modulo : 0) - 1; j < vi.size(); j += modulo)
//            {
//                int st = vi[i];
//                int en = vi[j];
//                int cnt1 = i == 0 ? (st + 1) : (st - vi[i - 1]);
//                int cnt2 = (j + 1 == vi.size()) ? (sz1 - en) : (vi[j + 1] - en);
//                ans += 1LL * cnt1 * cnt2 * cnt;
//                ++cnt;
//            }
//        }
//        return ans;

//        if (k == 0)
//        {
//            int st = -1;
//            for (int i = 0; i < vi.size(); ++i)
//            {
//                long long t2 = vi[i] - st - 1;
//
//                ans += t2 * (t2 + 1) / 2;
//
//                st = vi[i];
//            }
//            return ans;
//        }
//
//        for (int i = 0; i + k <= vi.size(); ++i)
//        {
//            int st = vi[i];
//            int en = vi[i + k - 1];
//            int cnt1 = i == 0 ? (st + 1) : (st - vi[i - 1]);
//            int cnt2 = (i + k == vi.size()) ? (sz1 - en) : (vi[i + k] - en);
//            ans += 1LL * cnt1 * cnt2;
//        }
//        return ans;
    }

};

int main()
{

    LT6952 lt;

//    myvi v = {3,1,9,6};
//    int mod = 3;
//    int k = 0;

    myvi v = {7,2};         // 1
    int mod = 7;
    int k = 0;

    cout<<lt.countInterestingSubarrays(v, mod, k)<<endl;

    return 0;
}
