
#include "../header/myheader.h"


// 只会暴力数数。。。或者靠map。然后遍历map。
// sort 然后 二分搜索？，但是有相同数，就。。。


class LT0315
{
public:


    // discuess, BST,BIT.
    // BST 需要写平衡二叉树，不然效率。当然肯定比数数快n多。
    // BIT 需要空间换时间，需要避免负数，而且稀疏的话太惨了，不知道有没有办法把数组变得稠密一点。
    // sort后，遍历原数组，在sort数组中查看和前一个值的，这个不行吧，需要遍历n次。有这时间早运算完了。
    // 好像可以借助计数排序那种，int arr[max-min],然后插入，然后遍历。能直接知道比它小的元素有几个。
    // 这个只能算是一个map，没办法直接改原数组，因为要O(n^2)才能修改完原数组。没意义，毕竟int才32个位，最多也就32次加法。

    // 二维有序数组，做插入排序，当然linkedlist肯定更快。看了下cpp的list还是Doubly-linked list
    // 思路和BST差不多。
//    Runtime: 336 ms, faster than 18.59% of C++ online submissions for Count of Smaller Numbers After Self.
//    Memory Usage: 10.2 MB, less than 78.20% of C++ online submissions for Count of Smaller Numbers After Self.
// 那个BST的discuss的说9ms。。。差得有点多。。。
    vector<int> lt0315c(vector<int>& nums)
    {
        int sz = nums.size();
        vector<int> result(sz);
        if (sz == 0)
            return result;          // nums == []; rbegin is null.
        long arr2[sz][2] = {{*nums.rbegin()}};      // signed integer overflow: 1908872400 + 1751648243 cannot be represented in type 'int'
#ifdef __test
        cout<<arr2[0][0]<<",111, "<<arr2[0][1]<<endl;
#endif // __test
        int arrMax = -1;        // last element
        int t1 = 0;
        int i = 0;
//        int count = 0;

        for (vector<int>::reverse_iterator it = nums.rbegin(), it2 = result.rbegin(); it != nums.rend(); it++, it2++)
        {
            t1 = *it;
//            i = arrMax;
            // 不能提前后移。。
            for (i = 0; i <= arrMax; i++)
            {
                if (arr2[i][0] >= t1)
                    break;
//                count += arr2[i][1];
            }
            if (i > arrMax)
            {
                arrMax++;
                arr2[i][0] = t1;
                arr2[i][1] = 1;
                if (i > 0)
                    arr2[i][1] += arr2[i - 1][1];
            }
            else if (arr2[i][0] != t1)
            {
                arrMax++;
                for (int j = arrMax; j >= i; j--)
                {
                    // runtime error: index 4 out of bounds for type 'int [*][2]' (solution.cpp)
                    arr2[j + 1][0] = arr2[j][0];            // leetcode [5,2,6,1] 说这里越界。。本地没有问题，申请数组的时候改成sz+1了。
                    arr2[j + 1][1] = arr2[j][1] + 1;
                }
                arr2[i][0] = t1;
                arr2[i][1] = 1 + (i > 0 ? arr2[i - 1][1] : 0);
            }
            else
            {
                for (int j = arrMax; j >= i; j--)
                    arr2[j][1]++;
            }
            if (i == 0)
            {
                *it2 = 0;
            }
            else
            {
                *it2 = arr2[i - 1][1];
            }

            #ifdef __test
            cout<<*it2<<", "<<arrMax<<endl;
            for (int m = 0; m < sz; m++)
            {
                cout<<arr2[m][0]<<":"<<arr2[m][1]<<"....";
            }
            cout<<endl;
            #endif // __test

        }
        return result;
    }

    // 15/16 ...
    vector<int> lt0315b(vector<int>& nums)
    {
        vector<int> result(nums.size());
        if (nums.size() < 1)
            return result;
        map<int, int> map2;
        int i = nums.size() - 1;
        result[i] = 0;
        for(vector<int>::reverse_iterator iter1 = nums.rbegin(); iter1 != nums.rend(); iter1++, i--)
        {
            map2[*iter1] += 1;
            for(map<int, int>::iterator iter3 = map2.begin(); iter3 != map2.end(); iter3++)
            {
                if (iter3->first < *iter1)
                    result[i] += iter3->second;
            }
        }
        return result;
    }

    // 15/16 timeout...
    vector<int> lt0315a(vector<int>& nums) {
        vector<int> result(nums.size());
        int i = 0;
        for (vector<int>::iterator iter1 = nums.begin(); iter1 != nums.end(); iter1++, i++)
        {
            int t1 = *iter1;
            for (vector<int>::iterator iter2 = iter1; iter2 != nums.end(); iter2++)
            {
                if (*iter2 < t1)
                {
                    result[i]++;
                }
            }
        }
        return result;
    }
};






int main()
{
#ifndef __test
    cout<<"AAA"<<endl;
#endif // __test
#ifdef __test
    cout<<"test"<<endl;
#endif // __test


    int arr[] = {5,2,6,1};

//    Expected: [10,27,10,35,12,22,28,8,19,2,12,2,9,6,12,5,17,9,19,12,14,6,12,5,12,3,0,10,0,7,8,4,0,0,4,3,2,0,1,0]
//    int arr[] = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
//    int arr[] = {83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    vector<int> v(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    LT0315 lt;
    vector<int> r = lt.lt0315c(v);

    for_each(r.begin(), r.end(), fun_cout);

    map<int, int> map2;
    map2[1] = 3;
//    cout<<endl<<map2[1]<<", "<<map2[0]<<endl;


    int i = 7;
    int j = (i - 1) ^ i;
    cout<<endl<<j<<endl;
    int i1 = (i & (-i)), i2 = ((i - 1) ^ i) & i;
    cout<<endl<<i1<<endl<<i2<<endl;
}

