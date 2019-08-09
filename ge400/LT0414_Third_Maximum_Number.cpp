
#include "../header/myheader.h"





// details
//        sort(nums.begin(), nums.end());
//        nums.erase(unique(nums.begin(), nums.end()), nums.end());
//
//        if (nums.size() < 3) {
//            if (nums[0] > nums[1]) {return nums[0];}
//            else {return nums[1];}
//        }
//        return nums[nums.size() - 3];
// 。。。STL  unique。
//      while (++first != last)
//      {
//        if (!(*result == *first))
//          *(++result)=*first;
//      }
// unique用之前需要sort。
// 就是3指针，头尾，result，每次头++，当头指针和result指针不相同时，++result内容=头指针内容。只是把后面的复制到result。
// 数据会损失。


// discuss
//        for (Integer n : nums) {
//            if (n.equals(max1) || n.equals(max2) || n.equals(max3)) continue;
//            if (max1 == null || n > max1) {
//                max3 = max2;
//                max2 = max1;
//                max1 = n;
//            } else if (max2 == null || n > max2) {
//                max3 = max2;
//                max2 = n;
//            } else if (max3 == null || n > max3) {
//                max3 = n;
//            }
//        }
// java

//    set<int> top3;
//    for (int num : nums)
//        if (top3.insert(num).second && top3.size() > 3)
//            top3.erase(top3.begin());
//    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();

// set去重。。。。set本就有序。




// 没有Integer，，，，INT_MIN 无法断定是无还是最小值。longlonglong？
// arr[i] != n || count < 3 有问题的，2,2,3,1。。应该是分成2个if,不是一个布尔表达式。


//Runtime: 4 ms, faster than 98.86% of C++ online submissions for Third Maximum Number.
//Memory Usage: 9.6 MB, less than 28.20% of C++ online submissions for Third Maximum Number.

class LT0414
{
    int arr[3] = {INT_MIN, INT_MIN, INT_MIN};
    set<int> set1;

    void updatea1(int n)
    {
        if (n >= arr[2])
        {
            int i = 0;
            for (; i < 3; i++)
            {
                if (arr[i] <= n)
                    break;
            }
            if (arr[i] != n || set1.find(n) == set1.end())
            {
                for (int j = 2; j > i; j--)
                {
                    arr[j] = arr[j - 1];
                }
                arr[i] = n;
                set1.insert(n);
            }
        }
    }

    int get3rda1()
    {
        return set1.size() < 3 ? arr[0] : arr[2];
    }
public:
    int lt0414a(vector<int>& nums)
    {
        int ans = 0;

        for (int n : nums)
        {
            updatea1(n);
        }

        ans = get3rda1();
        return ans;
    }


};

int main()
{
//    vector<int> nums = {1,2,-2147483648};
    vector<int> nums = {2,2,3,1};

    LT0414 lt;
    cout<<endl<<"ans : "<<lt.lt0414a(nums)<<endl;

    return 0;
}
