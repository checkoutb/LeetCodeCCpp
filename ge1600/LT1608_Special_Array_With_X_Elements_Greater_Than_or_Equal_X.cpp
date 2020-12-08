
#include "../header/myheader.h"

class LT1608
{
public:

// D D

//        if (1 <= size && size <= nums[0])
//            return size;










//Runtime: 4 ms, faster than 74.90% of C++ online submissions for Special Array With X Elements Greater Than or Equal X.
//Memory Usage: 8.8 MB, less than 28.67% of C++ online submissions for Special Array With X Elements Greater Than or Equal X.
    int lt1608a(vector<int>& nums)
    {
        int sz1 = nums.size();
        sort(begin(nums), end(nums));
        int cnt = 0;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            ++cnt;
            if (nums[i] >= cnt)
            {
                if (i == 0)
                    return cnt;
                if (cnt > nums[i - 1])
                    return cnt;
            }
        }
        return -1;
    }

};

int main()
{

//    myvi v = {3,5};
//    myvi v = {0,0};
    myvi v = {0,4,3,0,4};

    LT1608 lt;

    cout<<lt.lt1608a(v)<<endl;

    return 0;
}
