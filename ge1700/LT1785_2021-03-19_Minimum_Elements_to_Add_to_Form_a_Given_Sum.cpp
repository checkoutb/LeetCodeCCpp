
#include "../header/myheader.h"

class LT1785
{
public:

// D D

//return (abs(accumulate(begin(nums), end(nums), 0l) - goal) + limit - 1) / limit;

//        long sum = accumulate(A.begin(), A.end(), 0L),  diff = abs(goal - sum);
//        return (diff + limit - 1) / limit;

// (x - 1) / limit + 1
// (x - 1 + limit) / limit


//Runtime: 116 ms, faster than 100.00% of C++ online submissions for Minimum Elements to Add to Form a Given Sum.
//Memory Usage: 73.4 MB, less than 100.00% of C++ online submissions for Minimum Elements to Add to Form a Given Sum.
    int lt1785a(vector<int>& nums, int limit, int goal)
    {
//        int sum2 = std::accumulate(begin(nums), end(nums), 0);
        long sum2 = 0;
        for (int i : nums)
            sum2 += i;
        long tar = abs(goal - sum2);
        return tar == 0 ? 0 : (tar - 1) / limit + 1;
    }

};

int main()
{
//    myvi v = {1,-1,1};
//    int a = 3, b = -4;

    myvi v = {1,-10,9,1};
    int a = 100, b = 0;

    LT1785 lt;

    cout<<lt.lt1785a(v, a, b)<<endl;

    return 0;
}
