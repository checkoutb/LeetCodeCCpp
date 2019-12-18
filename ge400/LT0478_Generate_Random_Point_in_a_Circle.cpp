
#include "../header/myheader.h"

class Solution {
public:


// accepted......
    vector<double> randPoint2()
    {
        double rx = 0;
        double ry = 0;
        do
        {
            rx = x - r + 2 * r * ((double) rand() / (double) RAND_MAX);
            ry = y - r + 2 * r * ((double) rand() / (double) RAND_MAX);
        } while (((rx-x)*(rx-x) + (ry-y)*(ry-y)) > r*r);

        return {rx, ry};
    }


// ...discuss 抄 sqrt.... 之后就通过了。
// 圆是从圆心发散出去的，所以越靠近圆心，越厚。。不加sqrt，半径一半时，一半的点在小圆内，一半的点在小圆外，大圆内。但是小圆和外面的圆环的面积不相等。面积比是1：3

// 直角坐标系，极坐标系，直角坐标系命中率应该是 pi/4, 极坐标系需要 sin，cos。

// ... error...
    Solution(double radius, double x_center, double y_center) {
        srand((unsigned)time(NULL));
        r = radius;
        x = x_center;
        y = y_center;
    }

    vector<double> randPoint() {
        double rx = r * std::sqrt((double) rand() / (double) RAND_MAX);
        double qx = (double) rand() * (pi * 2)/ (double) RAND_MAX;

        return {rx * std::cos(qx) + x, rx * std::sin(qx) + y};
    }

private:
    const double pi = std::acos(-1);
    double r;
    double x;
    double y;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main()
{

    cout<<RAND_MAX<<endl<<endl;             // INT_MAX

    Solution sol(0.01, -73839.1, -3289891.3);
    int n = 4;

    for (int i = 0; i < n; i++)
    {
        vector<double> v2 = sol.randPoint();
        cout<<v2[0]<<", "<<v2[1]<<endl;
    }

    return 0;
}
