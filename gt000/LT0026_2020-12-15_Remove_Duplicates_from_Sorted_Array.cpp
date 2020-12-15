
#include "../header/myheader.h"

class LT0026
{
public:

// D D

//        for(int n: nums)
//        {
//            if(i==0 || n > nums[i-1])
//                nums[i++] = n;
//        }

// 第一个元素必然暂时唯一，所以lst = nums[0]， i = 1


//    for (int n : nums)
//        if (!i || n > nums[i-1])
//            nums[i++] = n;

//    int i = !nums.empty();
//    for (int n : nums)
//        if (n > nums[i-1])
//            nums[i++] = n;



//Runtime: 16 ms, faster than 78.25% of C++ online submissions for Remove Duplicates from Sorted Array.
//Memory Usage: 14.2 MB, less than 23.47% of C++ online submissions for Remove Duplicates from Sorted Array.
    int lt0026a(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int idx = 0;
        int lst = nums[0] - 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            int t2 = nums[i];
            if (t2 != lst)
                nums[idx++] = t2;
            lst = t2;
        }
        return idx;
    }

};

int main()
{
//    myvi v = {1,1,2};
    myvi v = {0,0,1,1,1,2,2,3,3,4};

    LT0026 lt;

    int len = lt.lt0026a(v);
    cout<<"len : "<<len<<endl;
    for (int i = 0; i < len; ++i)
    {
        cout<<v[i]<<", ";
    }

    return 0;
}
