
#include "../header/myheader.h"

class LT2919
{
public:




    // so hard, so easy...

//     Runtime98 ms
// Beats
// 87.18%
// Memory86.5 MB
// Beats
// 73.81%

// 2 1 4 6 2+1
    // dp .. [3][2]
    long long minIncrementOperations(vector<int>& nums, int k)
    {
        long long ans = 0LL;
        int mx = 0;
        size_t sz1 = nums.size();
        std::vector<long long> vl(sz1, 0LL);
        vl[0] = nums[0] >= k ? 0LL : (k - nums[0]);
        vl[1] = std::max(0LL, static_cast<long long>(k) - nums[1]);
        vl[2] = std::max(0LL, 1LL * k - nums[2]);

        long long t2 = vl[0];
        for (size_t i = 3; i != sz1; ++i)
        {
            // t2 = std::min(t2, vl[i - 3]);
            t2 = std::min(vl[i - 1], std::min(vl[i - 2], vl[i - 3]));
            vl[i] = t2 + std::max(0LL, 1LL * (k - nums[i]));
        }

#ifdef __test
        for (auto ll : vl)
        {
            cout<<ll<<", ";
        }
        cout<<endl;
#endif

        return std::min(vl[sz1 - 1], std::min(vl[sz1 - 2], vl[sz1 - 3]));

        // long long arr[3][2] = {};
//         std::vector<vector<long long>> vvl(3, vector<long long>(2, 0LL));
//
//         if ()
//         {
//
//         }
//
//         return std::min(vvl[0][1], std::min(vvl[1][1], vvl[2][1]));
    }


};

int main()
{

    LT2919 lt;

    myvi vi{2,3,0,0,2};
    int k{4};

    cout<<lt.minIncrementOperations(vi, k)<<endl;


    return 0;
}
