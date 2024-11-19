
#include "../header/myheader.h"

class LT3201
{
public:





// Runtime
// 112ms
// Beats60.72%
// Analyze Complexity
// Memory
// 95.19MB
// Beats79.37%

    // %2 == %2
    // 1+1 = 0
    // 0+1 = 1
    // 1,1,1,1,1...,1
    // 0,0,0,0,...0
    // 1,0,1,0,1,0, ...
    // 0 1 0 1 0 1 0 1...
    int maximumLength(vector<int>& nums)
    {
        int lst = nums[0] % 2;
        int t2 = 1;
        
        int all1 = lst;
        int all0 = 1 - lst;
        
        int sz1 = nums.size();
        
        for (int i = 1; i < sz1; ++i) {
            if (nums[i] % 2 == 0) {
                ++all0;
            } else {
                ++all1;
            }
            if (nums[i] % 2 == lst) {
                ;
            } else {
                lst = 1 - lst;
                ++t2;
            }
        }
        
        return std::max(std::max(all0, all1), t2);
    }



};

int main()
{

    LT3201 lt;


    return 0;
}
