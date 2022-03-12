
#include "../header/myheader.h"

class LT2176
{
public:

// D D

//    int res = 0;
//    unordered_map<int, vector<int>> m;
//    for (int i = 0;  i < nums.size(); ++i)
//        m[nums[i]].push_back(i);
//    for (auto &[n, ids] : m) {
//        unordered_map<int, int> gcds;
//        for (auto i : ids) {
//            auto gcd_i = gcd(i, k);
//            for (auto &[gcd_j, cnt] : gcds)
//                res += gcd_i * gcd_j % k ? 0 : cnt;
//            ++gcds[gcd_i];
//        }
//    }
//    return res;



//Runtime: 14 ms, faster than 63.23% of C++ online submissions for Count Equal and Divisible Pairs in an Array.
//Memory Usage: 12.6 MB, less than 7.26% of C++ online submissions for Count Equal and Divisible Pairs in an Array.
    int lt2176a(vector<int>& nums, int k)
    {
        unordered_map<int, vector<int>> map2;
        for (int i = 0; i < nums.size(); ++i)
        {
            map2[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto& p : map2)
        {
            for (int i = 0; i < p.second.size(); ++i)
            {
                for (int j = i + 1; j < p.second.size(); ++j)
                {
                    if (p.second[i] * p.second[j] % k == 0)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT2176 lt;


    return 0;
}
