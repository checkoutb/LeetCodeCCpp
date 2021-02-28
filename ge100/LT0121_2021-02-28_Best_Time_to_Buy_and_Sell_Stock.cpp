
#include "../header/myheader.h"

class LT0121
{
public:





//Runtime: 120 ms, faster than 34.31% of C++ online submissions for Best Time to Buy and Sell Stock.
//Memory Usage: 93.3 MB, less than 19.01% of C++ online submissions for Best Time to Buy and Sell Stock.
    int lt0121a(vector<int>& prices)
    {
        int mn = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > mn)
            {
                ans = max(ans, prices[i] - mn);
            }
            else
            {
                mn = prices[i];
            }
        }
        return ans;
    }

};

int main()
{

    LT0121 lt;


    return 0;
}
