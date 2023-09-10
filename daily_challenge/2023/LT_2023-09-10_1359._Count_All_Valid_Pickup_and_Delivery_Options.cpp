
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //long long res = 1, cap = 1000000007;
    //for (int i = 1; i < n + 1; ++i) res = res * i % cap;
    //for (int i = 1; i < 2 * n; i += 2) res = res * i % cap;
    //return res;


    // UI��ô���ϰ��ˣ� ..�и��л�����
    // �°������ �����˴��롣����Ҫ�¿�ҳ�档
    // ֮ǰ�����°治�ã�Ӧ���� �Ҳ��� runtime, memory usage (�������Ҳ��������ߺ��鷳������û�аٷֱ�)

//Runtime: 2 ms, faster than 56.67 % of C++ online submissions for Count All Valid Pickupand Delivery Options.
//Memory Usage : 6 MB, less than 43.33 % of C++ online submissions for Count All Valid Pickupand Delivery Options.

    // p2 (d2) p1 (d2) d1 (d2)
    // 123 -> 29830541
    // �úͷŵ� ���С�  ��֮ǰ����������
    int countOrders(int n)
    {
        const int MOD = 1e9 + 7;
        long long t2 = 1LL;     // n == 1, ans
        long long t3 = 0LL;
        while (n > 1)
        {
            //t3 = n * 2 - 1;        // location of pickup
            // n*2-2  ... 1

            t2 = t2 * (1LL * (1 + n * 2 - 1) * (n * 2 - 1) / 2) % MOD;

            --n;
        }
        return t2;
    }

};

int main()
{

    LT lt;


    return 0;
}
