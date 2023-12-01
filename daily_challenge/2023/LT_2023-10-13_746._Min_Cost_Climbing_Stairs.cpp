
#include "../../header/myheader.h"

class LT
{
public:





// Runtime0 ms
// Beats
// 100%
// Memory13.8 MB
// Beats
// 52.88%
    int minCostClimbingStairs(vector<int>& cost)
    {
        for (int i = 2; i < cost.size(); ++i)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }

};

int main()
{

    LT lt;


    return 0;
}
