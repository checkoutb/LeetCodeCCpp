
#include "../header/myheader.h"

class LT2593
{
public:

    // D D

    //long long score = 0, sz = n.size();
    //vector<int> id(sz);
    //iota(begin(id), end(id), 0);
    //sort(begin(id), end(id), [&](int i, int j) { return n[i] == n[j] ? i < j : n[i] < n[j]; });
    //for (int i : id)
    //    if (n[i]) {
    //        score += n[i];
    //        n[i] = n[min((int)sz - 1, i + 1)] = n[max(0, i - 1)] = 0;
    //    }
    //return score;



    //Runtime259 ms
    //    Beats
    //    100 %
    //    Memory92.7 MB
    //    Beats
    //    40 %
    long long lt2593a(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<bool> vb(sz1);
        long long ans = 0LL;

        vector<pair<int, int>> vp(sz1);
        for (int i = 0; i < sz1; ++i)
            vp[i] = make_pair(nums[i], i);

        sort(begin(vp), end(vp));
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (vb[vp[i].second])
                continue;

            ans += vp[i].first;
            t2 = vp[i].second;
            if (t2 > 0 && (!vb[t2 - 1]))
                vb[t2 - 1] = true;
            if (t2 < sz1 - 1 && (!vb[t2 + 1]))
                vb[t2 + 1] = true;
        }
        return ans;
    }

};

int main()
{

    LT2593 lt;


    return 0;
}
