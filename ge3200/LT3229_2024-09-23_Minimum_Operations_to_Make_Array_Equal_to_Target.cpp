
#include "../header/myheader.h"

class LT3229
{
public:


    // D D

    // Just need to calculate the sum of increments
        // for (int i = 0; i < n; ++i) {
        //     res += max(target[i] - A[i] - pre, 0);
        //     pre = target[i] - A[i];
        // }
        // return res + max(-pre, 0);
    // 正数上升侧， 负数下降侧


// Runtime
// 201ms
// Beats15.44%
// Analyze Complexity
// Memory
// 181.38MB
// Beats10.66%

    // any subarray, +1 or -1
    // i have a good idea ...
    // ...long long...
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        int op = 0; // last operation
        int sz1 = nums.size();
        for (int i = 0; i < sz1; ++i) {
            int t2 = target[i] - nums[i];  // need operation
            if (t2 == 0) {
                op = 0;
                continue;
            }
            
            if (op == 0) {
                op = t2;
                ans += std::abs(t2);
            } else if (op > 0) {
                if (t2 > 0) {
                    ans += std::max(0, t2 - op);
                    op = t2;
                } else {
                    ans += -t2;
                    op = t2;
                }
            } else {
                if (t2 > 0) {
                    ans += t2;
                    op = t2;
                } else {
                    ans += std::max(0, op - t2);
                    op = t2;
                }
            }
        }
        return ans;
    }


};

int main()
{

    LT3229 lt;


    return 0;
}
