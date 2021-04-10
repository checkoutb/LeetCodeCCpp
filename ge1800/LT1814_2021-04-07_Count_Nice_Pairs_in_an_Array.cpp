
#include "../header/myheader.h"

class LT1814
{
public:

// D D

//        for (int& a : A)
//            res = (res + count[a - rev(a)]++) % mod;

//    for (; n > 0; n /= 10)
//        res = res * 10 + n % 10;



//Runtime: 100 ms, faster than 75.51% of C++ online submissions for Count Nice Pairs in an Array.
//Memory Usage: 56.7 MB, less than 5.03% of C++ online submissions for Count Nice Pairs in an Array.
// n[i] + rev(n[j]) == n[j] + rev(n[i])     <=>   n[i] - rev(n[i]) == n[j] - rev(n[j])
    int lt1814a(vector<int>& nums)
    {
        unordered_map<int, int> map2;
        for (int i = 0; i < nums.size(); ++i)
        {
            int t1 = nums[i];
            int t2 = 0;
            while (t1 > 0)
            {
                t2 *= 10;
                t2 += t1 % 10;
                t1 /= 10;
            }
            map2[nums[i] - t2]++;
        }
        int ans = 0;
        const int mod = 1e9 + 7;
        for (auto& p : map2)
        {
            long t2 = p.second;
            ans += ((1 + t2 - 1) * (t2 - 1) / 2) % mod;
            ans %= mod;
        }
        return ans;
    }

};

int main()
{
//    vector<int> v = {42,11,1,97};
    vector<int> v = {13,10,35,24,76};

    LT1814 lt;

    cout<<lt.lt1814a(v)<<endl;

    return 0;
}
