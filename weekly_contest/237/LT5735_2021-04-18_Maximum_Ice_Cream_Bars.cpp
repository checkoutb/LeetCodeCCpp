
#include "../../header/myheader.h"

class LT5735
{
public:



// AC
    int lt5735a(vector<int>& costs, int coins)
    {
        std::sort(begin(costs), end(costs));
        int ans = 0;
        for (int i = 0; i < costs.size(); ++i)
        {
            if (coins >= costs[i])
            {
                coins -= costs[i];
                ans++;
            }
            else
            {
                break;
            }
        }
        return ans;
    }

};

int main()
{

    LT5735 lt;


    return 0;
}
