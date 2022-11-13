
#include "../header/myheader.h"

class LT2453
{
public:


    // D D

    //int res = 1e9, maxc = 0;
    //unordered_map<int, int> count;
    //for (int a : A)
    //    maxc = max(maxc, ++count[a % space]);
    //for (int a : A)
    //    if (count[a % space] == maxc)
    //        res = min(res, a);
    //return res;




//Runtime178 ms
//Beats
//94.74 %
//Memory58.1 MB
//Beats
//99.51 %
    int lt2453a(vector<int>& nums, int space)
    {
        int sz1 = nums.size();
        vector<pair<int, int>> vp(sz1);

        for (int i = 0; i < sz1; ++i)
        {
            vp[i] = std::make_pair(nums[i] % space, -nums[i]);
        }

        sort(begin(vp), end(vp));

        int cnt = 1;
        int ans = -1;
        int mxcnt = 0;
        vp.push_back(make_pair(-1, -1));
        for (int i = 0; i < sz1; ++i)
        {
            if (vp[i].first != vp[i + 1].first)
            {
                if (cnt > mxcnt)
                {
                    ans = -vp[i].second;
                    mxcnt = cnt;
                }
                else if (cnt == mxcnt)
                {
                    ans = min(ans, -vp[i].second);
                }
                cnt = 0;
            }
            ++cnt;
        }

        return ans;
    }

};

int main()
{

    LT2453 lt;

    //myvi v = { 3,7,8,1,1,5 };
    //int sp = 2;

    //myvi v = { 1,2,3,4,5,6 };
    //int sp = 2;

    myvi v = { 6,2,5 };
    int sp = 100;

    cout << lt.lt2453a(v, sp);

    return 0;
}
