
#include "../header/myheader.h"

class LT2144
{
public:

// D D

//        for (int i = 0; i < A.size(); ++i)
//            if (i % 3 != n % 3)
//                res += A[i];

//    for (int i = 0; i < cost.size(); ++i)
//        res += i % 3 == 2 ? 0 : cost[i];


//Runtime: 14 ms, faster than 12.88% of C++ online submissions for Minimum Cost of Buying Candies With Discount.
//Memory Usage: 10.9 MB, less than 35.55% of C++ online submissions for Minimum Cost of Buying Candies With Discount.
    int lt2144a(vector<int>& cost)
    {
        sort(begin(cost), end(cost));
        int ans = 0;
        for (int i = cost.size() - 1; i >= 0; i--)
        {
            ans += cost[i--];
            if (i >= 0)
                ans += cost[i--];
        }
        return ans;
    }

};

int main()
{

    LT2144 lt;


    return 0;
}
