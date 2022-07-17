
#include "../header/myheader.h"

class LT1906
{
public:

    // D D

    // prefix sum ...  binary search


    //vector<int> res, idx[101];
    //for (int i = 0; i < nums.size(); ++i)
    //    idx[nums[i]].push_back(i);
    //for (int i = 0; i < qs.size(); ++i) {
    //    int prev = 0, delta = INT_MAX;
    //    for (int j = 1; j <= 100; ++j) {
    //        auto it = lower_bound(begin(idx[j]), end(idx[j]), qs[i][0]);
    //        if (it != end(idx[j]) && *it <= qs[i][1]) {
    //            delta = min(delta, prev == 0 ? INT_MAX : j - prev);
    //            prev = j;
    //        }
    //    }
    //    res.push_back(delta == INT_MAX ? -1 : delta);
    //}




//Runtime: 1147 ms, faster than 42.51 % of C++ online submissions for Minimum Absolute Difference Queries.
//Memory Usage : 343.1 MB, less than 31.88 % of C++ online submissions for Minimum Absolute Difference Queries.
    // 1 <= nums[i] <= 100
    vector<int> lt1906a(vector<int>& nums, vector<vector<int>>& queries)
    {
        int sz1 = nums.size();
        vector<vector<int>> vvi(sz1, vector<int>(101, 0));
        vvi[0][nums[0]] = 1;
        int mn = nums[0];
        int mx = nums[0];
        unordered_set<int> set2;
        set2.insert(nums[0]);
        for (int i = 1; i < sz1; ++i)
        {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
            
            for (int n : set2)              // for i in [mn, mx]
            {
                vvi[i][n] = vvi[i - 1][n];
            }
            if (vvi[i][nums[i]] == 0)
                set2.insert(nums[i]);
            vvi[i][nums[i]]++;
        }

        vector<int> ans(queries.size());
        int lst = -1;
        for (int i = 0; i < queries.size(); ++i)
        {
            lst = -1;
            int st = queries[i][0];
            int en = queries[i][1];
            int mnabs = 111;
            for (int j = mn; j <= mx; ++j)
            {
                int t2 = vvi[en][j] - (st == 0 ? 0 : vvi[st - 1][j]);
                if (t2 != 0)
                {
                    if (lst != -1)
                    {
                        mnabs = min(mnabs, j - lst);
                    }
                    lst = j;
                }
            }
            ans[i] = mnabs == 111 ? -1 : mnabs;
        }
        return ans;
    }

};

int main()
{

    LT1906 lt;

    myvi v = { 1,3,4,8 };
    myvvi vv = { {0,1},{1,2},{2,3},{0,3} };

    myvi v2 = lt.lt1906a(v, vv);

    showVectorInt(v2);

    return 0;
}
