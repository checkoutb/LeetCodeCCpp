
#include "../header/myheader.h"

class LT0442
{
public:


// discuss
//            int index = Math.abs(nums[i])-1;
//            if (nums[index] < 0)
//                res.add(Math.abs(index+1));
//            nums[index] = -nums[index];
// 。。

// 先排序，再遍历。
//        while (i < nums.size()) {
//            if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
//            else i++;
//        }
//        for (i = 0; i < nums.size(); i++) {
//            if (nums[i] != i + 1) res.push_back(nums[i]);
//        }


//        for(int i = 0; i < nums.size(); i ++){
//            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
//            if(nums[abs(nums[i])-1] > 0) res.push_back(abs(nums [i]));
//        }

// 用正负做标记。而不是用值。



    // error..想利用 数值与下标间的关系来获得唯一值。
    // 前i个已经计算过，所以如果swap后的值是前i个的，那么可以跳过。
    // 不。错在： 1，2，3，4，2，6， 这种情况，第二个2会和前面的swap，我无法确定
    // 但又出现了3，3，2.。。
    vector<int> lt0442c(vector<int>& nums)
    {
        vector<int> ans;
        for (int i = 0, sz1 = nums.size(); i < sz1; i++)
        {
            int v1 = nums[i] - 1;
            if (v1 != i)
            {
                std::swap(nums[i], nums[v1]);
                if (nums[i] == v1 + 1)
                {
                    if (nums[i] <= i && nums[i] != nums[v1])
                        continue;
                    ans.push_back(v1 + 1);
                }
                else
                {
                    i--;
                }
            }
        }
        return ans;
    }


//Runtime: 156 ms, faster than 14.16% of C++ online submissions for Find All Duplicates in an Array.
//Memory Usage: 20.7 MB, less than 15.00% of C++ online submissions for Find All Duplicates in an Array.

    vector<int> lt0442a(vector<int>& nums)
    {
        set<int> ans;

        int sz1 = nums.size();
        for (int i = 0; i < sz1; i++)
        {
            int v1 = nums[i] - 1;
            if (v1 != i)
            {
                if (nums[v1] == v1 + 1)
                    ans.insert(v1 + 1);
                else
                {
                    std::swap(nums[i], nums[v1]);
                    i--;
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());             // new...
    }
};

int main()
{
//    vector<int> v2 = {5,4,6,7,9,3,10,9,5,6};
    vector<int> v2 = {4,3,2,7,8,2,3,1};
//    vector<int> v2 = {1,2,3,4,2,6};

    LT0442 lt;

    vector<int> ans = lt.lt0442c(v2);

    for_each(ans.begin(), ans.end(), fun_cout);

    return 0;
}
