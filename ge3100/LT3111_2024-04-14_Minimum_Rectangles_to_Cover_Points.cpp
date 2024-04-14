
#include "../header/myheader.h"

class LT3111
{
public:

    // D D

        // int r = 0;
        // for (int i = 0; i < n; ++r) {
        //     for (const int j = i; i < n && points[i][0] - points[j][0] <= w; ++i)
        //         ;
        // }
        // return r;



// Runtime
// 242ms
// Beats100.00%of users with C++
// Memory
// 118.25MB
// Beats60.00%of users with C++
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w)
    {
        std::sort(std::begin(points), std::end(points), [](const std::vector<int>& v1, const std::vector<int>& v2){
            return v1[0] < v2[0];
        });
        int ans = 1;
        int st = points[0][0];
        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i][0] <= st + w)
            {
                ;
            }
            else
            {
                ++ans;
                st = points[i][0];
            }
        }
        return ans;
    }

};

int main()
{

    LT3111 lt;


    return 0;
}
