
#include "../header/myheader.h"

class LT2281
{
public:

// D

//https://leetcode.com/problems/sum-of-total-strength-of-wizards/discuss/2061787/Amazon-Online-Assessment
// 经过大佬鉴定，这道题太难了。
// 还有里面的 rexue70的回复, tongkuokang(回复的rexue70)。。。 一个rank21，一个周赛top0.05% ......
//
//    vector<int> ps_l(sz + 1), pm_l(sz + 1); // prefix sum and prefix mul from the left.
//    vector<int> ps_r(sz + 1), pm_r(sz + 1); // ... from the right.
//    vector<int> st; // mono-increasing stack.

// O(n)


// min(subarr) * sum(subarr)
// sum(subarr) ==== prefix sum
// min(subarr) ??? dp. min(subarr[4][11]) == min(min[4][x], min[x+1][11])
// 依然需要for for,,, tle?
    int lt2281a(vector<int>& strength)
    {
        int sz1 = strength.size();
        vector<long> vl(sz1, 0L);
        vl[0] = strength[0];
        for (int i = 1; i < sz1; ++i)
        {
            vl[i] = vl[i - 1] + strength[i];
        }
        const int MOD = 1e9 + 7;
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            int mn = strength[i];
            for (int j = 0; j < sz1; ++j)
            {
                mn = min(mn, strength[j]);
                // ... prefix sum 没有意义。。这里可以直接累加的。。
            }
        }
        return ans;
    }


};

int main()
{

    LT2281 lt;


    return 0;
}
