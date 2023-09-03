
#include "../../header/myheader.h"

class LT7020
{
public:




// AC
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (; low <= high; ++low)
        {
            if (isSym(low))
            {
                #ifdef __test
//                cout<<low<<endl;
                #endif // __test
                ++ans;
            }
        }
        return ans;
    }

    bool isSym(int n)
    {
        int t2 = n;
        int cnt = 0;
        while (t2 > 0)
        {
            ++cnt;
            t2 /= 10;
        }
        if (cnt % 2 == 1)
            return false;

        cnt >>= 1;

        int a = 0;
        int b = 0;

//        cout<<cnt<<"--"<<n<<" --------"<<endl;

        for (int i = 0; i < cnt; ++i)
        {
            a += n % 10;
            n /= 10;
        }
        for (int i = 0; i < cnt; ++i)
        {
            b += n % 10;
            n /= 10;
        }
        #ifdef __test
//        cout<<a<<" - "<<b<<endl;
        #endif // __test
        return a == b;
    }

};

int main()
{

    LT7020 lt;

    int a = 1;
    int b = 100;

    cout<<lt.countSymmetricIntegers(a, b)<<endl;

    return 0;
}
