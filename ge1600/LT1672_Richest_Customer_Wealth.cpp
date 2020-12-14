
#include "../header/myheader.h"

class LT1672
{
public:




//Runtime: 4 ms, faster than 99.75% of C++ online submissions for Richest Customer Wealth.
//Memory Usage: 8.2 MB, less than 23.64% of C++ online submissions for Richest Customer Wealth.
    int lt1672a(vector<vector<int>>& accounts)
    {
        int ans = 0;
        for (int i = 0; i < accounts.size(); ++i)
        {
            int sum2 = 0;
            for (int j = 0; j < accounts[0].size(); ++j)
                sum2 += accounts[i][j];
            ans = max(sum2, ans);
        }
        return ans;
    }

};

int main()
{

    LT1672 lt;


    return 0;
}
