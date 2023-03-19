
#include "../header/myheader.h"

class LT2588
{
public:

    // D D

    //for (auto x : nums)
    //{
    //    curr = curr ^ x;
    //    ans += m[curr];
    //    m[curr]++;
    //}
    // 。。。。


    //for (int a : A)
    //    res += dp[pre ^= a]++;



    //Runtime497 ms
    //    Beats
    //    75 %
    //    Memory122.6 MB
    //    Beats
    //    50 %
    //
    long long lt2588a(vector<int>& nums)
    {
        int sz1 = nums.size();
        map<int, int> map2;

        int flg = 0;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            t2 = nums[i];
            
            for (int j = 0; t2 != 0; ++j)
            {
                if ((t2 & (1 << j)) == 0)
                {
                    ;
                }
                else
                {
                    flg ^= (1 << j);
                    t2 ^= (1 << j);
                }
            }
            ++map2[flg];
        }

        long long ans = map2.find(0) == map2.end() ? 0LL : (map2[0]);

        for (auto& [k, v] : map2)
        {
            ans += 1LL * (v - 1) * v / 2;
        }
        return ans;
    }

};

int main()
{

    LT2588 lt;

    myvi v = { 0,4,3,1,2,4 };

    cout << lt.lt2588a(v) << endl;

    return 0;
}
