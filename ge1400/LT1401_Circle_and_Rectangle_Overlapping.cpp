
#include "../header/myheader.h"

class LT1401
{
public:

// D D

//        int x = max(x1,min(x2,x_center));
//        int y = max(y1,min(y2,y_center));
//        int dis = (x-x_center)*(x-x_center) + (y-y_center)*(y-y_center);
//        return dis <= (radius * radius) ? true : false;
// ...



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Circle and Rectangle Overlapping.
//Memory Usage: 6.2 MB, less than 70.62% of C++ online submissions for Circle and Rectangle Overlapping.
// 圆心在矩形内/边，
// 否则：圆心到矩形边/顶点的 距离 <= 半径，
    bool lt1401a(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        if (x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2)
            return true;

        // x轴 投影重叠
        if (x_center >= x1 && x_center <= x2)
        {
            if (min(abs(y_center - y1), abs(y_center - y2)) <= radius)
                return true;
//            else
//                return false;
        }
        else if (y_center >= y1 && y_center <= y2)
        {
            if (min(abs(x_center - x1), abs(x_center - x2)) <= radius)
                return true;
//            else
//                return false;
        }
        else
        {
            int xlen = min(abs(x_center - x1), abs(x_center - x2));
            int ylen = min(abs(y_center - y1), abs(y_center - y2));
            int len2 = xlen * xlen + ylen * ylen;

            #ifdef __test
            cout<<xlen<<", "<<ylen<<", "<<len2<<", "<<radius * radius<<endl;
            #endif // __test

            if (radius * radius >= len2)
                return true;
        }
        return false;
    }

};

int main()
{
    int r{1206}, xc{-5597}, yc{-276}, x1{-5203}, y1{-1795}, x2{-4648}, y2{1721};            // true

    LT1401 lt;

    cout<<lt.lt1401a(r,xc,yc,x1,y1,x2,y2)<<endl;

    return 0;
}
