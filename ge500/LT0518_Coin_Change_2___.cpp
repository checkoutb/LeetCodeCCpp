
#include "../header/myheader.h"

class LT0518
{
public:



    // 17/27 tle
    int cnt = 0;
    int lt0518a(int amount, vector<int>& coins)
    {
        dfsa1(amount, coins, 0, 0);
        return cnt;
    }

    void dfsa1(int tar, vector<int>& coins, int got, int start)
    {
        if (got >= tar)
        {
            cnt += (got == tar);
            return;
        }
        for (int i = start; i < coins.size(); i++)
        {
            dfsa1(tar, coins, got + coins[i], i);
        }
    }
};

int main()
{
    int a = 5;
    vector<int> c = {1,2,5};

    LT0518 lt;
    cout<<lt.lt0518a(a, c)<<endl;

    return 0;
}
