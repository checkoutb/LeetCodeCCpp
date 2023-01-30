
#include "../header/myheader.h"

class LT2522
{
public:




    //Runtime13 ms
    //    Beats
    //    72.89 %
    //    Memory8.9 MB
    //    Beats
    //    96.1 %

    // <= k
    // <= 456 , "453999" 453 99 9  , 45 399 9
    int lt2522a(string s, int k)
    {
        int ans = 0;
        long long t2 = 0LL;
        for (int i = 0; i < s.size(); ++i)
        {
            t2 = t2 * 10 + (s[i] - '0');
            if (t2 > k)
            {
                ++ans;
                t2 = (s[i] - '0');
                if (t2 > k)
                    return -1;
            }
        }
        return ans + 1;
    }

};

int main()
{

    LT2522 lt;

    string s = "165462";
    int k = 3;

    cout << lt.lt2522a(s, k) << endl;

    return 0;
}
