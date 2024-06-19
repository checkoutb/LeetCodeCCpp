
#include "../header/myheader.h"

class LT3153
{
public:





    
// Runtime
// 121ms
// Beats74.28%of users with C++
// Memory
// 112.42MB
// Beats18.74%of users with C++
    // base 10
    long long sumDigitDifferences(vector<int>& nums) {
        std::vector<int> vi(10);
        long long ans = 0LL;
        int sz1 = nums.size();
        int t2 = 0;
        bool go = true;
        while (go) {
            go = false;
            std::fill(std::begin(vi), std::end(vi), 0);
            for (int i = 0; i < sz1; ++i) {
                ++vi[nums[i] % 10];
                nums[i] /= 10;
                if (!go && nums[i] > 0) {
                    go = true;
                }
            }
            t2 = 0;
            for (int i = 0; i < 10; ++i) {
                ans += 1LL * t2 * vi[i];
                t2 += vi[i];
            }
        }
        return ans;
    }
    

};

int main()
{

    LT3153 lt;


    return 0;
}
