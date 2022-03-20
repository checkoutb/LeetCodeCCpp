
#include "../header/myheader.h"

class LT2210
{
public:

// D D


//        for(int i = 1; i < a.length - 1; i++)
//            if(left < a[i] && a[i] > a[i + 1] || left > a[i] && a[i] < a[i + 1]){
//                r++;
//                left = a[i];
//            }


//Runtime: 4 ms, faster than 72.73% of C++ online submissions for Count Hills and Valleys in an Array.
//Memory Usage: 8.8 MB, less than 90.91% of C++ online submissions for Count Hills and Valleys in an Array.
    int lt2210a(vector<int>& nums)
    {
        int ans = 0;
        int sz1 = nums.size();
        for (int i = 1; i < sz1 - 1; ++i)
        {
            if (nums[i] == nums[i - 1])
                continue;
            int l = 0;
            int r = 0;
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[j] != nums[i])
                {
                    l = nums[j] - nums[i];
                    break;
                }
            }
            for (int j = i + 1; j < sz1; ++j)
            {
                if (nums[j] != nums[i])
                {
                    r = nums[j] - nums[i];
                    break;
                }
            }
            if (l * r > 0)
            {
                #ifdef __test
                cout<<i<<endl;
                #endif // __test
                ans++;
            }
        }
        return ans;
    }

};

int main()
{

    LT2210 lt;

    myvi v = {2,4,1,1,6,5};

    cout<<lt.lt2210a(v)<<endl;

    return 0;
}
