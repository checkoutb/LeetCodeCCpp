
#include "../header/myheader.h"

class LT2240
{
public:

// D D

//        while(total >= 0) {
//            ans += (total / cost2) + 1;
//            total -= cost1;
//        }


//    for (int cnt = 0; cnt * cost1 <= total; ++cnt)
//        res += (total - cnt * cost1) / cost2 + 1;


//long long waysToBuyPensPencils(int total, int cost1, int cost2) {
//    return total < 0 ? 0 : 1 + total / cost2 + waysToBuyPensPencils(total - cost1, cost1, cost2);
//}


//        for (; total >= 0; total -= cost1)
//            res += total / cost2 + 1;


//https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/discuss/1955208/O(sqrt(total))-Python-0.21-ms-JavaC%2B%2B-0-ms



//Runtime: 11 ms, faster than 100.00% of C++ online submissions for Number of Ways to Buy Pens and Pencils.
//Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Number of Ways to Buy Pens and Pencils.
    long long lt2240a(int total, int cost1, int cost2)
    {
        long long ans = 0LL;

        int t2 = 0;
        if (cost1 < cost2)
        {
            int t3 = cost1;
            cost1 = cost2;
            cost2 = t3;
        }
        while (t2 <= total)
        {
            ans += (total - t2) / cost2 + 1;
            t2 += cost1;
        }

        return ans;
    }

};

int main()
{

    LT2240 lt;


    return 0;
}
