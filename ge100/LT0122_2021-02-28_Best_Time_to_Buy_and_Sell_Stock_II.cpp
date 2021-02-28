
#include "../header/myheader.h"

class LT0122
{
public:

// D D

//        while (i < N) {
//            while (i < N && prices[i + 1] <= prices[i]) i++;
//            buy = prices[i];
//
//            while (i < N && prices[i + 1] > prices[i]) i++;
//            sell = prices[i];
//
//            profit += sell - buy;
//        }
// 今天之后的 最低谷，最低谷之后的最高峰。


//Runtime: 8 ms, faster than 69.71% of C++ online submissions for Best Time to Buy and Sell Stock II.
//Memory Usage: 13.1 MB, less than 48.81% of C++ online submissions for Best Time to Buy and Sell Stock II.
    int lt0122a(vector<int>& prices)
    {
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }

};

int main()
{

    LT0122 lt;


    return 0;
}
