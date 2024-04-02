
#include "../header/myheader.h"

class LT3086
{
public:



    // 9223372036854775807 out of range [-(2^53-1), 2^53-1]
    // [aliceIndex] == 1 ... no ...
    long long minimumMoves(vector<int>& nums, int k, int maxChanges)
    {
        std::vector<int> vi;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
                vi.push_back(i);
        }
        int st = 0, en = 0;
        long long cnt = 0LL;
        // long long ans = LLONG_MAX;
        long long ans = 2LL << 52;

        if (maxChanges + 3 >= k)
        {
            for (int i = 0; i < vi.size(); ++i)
            {
                int t2 = 1;
                st = en = i;
                if (t2 < k && i + 1 < vi.size() && vi[i] + 1 == vi[i + 1])
                {
                    t2++;
                    en++;
                }
                if (t2 < k && i > 0 && vi[i] - 1 == vi[i - 1])
                {
                    t2++;
                    st--;
                }
                if (maxChanges + t2 >= k)
                {
                    cnt = t2 - 1 + (k - t2) * 2;
                }
                else
                {
                    cnt = t2 + maxChanges * 2 - 1;
                    t2 += maxChanges;
                    if (choseSt(vi, st, en, i))
                    {
                        st--;
                        cnt += vi[i] - vi[st];
                        t2++;
                    }
                    else
                    {
                        en++;
                        cnt += vi[en] - vi[i];
                        t2++;
                    }
                    if (t2 < k)
                    {
                        if (choseSt(vi, st, en, i))
                        {
                            st--;
                            cnt += vi[i] - vi[st];
                            t2++;
                        }
                        else
                        {
                            en++;
                            cnt += vi[en] - vi[i];
                            t2++;
                        }
                    }
                }
#ifdef __test
                cout<<cnt<<", "<<i<<", "<<st<<", "<<en<<", "<<t2<<", "<<maxChanges<<", "<<t2<<endl;
                cout<<vi[i]<<", "<<vi[st]<<", "<<vi[en]<<endl;
#endif
                ans = min(cnt, ans);
            }
            if (vi.size() == 0)
            {
                ans = k * 2;
            }
            return ans;
        }

        int t2 = 1;
        int t3 = 0;
        int got = 1 + maxChanges;
        int used = maxChanges * 2;
        cnt = used;
        t2 = got;
        while (t2 < k)
        {
            en++;
            cnt += vi[en] - vi[0];
            t2++;
        }
        ans = min(ans, cnt);
        // for (int i = 1; i < vi.size(); ++i)
        for (int i = 1; i < nums.size(); ++i)
        {
            t3 = 0;
            // cnt += (vi[i] - vi[i - 1]);// * (i - st + 1);
            // cnt -= (vi[i] - vi[i - 1]);// * (en - i);
            while (vi[i] - vi[st] > vi[en] - vi[i])
            {
                t3++;
                st++;
                cnt -= vi[i] - vi[st];
            }
            while (t3-- > 0)
            {
                if (choseSt(vi, st, en, i))
                {
                    cnt += vi[i] - vi[st];
                    --st;
                }
                else
                {
                    cnt += vi[en] - vi[i];
                    en++;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }

    bool choseSt(std::vector<int>& vi, int st, int en, int i)
    {
        if (st == 0)
            return false;
        if (en == vi.size() - 1)
            return true;
        return (vi[i] - vi[st]) < (vi[en] - vi[i]) ? true : false;
    }
};

int main()
{

    LT3086 lt;

    // myvi v {1,1,0,0,0,1,1,0,0,1};
    // int k = 3;
    // int mxchg = 1;

    // myvi v = {0,0,0,0};
    // int k = 2;
    // int mxchg = 3;

    // myvi v {1,0,1,0,1};
    // int k {3}, mxchg {0};   // 4

    // myvi v {0,1,1,1};
    // int k = 3;
    // int mxchg = 0;

    myvi v = {1,1,0,1,1};       // 8
    int k = 5;
    int mxchg = 1;

    cout<<lt.minimumMoves(v, k, mxchg)<<endl;

    return 0;
}
