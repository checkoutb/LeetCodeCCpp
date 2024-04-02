
#include "../header/myheader.h"

class LT3080
{
public:


    // D D

    // priq





// Runtime
// 219ms
// Beats95.46%of users with C++
// Memory
// 133.36MB
// Beats77.59%of users with C++
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        int sz1 = nums.size();
        int szq = queries.size();
        std::vector<long long> ans(szq, 0LL);

        std::vector<std::pair<int, int>> vp(sz1);
        long long sum2 = 0LL;
        for (int i = 0; i < sz1; ++i)
        {
            sum2 += nums[i];
            vp[i].first = nums[i];
            vp[i].second = i;
        }
        using std::begin;
        using std::end;
        std::sort(begin(vp), end(vp));

        std::vector<bool> mrk(sz1, false);  // marked ?
        int st = 0; // first not mark
        for (int i = 0; i < szq; ++i)
        {
            int idx = queries[i][0];
            int k = queries[i][1];
            if (!mrk[idx])
            {
                mrk[idx] = true;
                sum2 -= nums[idx];
            }
            while (st < sz1 && k-- > 0)
            {
                while (st < sz1 && mrk[vp[st].second])
                {
                    ++st;
                }
                if (st < sz1)
                {
                    mrk[vp[st].second] = true;
                    sum2 -= vp[st].first;
                    ++st;
                }
            }
            ans[i] = sum2;
        }

        return ans;
    }

};

int main()
{

    LT3080 lt;


    return 0;
}
