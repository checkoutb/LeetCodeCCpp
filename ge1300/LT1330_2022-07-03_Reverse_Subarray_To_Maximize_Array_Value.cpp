
#include "../header/myheader.h"

class LT1330
{
public:

    // D


    // 。。。。
    // 要么前半段反转，要么后半段反转，要么max min反转。 用的是 2*(max,min) 。。

    // 不清楚。



    // a b c d e f ,,,,,  b-a c-b d-c e-d f-d       e-d,f-d,
    // a b e d c f ,,,,,  b-a e-b d-e c-d f-c       e-b,f-c
    // 差了交界处的  for for
    // 2 3 1 5 4    2 5 1 3 4       2 3 5 1 4
    //  1 2 4 1      3 4 2 1         1 2 4 3
    // 1 2 3 4 5    
    // min-diff ?
    // 2 4 9 24 2 1 10   2 2 24 9 4 1 10  
    // 0 22 15 5 3 9  != 68
    // 
    // abs(a-b) = max(a-b,a+b,-a-b,-a+b)
    // 对于确定的a，必然是和 max/min 才能获得abs最大。 但是 subarr 的某端 必然是 max或min？
    // 2 4 24 9 2 1 10
    //  2 20 15 7 1 9  22 22 10... no
    // 
    int lt1330a(vector<int>& nums)
    {
        int sz1 = nums.size();
        int sum2 = 0;
        for (int i = 1; i < sz1; ++i)
        {
            sum2 += abs(nums[i] - nums[i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)           // aaaa[i,j]aaa
        {
            for (int j = i + 1; j < sz1; ++j)
            {
                int t2 = sum2 - (i == 0 ? 0 : abs(nums[i] - nums[i - 1])) - (j == (sz1 - 1) ? 0 : abs(nums[j + 1] - nums[j]))
                    + (i == 0 ? 0 : abs(nums[j] - nums[i - 1])) + (j == (sz1 - 1) ? 0 : abs(nums[j + 1] - nums[i]));
#ifdef __test
                cout << i << ", " << j << " - - " << t2 << ", " << ans << endl;
#endif
                ans = max(ans, t2);
            }
        }
        return ans;
    }

};

int main()
{

    LT1330 lt;

    //myvi v = { 2,3,1,5,4 };

    myvi v = { 2,4,9,24,2,1,10 };       // 2 4 9 2 24 1 10  .. . 让max 和 min 到一起？  。。 估计是 最大和最小，最大和次小， 次大和最小，次大和次小
                        // 最大-最小 是 最大diff。 再怎么换，也不可能比这个diff 更大。 但是 最大-最小+0-0 ， 和 次大-最小+最大-次小， 不知道谁最大的。
                            // 所以需要 尝试啊， 多少次？ 什么条件结束？

    cout << lt.lt1330a(v) << endl;

    return 0;
}
