
#include "../header/myheader.h"

class LT2507
{
public:

    // D D

    //int i = 2;
    //while (i * i <= n) {
    //    if (n % i == 0) {
    //        ret += i;
    //        n /= i;
    //    }
    //    else {
    //        ++i;
    //    }
    //}

    // 不需要 预先 prm。 上面从2开始，已经把 2的倍数 全部剔除了。


    // We prepare the list of primes to cover up to sqrt(10,000).
    // int p[65] = {2, 3, 5, 7,
    //........


    // 相同代码，一次tle，一次2907。。。
    //Runtime2907 ms
    //    Beats
    //    7.69 %
    //    Memory11.2 MB
    //    Beats
    //    23.8 %
    int lt2507a(int n)
    {
        //int sqt = std::sqrt(n);
        int sqt = n >> 1;
        vector<int> prm;
        for (int i = 2; i <= sqt; ++i)
        {
            for (int p : prm)
            {
                if (i % p == 0)
                {
                    goto AAA;
                }
            }

            prm.push_back(i);

            AAA:
            continue;
        }
        int lst = -1;
        int t2 = 0;
        while (lst != n)
        {
            lst = n;
            t2 = 0;
            for (int i = 0; i < prm.size() && n >= prm[i]; ++i)
            {
                while (n % prm[i] == 0)
                {
                    n /= prm[i];
                    t2 += prm[i];
                }
            }
            if (t2 != 0)
                n = t2;
        }
        return n;
    }

};

int main()
{

    LT2507 lt;

    int n = 15;
    //cout << lt.lt2507a(n) << endl;

    cout << lt.lt2507a(100000) << endl;

    return 0;
}
