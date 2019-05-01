
#include "../header/myheader.h"

class LT0324
{
public:

    // 最简单的就是 排序，然后 头尾头尾。。
    // 似乎好像O(n)也是很简单的。。就是看自己是否满足，不满足就和后面互换？不，第二个例子就错了。。也不是1，3，2，3，1，2也符合的
    // 1,10,2,9,3,7,5,5,5
    // 不加goto，42/44 结果错误。加goto 18/44 timeout

    // discuss，int median = kthSmallestNumber(nums, m);，也是，找到中间值。。算了，还是排序后头尾头尾吧。
    // return (2 * i + 1) % (n | 1);


// 。。。我。。。抄。。。的。。。。

//public void wiggleSort(int[] nums) {
//    int n = nums.length, m = (n + 1) >> 1;
//    int median = kthSmallestNumber(nums, m);
//
//    for (int i = 0, j = 0, k = n - 1; j <= k;) {
//        if (nums[A(j, n)] > median) {
//            swap(nums, A(i++, n), A(j++, n));
//        } else if (nums[A(j, n)] < median) {
//            swap(nums, A(j, n), A(k--, n));
//        } else {
//            j++;
//        }
//    }
//}
//
//private int A(int i, int n) {
//    return (2 * i + 1) % (n | 1);
//}


//    private int kthSmallestNumber(int[] nums, int k)
//    {
//        Random random = new Random();
//        for (int i = nums.length - 1; i >= 0; i--)
//        {
//            swap(nums, i, random.nextInt(i + 1));
//        }
//        int l = 0, r = nums.length - 1;
//        k--;
//        while (l < r)
//        {
//            int m = getMiddle(nums, l, r);
//            if (m < k)
//            {
//                l = m + 1;
//            }
//            else if (m > k)
//            {
//                r = m - 1;
//            }
//            else
//            {
//                break;
//            }
//        }
//        return nums[k];
//    }
//
//    private int getMiddle(int[] nums, int l, int r)
//    {
//        int i = l;
//        for (int j = l + 1; j <= r; j++)
//        {
//            if (nums[j] < nums[l]) swap(nums, ++i, j);
//        }
//        swap(nums, l, i);
//        return i;
//    }




    void lt0324a(vector<int>& nums) {
        int sz = nums.size();
//        bool flag = true;

        AAA:
        int t1 = nums[0] + 1, t2 = nums[0] - 1, t3, t4, j;
        for (int i = 0; i < sz; i++)
        {
#ifdef __test
//            cout<<"   ";
//            for_each(nums.begin(), nums.end(), fun_cout);
//            cout<<endl;
            cout<<"i = "<<i<<endl;
#endif // __test

            t3 = t2;
            t2 = t1;
            t1 = nums[i];

#ifdef __test
            cout<<t3<<","<<t2<<","<<t1<<endl;
#endif // __test

            if (comparea1(t3, t2, t1, i))
            {
                // NOOP
            }
            else
            {
                if (t2 == t1)
                {
                    // ......相等。。。实在是。。。
                    #ifdef __test
                    cout<<i<<","<<t1<<endl;
                    for_each(nums.begin(), nums.end(), fun_cout);
                    system("pause");        // bat的pause。
                    #endif // __test

                    j = 1;
                    for (; j < i; j++)
                    {
                        if (nums[j] != t1)
                        {
                            #ifdef __test
                            cout<<"??? "<<t1<<"..."<<j<<"..."<<nums[j - 1]<<",,"<<t1<<".."<<nums[j]<<"```"<<nums[j + 1]<<endl;
                            #endif // __test
                            if (comparea1(nums[j - 1], t1, nums[j + 1], j + 1))
                            {
                                #ifdef __test
                                cout<<"   !"<<endl;
                                #endif // __test
                                // swap
                                nums[i] = nums[j];
                                nums[j] = t1;
                                t1 = nums[i - 1];
                                t2 = t3;
                                i--;
#ifdef __test
                                cout<<"zzz  "<<i<<endl;
#endif // __test
                                break;
                            }
                        }
                    }
                    if (i == j)
                    {
                        for (j++; j < sz; j++)
                        {
                            if (nums[j] != t1)
                            {
                                nums[i] = nums[j];
                                nums[j] = t1;
                                t1 = nums[i - 1];
                                t2 = t3;
                                i--;
#ifdef __test
                                cout<<"aaaa "<<i<<endl;
#endif // __test
                                break;
                            }
                        }
                    }

                    // 4,5,5,6 找不到可以用的。。。
                    t1 = nums[i];
                    nums[i] = nums[0];
                    nums[0] = t1;
                    goto AAA;
                }
                else
                {
                    #ifdef __test
                    cout<<i<<","<<t1<<","<<t2<<","<<t3<<","<<""<<","<<""<<","<<endl;
                    #endif // __test

                    nums[i] = t2;
                    nums[i - 1] = t1;
                    t2 = t1;
                    t1 = nums[i];
                }
            }
        }
    }

    // flag == true ? a < b > c : a > b < c;
    // index is c's index.
    bool comparea1(int a, int b, int c, int index)
    {
        bool flag = (index % 2) == 0;
        if (flag)
        {
            return a < b && b > c;
        }
        else
        {
            return a > b && b < c;
        }
    }
};

int main()
{
//    int arr[] = {2, 5, 10, 1, 6, 4};
//    int arr[] = {1, 5, 1, 1, 6, 4};
//    int arr[] = {1, 3, 2, 2, 3, 1};
//    int arr[] = {1,10,2,9,3,7,5,5,5};
//    int arr[] = {5,5,5,1,10,2,9,3,7};

//    int arr[] = {4,5,5,6};      // 42/44
    int arr[] = {1,3,2,2,2,1,1,3,1,1,2};        // 加上goto AAA后，18/44 就超时了。

    vector<int> v(arr, arr + (sizeof(arr) / sizeof(arr[0])));
    LT0324 lt;
    lt.lt0324a(v);
    for_each(v.begin(), v.end(), fun_cout);
    return 0;
}
