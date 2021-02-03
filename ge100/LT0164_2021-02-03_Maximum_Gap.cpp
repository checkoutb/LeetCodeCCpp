
#include "../header/myheader.h"

class LT0164
{
public:

// D D

// [4, 8]ms 的是 sort 后 for。。。  heap太拉了。。

//// LSD (Least Significant Digit) sort

// radix sort



//    if (num == null || num.length < 2)
//        return 0;
//    // get the max and min value of the array
//    int min = num[0];
//    int max = num[0];
//    for (int i:num) {
//        min = Math.min(min, i);
//        max = Math.max(max, i);
//    }
//    // the minimum possibale gap, ceiling of the integer division
//    int gap = (int)Math.ceil((double)(max - min)/(num.length - 1));
//    int[] bucketsMIN = new int[num.length - 1]; // store the min value in that bucket
//    int[] bucketsMAX = new int[num.length - 1]; // store the max value in that bucket
//    Arrays.fill(bucketsMIN, Integer.MAX_VALUE);
//    Arrays.fill(bucketsMAX, Integer.MIN_VALUE);
//    // put numbers into buckets
//    for (int i:num) {
//        if (i == min || i == max)
//            continue;
//        int idx = (i - min) / gap; // index of the right position in the buckets
//        bucketsMIN[idx] = Math.min(i, bucketsMIN[idx]);
//        bucketsMAX[idx] = Math.max(i, bucketsMAX[idx]);
//    }
//    // scan the buckets for the max gap
//    int maxGap = Integer.MIN_VALUE;
//    int previous = min;
//    for (int i = 0; i < num.length - 1; i++) {
//        if (bucketsMIN[i] == Integer.MAX_VALUE && bucketsMAX[i] == Integer.MIN_VALUE)
//            // empty bucket
//            continue;
//        // min value minus the previous value is the current gap
//        maxGap = Math.max(maxGap, bucketsMIN[i] - previous);
//        // update previous bucket value
//        previous = bucketsMAX[i];
//    }
//    maxGap = Math.max(maxGap, max - previous); // updata the final max value gap
//    return maxGap;

//We put n-2 elements in n-1 buckets. That's the key. At least one bucket is empty, so the max gap can't come from a single bucket. It can only come from two adjacent buckets, or one bucket and (max or min).

//If every gap is smaller or equal to Floor of (max-min)/(n-1), then average number won't be (max-min)/(n-1), so there must be a gap larger than Ceil of (max-min)/(n-1)

//Based on this, we only need to compare max number in this bucket and min number in next bucket to get the relatively large gap and find out which two bucket have the largest gap.

// 感觉是 bucket，直到出现 空的bucket。
// 或者是， bucket， 只需要判断 bucket中最大 与之前的最小， 不， 这种是错的，   所以是上面的， 需要出现一个 空bucket。
// 上面是直接算出 gap了， 所以是一次成形。
// gap = 最大值-最小值/个数-1 ，必然存在2个连续数字的差距 大于 gap，这样必然有一个 bucket是空的。



//
// 难道说 插入排序？ 还是直接 组成set？
// 速度慢，空间少，  说明 ，， 确实 题目说了  线性 时间，空间，  heap是 logN(可能) 的时间， 1的空间。
//Runtime: 20 ms, faster than 12.50% of C++ online submissions for Maximum Gap.
//Memory Usage: 8.7 MB, less than 87.93% of C++ online submissions for Maximum Gap.
// 有序后，相邻数的最大差.. 线性。。？
// heap，，
    int lt0164a(vector<int>& nums)
    {
        if (nums.size() < 2)
            return 0;
        std::make_heap(begin(nums), end(nums));
        #ifdef __test
        showVectorInt(nums);
        #endif // __test
        int ans = 0;
        std::pop_heap(begin(nums), end(nums));
        int lst = nums.back();
        nums.pop_back();
        while (!nums.empty())
        {
            std::pop_heap(begin(nums), end(nums));
            #ifdef __test
            showVectorInt(nums);
            #endif // __test
            int t2 = nums.back();
            nums.pop_back();
            ans = max(ans, lst - t2);
            lst = t2;
        }
        return ans;
    }

};

int main()
{
    myvi v = {3,6,9,1};

    LT0164 lt;

    cout<<lt.lt0164a(v)<<endl;

    return 0;
}
