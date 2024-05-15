
#include "../header/myheader.h"

class LT2354
{
public:


    // D D


        // vector<int> bitCount(33,0);
        // bitCount[__builtin_popcount(nums[0])]++;

    #define getunique(v) { sort(v.begin() , v.end()) ; v.erase(unique(v.begin() , v.end()), v.end());}






// Runtime
// 141ms
// Beats91.37%of users with C++
// Memory
// 68.80MB
// Beats82.01%of users with C++

    // bit_count(a or b) = bit_count(a) + bit_count(b) - bit_count(a & b)
    // bit_count(a & b) =
    // bit_count(a or b) + bit_count(a & b) = bit_count(a) + bit_count(b)
    long long countExcellentPairs(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        vector<int> vi;
        long long ans = 0LL;
        std::sort(nums.begin(), nums.end());
        vi.push_back(bit_cnt(nums[0]));
        for (int i = 1; i < sz1; ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                vi.push_back(bit_cnt(nums[i]));
            }
        }

        std::sort(vi.begin(), vi.end());

#ifdef __test
        cout<<ans<<", \n";
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
#endif

        int idx = vi.size();
        for (int i = 0; i < vi.size(); ++i)
        {
            while (idx - 1 >= 0 && (vi[i] + vi[idx - 1]) >= k)
            {
                --idx;
            }
            ans += vi.size() - idx;

            cout<<ans<<endl;

        }
        return ans;
    }

    int bit_cnt(int a)
    {
        int ans = 0;
        while (a > 0)
        {
            ans += 1 & a;
            a >>= 1;
        }
        return ans;
    }
};

int main()
{

    LT2354 lt;

    myvi v{1,2,3,1};
    int k{3};

    std::cout<<lt.countExcellentPairs(v, k)<<std::endl;

    return 0;
}
