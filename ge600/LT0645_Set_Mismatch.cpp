
#include "../header/myheader.h"

class LT0645
{
public:


// D D

//def findErrorNums(self, nums):
//    return [sum(nums) - sum(set(nums)), sum(range(1, len(nums)+1)) - sum(set(nums))]


//         int n=nums.size();
//         int sum=(n*(n+1))/2;
//            int k=0;
//            for(int i=0;i<n;i++)
//            {
//                k+=abs(nums[i]);
//                if(nums[abs(nums[i])-1]<0)
//                    a=abs(nums[i]);
//                else
//                    nums[abs(nums[i])-1]*=-1;
//            }
//            b=sum-k+a;
//            return {a,b};


//        int[] ans = new int[2];
//        for(int i = 0; i < nums.length; i++) {
//            int val = Math.abs(nums[i]);
//            ans[1] ^= (i+1) ^ val;
//            if (nums[val-1] < 0) ans[0] = val;
//            else nums[val-1] = -nums[val-1];
//        }
//        ans[1] ^= ans[0];
//        return ans;


//        for (int i = 0; i < nums.length; i++) {
//            while (nums[i] - 1 != i && nums[nums[i] - 1] != nums[i]) {
//                swap(nums, i, nums[i] - 1);
//            }
//        }
//
//        for (int i = 0; i < nums.length; i++) {
//            if (nums[i] - 1 != i) {
//                result[0] = nums[i];
//                result[1] = i + 1;
//                break;
//            }
//        }

//    int[] res = new int[2];
//    for (int i : nums) {
//        if (nums[Math.abs(i) - 1] < 0) res[0] = Math.abs(i);
//        else nums[Math.abs(i) - 1] *= -1;
//    }
//    for (int i=0;i<nums.length;i++) {
//        if (nums[i] > 0) res[1] = i+1;
//    }
// 碰到负数，说明之前已经取负了，说明之前碰到这个数了。所以是 重复，这里没有把负数变成正数。
// 碰到正数，说明这个下标没有人访问过，说明没有 这个值。


//Runtime: 92 ms, faster than 41.78% of C++ online submissions for Set Mismatch.
//Memory Usage: 21.9 MB, less than 43.47% of C++ online submissions for Set Mismatch.
// 能二分，看值和下标是否是+1的关系。
    vector<int> findErrorNums(vector<int>& nums)
    {
        std::sort(begin(nums), end(nums));
        bool findLost = false;
        bool findDup = false;
        int lost = -1;
        int dup = -1;
        if (nums[0] != 1)
        {
            lost = 1;
            findLost = true;
        }
        if (nums[nums.size() - 1] != nums.size())
        {
            lost = nums.size();
            findLost = true;
        }
        for (int i = 1; i < nums.size(); i++)
        {
            if (!findDup)
            {
                if (nums[i] == nums[i - 1])
                {
                    dup = nums[i];
                    findDup = true;
                    continue;
                }
            }
            if (!findLost)
            {
                if (nums[i] != nums[i - 1] + 1)
                {
                    lost = nums[i - 1] + 1;
                    findLost = true;
                }
            }
            if (findDup && findLost)
                break;
        }
        return {dup, lost};
    }

};

int main()
{

//    vector<int> v = {1,2,2,4};
//    vector<int> v = {1,3,3};
    vector<int> v = {1,5,3,2,2,7,6,4,8,9};

    LT0645 lt;

    vector<int> v2 = lt.findErrorNums(v);

    cout<<v2[0]<<", "<<v2[1]<<endl;

    return 0;
}
