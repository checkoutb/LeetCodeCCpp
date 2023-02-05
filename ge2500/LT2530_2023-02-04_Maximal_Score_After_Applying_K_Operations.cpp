
#include "../header/myheader.h"

class LT2530
{
public:

    // D D


    // priority_queue<int> pq(begin(nums), end(nums));
    //if ((n + 2) / 3)
    //    pq.push((n + 2) / 3);




    //Runtime250 ms
    //    Beats
    //    99.38 %
    //    Memory72.4 MB
    //    Beats
    //    88.43 %
    long long ly2530a(vector<int>& nums, int k)
    {
        priority_queue<int> priq;

        std::sort(begin(nums), end(nums));

        long long ans = 0LL;
        int a, b;
        int idx = nums.size() - 1;
        while (k-- > 0)
        {
            a = idx >= 0 ? nums[idx] : -1;
            b = priq.empty() ? -1 : priq.top();
            if (a > b)
            {
                ans += a;
                --idx;
                priq.push((a + 2) / 3);
            }
            else
            {
                ans += b;
                priq.pop();
                priq.push((b + 2) / 3);
            }
        }

        return ans;
    }

};

int main()
{

    LT2530 lt;


    return 0;
}
