
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //while (p2 >= 0) {
    //    if (p1 >= 0 && nums1[p1] > nums2[p2]) {
    //        nums1[i--] = nums1[p1--];
    //    }
    //    else {
    //        nums1[i--] = nums2[p2--];
    //    }
    //}


    //func merge(nums1[]int, m int, nums2[]int, n int) {
    //    idx := len(nums1) - 1
    //    m--
    //    n--
    //    for m >= 0 || n >= 0 {
    //        t1, t2 := -2100000000, -2100000000
//            if m >= 0 {
//                t1 = nums1[m]
//            }
    //        if n >= 0 {
    //            t2 = nums2[n]
    //        }
    //        if t1 > t2{
    //            nums1[idx] = t1
    //            m--
    //        }
    //        else {
    //            nums1[idx] = t2
    //                n--
    //        }
    //        idx--
    //    }
    //}


//Runtime: 6 ms, faster than 29.53 % of C++ online submissions for Merge Sorted Array.
//Memory Usage : 9.1 MB, less than 30.68 % of C++ online submissions for Merge Sorted Array.
    void ltb(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int sz1 = m + n;
        for (int i = m - 1; i >= 0; --i)
        {
            nums1[i + n] = nums1[i];
        }
        int i1 = n;
        int i2 = 0;
        int idx = 0;
        while (idx < sz1)
        {
            if (i1 < sz1 && i2 < n)
            {
                if (nums1[i1] < nums2[i2])
                {
                    nums1[idx] = nums1[i1++];
                }
                else
                {
                    nums1[idx] = nums2[i2++];
                }
            }
            else
            {
                if (i1 == sz1)
                {
                    nums1[idx] = nums2[i2++];
                }
                else
                {
                    nums1[idx] = nums1[i1++];
                }
            }

            idx++;
        }

    }


    // ...
    // nums1 整体后移n位。 或：
    void lta(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int fst = m;        // nums1 's first empty element
        int i1 = 0, i2 = 0;
        int sz1 = m + n;
        while (i1 < sz1)
        {
            if (i2 == n)
                break;

            if (nums1[i1] <= nums2[i2])
            {
                ++i1;
            }
            else
            {
                // nums1 // ..... 无法 放到 nums1[lst]。。会造成无序。。 所以只能整体后移。。
                            // 或者需要一个辅助数组，vi.push_back(nums1[i])， 后续对比的时候 优先和 辅助数组的元素对比，辅助数组空，则和 nums1 对比。

                ++i2;
            }
        }
    }

};

int main()
{

    LT lt;

    //myvi v = { 1,2,3,0,0,0 };
    //myvi v2 = { 2,5,6 };
    //int m{ 3 }, n(3);

    //myvi v = { 1 };
    //myvi v2 = {};
    //int m = 1, n = 0;

    myvi v = { 0 };
    myvi v2 = { 1 };
    int m = 0, n = 1;

    lt.ltb(v, m, v2, n);

    showVectorInt(v);

    return 0;
}
