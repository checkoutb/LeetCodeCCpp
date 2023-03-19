
#include "../header/myheader.h"

class LT1553
{
public:

    // D D

    //unordered_map<int, int> dp;
    //int minDays(int n) {
    //    if (n <= 1)
    //        return n;
    //    if (dp.count(n) == 0)
    //        dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
    //    return dp[n];
    //}




    //Runtime17 ms
    //    Beats
    //    50.81 %
    //    Memory8.6 MB
    //    Beats
    //    89.90 %
    int lt1553a(int n)
    {
        map<int, int> map2;

        int ans = dfsa1(map2, n);

        return ans;
    }

    int dfsa1(map<int, int>& map2, int n)
    {
        if (map2.find(n) != map2.end())
            return map2[n];

        if (n == 0)
            return 0;

        int ans = 0;

        ans = n % 2 + dfsa1(map2, n / 2) + (n / 2 != 0);
        ans = min(ans, n % 3 + dfsa1(map2, n / 3) + (n / 3 != 0));

        //if (n % 6 == 0)
        //{
        //    ans = 1 + min(dfsa1(map2, n / 2), dfsa1(map2, n / 3));
        //}
        //else if (n % 2 == 0)
        //{
        //    ans = 1 + dfsa1(map2, n / 2);
        //}
        //else if (n % 3 == 0)
        //{
        //    ans = 1 + dfsa1(map2, n / 3);
        //}
        //else
        //{
        //    ans = 1 + dfsa1(map2, n - 1);
        //}


        map2[n] = ans;
        return ans;
    }

};

int main()
{

    LT1553 lt;

    int n = 10;


    cout << lt.lt1553a(n) << endl;

    return 0;
}
