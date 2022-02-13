
#include "../header/myheader.h"

class LT2009
{
public:


// D D

//nums.erase(unique(begin(nums), end(nums)), end(nums));
// unique返回 A ForwardIt to the new end of the range.
// erase：Removes the elements in the range [first, last).


//        sort(nums.begin(),nums.end());
//        nums.erase(unique(nums.begin(),nums.end()),nums.end());
//        int j=0;
//        for(int i=0;i<nums.size();i++){
//            while(j<nums.size() && nums[i]+n>nums[j])j++;
//            ans=min(ans,n-(j-i));
//        }


//Runtime: 453 ms, faster than 28.39% of C++ online submissions for Minimum Number of Operations to Make Array Continuous.
//Memory Usage: 93 MB, less than 29.48% of C++ online submissions for Minimum Number of Operations to Make Array Continuous.
// 文章本天成，妙手偶得之。
// 最开始： sort,  肯定是从 2侧 操作的， 而且 拆下来以后，不需要 确定是什么，只需要知道 有一个 任意数字 就可以了。比如，最大值去掉后，剩下的max-min=sz1, 那么 说明 有一个位置，只要 最大的 变成 这个位置 就可以了。
// sliding window, 窗口大小是 sz1， 找到 窗口内 最多的 唯一数值 个数。 就可以了。
    int lt2009a(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        int ans = 0;
        int sz1 = nums.size();
        unordered_set<int> set2;
        int en = 0;
        int mxcnt = 0;
        for (int i = 0; i < sz1; i++)
        {
            while (en < sz1 && nums[i] + sz1 > nums[en])
            {
                set2.insert(nums[en++]);
            }
            if (set2.size() > mxcnt)
                mxcnt = set2.size();
            set2.erase(nums[i]);            // i++ 足够了。
        }
        ans = sz1 - mxcnt;
        return ans;
    }

};

int main()
{

    LT2009 lt;

//    myvi v = {4,2,3,6,8};
//    myvi v = {1,2,3,5,6};
//    myvi v = {1,11,22,33};
    myvi v = {1,1,11,22};

    cout<<lt.lt2009a(v)<<endl;

    return 0;
}
