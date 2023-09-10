
#include "../header/myheader.h"

class LT2640
{
public:





    //Runtime125 ms
    //    Beats
    //    51.29 %
    //    Memory53.6 MB
    //    Beats
    //    67.35 %
    vector<long long> findPrefixScore(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<long long> vll(sz1);
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            t2 = max(t2, nums[i]);
            vll[i] = t2 + nums[i];
        }
        for (int i = 1; i < sz1; ++i)
        {
            vll[i] += vll[i - 1];
        }
        return vll;
    }

};

int main()
{

    LT2640 lt;


    return 0;
}
