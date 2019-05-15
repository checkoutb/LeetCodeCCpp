
#include "../header/myheader.h"

class LT0367
{
public:


//		long r = num/2+1;
//		while (r*r > num)
//			r = (r + num / r) / 2;
//		return r*r == num;
// Newton Method

//A square number is 1+3+5+7+...,
//     int i = 1;
//     while (num > 0) {
//         num -= i;
//         i += 2;
//     }
//     return num == 0;




//Runtime: 4 ms, faster than 96.84% of C++ online submissions for Valid Perfect Square.
//Memory Usage: 8.1 MB, less than 25.00% of C++ online submissions for Valid Perfect Square.


// num: 1。。。

    // 46341 * 46341 cannot be represented in type 'int'
    bool lt0367a(int num)
    {
        int max1 = num / 2 + 1;
        max1 = min(max1, 46340);
        for (int i = 0; i <= max1; i++)
        {
            if (i*i == num)
                return true;
        }
        return false;
    }
};

int main()
{
    LT0367 lt;

    return 0;
}
