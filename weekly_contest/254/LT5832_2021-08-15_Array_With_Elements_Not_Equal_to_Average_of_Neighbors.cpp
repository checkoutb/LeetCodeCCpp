
#include "../../header/myheader.h"

class LT5832
{
public:






// AC  cao...wo buzhidao weishenme...
    vector<int> ltb(vector<int>& nums)
    {
        int sz1 = nums.size();
        std::sort(begin(nums), end(nums));
        for (int i = 2; i < sz1; ++i)
        {
            if (i < 2)
                continue;
            if (nums[i] + nums[i - 2] == nums[i - 1] * 2)
            {
                swap(nums[i], nums[i - 1]);
                i -= 2;
            }
        }
        return nums;
    }



// (odd + even) / 2 != int
// 排序，然后3个 3个一组，  中小大。  中+大/2 > 小。 但后续的。 3部分。
// 中小大 中小大 中小大    大中小。   中小大 大小中 中小大 大小中  小大大。。
// 中小大 小大中 大小中    中小大 小大中。。 小中中可以让中间部分从大往小遍历来规避掉  ， 上面的小大大 也能这样规避掉的,上面还有个大大小。。。
//                  中中小。。。
    vector<int> lta(vector<int>& nums)
    {
        std::sort(begin(nums), end(nums));
        int sz1 = nums.size();
        int small = 0;
        int mid = sz1 / 3 * 2 + 1;      // .
        int big = mid + 1;
        int mnbig = mid;
        vector<int> ans(sz1);
        int i = 0;
        while (i < sz1)
        {
            if (i < sz1 && mid > small)
            {
                ans[i++] = nums[mid--];
            }
            if (i < sz1 && small < mid)
            {
                ans[i] = nums[small];
                i++;
                small++;
            }
            if (i < sz1 && big > mnbig)
            {
                ans[i++] = nums[big++];
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,2,3,4,5};
    myvi v = {1,5,2,6,3,7,4,8};

    LT5832 lt;

    myvi v2 = lt.ltb(v);

    showVectorInt(v2);

    return 0;
}
