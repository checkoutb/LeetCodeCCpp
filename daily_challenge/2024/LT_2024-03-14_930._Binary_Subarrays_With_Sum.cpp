
#include "../../header/myheader.h"

class LT
{
public:

    // D D

        // for (auto i: nums) {
        //     sum += i;
        //     ans += m[sum-goal];
        //     m[sum]++;
        // }


    // int find(vector<int> &v,int g){
    //     int i=0,j=0;
    //     int sum=0;
    //     int c=0;
    //     while(j<v.size()){
    //         sum+=v[j];
    //         while(sum>g && i<=j){
    //             sum=sum-v[i];
    //             i++;
    //         }
    //         c+=(j-i+1);
    //         j++;
    //     }
    //     return c;
    // }
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     return find(nums,goal)-find(nums,goal-1);
    // }
    //
    // c += (j-i+1)   所以要 goal - (goal-1)
    //
    // j-i+1 是以 j为结尾，下标往前1个，下标往前2个，下标往前i-1个 subarray 的个数。 这些subarray的和 是0,1,2,..., goal
    //      所以 goal - (goal-1) 就 等于 goal 的subarray个数。




// Runtime
// 25ms
// Beats69.52%of users with C++
// Memory
// 32.01MB
// Beats50.38%of users with C++
    // 0, 1 .  non-decrease
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        int sz1 = nums.size();
        int ans = 0;
        vector<int> v1 {-1};     // 1's index
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i])
                v1.push_back(i);
        }
        v1.push_back(sz1);

        if (goal == 0)
        {
            for (int i = 1; i < v1.size(); ++i)
            {
                int t2 = v1[i] - v1[i - 1] - 1;
                ans += (t2 + 1) * t2 / 2;
            }
            return ans;
        }

        for (int i = goal; i + 1 < v1.size(); ++i)
        {
            ans += (v1[i - goal + 1] - v1[i - goal]) * (v1[i + 1] - v1[i]);
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
