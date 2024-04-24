
#include "../header/myheader.h"

class LT1611
{
public:


    // g

    // ...?

    // 9 -> 14
    // 01001 -> 01010 -> 01100 -> 00100 -> 00101 -> 00110 -> 00010 -> 00011 -> 00001 -> 00000
    // ?

    // 11 -> 01 -> 0
    // 10 -> 11 -> 01 -> 0
    // ?
    // 001000 -> 011000 / 001001 -> ?
    // 001000 -> 001001 -> 001010 -> 001100 -> 000100 ->
    int minimumOneBitOperations(int n)
    {
        int ans = 0;
        for (int i = 0; i < 31; ++i)
        {
            if ((n & 1<<i) != 0 && (n & 1 << (i + 1)) != 0)
            {
                n ^= (1 << (i + 1));
                ans++;
                break;
            }
        }

        int arr[32] = {0};
        arr[0] = 1;
        for (int i = 1; i < 32; ++i)
        {
            arr[i] = arr[i - 1] + (i) + 1;
        }

        for (int i = 0; i < 31; ++i)
        {
            if ((n & (1 << i)) != 0)
            {
                ans += arr[i];
            }
        }
        return ans;
    }
};

int main()
{

    LT1611 lt;


    return 0;
}
