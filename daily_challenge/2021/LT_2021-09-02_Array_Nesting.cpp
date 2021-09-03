
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        for (int i = 0; i < numsSize; i++) {
//            if (!visited[i]) {
//                int groupSize = 0, j = i;
//                while (!visited[j]) {
//                    visited[j] = true;
//                    j = nums[j];
//                    groupSize++;
//                }
//                maxGroupSize = max(maxGroupSize, groupSize);
//            }
//        }
// 尾递归。不需要。
// permutation 所以不会出现 2个部分重叠的环 (就是 2个元素值相同。不会出现)。


// 记录 开始的值，就可以了。。。不需要 set。。。






// AC
// 必然成环，所以用bool 标记 是否已经被计算过了。来减少内存。
    int lta(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<bool> vb(sz1, false);
        unordered_set<int> set2;
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (vb[i] == false)
            {
                set2.clear();
                ans = max(ans, dfsa1(nums, vb, i, set2));
            }
        }
        return ans;
    }

    int dfsa1(vector<int>& nums, vector<bool>& vb, int idx, unordered_set<int>& set2)
    {
        if (set2.find(nums[idx]) != set2.end())
        {
            return 0;
        }
        if (!vb[idx])
            vb[idx] = true;
        idx = nums[idx];
        set2.insert(idx);
        return dfsa1(nums, vb, idx, set2) + 1;
    }

};

int main()
{
    myvi v = {5,4,0,3,1,6,2};
//    myvi v = {0,1,2};

    LT lt;

    cout<<lt.lta(v)<<endl;

    return 0;
}
