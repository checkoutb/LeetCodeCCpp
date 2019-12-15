
#include "../header/myheader.h"

class LT0448
{
public:

// detail:
// nums[idx] *= -1;
// 之前有类似的方法的。。忘记了。。discuss:similar to 442

//        for(int i = 0; i < nums.size(); ++i){
//            while(nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]){
//                swap(nums[i],nums[nums[i] - 1]);
//            }
//        }
// 总觉得while能快速xx(类似有序)。。。但是总比较次数应该差不多。。对，速度112ms，差不多的



// discuss
// for (int i = 0; i < nums.length; i ++) nums[(nums[i]-1) % n] += n;
// 对于出现的数，直接+nums.length。。




//Runtime: 116 ms, faster than 69.83% of C++ online submissions for Find All Numbers Disappeared in an Array.
//Memory Usage: 16 MB, less than 10.00% of C++ online submissions for Find All Numbers Disappeared in an Array.

// if (nums[i] != i && nums[nums[i]] != nums[i]) {swap} else i++
    vector<int> lt0448a(vector<int>& nums)
    {
        vector<int> ans;
        int i = 0;
        int sz1 = nums.size();
        nums.push_back(0);
        while (i < sz1)
        {
            if (nums[i] != i)
            {
                if (nums[nums[i]] != nums[i])
                {
                    std::swap(nums[i], nums[nums[i]]);
                }
                else
                {
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        for (int i = 1; i <= sz1; i++)
        {
            if (i != nums[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{

    vector<int> nums = {4,3,2,7,8,2,3,1};

    LT0448 lt;

    vector<int> result = lt.lt0448a(nums);
    for_each(result.begin(), result.end(), fun_cout);
    return 0;
}
