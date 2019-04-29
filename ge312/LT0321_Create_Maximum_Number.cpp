
#include "../header/myheader.h"

class LT0321
{
public:

    // discuss 的代码都好长。。。gg。。。
    // 这里能想到的提升点就是当2个数组都出现了最大值时，应该是前推然后回溯回来决定哪个，而不是我这样的暴力方法。
    // 但是前推可能又碰到相同数，无尽呐。好像也没问题？毕竟前推完就知道后续n个的实际取值了？
    // 而且应该不会无尽吧，一共就10个数字，应该不可能出现需要前推后尾才能确定的情况吧。
    // 不管了。。

    // 77/102 timeout...
    vector<int> lt0321b(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int t1 = len1 + len2 - k;
        int max1 = 0, max2 = 0, in1 = 0, in2 = 0, s1 = 0, s2 = 0, inr = 0;
        vector<int> result(k);

        result = recursionb1(nums1, nums2, k, in1, in2, inr, result);

        return result;
    }

    vector<int> recursionb1(vector<int>& nums1, vector<int>& nums2, int k, int in1, int in2, int inr, vector<int> result)
    {
        #ifdef __test
        cout<<k<<","<<in1<<","<<in2<<","<<inr<<","<<endl;
        for_each(result.begin(), result.end(), fun_cout);
        cout<<endl<<endl;
        #endif // __test
        if (k == 0)
            return result;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int t1 = len1 + len2 - in1 - in2 - k;
        int len1max = (len1 - 1) > (in1 + t1) ? in1 + t1 : len1 - 1;
        int len2max = (len2 - 1) > (in2 + t1) ? in2 + t1 : len2 - 1;

        int m1 = 0, m2 = 0;
        int i1 = in1, i2 = in2;
        if (in1 >= len1)
        {
            m1 = -1;
        }
        else
        {
            m1 = nums1[in1];
        }
        if (in2 >= len2)
        {
            m2 = -1;
        }
        else
        {
            m2 = nums2[in2];
        }
        for (int i = in1; i <= len1max; i++)
        {
            if (nums1[i] > m1)
            {
                m1 = nums1[i];
                i1 = i;
            }
        }
        for (int i = in2; i <= len2max; i++)
        {
            if (nums2[i] > m2)
            {
                m2 = nums2[i];
                i2 = i;
            }
        }
        if (m1 == m2)
        {
            result[inr] = m1;
            inr++;
            k--;
            vector<int> v1 = recursionb1(nums1, nums2, k, i1 + 1, in2, inr, result);
            vector<int> v2 = recursionb1(nums1, nums2, k, in1, i2 + 1, inr, result);
            bool takeV1 = false;
            for (int i = 0; i < v1.size(); i++)         // i = 0
            {
                if (v1[i] != v2[i])
                {
                    takeV1 = v1[i] > v2[i];
                    break;
                }
            }
            result = takeV1 ? v1 : v2;
        }
        else
        {
            int ts1 = 0, ts2 = 0;
            if (m1 > m2)
            {
                result[inr] = m1;
                in1 = i1;
                ts1 = 1;
            }
            else
            {
                result[inr] = m2;
                in2 = i2;
                ts2 = 1;
            }
            inr++;
            k--;
            result = recursionb1(nums1, nums2, k, in1 + ts1, in2 + ts2, inr, result);
        }
        return result;
    }

    // 需要维持原数组顺序。
    // deprecated
    vector<int> lt0321a(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int t1 = len1 + len2 - k;
        int max1, max2, in1, in2, s1 = 0, s2 = 0;
        #ifdef __test
        cout<<max1<<", "<<max2<<", "<<in1<<", "<<in2<<endl;         // random...
        #endif // __test
        vector<int> result(k);
        int inr = 0;
        for (int i = s1; i < t1 && i < len1; i++)
        {
            if (nums1[i] > max1)
            {
                max1 = nums1[i];
                in1 = i;
            }
        }
        for (int i = s2; i < t1 && i < len2; i++)
        {
            if (nums2[i] > max2)
            {
                max2 = nums2[i];
                in2 = i;
            }
        }
        if (max1 == max2)
        {

        }
        else
        {
            if (max1 > max2)
            {
                s1 = in1;
                result[inr] = max1;
            }
            else
            {
                s2 = in2;
                result[inr] = max2;
            }
            inr++;
        }
//        for (int i = 0; i < t1; i++)
//        {
//            if (i < len1 && nums1[i] > max1)
//            {
//                max1 = nums1[i];
//                in1 = i;
//            }
//            if (i < len2 && nums2[i] > max2)
//            {
//                max2 = nums2[i];
//                in2 = i;
//            }
//        }



        return result;
    }

//    void recursiona1(vector<int>& n1, vector<int>& n2, int n1s, int n2s, int k2, vector<int> result)
//    {
//        int len1 = n1.size() - n1s;
//        int len2 = n2.size() - n2s;
//        int t1 = len1 + len2 - k2;
//        int r = 0;
//        result[result.size() - k] = r;
//    }

};


//Input:
//nums1 = [6, 7]
//nums2 = [6, 0, 4]
//k = 5
//Output:
//[6, 7, 6, 0, 4]

//Input:
//nums1 = [3, 9]
//nums2 = [8, 9]
//k = 3
//Output:
//[9, 8, 9]

int main()
{
    int arr1[] = {3, 4, 6, 5};
    int arr2[] = {9, 1, 2, 5, 8, 3};        // [9, 8, 6, 5, 3]
    int k = 5;

//    int arr1[] = {6, 7};
//    int arr2[] = {6, 0, 4};
//    int k = 5;

//    int arr1[] = {3,9};
//    int arr2[] = {8,9};
//    int k = 3;

    vector<int> v1(arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0])));
    vector<int> v2(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));
    LT0321 lt;
//    cout<<endl<<endl<<lt.lt0321a(v1, v2, k)<<endl;
    vector<int> v3 = lt.lt0321b(v1, v2, k);
    cout<<endl<<endl;
    for_each(v3.begin(), v3.end(), fun_cout);
    return 0;
}
