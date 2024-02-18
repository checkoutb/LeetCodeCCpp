
#include "../../header/myheader.h"

class LT
{
public:




//     Runtime7 ms
// Beats
// 60.44%
// Memory10.5 MB
// Beats
// 64.64%
    int minTimeToVisitAllPoints(vector<vector<int>>& points)
    {
        int ans = 0;
        int x{points[0][0]}, y{points[0][1]};
        // int x2, y2;
        for (auto& vi : points)
        {
            // x2 = vi[0];
            // y2 = vi[1];
            x = std::abs(x - vi[0]);
            y = std::abs(y - vi[1]);

            ans += std::max(x, y);

            x = vi[0], y = vi[1];
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
