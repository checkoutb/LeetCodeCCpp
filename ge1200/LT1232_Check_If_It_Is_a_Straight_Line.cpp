
#include "../header/myheader.h"

class LT1232
{
public:


// D D

// ... 乘法不需要剔除 0。。。



//Runtime: 12 ms, faster than 96.88% of C++ online submissions for Check If It Is a Straight Line.
//Memory Usage: 10.4 MB, less than 30.99% of C++ online submissions for Check If It Is a Straight Line.
// x1/y1 = x2/y2
// x1*y2 = x2*y1
// y = 0
    bool lt1232a(vector<vector<int>>& coordinates)
    {
        if (coordinates[1][1] == coordinates[0][1])
        {
            for (vector<int>& v : coordinates)
            {
                if (v[1] != coordinates[0][1])
                {
                    return false;
                }
            }
        }
        else
        {
            int x1 = coordinates[1][0] - coordinates[0][0];
            int y1 = coordinates[1][1] - coordinates[0][1];
            for (int i = 2; i < coordinates.size(); i++)
            {
                int x2 = coordinates[i][0] - coordinates[i-1][0];
                int y2 = coordinates[i][1] - coordinates[i-1][1];
                if (x1 * y2 != x2 * y1)
                    return false;
            }
        }
        return true;
    }

};

int main()
{
//    vector<vector<int>> vv = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    vector<vector<int>> vv = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};

    LT1232 lt;

    cout<<lt.lt1232a(vv);

    return 0;
}
