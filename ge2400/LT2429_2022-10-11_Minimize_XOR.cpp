
#include "../header/myheader.h"

class LT2429
{
public:

    // D D

    // int a = Integer.bitCount(num1), b = Integer.bitCount(num2), res = num1;

    // int a = __builtin_popcount(num1), b = __builtin_popcount(num2), res = num1;

    // a, b = num1.bit_count(), num2.bit_count()


    //for (int i = 0; i < 32; ++i) {
    //    if (a > b && ((1 << i) & num1) > 0) {
    //        res ^= 1 << i;
    //        a--;
    //    }
    //    if (a < b && ((1 << i) & num1) == 0) {
    //        res ^= 1 << i;
    //        a++;
    //    }
    //}


    //int b = __builtin_popcount(num2), x = (1 << b) - 1;
    //for (int l1 = 30, l2 = b - 1; x < num1 && l2 >= 0; --l1, --l2) {
    //    while (((1 << l1) & num1) == 0)
    //        --l1;
    //    x += (1 << l1) - (1 << l2);
    //}


//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Minimize XOR.
//Memory Usage : 5.9 MB, less than 81.91 % of C++ online submissions for Minimize XOR.
    int lt2429a(int num1, int num2)
    {
        int arr1[32] = { 0 };
        int arr2[32] = { 0 };
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (num1 & (1 << i))
            {
                ++cnt1;     // cnt--.....
                arr1[i] = 1;
            }
            if (num2 & (1 << i))
            {
                ++cnt2;     // cnt++
                arr2[i] = 1;
            }
        }

        if (cnt1 == cnt2)
        {
            return num1;
        }
        else if (cnt1 < cnt2)
        {
            int cnt = cnt2 - cnt1;
            for (int i = 0; i < 32; ++i)
            {
                if (cnt > 0 && (arr1[i] == 0))
                {
                    arr1[i] = 1;
                    --cnt;
                }
            }
        }
        else
        {
            int cnt = cnt1 - cnt2;
            for (int i = 0; i < 32; ++i)
            {
                if (cnt > 0 && (arr1[i] == 1))
                {
                    arr1[i] = 0;
                    --cnt;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (arr1[i])
            {
                ans |= (1 << i);
            }
        }
        return ans;
    }

};

int main()
{

    LT2429 lt;

    int a(25), b(72);

    cout << lt.lt2429a(a, b) << endl;

    return 0;
}
