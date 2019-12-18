
#include "../header/myheader.h"

class LT0494
{
public:




//                  sum(P) - sum(N) = target
//sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
//                       2 * sum(P) = target + sum(nums)
// 然后forfor 寻找 和是 (tar+sum) / 2 的组合数。 首先sum>tar,第二sum+tar是偶数。。。forfor也很。。
//        for (int n : nums)
//            for (int i = s; i >= n; i--)
//                dp[i] += dp[i - n];
// dp的下标是和。dp[0]是1，所以 dp[x of nums] 也是1。。。。有语言能够 dp[x of nums] = 1 这种吗？ 或者x in nums。不过好像没什么用。。
// 由于是 和，所以 最小数就是n，最大数只需要到 s就可以了。。第一个n是既是自己，又是第二个n的垫脚石。如此往后。



// error
    int lt0494c(vector<int>& nums, int S)
    {
        int sz1 = nums.size();
        int plusArr[sz1][sz1] = {{0}};
        int minusArr[sz1][sz1] = {{0}};

        for (int i = 0; i < sz1; i++)
        {
            for (int j = i; j < sz1; j++)
            {
                if (i == j)
                {
                    plusArr[i][j] = nums[i];
                    minusArr[i][j] = -nums[i];
                }
                else
                {
                    plusArr[i][j] = plusArr[i][j - 1] + nums[i];
                    minusArr[i][j] = minusArr[i][j - 1] - nums[j];
                }
            }
        }
        dfsc1(nums, S, 0, (int*)plusArr, (int*)minusArr, 0);
        dfsc1(nums, S, 0, (int*)minusArr, (int*)plusArr, 0);
        return ansc;
    }
    int ansc = 0;
    void dfsc1(vector<int>& nums, int tar, int sum, int* arr1, int* arr2, int i)
    {

        if (i == nums.size())
        {
            if (tar == sum)
                ansc++;
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            dfsc1(nums, tar, sum + arr1[i * nums.size() + j], arr2, arr1, j);
//            dfsc1(nums, tar, sum + marr[i * nums.size() + j], parr, marr, (i + j));
        }
    }



//Runtime: 388 ms, faster than 39.02% of C++ online submissions for Target Sum.
//Memory Usage: 8.7 MB, less than 61.54% of C++ online submissions for Target Sum.

    int lt0494b(vector<int>& nums, int S)
    {
        vector<int> sums(nums.size());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            sums[i] = sum;
        }
        dfsb1(nums, S, 0, nums.size() - 1, sums);
        return ansb;
    }
    int ansb = 0;
    void dfsb1(vector<int>& nums, int tar, int sum, int i, vector<int>& ss)
    {
        if (i == -1)
        {
            if (tar == sum)
                ansb++;
            return;
        }
        if (std::abs(tar - sum) > std::abs(ss[i]))
        {
            return;
        }
        dfsb1(nums, tar, sum - nums[i], i - 1, ss);
        dfsb1(nums, tar, sum + nums[i], i - 1, ss);
    }


//Runtime: 1092 ms, faster than 17.22% of C++ online submissions for Target Sum.
//Memory Usage: 8.5 MB, less than 84.62% of C++ online submissions for Target Sum.

    int lt0494a(vector<int>& nums, int S)
    {
        dfsa1(nums, S, 0, 0);
        return ans;
    }
    int ans = 0;
    void dfsa1(vector<int>& nums, int tar, int sum, int i)
    {
        if (i == nums.size())
        {
            if (tar == sum)
                ans++;
            return;
        }
        dfsa1(nums, tar, sum - nums[i], i + 1);
        dfsa1(nums, tar, sum + nums[i], i + 1);
    }
};

int main()
{

    vector<int> v = {1,1,1,1,1};
    int t = 3;

    LT0494 lt;

    cout<<lt.lt0494c(v, t)<<endl;

    return 0;
}
