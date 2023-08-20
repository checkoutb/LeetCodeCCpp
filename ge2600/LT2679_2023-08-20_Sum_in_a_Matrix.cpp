
#include "../header/myheader.h"

class LT2679
{
public:


// D D

        // const int cols = size(nums[0]);
        // vector<int> maxs(cols);
        // for (vector<int>& row : nums) {
        //     sort(begin(row), end(row));
        //     for (int c = 0; c < cols; ++c)
        //         maxs[c] = max(maxs[c], row[c]);
        // }
        // return reduce(begin(maxs), end(maxs));



// Runtime92 ms
// Beats
// 96.36%
// Memory48 MB
// Beats
// 30.49%
    int matrixSum(vector<vector<int>>& nums)
    {
        for (vector<int>& vi : nums)
            sort(begin(vi), end(vi));
        int ans = 0;
        for (int j = 0; j < nums[0].size(); ++j)
        {
            int t2 = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                t2 = max(t2, nums[i][j]);
            }
            ans += t2;
        }
        return ans;
    }

};

int main()
{

    LT2679 lt;


    return 0;
}
