
#include "../header/myheader.h"

class LT0837
{
public:

    // D



    // g


    // 要么tle， 增加lmt 就wrong。
    // 1% > 99% .... 不行。。 本来想的是 第一次就是 下标 1-maxPts 都+1，可以变成 下标1 +1， 下标maxPts -1。 但是 10^4 * 10^4 ...
    // maxPts 分 概率， 当概率 < 0.0000001 的时候 直接返回就是了， 即使二分也是非常快的下降。
    double lt0837a(int n, int k, int maxPts)
    {
        long double lmt = 0.000000001;
        return dfsa1(maxPts, n, k, 1.0, 0, lmt);
    }

    // >=k时停止，   总共获得 <=n 的概率
    double dfsa1(int mxp, int n, int k, long double r, int got, long double& lmt)
    {
#ifdef __test
        cout << got << ", " << r << endl;
#endif
        if (r < lmt)
        {
            return got <= n ? r : 0;
        }
        if (got >= k)
        {
            return got <= n ? r : 0;
        }
        if (got > n)
        {
            return 0;
        }
        long double nr = r / mxp;
        double ans = 0.0;
        for (int i = 1; i <= mxp; ++i)
        {
            ans += dfsa1(mxp, n, k, nr, got + i, lmt);
        }
        return ans;
    }


};

int main()
{

    LT0837 lt;

    //int n{ 6 }, k{ 1 }, mxp{ 10 };

    //int n{ 21 }, k{ 17 }, mxp{ 10 };

    int n{ 421 }, k{ 400 }, mxp{ 47 };

    cout << lt.lt0837a(n, k, mxp) << endl;

    return 0;
}
