
#include "../header/myheader.h"

class LT0858
{
public:


// D
// 不再反射，而是向外添加格子，直到碰到端点，然后判断 最终的这个格子 是 哪个状态 的副本。
// 只在x轴上反射，延长y轴的格子， 取p,q的最小公倍数 个格子， 在最终的格子中，会碰到端点。

// 最小公倍数。


// gg
    int lt0858a(int p, int q)
    {
        int lx = 0;
        int ly = 0;
        int x = p;
        int y = q;
        int ans = -1;
        while ((ans = reflecta1(x, y, p)) == -1)
        {

        }
        return ans;
    }

    pair<int, int> goa1(int lx, int ly, int x, int y, int q)
    {
        int lenx = 0;
        int leny = 0;
        if (x == 0 || x == q)
        {
            lenx = lx - x;
            leny = y - ly;
        }
        else
        {
            lenx = x - lx;
            leny = ly - y;
        }

        // 判断到x y 0/q 的坐标，选短的。

//
//        // x += lenx   y+=leny,  yuejie huo  buman
//        x += lenx;
//        y += leny;
//
//        if (x == 0)
//        {
//
//        }
//        else if (x == q)
//        {
//
//        }
//        else if (y == 0)
//        {
//
//        }
//        else if (y == q)
//        {
//
//        }


    }

    int reflecta1(int x, int y, int q)
    {
        if (x == y && x == q)
            return 1;
        if (x == q && y == 0)
            return 0;
        if (x == 0 && y == q)
            return 2;
        return -1;
    }
};

int main()
{

    LT0858 lt;


    return 0;
}
