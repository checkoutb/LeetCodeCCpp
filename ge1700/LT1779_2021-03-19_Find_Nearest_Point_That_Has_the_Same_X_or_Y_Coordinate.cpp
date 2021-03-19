
#include "../header/myheader.h"

class LT1779
{
public:

// D D

//        for(int i = 0; i < points.size(); i++){
//            if(points[i][0] == x || points[i][1] == y){
//                int cur = abs(points[i][0] - x) + abs(points[i][1] - y);
//                if(cur < dist){
//                    dist = cur;
//                    ans = i;
//                }
//            }
//        }



//Runtime: 152 ms, faster than 100.00% of C++ online submissions for Find Nearest Point That Has the Same X or Y Coordinate.
//Memory Usage: 59.2 MB, less than 100.00% of C++ online submissions for Find Nearest Point That Has the Same X or Y Coordinate.
    int lt1779a(int x, int y, vector<vector<int>>& points)
    {
        int ans = -1;
        int len = INT_MAX >> 1;
//        for (vector<int>& vi : points)
        for (int i = 0; i < points.size(); ++i)
        {
            vector<int>& vi = points[i];
            if (vi[0] == x)
            {
                if (len > abs(vi[1] - y))
                {
                    ans = i;
                    len = abs(vi[1] - y);
                }
            }
            else if (vi[1] == y)
            {
                if (len > abs(vi[0] - x))
                {
                    ans = i;
                    len = abs(vi[0] - x);
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT1779 lt;


    return 0;
}
