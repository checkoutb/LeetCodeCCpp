
#include "../header/myheader.h"

class LT2087
{
public:

    // D D





//Runtime: 277 ms, faster than 63.51 % of C++ online submissions for Minimum Cost Homecoming of a Robot in a Grid.
//Memory Usage : 149.9 MB, less than 72.70 % of C++ online submissions for Minimum Cost Homecoming of a Robot in a Grid.
    int lt2087a(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts)
    {
        int ans = 0;
        for (int i = startPos[0], df = startPos[0] > homePos[0] ? -1 : 1; i != homePos[0]; i += df)
        {
            ans += rowCosts[i + df];
        }
        for (int j = startPos[1], df = startPos[1] > homePos[1] ? -1 : 1; j != homePos[1]; j += df)
        {
            ans += colCosts[j + df];
        }
        return ans;
    }

};

int main()
{

    LT2087 lt;


    return 0;
}
