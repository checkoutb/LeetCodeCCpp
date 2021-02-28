
#include "../header/myheader.h"

class LT0714
{
public:

// D D

//        n = len(prices)
//        if n < 2:
//             return 0
//        ans = 0
//        minimum = prices[0]
//        for i in range(1, n):
//            if prices[i] < minimum:
//                minimum = prices[i]
//            elif prices[i] > minimum + fee:
//                ans += prices[i] - fee - minimum
//                minimum = prices[i] - fee
//        return ans


//        int cash =0, hold = -prices[0];
//        for (int i=1; i< prices.size(); i++){
//            cash = max(cash, hold + prices[i] - fee);
//            hold = max(hold, cash-prices[i]);
//        }
//        return cash;


//Runtime: 196 ms, faster than 24.38% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
//Memory Usage: 90.8 MB, less than 8.03% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
// hint1
    int lt0714a(vector<int>& prices, int fee)
    {
        int sz1 = prices.size();
        vector<vector<int>> vvi(sz1, vector<int>(2, 0));
        vvi[0][0] = 0;
        vvi[0][1] = -prices[0] - fee;
        for (int i = 1; i < sz1; ++i)
        {
            vvi[i][0] = max(vvi[i - 1][0], prices[i] + vvi[i - 1][1]);
            vvi[i][1] = max(vvi[i - 1][1], vvi[i - 1][0] - prices[i] - fee);
        }
        #ifdef __test
        for (myvi& v : vvi)
        {
            for (int i : v)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvi[sz1 - 1][0];
    }

};

int main()
{
//    myvi v = {1, 3, 2, 8, 4, 9};
//    int f = 2;

    myvi v = {1,3,7,5,10,3};
    int f = 3;


    LT0714 lt;

    cout<<lt.lt0714a(v, f)<<endl;

    return 0;
}
