
#include "../header/myheader.h"

class LT2300
{
public:

    // D D

    //for (int i = 0; i < n; i++) {
    //    int val = sp[i];
    //    int l = 0;
    //    int r = m - 1;
    //    while (l <= r) {
    //        long long mid = (l + r) / 2;
    //
    //        if (1LL * val * po[mid] >= success) {
    //            r = mid - 1;
    //        }
    //        else {
    //            l = mid + 1;
    //        }
    //
    //    }
    //    ans[i] = m - l;
    //}



//Runtime: 302 ms, faster than 86.15 % of C++ online submissions for Successful Pairs of Spellsand Potions.
//Memory Usage : 114.6 MB, less than 5.01 % of C++ online submissions for Successful Pairs of Spellsand Potions.
    vector<int> lt2300a(vector<int>& spells, vector<int>& potions, long long success)
    {
        vector<int> ans(spells.size());
        unordered_map<int, int> map2;
        sort(begin(potions), end(potions));

        for (int i = 0; i < spells.size(); ++i)
        {
            if (map2.find(spells[i]) != map2.end())
            {
                ans[i] = map2[spells[i]];
                continue;
            }
            int t2 = spells[i];
            int cnt = potions.size();
            int l = 0, r = potions.size() - 1;

            while (l <= r && r >= 0)      // ... upper/lower_bound( , , success / t2) ...
            {
                int mid = (l + r) / 2;
                long long t3 = 1LL * potions[mid] * t2;
                if (t3 < success)
                {
                    l = mid + 1;
                }
                else if (t3 > success)
                {
                    cnt = mid;
                    r = mid - 1;
                }
                else
                {
                    l = r = mid - 1;
                    cnt = mid;
                }
            }
            cnt = potions.size() - cnt;
            ans[i] = cnt;
            map2[t2] = cnt;
        }

        return ans;
    }

};

int main()
{

    LT2300 lt;

    //myvi v = { 5,1,3 };
    //myvi v2 = { 1,2,3,4,5 };
    //int s = 7;

    myvi v = { 3,1,2 };
    myvi v2 = { 8,5,8 };
    int s = 16;

    myvi ans = lt.lt2300a(v, v2, s);

    showVectorInt(ans);

    return 0;
}
