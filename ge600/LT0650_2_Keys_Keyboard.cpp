
#include "../header/myheader.h"

class LT0650
{
public:



// 复制到小于n的 2的次方？
// 奇数不可能通过复制来获得，所以一路/2，直到奇数？ 。 不，奇数复制3次就是奇数了。。 复制质数次。。。如果能被大质数除净，就分开？
    int lt0650b(int n)
    {
//        int arr[] = {1,2,4,8,16,32,64,128,256,512,1024};

    }



// 。。。 错了，这里是3个操作， a键，复制全部，粘贴。。。。题目只有2个操作，和一个初始的a。。
// 是不是每次都 奇数-1，然后除以2 是最少次数
    int lt0650a(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans++;
                n--;
            }
            else
            {
                ans++;
                n /= 2;
            }
        }
        return ans;
    }

};

int main()
{

    LT0650 lt;


    return 0;
}
