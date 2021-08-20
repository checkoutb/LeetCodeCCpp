
#include "../../header/myheader.h"

class LT
{
public:



};

// D D

//    vector<int> partialSum;
//public:
//    NumArray(vector<int>& nums) : partialSum(nums.size()) {
//        partial_sum(nums.begin(), nums.end(), partialSum.begin());
//    }
//
//    int sumRange(int left, int right) {
//        return left >= 1? partialSum[right] - partialSum[left - 1]: partialSum[right];
//    }
// partial_sum



// AC
class NumArray {
    vector<int> vi;
public:
    NumArray(vector<int>& nums) {
        vi = nums;
        for (int i = 1; i < vi.size(); ++i)
            vi[i] += vi[i - 1];
    }

    int sumRange(int left, int right) {
        int t2 = left == 0 ? 0 : vi[left - 1];
        return vi[right] - t2;
    }
};


int main()
{

    LT lt;


    return 0;
}
