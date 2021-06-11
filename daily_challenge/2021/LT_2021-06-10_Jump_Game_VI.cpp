
#include "../../header/myheader.h"

class LT
{
public:


// 想到一种： 目前看来后续k个中 第一个非负数 是必取的：
// 从下标0开始搜索，直到第一个非负数， 如果这个非负数在范围k内，则跳到这个 下标，然后continue
//          如果这个非负数不在范围k内(或者已经到size)， 就转换成 全负数的情况下，怎么通过。
// 这种把问题转变了一点点的算不算子问题，divide-merge，应该算，全负数是这道题目的子集。
// 全负数的情况下，感觉还是得 ltb 这种， 不过规模小了以后， set的性能应该快很多吧。


// gg

// deque 保持最大。

// 感觉是 multiset 性能拉跨。。  deque, priority_queue, 都有。



//Instead of checking every j for every i,
//keep track of the smallest dp[i] values in a heap and calculate dp[i] from right to left.
//When the smallest value in the heap is out of bounds of the current index,
//remove it and keep checking.
// 最小堆，  从后往前。   无法理解。  这个说的是 for循环里面， 还是 整个for循环都要换。
// 好像往后k个中， 第一个正数 就是需要选择的，  但是如果全是负数就。。
// 从后往前的话，也是类似， 第一个正数就是选择的， 全负。。
    int ltc(vector<int>& nums, int k)
    {

    }


// tle....
// hint2    stack..no,  multiset.erase(iterator), not int... or map?
// 从 向后看，变成 向前看。
// 但是 hint2 的，，，细看下，保存的smallest，， 好像hint2的解法  和我想的不太一样。。
    int ltb(vector<int>& nums, int k)
    {
        multiset<int> mset2;
        mset2.insert(nums[0]);
        int sti = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] += *mset2.rbegin();     // max
            mset2.insert(nums[i]);
            if (mset2.size() > k)
            {
                mset2.erase(mset2.find(nums[sti++]));
            }
        }
        #ifdef __test
        showVectorInt(nums);
        #endif // __test
        return nums[nums.size() - 1];
    }


// tle
    int lta(vector<int>& nums, int k)
    {
        vector<int> vi(nums.size(), INT_MIN);
        int ans = 0;
        vi[0] = nums[0];

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                if (i + j < nums.size())
                {
                    vi[i + j] = max(vi[i + j], nums[i + j] + vi[i]);
                }
                else
                {
                    break;
                }
            }
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        ans = vi[vi.size() - 1];
        return ans;
    }

};

int main()
{
    myvi v = {1,-1,-2,4,-7,3};
    int k{2};

//    myvi v = {10,-5,-2,4,0,3};
//    int k{3};

//    myvi v = {1,-5,-20,4,-1,3,-6,-3};
//    int k{2};

    LT lt;

//    cout<<lt.lta(v, k)<<endl;
    cout<<lt.ltb(v, k)<<endl;

    return 0;
}
