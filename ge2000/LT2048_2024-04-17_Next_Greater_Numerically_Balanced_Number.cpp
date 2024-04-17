
#include "../header/myheader.h"

class LT2048
{
public:

    // D D

    // vector<int>v{0, 1,22, 122, 212, 221, 333, 1333, 3133, 3313, 3331, 4444, 14444,
    //         22333, 23233, 23323, 23332





    // 。。。。。。。。。。。。。。。

// Runtime
// 88ms
// Beats42.37%of users with C++
// Memory
// 8.23MB
// Beats62.71%of users with C++
    int nextBeautifulNumber(int n)
    {
        while (true)
        {
            n++;
            if (ok(n))
            {
                return n;
            }
        }
        return -1;
    }

    bool ok(int n)
    {
        int arr[10] = {0};
        while (n > 0)
        {
            ++arr[n % 10];
            n /= 10;
        }
        for (int i = 0; i < 10; ++i)
        {
            if (arr[i] != 0 && arr[i] != i)
                return false;
        }
        return true;
    }

    // d occur d times
    // 1 22 122 212 221 333 1333
    // 只能 硬算啊。
    // <= 10^6  ，<，  最多6位数
    int nextBeautifulNumber__(int n)
    {
        vector<int> vi;
        while (n > 0)
        {
            vi.push_back(n % 10);
            n /= 10;
        }
        std::reverse(std::begin(vi), std::end(vi));

        // x ...
        if (vi[0] <= vi.size())
        {

        }

        // x+1 ...
        if (vi[0] + 1 <= vi.size())
        {

        }

        // 1 ....
        {

        }
        return -1;
    }

};

int main()
{

    LT2048 lt;


    return 0;
}
