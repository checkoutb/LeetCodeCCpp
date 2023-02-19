
#include "../header/myheader.h"

class LT2572
{
public:




    // g

    // error

    // prime
    // 1 2 3 5 7 11 13 17 19 23 29
    // 2 * 15  235
    // 2 * 6   223
    // bu , 一共就30个数字， 虽然1000，但是都是重复的。
    // 30 ... int_max > 1<<30 .. so.. md mei yong dao.
    int lt2572a(vector<int>& nums)
    {
        int sz1 = nums.size();
        int arr[31] = { 0 };
        for (int i : nums)
            ++arr[i];
        vector<int> vi(31, 0);
        //vi[1] = 1;
        //int prm[] = { 2,3,5,7,11,13,17,19,23,29 };
        vector<int> prm = { 2,3,5,7,11,13,17,19,23,29 };
        
        int t2 = 0;
        for (int i = 2; i < 31; ++i)
        {
            t2 = 0;
            for (int j = 0; j < prm.size() && i >= prm[j]; ++j)
            {
                if (i % (prm[j] * prm[j]) == 0)       // 4 8 16   9 27  25
                {
                    vi[i] = -1;
                    goto AAA;
                }
                if (i % prm[j] == 0)
                {
                    t2 |= (1 << j);
                }
            }
            vi[i] = t2;
            AAA:
            continue;
        }
        const int MOD = 1e9 + 7;
        int ans = dfsa1(vi, arr, 2, 0);
        if (arr[1] != 0)
            ans = 1LL * (ans + 1) * arr[1] % MOD;
        return ans;
    }

    int dfsa1(vector<int>& vi, int arr[31], int idx, int got)
    {
        if (idx > 30)
            return 1;
        if (vi[idx] == -1 || arr[idx] == 0)
        {
            return dfsa1(vi, arr, idx + 1, got);
        }
        const int MOD = 1e9 + 7;

        int ans = 0;
        if ((got & vi[idx]) == 0)
        {
            ans = dfsa1(vi, arr, idx + 1, got | vi[idx]);
        }
        ans = (ans + dfsa1(vi, arr, idx + 1, got)) % MOD;
        return ans;
    }

};

int main()
{

    LT2572 lt;

    myvi v = { 3,4,4,5 };

    cout << lt.lt2572a(v) << endl;

    return 0;
}
