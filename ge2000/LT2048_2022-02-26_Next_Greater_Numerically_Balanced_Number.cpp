
#include "../header/myheader.h"

class LT2048
{
public:




// g


// 数字发生数字次。
// 1个1
// 2个2
// 3个3
// 4个4 <> 1个1 + 3个3
// 获得n 的 长度。然后拼接。 反过来， n个n，然后 尝试缩小。
    int lt2048a(int n)
    {
        int cnt = 0;
        int t2 = n;
        while (t2 > 0)
        {
            cnt++;
            t2 /= 10;
        }
        t2 = 0;
        for (int i = 0; i < cnt; i++)
        {
            t2 = t2 * 10 + cnt;
        }
        ans = 0;
        if (cnt <= n)           // 1xxx
        {
            // min
            ans = 1;
//            if (cnt > 3)
            for (int i = 2; i <= n; i++)
            {
                if ((cnt - i) <= i && cnt != i)
                {
                    ;
                }
                else
                {
                    for (int j = 0; j < i; j++)
                    {
                        ans = ans * 10 + i;
                    }
                    cnt -= i;
                }
            }
            return ans;
        }
        else
        {
            // ? 55555 -> 1+4 -> 2+3
            // 66666 2+4 1+5
            // 乱了
            // 1 22 122 212 221 333 1333
            // 44440 - 44441

            //
        }
    }

};

int main()
{

    LT2048 lt;


    return 0;
}
