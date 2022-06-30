
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        int r=nums.size()-1;
//        sort(nums.begin(),nums.end());
//        int l=0;
//        int cnt=0;
//        while(l<r){
//            cnt+=nums[r--]-nums[l++];
//        }
// ...


//        int n = nums.size();
//        auto it = nums.begin() + n/2;
//        nth_element(nums.begin(), it, nums.end());
//        int median = *it;



//Runtime: 18 ms, faster than 42.75% of C++ online submissions for Minimum Moves to Equal Array Elements II.
//Memory Usage: 10.7 MB, less than 99.77% of C++ online submissions for Minimum Moves to Equal Array Elements II.
// x-[0] + x-[1] .... + [n-1]-x + [n]-x
// 这个x应该是数组的元素，但是怎么证明？ 反证， 如果 x不是数组的元素，且在 [a]，[a+1] 之间。 那么如果前半部分的 元素个数 小于后半部分
//      那么 x+1 的值 必然 小于 x 的值。 因为 x+1的值 == x的值 + 前半部分*1 - 后半部分*1。 。。 这样的话，直接是中位数？ yes。
// 偶数个数呢？好像无所谓的。只要中间的就可以了。
    int lta(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        int md = nums[nums.size() / 2];
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i)
            ans += abs(nums[i] - md);

        return ans;

//        int sz1 = nums.size();
//        sort(begin(nums), end(nums));
//        long long ans = INT_MAX;
//        long long sum2 = accumulate(begin(nums), end(nums), 0LL);
//        int md = nums[0];
//        ans = sum2 - 1LL * sz1 * md;
//        long long pre = nums[0];
//        sum2 -= nums[0];
//
//        for (int i = 1; i < sz1; ++i)       // <i, >=i
//        {
//
//            sum2 -= nums[i];
//            pre += nums[i];
//        }
//
//        return ans;
    }

};

int main()
{

    LT lt;

//    myvi v = {1,2,3};
    myvi v = {1,10,2,9};

    cout<<lt.lta(v)<<endl;

    return 0;
}
