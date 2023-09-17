
#include "../header/myheader.h"

class LT2741
{
public:




//Runtime218 ms
//Beats
//82.11%
//Memory75.8 MB
//Beats
//53.55%
    // sz1 <= 14
    int specialPerm(vector<int>& nums)
    {
        int ans = 0;
        const int MOD = 1e9 + 7;
        vector<vector<int>> vi(nums.size(), vector<int>((1 << nums.size()), -1));
        for (int i = 0; i < nums.size(); ++i)
        {
            ans = (ans + dfsa1(vi, i, 1 << i, nums)) % MOD;
        }
        return ans;
    }

    int dfsa1(vector<vector<int>>& vi, int idx, int got, vector<int>& v2)
    {
        if (vi[idx][got] != -1)
            return vi[idx][got];
        if (got == ((1 << v2.size()) - 1))
            return 1;

        int ans = 0;
        int num = v2[idx];
        const int MOD = 1e9 + 7;
        for (int i = 0; i < v2.size(); ++i)
        {
            if ((got & (1 << i)) == 0)
            {
                if (v2[i] % num == 0 || num % v2[i] == 0)
                {
                    ans = (ans + dfsa1(vi, i, got | (1 << i), v2)) % MOD;
                }
            }
        }
        vi[idx][got] = ans;
        return ans;
    }

};

int main()
{

    LT2741 lt;

//    myvi v = {2,3,6};
    myvi v = {1,4,3};

    cout<<lt.specialPerm(v)<<endl;

    return 0;
}
