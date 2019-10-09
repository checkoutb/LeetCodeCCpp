
#include "../header/myheader.h"

class LT0440
{
public:





    // error
    int lt0440c(int n, int k)
    {
        int diff = 1;
        int n2 = n;
        while (n2 >= 10)
        {
            n2 /= 10;
            diff = diff * 10 + 1;
        }

        int ans = 1;
        int i = 1;
        while (i < k)
        {
            #ifdef __test
            cout<<i<<" , "<<ans<<" , "<<diff<<endl;
            system("pause");
            #endif // __test

            if (i + diff <= k)
            {
//                ans++;
                i += diff;

                if (ans + 1 > n)
                {
                    ans /= 10;
                }
                ans++;
                while (ans % 10 == 0)
                {
                    ans /= 10;
                }

            }
            else
            {
                diff /= 10;
//                ans *= 10;
//                i++;
            }
        }
        return ans;
    }



// 1        1
// 2        10
// 1112     2
// 2223     3
// 3334     4


    // 差距是11，111，1111这种。

    // 没有return，返回的随机数是 正确结果 的字典顺序的前一个。。
    int lt0440b(int n, int k)
    {
        int i = 1;
        long ans = 1;
        for (; i < k; i++)
        {
            #ifdef __test
//            if (ans <= 10)
                cout<<" "<<i<<"  "<<ans<<endl;
            #endif // __test
            if (ans * 10 <= n)
            {
                ans *= 10;
            }
            else
            {
                if (ans + 1 > n)
                {
                    ans /= 10;
                }
                ans++;
                while (ans % 10 == 0)
                {
                    ans /= 10;
                }
            }
        }
        return (int) ans;
    }


    // tle.. 596516650 593124772
    // LT0386..
    int lt0440a(int n, int k)
    {
        int i = 1;
        long ans = 1;
        for (; i < k; i++)
        {
            #ifdef __test
            cout<<" ...   "<<ans<<endl;
            #endif // __test

            if (ans * 10 <= n)          // 1.10.100.1000...
            {
                ans *= 10;
                continue;
            }
            if (ans + 1 <= n)           // 1000.1001.1002.1003...
            {
                ans += 1;
                while (ans % 10 == 0)               // 108.109.  110/10==11 . 11*10==110..111.112.....198.199.. 200/10/10==2. 20. 200. 201.202
                    ans /= 10;
                continue;
            }
            else                        // max:1010  now:1010  1010/10 + 1 = 102...102*10>1010..so 102.103.104..
            {
                ans /= 10;
                ans += 1;
                while (ans % 10 == 0)               // 108.109.  110/10==11 . 11*10==110..111.112.....198.199.. 200/10/10==2. 20. 200. 201.202
                    ans /= 10;
                continue;
            }
        }

        return (int) ans;
    }
};

int main()
{
    int n = 13;
    int k = 2;

    LT0440 lt;
    cout<<endl<<"result : "<<lt.lt0440c(n, k)<<endl;

    cout<<endl<<endl;
    lt.lt0440b(n, k);

    return 0;
}
