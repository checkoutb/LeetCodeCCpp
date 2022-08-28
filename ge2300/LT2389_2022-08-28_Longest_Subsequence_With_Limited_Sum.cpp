
#include "../header/myheader.h"

class LT2389
{
public:

    // D D

    //sort(begin(nums), end(nums));
    //partial_sum(begin(nums), end(nums), begin(nums));
    //transform(begin(queries), end(queries), begin(queries), [&](int q) {
    //    return upper_bound(begin(nums), end(nums), q) - begin(nums);
    //    });




//Runtime: 17 ms, faster than 100.00 % of C++ online submissions for Longest Subsequence With Limited Sum.
//Memory Usage : 13.7 MB, less than 40.00 % of C++ online submissions for Longest Subsequence With Limited Sum.
    vector<int> lt2389a(vector<int>& nums, vector<int>& queries)
    {
        int sz1 = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 1; i < sz1; ++i)
        {
            nums[i] += nums[i - 1];
        }
        for (int i = 0; i < queries.size(); ++i)
        {
            queries[i] = std::distance(begin(nums), upper_bound(begin(nums), end(nums), queries[i]));
        }
        return queries;
    }

};

int main()
{

    LT2389 lt;

    myvi v = { 5,4,2,1 };
    myvi q = { 0,3,10,21 };


    lt.lt2389a(v, q);

    showVectorInt(q);

    return 0;
}
