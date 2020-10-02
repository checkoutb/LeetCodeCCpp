
#include "../header/myheader.h"

class LT0643
{
public:


// D D

//        long sum = 0;
//        for (int i = 0; i < k; i++) sum += nums[i];
//        long max = sum;
//
//        for (int i = k; i < nums.length; i++) {
//            sum += nums[i] - nums[i - k];
//            max = Math.max(max, sum);
//        }
//
//        return max / 1.0 / k;



//def findMaxAverage(self, nums, k):
//    sums = [0] + list(itertools.accumulate(nums))
//    return max(map(operator.sub, sums[k:], sums)) / k


//NumPy version (requires import numpy as np):
//
//def findMaxAverage(self, nums, k):
//    sums = np.cumsum([0] + nums)
//    return int(max(sums[k:] - sums[:-k])) / k



//Runtime: 324 ms, faster than 25.49% of C++ online submissions for Maximum Average Subarray I.
//Memory Usage: 78 MB, less than 9.56% of C++ online submissions for Maximum Average Subarray I.
    double findMaxAverage(vector<int>& nums, int k)
    {
        double ans = INT_MIN;
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
        ans = ((double) nums[k - 1]) / k;
        for (int i = k; i < nums.size(); i++)
        {
            ans = max(ans, ((double) (nums[i] - nums[i - k])) / k);
        }

        return ans;
    }

};

int main()
{

    vector<int> v = {1,12,-5,-6,50,3};
    int k{4};

    LT0643 lt;

    cout<<lt.findMaxAverage(v, k)<<endl;

    return 0;
}
