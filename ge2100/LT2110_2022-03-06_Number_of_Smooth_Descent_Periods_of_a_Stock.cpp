
#include "../header/myheader.h"

class LT2110
{
public:

// D D

//int *dp = new int[prices.size()];



//Runtime: 278 ms, faster than 17.08% of C++ online submissions for Number of Smooth Descent Periods of a Stock.
//Memory Usage: 93.3 MB, less than 39.46% of C++ online submissions for Number of Smooth Descent Periods of a Stock.
    long long lt2110a(vector<int>& prices)
    {
        long long ans = 1;
        int len = 1;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] == prices[i - 1] - 1)
            {
                len++;
                ans += len;
            }
            else
            {
                len = 1;
                ans++;
            }
        }
        return ans;
    }

};

int main()
{

    LT2110 lt;


    return 0;
}
