
#include "../header/myheader.h"

class LT1909
{
public:

// D D


//        int n = nums.size(), c = 0;
//        for (int i = 1; i < n; i++) {
//            if (nums[i] > nums[i-1]) continue;
//            else {
//                ++c;
//                if (c > 1) return false;
//                if (i-2 < 0) continue;
//                if (nums[i] > nums[i-2]) continue;
//                else nums[i] = nums[i-1];
//            }
//        }
//        return true;


//        int x=0,y=0;
//        int last=nums[nums.size()-1];
//        for(int i=nums.size()-2;i>=0;i--)
//        {
//            if(nums[i]<last)
//                last=nums[i];
//            else
//                x++;
//        }
//        last=nums[0];
//        for(int i=1;i<nums.size();i++)
//        {
//            if(nums[i]>last)
//                last=nums[i];
//            else
//                y++;
//        }
//
//        return min(x,y)<=1;




//When we find a drop, we check if the current number nums[i] is greater than the number before the previous one nums[i - 2].
//    If so, the number nums[i - 1] needs to be removed.
//    Otherwise, the current number needs to be removed (nums[i]).
//        For simplicity, I just assign the previous value to the current number (nums[i] = nums[i - 1]).
//    int cnt = 0;
//    for (int i = 1; i < nums.size() && cnt < 2; ++i) {
//        if (nums[i - 1] >= nums[i]) {
//            ++cnt;
//            if (i > 1 && nums[i - 2] >= nums[i])
//                nums[i] = nums[i - 1];
//        }
//    }
//    return cnt < 2;





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove One Element to Make the Array Strictly Increasing.
//Memory Usage: 10 MB, less than 34.15% of C++ online submissions for Remove One Element to Make the Array Strictly Increasing.
    bool lt1909a(vector<int>& nums)
    {
        int sz1 = nums.size();
        for (int i = 0; i < sz1 - 1; ++i)
        {
            if (nums[i] >= nums[i + 1])
            {
                if (i == 0)
                {
                    nums[i] = nums[i + 1] - 1;
                    break;
                }
                else if (i == sz1 - 2)
                {
                    nums[i + 1] = nums[i] + 1;          // or = -1
                    break;
                }
                else if (nums[i + 1] > nums[i - 1])
                {
                    nums[i] = -1;
                    break;
                }
                else
                {
                    nums[i + 1] = -1;
                    break;
                }
            }
        }
        int prev = nums[0];
        for (int i = 1; i < sz1; ++i)
        {
            if (nums[i] == -1)
                continue;
            if (nums[i] <= prev)
                return false;
            prev = nums[i];
        }
        return true;
    }


};

int main()
{
//    myvi v = {1,2,10,5,7};
//    myvi v = {2,3,1,2};
//    myvi v = {1,1,1};
    myvi v = {1,2,3};

    LT1909 lt;

    cout<<lt.lt1909a(v)<<endl;

    return 0;
}
