
#include "../../header/myheader.h"

class LT
{
public:


// D

//        int c = 0;
//        int n = nums.size();
//        int idx;
//        for(int i = 0; i < n-1; i++) {
//            if(nums[i] > nums[i+1]) {
//                idx = i;
//                c++;
//            }
//            if(c == 2) return false;
//        }
//        if(!(idx-1 >= 0 and idx+1 < n and nums[idx-1] > nums[idx+1]) or !(idx < n and idx+2 < n and nums[idx] > nums[idx+2])) {
//            return true;
//        }
//        return false;


//        for (int i = 1; i < n; i++) {
//            if (nums[i] < prev) {
//                if (--cnt == -1) return false;
//                // [4], 2, 3       -> 2, 2, 3
//                // -1, [4], 2, 3   -> -1, 2, 2, 3
//                // 2, 3, 3, [2], 4 -> 2, 3, 3, 3, 4
//                if (i != 1 && nums[i-2] > nums[i])
//                    continue;
//            }
//            prev = nums[i];
//        }


//        for(int i=1;i<nums.size();i++)
//        {
//            if(nums[i]<nums[i-1])
//            {
//                error++;
//
//                if(error>1 || ((i>1 && i<nums.size()-1) && (nums[i]<nums[i-2]  && nums[i+1]<nums[i-1]) ))
//                    return false;
//            }
//        }
// 2次降序
// 或者 前提是  i < i-1 (降序),   i-2 > i   i + 1 < i-1.  怎么找到这种的。。。
// 4 5 3 4
// ????




// AC
    bool checkPossibility(vector<int>& nums)
    {
        int cnt = 0;
        int sz1 = nums.size();
        if (sz1 <= 2)
            return true;

        if (nums[0] > nums[1])
        {
            cnt++;
            nums[0] = nums[1];
        }
        if (nums[sz1 - 2] > nums[sz1 - 1])
        {
            cnt++;
            nums[sz1 - 1] = nums[sz1 - 2];
        }
        for (int i = 1; i < sz1 - 1; ++i)
        {
            if (cnt > 1)
                break;
            if (nums[i] >= nums[i - 1] && nums[i + 1] >= nums[i])
            {
                ;
            }
            else
            {
                if (nums[i + 1] < nums[i - 1])
                {
                    nums[i + 1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i - 1];
                }
                cnt++;
            }
        }

        return cnt <= 1;
    }

};

int main()
{
//    myvi v = {4,2,3};
    myvi v = {4,2,1};

    LT lt;

    cout<<lt.checkPossibility(v)<<endl;

    return 0;
}
