
#include "../header/myheader.h"

class LT2364
{
public:

    // D D

    //unordered_map<int, int> freq;
    //for (int i = 0; i < nums.size(); ++i) ++freq[i - nums[i]];
    //long long ans = 0;
    //for (auto& [k, v] : freq) ans += (long long)v * (nums.size() - v);
    //return ans / 2;



//Runtime: 507 ms, faster than 25.00 % of C++ online submissions for Count Number of Bad Pairs.
//Memory Usage : 88.3 MB, less than 100.00 % of C++ online submissions for Count Number of Bad Pairs.
    // . j-i != n[j] - n[i]     j-n[j] != i-n[i]
    long long lt2364a(vector<int>& nums)
    {
        unordered_map<int, long long> map2;
        long long ans = 0LL;
        for (int i = 0; i < nums.size(); ++i)
        {
            int t2 = i - nums[i];
            ans += (i - map2[t2]);
            map2[t2]++;
        }
        return ans;
    }

};

int main()
{

    LT2364 lt;

    myvi v = { 4,1,3,3 };

    cout << lt.lt2364a(v) << endl;

    return 0;
}
