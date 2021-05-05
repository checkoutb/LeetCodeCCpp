
#include "../header/myheader.h"

class LT1838
{
public:

// D D

//        for (j = 0; j < A.size(); ++j) {
//            k += A[j];
//            if (k < (long)A[j] * (j - i + 1))
//                k -= A[i++];
//        }
// if.




//Runtime: 168 ms, faster than 72.78% of C++ online submissions for Frequency of the Most Frequent Element.
//Memory Usage: 79.5 MB, less than 32.87% of C++ online submissions for Frequency of the Most Frequent Element.
// 99999 * 99990 cannot be represented in type 'int'     [1,1,1,....1,1,100000]
    int lt1838a(vector<int>& nums, int k)
    {
        sort(begin(nums), end(nums));
        int st = 0;
        long used = 0;
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            used += ((long) nums[i] - nums[i - 1]) * (i - st);
            while (used > k)
            {
                used -= nums[i] - nums[st++];
            }
            ans = max(ans, i - st + 1);
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,2,4};
//    int k{5};

//    myvi v = {1,4,8,13};
//    int k = 5;

    myvi v = {3,6,9};
    int k = 3;

    LT1838 lt;

    cout<<lt.lt1838a(v, k)<<endl;

    return 0;
}
