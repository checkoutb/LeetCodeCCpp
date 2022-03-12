
#include "../header/myheader.h"

class LT2169
{
public:




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Operations to Obtain Zero.
//Memory Usage: 5.8 MB, less than 74.72% of C++ online submissions for Count Operations to Obtain Zero.
    int lt2169a(int num1, int num2)
    {
        if (num1 < num2)
            swap(num1, num2);
        int ans = 0;
        while (num2 != 0)
        {
            ans += num1 / num2;
            num1 -= num2 * (num1 / num2);
            if (num1 < num2)
                swap(num1, num2);
        }
        return ans;
    }

};

int main()
{

    LT2169 lt;


    return 0;
}
