
#include "../header/myheader.h"

class LT0327
{
public:



    // discuss
    // mergeSort
    // 通过 sums[i + 1] = sums[i] + nums[i]; 将问题转化为 sums数组中有多少对下标能满足 sums[j]-sums[i] between lower and upper.
    // sums可以排序。通过mergeSort边排序，边计数。返回mergeSort范围内的 下标对数。代码很难。。
    //
//    for (int i = start, r = 0; i < mid; ++i, ++r) {
//        while (k < end && sums[k] - sums[i] < lower) k++;
//        while (j < end && sums[j] - sums[i] <= upper) j++;
//        while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
//        cache[r] = sums[i];
//        count += j - k;
//    }


    // 回溯..不，不是回溯，依然是暴力。只不过不需要数组了。
    // 61/61 tle
    int lt0327b(vector<int>& nums, int lower, int upper)
    {
        int len = nums.size();
        if (len == 0 || upper < lower)
            return 0;
        long t1 = 0;
        int result = 0;
        for (int i = 0; i < len; i++)
        {
            t1 = 0;
            for (int j = i; j < len; j++)
            {
                t1 += nums[j];
                if (t1 >= lower && t1 <= upper)
                    result++;
            }
        }
        return result;
    }

    // ...这题目的意思。。数组nums，lower和upper是和的范围，在数组中选取i,j，使得下标i到j的和在lower，upper范围中。
    // dp走起。。。
    // 但是无法比O(n^2)更快啊。。。先O(n^2)再说了。
    // dp似乎可以2种，都是双层for，一种是i为开始，j为结束，另一种是i是步长，j是开始/结束。。两者好像都一样，结果都是三角矩阵
    // A naive algorithm of O(n2) is trivial..too young too simple...

    // 55/61 stack overflow..
    // 那就是需要前推回溯之类的了，不需要大量数组来保存，但是依然是0(n^2)吧？
    int lt0327a(vector<int>& nums, int lower, int upper) {
        int sz = nums.size();
        if (sz == 0 || lower > upper)
            return 0;
        long dp[sz][sz] = {};
        long t1 = 0;
        int result = 0;
        for (int i = 0; i < sz; i++)        // start
        {
            t1 = 0;
            for (int j = i; j < sz; j++)    // end
            {
                t1 += nums[j];
                dp[i][j] = t1;
            }
        }
        for (int i = 0; i < sz; i++)
        {
            for (int j = i; j < sz; j++)
            {
                t1 = dp[i][j];
                if (t1 >= lower && t1 <= upper)
                    result++;
            }
        }
        return result;
    }
};

int main()
{
    int arr[] = {-2,5,-1};
    int lower = -2;
    int upper = 2;

    vector<int> v(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    LT0327 lt;
    cout<<endl<<lt.lt0327b(v, lower, upper)<<endl;
    return 0;
}
