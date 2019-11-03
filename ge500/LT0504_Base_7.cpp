
#include "../header/myheader.h"

class LT0504
{
public:

// discuss
// 1次循环 or recursion。

// 4396！
    string lt0504a(int num)
    {
        bool b1 = num < 0;
        num = abs(num);
        int a = 1;
        while (a <= num)
        {
            a *= 7;
        }
        a /= 7;
        int ans2 = 0;
        while (a > 0)
        {
            ans2 *= 10;
            ans2 += (num / a);
            num %= a;
            a /= 7;
        }
        return (b1 ? "-" : "") + to_string(ans2);
    }
};

int main()
{
    int arr[] = {100, -7};

    LT0504 lt;
    cout<<endl;
    for (int i : arr)
    {
        cout<<lt.lt0504a(i)<<endl;
    }

    return 0;
}
