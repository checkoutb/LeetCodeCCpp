
#include "../header/myheader.h"

class LT1266
{
public:

// D D




//Runtime: 8 ms, faster than 99.34% of C++ online submissions for Minimum Time Visiting All Points.
//Memory Usage: 10.6 MB, less than 36.22% of C++ online submissions for Minimum Time Visiting All Points.
    int lt1266a(vector<vector<int>>& points)
    {
        int ans = 0;
        for (int i = 1; i < points.size(); ++i)
        {
            int x = std::abs(points[i][0] - points[i - 1][0]);
            int y = std::abs(points[i][1] - points[i - 1][1]);
            ans += max(x, y);
        }
        return ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{1,1},{3,4},{-1,0}};
    vector<vector<int>> vv = {{3,2},{-2,2}};

    LT1266 lt;

    cout<<lt.lt1266a(vv)<<endl;

    return 0;
}
