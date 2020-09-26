
#include "../header/myheader.h"

class LT0565
{
public:


// D D

// 能dfs，但是不能memo

// 看来，每个元素必然在一个环中，没有q这种形态(有一段不是环的一部分)，全是o。。 所以只要nums[i]这个值<0，说明已经计算过了。
// 我的代码好像就是这样的。。当时认为是有q这种的。。
// if 和 while 和可以合并的。 while(nums[i] >= 0)

// 由于必然成环，所以有没有memo 也无所谓了， 而且 memo 不会被用到。



    int lt0565a(vector<int>& nums)
    {
        int tag1 = -1;
        int len1 = 0;
        int j = 0;
        int k = 0;
        int ans = 0;
//        vector<int> map2(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                len1 = 0;
                j = i;
                while (nums[j] != tag1)
                {
                    len1++;
                    k = nums[j];
                    nums[j] = tag1;
                    j = k;
                }
                ans = max(ans, len1);
                tag1--;
            }
        }
        return ans;
    }


    // 不能dfs， 考虑一个长度5的环， 第一次访问到里面的一个点时，这个点的map2就是5，下次访问 这个点的 后面一个点时，由于之前dfs了，所以map2里是4。如果是第一次访问的点的前面那个点，map2里是1。
    int dfsa1(vector<int>& map2, vector<int>& nums, int tag1, int i)
    {
        if (map2[nums[i]] != -1)
            return map2[nums[i]];
        if (nums[i] == tag1)
        {
            map2[nums[i]] = 0;
            return 0;
        }
        int ii = nums[i];
        nums[i] = tag1;
        int len = dfsa1(map2, nums, tag1, ii);
        return -1;
    }
};

int main()
{

    vector<int> v = {5,4,0,3,1,6,2};

    LT0565 lt;

    cout<<lt.lt0565a(v)<<endl;

    return 0;
}
