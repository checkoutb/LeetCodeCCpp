
#include "../header/myheader.h"

class LT1774
{
public:

// D D

//void dp(vector<int>& tC, int i, int cost, int t, int &best, int max_top = 2) {
//    if (cost >= t || i >= tC.size()) {
//        if (abs(cost - t) < abs(best - t))
//            best = cost;
//        else if (abs(best - t) == abs(cost - t))
//            best = min(best, cost);
//    }
//    else
//        for (auto j = 0; j <= max_top; ++j)
//            dp(tC, i + 1, cost + j * tC[i], t, best);
//}
//int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
//    int best = INT_MAX;
//    for (auto base : baseCosts)
//        dp(toppingCosts, 0, base, target, best);
//    return best;
//}
// .. 任何组合，后面都可以不再取值，所以 如果答案是一个 小于 t的 cost，那么 这个答案是由于 i >= tC.size() 而进入 if 块的。



//Runtime: 12 ms, faster than 83.33% of C++ online submissions for Closest Dessert Cost.
//Memory Usage: 9.6 MB, less than 50.00% of C++ online submissions for Closest Dessert Cost.
    int lt1774a(vector<int>& baseCosts, vector<int>& toppingCosts, int target)
    {
        for (int i : baseCosts)
            dfsa1(i, target, toppingCosts, 0);
        return ans;
    }
    int ans = INT_MAX >> 1;
    void dfsa1(int got, int target, vector<int>& cost, int idx)
    {
        if (abs(got - target) < abs(ans - target))
        {
            ans = got;
        }
        else if (abs(got - target) == abs(ans - target))
        {
            ans = min(ans, got);
        }
        if (idx == cost.size())
            return;
        if (got >= target)
            return;
        if (ans == target)
            return;

        for (int i = 0; i <= 2; ++i)
        {
            dfsa1(got + cost[idx] * i, target, cost, idx + 1);
        }
    }

};

int main()
{
//    myvi v = {1,7};
//    myvi v2 = {3,4};
//    int t = 10;

//    myvi v = {2,3};
//    myvi v2 = {4,5,100};
//    int t = 18;

//    myvi v = {3,10};
//    myvi v2 = {2,5};
//    int t = 9;

    myvi v = {10};
    myvi v2 = {1};
    int t = 1;

    LT1774 lt;

    cout<<lt.lt1774a(v, v2, t);

    return 0;
}
