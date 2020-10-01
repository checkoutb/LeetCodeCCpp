
#include "../header/myheader.h"

class LT0611
{
public:


// D D
//        for (int i = 2; i < nums.length; i++) {
//            int left = 0, right = i - 1;
//            while (left < right) {
//                if (nums[left] + nums[right] > nums[i]) {
//                    result += (right - left);
//                    right--;
//                }
//                else {
//                    left++;
//                }
//            }
//        }

// 如果 left + right > num. 那么 right 和 i 和 [left,right) 都组成 三角形。



//Runtime: 32 ms, faster than 58.71% of C++ online submissions for Valid Triangle Number.
//Memory Usage: 11.7 MB, less than 20.33% of C++ online submissions for Valid Triangle Number.
    int lt0611a(vector<int>& nums)
    {
        int ans{0};
        std::sort(begin(nums), end(nums));
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= 0)
                continue;
            int mxi = i + 2;
            for (int j = i + 1; j < nums.size(); j++)
            {
                int mx = nums[i] + nums[j];
                while (mxi < nums.size() && nums[mxi] < mx)
                {
                    mxi++;
                }
                ans += mxi - j - 1;
            }
        }

        return ans;
    }

};

int main()
{
//    vector<int> v = {2,2,3,4};
//    vector<int> v = {1,1,3,4};
    vector<int> v = {0,0,0};

    LT0611 lt;

    cout<<lt.lt0611a(v)<<endl;

    return 0;
}
