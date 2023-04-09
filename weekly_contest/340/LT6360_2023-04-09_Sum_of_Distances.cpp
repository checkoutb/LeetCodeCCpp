
#include "../../header/myheader.h"

class LT6360
{
public:



    // AC
    vector<long long> distance(vector<int>& nums) {

        int sz1 = nums.size();
        vector<long long> ans(sz1, 0LL);

        //map<int, pair<int, long long>> map2;

        vector<pair<int, int>> vp(sz1);

        for (int i = 0; i < sz1; ++i)
        {
            vp[i].first = nums[i];
            vp[i].second = i;
        }

        sort(begin(vp), end(vp));

        long long sum2 = vp[0].second;      // sum of pre index
        long long cnt = 1L;                // cnt of pre index
        for (int i = 1; i < sz1; ++i)
        {
            if (vp[i].first == vp[i - 1].first)
            {
                ans[vp[i].second] += cnt * vp[i].second - sum2;

                sum2 += vp[i].second;
                ++cnt;
            }
            else
            {
                sum2 = vp[i].second;
                cnt = 1LL;
            }
        }

        sum2 = vp[sz1 - 1].second;
        cnt = 1LL;
        for (int i = sz1 - 2; i >= 0; --i)
        {
            if (vp[i].first == vp[i + 1].first)
            {
                ans[vp[i].second] += sum2 - cnt * vp[i].second;

                sum2 += vp[i].second;
                ++cnt;
            }
            else
            {
                sum2 = vp[i].second;
                cnt = 1LL;
            }
        }

        return ans;
    }
};

int main()
{

    LT6360 lt;

    //myvi v = { 1,3,1,1,2 };
    myvi v = { 5,4,1 };


    vector<long long> v2 = lt.distance(v);

    for (long long a : v2)
    {
        cout << a << ", ";
    }

    return 0;
}
