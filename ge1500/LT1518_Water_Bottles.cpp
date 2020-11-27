
#include "../header/myheader.h"

class LT1518
{
public:

// D D

//return int(numBottles + (numBottles - 1) / (numExchange - 1))

//    int numWaterBottles(int n, int k) {
//        return n < k ? n : k + numWaterBottles(n - k + 1, k);
//    }

//return numBottles + (numBottles -1)//(numExchange-1)

//return (numBottles*numExchange-1)//(numExchange-1)
// py // 是 整除。



//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Water Bottles.
//Memory Usage: 6.3 MB, less than 14.33% of C++ online submissions for Water Bottles.
// ...这个。。。好吧，不能赊帐。。。 估计后续还有个 能赊帐的题目。。
    int lt1518a(int numBottles, int numExchange)
    {
        int ans = numBottles;
        int empt = numBottles;
        while (empt >= numExchange)
        {
            ans += empt / numExchange;
            empt = empt % numExchange + empt / numExchange;
        }
        return ans;
    }

};

int main()
{

//    int n{9}, e{3};
//    int n{15}, e{4};
    int n{2}, e{3};

    LT1518 lt;

    cout<<lt.lt1518a(n, e);

    return 0;
}
