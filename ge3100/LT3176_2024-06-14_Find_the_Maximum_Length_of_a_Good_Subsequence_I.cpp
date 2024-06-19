
#include "../header/myheader.h"

class LT3176
{
public:






    
// Runtime
// 244ms
// Beats75.04%
// Analyze Complexity
// Memory
// 23.28MB
// Beats80.08%
    // seq, at most k that !=, other are ==
    // == alway append,
    // != , k-1.
    // sz1 500, k 25
    int maximumLength(vector<int>& nums, int k) {
        int sz1 = nums.size();
        int sz2 = std::min(k + 1, sz1);
        std::vector<std::vector<int>> vvi(sz1, std::vector<int>(sz2, 0));
        vvi[0][0] = 1;
        for (int i = 0; i < sz1; ++i) {
            vvi[i][0] = 1;  // ..
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < sz2; ++k) {
                    if (vvi[j][k] == 0)
                        continue; // not break
                    if (nums[i] == nums[j]) {
                        vvi[i][k] = std::max(vvi[j][k] + 1, vvi[i][k]);
                    } else {
                        if (k + 1 < sz2)
                            vvi[i][k + 1] = std::max(vvi[j][k] + 1, vvi[i][k + 1]);
                    }
                }
            }
        }
        #ifdef __test
        for (myvi& vi : vvi) {
            for (int i : vi) {
                std::cout<<i<<',';
            }
            std::cout<<std::endl;
        }
        #endif
        int ans = 0;
        for (int i = 0; i < sz1; ++i) {
            ans = std::max(ans, *max_element(std::begin(vvi[i]), std::end(vvi[i])));
        }
        return ans;
    }


};

int main()
{

    LT3176 lt;

    // myvi v {1,2,1,1,3};
    // int k {2};

    myvi v {3,24,33};
    int k {3};
    
    std::cout<<lt.maximumLength(v, k)<<std::endl;

    return 0;
}
