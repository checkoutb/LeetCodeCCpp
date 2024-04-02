
#include "../header/myheader.h"

class LT3066
{
public:


    // D D

    // 直接全部放进去， while (priq.top() < k) { }

    // 被 26% 的通过率唬到了。


// Runtime
// 217ms
// Beats57.05%of users with C++
// Memory
// 90.93MB
// Beats82.82%of users with C++
    // priq buxing ?
    int minOperations(vector<int>& nums, int k)
    {
        std::priority_queue<int, vector<int>, std::greater<>> priq;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < k)
                priq.push(nums[i]);
        }
        int ans = 0;
        // while (!priq.empty())
        while (priq.size() > 1)
        {
            ++ans;
            int t2 = priq.top();
            priq.pop();
            int t3 = priq.top();
            priq.pop();

            t2 <<= 1;
            if (t2 >= k)
                continue;

            t2 += t3;
            if (t2 >= k)
                continue;

            priq.push(t2);
        }
        return ans + !priq.empty();
    }

};

int main()
{

    LT3066 lt;


    return 0;
}
