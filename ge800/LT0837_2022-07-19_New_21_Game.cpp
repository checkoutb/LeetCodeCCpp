
#include "../header/myheader.h"

class LT0837
{
public:

    // D



    // g


    // Ҫôtle�� ����lmt ��wrong��
    // 1% > 99% .... ���С��� ��������� ��һ�ξ��� �±� 1-maxPts ��+1�����Ա�� �±�1 +1�� �±�maxPts -1�� ���� 10^4 * 10^4 ...
    // maxPts �� ���ʣ� ������ < 0.0000001 ��ʱ�� ֱ�ӷ��ؾ����ˣ� ��ʹ����Ҳ�Ƿǳ�����½���
    double lt0837a(int n, int k, int maxPts)
    {
        long double lmt = 0.000000001;
        return dfsa1(maxPts, n, k, 1.0, 0, lmt);
    }

    // >=kʱֹͣ��   �ܹ���� <=n �ĸ���
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
