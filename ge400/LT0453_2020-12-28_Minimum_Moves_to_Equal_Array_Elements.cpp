
#include "../header/myheader.h"

class LT0453
{
public:


// D

//define sum as the sum of all the numbers, before any moves; minNum as the min number int the list; n is the length of the list;
//After, say m moves, we get all the numbers as x , and we will get the following equation
//              sum + m * (n - 1) = x * n
// actually:    x = minNum + m
// so:          sum - minNum * n = m

//return sum(nums) - len(nums) * min(nums)

// 关键就是   x=minNum+m， 因为 min_ele 这个元素，每次 操作，都会碰到， 所以能知道 元素值最终是 min_ele + m
// 面积相等。


// tle...
    int lt0453c(vector<int>& nums)
    {
        std::sort(begin(nums), end(nums));
        int ans = 0;
        int sz1 = nums.size();
        while (true)
        {
//            std::sort(begin(nums), end(nums));
            for (int i = sz1 - 2; i >= 0; --i)
            {
                if (nums[i] < nums[i + 1])
                {
                    int t2 = nums[i + 1] - nums[i];
                    for (int j = 0; j <= i; j++)
                    {
                        nums[j] += t2;
                    }
                    int t3 = t2 * (sz1 - i - 2);
                    for (int j = i + 1; j < sz1; ++j)
                    {
                        nums[j] += (t3 / (sz1 - j));
                        t3 -= (t3 / (sz1 - j));
                    }

//                    int t3 = t2 * (sz1 - i -2);
//                    int t4 = t3 / (sz1 - 1 - j);
//                    int t5 = t3 % (sz1 - 1 - j);        // 应该已经有序了。
//                    int j = 1;
//                    for (; j <= sz1 - 1 - j - t5; j++)
//                    {
//                        nums[j] += ;
//                    }
                    ans += t2;
                    goto AAA;
                }
            }
            break;
            AAA:
            continue;
        }
        return ans;
    }


// error
// 只要 min max 超过1, 就 继续。   会不会 nums的元素，超过INT_MAX？
    int lt0453b(vector<int>& nums)
    {
        int mx = nums[0];
        int mn = nums[0];
        int mnidx = 0;
        long sum2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum2 += nums[i];
            mx = max(mx, nums[i]);
            if (mn < nums[i])
            {
                mn = nums[i];
                mnidx = i;
            }
//            mn = min(mn, nums[i]);
        }
        int sz1 = nums.size();
        int ans = 0;
        while (mn + 1 < mx)
        {
            int t1 = mx - mn;
            ans += (mx - mn);
            nums[mnidx] += t1;

            long t2 = (long) (mx - mn) * (sz1 - 2);
            int t3 = (sum2 + t2 + t1) / sz1;
            for (int i = 0; i < sz1; ++i)
            {
                if (i == mnidx)
                    continue;
                nums[i] += -11111;
            }

            mn = mx = sum2 = nums[0];
            mnidx = 0;
            for (int i = 1; i < nums.size(); ++i)
            {
                sum2 += nums[i];
//                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
                if (mn < nums[i])
                {
                    mn = nums[i];
                    mnidx = i;
                }
            }
        }

        return ans;
    }


// error
// 反推， 要全部相等，那么之前就是  n-1个相同，1个大1,  之前  n-2个相同，2个大1,   之前 n-3个相同，3个大一。
// . [1,1000,1000,1000,1000]
// 根据反推， 一旦 元素差值 不超过1时， 就可以得到ans了。
// 至少需要 max_ele - min_ele 次。     (这么多次以后，得到的应该是 差值不超过1的。!!??)
    int lt0453a(vector<int>& nums)
    {
        int mx = nums[0];
        int mn = nums[0];
        long sum2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum2 += nums[i];
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        if (mn == mx)
            return 0;
        int sz1 = nums.size();
        long t2 = (long) (mx - mn) * (sz1 - 1);
        t2 += sum2;
        t2 %= sz1;
        int ans = t2 + (mx - mn);
        return ans;
    }

};

int main()
{
//    myvi v = {1,2,3};
    myvi v = {-100,0,100};      // 300     操作过程中， max也在变大。  。 就是 上面提到的： 这么多次以后，得到的应该是 差值不超过1的, 不成立。。

    LT0453 lt;

    cout<<lt.lt0453c(v)<<endl;

    return 0;
}
