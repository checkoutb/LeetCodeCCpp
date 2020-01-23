
#include "../header/myheader.h"

class LT0704
{
public:


// d && d
// mid=l+(r-l)/2;       好处就是不会>INT_MAX，不过这种发生的几率为0，相加>21.5亿，至少就需要约11亿元素，这运算能力要求太高了。。
// nums[mid] == target 直接return mid; 程序的最后是return -1;  这样不会出现 nums[start]，这种可能越界的行为。

// 一般命名 hi/lo, left/right



// 如果nums.size() == 0，这个就错了，nums[0]越界了。。。

//Runtime: 52 ms, faster than 72.20% of C++ online submissions for Binary Search.
//Memory Usage: 10.9 MB, less than 66.67% of C++ online submissions for Binary Search.

    int lt0704a(vector<int>& nums, int target)
    {
        int sz1 = nums.size();
        int start = 0, end2 = sz1 - 1;
        while (start < end2)
        {
            int mid = (start + end2) / 2;
            if (nums[mid] == target)
            {
                start = mid;
                end2 = mid;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end2 = mid - 1;
            }
        }
        return nums[start] == target ? start : -1;
    }

};

int main()
{

//    int arr2[][] = {{-1,0,3,5,9,12}, {-1,0,3,5,9,12}};
    vector<vector<int>> vv2 = {{-1,0,3,5,9,12}, {-1,0,3,5,9,12}};
    int target[] = {9, 2};

    LT0704 lt;

    for (int i = 0; i < vv2.size(); i++)
    {
        cout<<lt.lt0704a(vv2[i], target[i])<<endl;
    }

    return 0;
}
