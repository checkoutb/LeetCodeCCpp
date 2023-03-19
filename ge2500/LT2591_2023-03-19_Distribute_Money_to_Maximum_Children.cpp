
#include "../header/myheader.h"

class LT2591
{
public:

    // D D

    //if (money < giftees)
    //{
    //    return 0;
    //}
    //else if (giftees * 8 == money)
    //{
    //    return giftees;
    //}
    //else if (giftees * 8 < money)
    //{
    //    return giftees - 1;
    //}
    //else
    //{
    //    money -= giftees;
    //    int num = money / 7;
    //
    //    if (money % 7 == 3)
    //    {
    //        return num - 1;
    //    }
    //    else
    //    {
    //        return num;
    //    }
    //}
    //
    // 这道题改过吧。 钱<人，这里返回了0。



    //money -= children;
    //if (money < 0)
    //    return -1;
    //if (money / 7 == children && money % 7 == 0)
    //    return children;
    //if (money / 7 == children - 1 && money % 7 == 3)
    //    return children - 2;
    //return min(children - 1, money / 7);

    //First, we give everyone one dollar to satisfy condition 2.
    //Then, we check how many kids can get exactly 7 more dollars.







    // 错了4次。。。
    //
    //Runtime8 ms
    //    Beats
    //    12.50 %
    //    Memory5.9 MB
    //    Beats
    //    100 %
    // 这道题应该就是 easy is not easy.  16.8% 的 通过率。
    int lt2591a(int money, int children)
    {
        if (money < children)
            return -1;

        for (int i = money / 8; i > 0; --i)     // 多少个人 收到8
        {
            int t2 = money - i * 8;     // 剩余的钱
            int t3 = children - i;     // 剩余的人

            if (t3 < 0)
            {
                return (min(i, children) - 1);
            }
            else if (t3 == 0)
            {
                return i - (t2 != 0);
            }
            else
            {
                if (t3 == 1 && t2 == 4)
                {
                    return (i - 1);
                }
                if (t2 >= t3)
                    return i;
            }

        }
        return 0;
    }

};

int main()
{

    LT2591 lt;

    //int m = 20;
    //int n = 3;

    int m = 24;
    int n = 2;

    cout << lt.lt2591a(m, n) << endl;

    return 0;
}
