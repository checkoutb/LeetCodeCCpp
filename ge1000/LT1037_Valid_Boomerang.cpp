
#include "../header/myheader.h"

class LT1037
{
public:


// D D

//Calculate the area of the triangle: x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) and compare it to zero.



//Runtime: 4 ms, faster than 67.87% of C++ online submissions for Valid Boomerang.
//Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for Valid Boomerang.
    bool lt1037a(vector<vector<int>>& points)
    {
        int x1{points[0][0]},x2{points[1][0]},x3{points[2][0]},y1{points[0][1]},y2{points[1][1]},y3{points[2][1]};
        int t1 = (x3-x1)*(y2-y1);
        int t2 = (x2-x1)*(y3-y1);
        if (t1 != t2)
            return true;
        if (t1 == 0)
        {
            t1 = (x1-x3)*(y2-y3);
            t2 = (x2-x3)*(y1-y3);
            if (t1 != t2)
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
    }

};

int main()
{

    vector<vector<int>> vv = {{1,1},{2,3},{3,2}};
//    vector<vector<int>> vv = {{1,1},{2,2,},{3,3}};
//    vector<vector<int>> vv = {{0,1},{2,2},{2,0}};

    LT1037 lt;

    cout<<lt.lt1037a(vv)<<endl;

    return 0;
}
