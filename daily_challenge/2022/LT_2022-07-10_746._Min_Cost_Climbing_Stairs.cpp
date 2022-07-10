
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //for (int i = 2; i < cost.length; i++) {
    //    cost[i] += Math.min(cost[i - 1], cost[i - 2]);
    //}
    //return Math.min(cost[cost.length - 1], cost[cost.length - 2]);



//Runtime: 9 ms, faster than 61.41 % of C++ online submissions for Min Cost Climbing Stairs.
//Memory Usage : 13.6 MB, less than 79.79 % of C++ online submissions for Min Cost Climbing Stairs.
//Runtime: 16 ms, faster than 22.15 % of C++ online submissions for Min Cost Climbing Stairs.
//Memory Usage : 13.7 MB, less than 51.95 % of C++ online submissions for Min Cost Climbing Stairs.
    int lta(vector<int>& cost)
    {
        int sz1 = cost.size();
        int ppre = 0;
        int pre = 0;
        
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = min(ppre, pre) + cost[i];
            ppre = pre;
            pre = t2;
        }
        return min(ppre, pre);
    }

};

int main()
{

    LT lt;

    //myvi v = { 10,15,20 };
    myvi v = { 1,100,1,1,1,100,1,1,100,1 };

    cout << lt.lta(v) << endl;

    return 0;
}
