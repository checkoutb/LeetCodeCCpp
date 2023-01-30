
#include "../header/myheader.h"

class LT2517
{
public:






    //Runtime217 ms
    //    Beats
    //    90.16 %
    //    Memory48.5 MB
    //    Beats
    //    41.51 %
    int lt2517a(vector<int>& price, int k)
    {
        int sz1 = price.size();
        sort(begin(price), end(price));

        int st = 0;
        int en = (price[sz1 - 1] - price[0]) / (k - 1);
        int ans = -123;
        while (st <= en)
        {
            int md = (st + en) / 2;     // min gap
            int cnt = 1;
            int lst = price[0];
            for (int i = 1; i < sz1 && cnt < k; ++i)
            {
                if (price[i] >= lst + md)
                {
                    ++cnt;
                    lst = price[i];
                }
            }
            if (cnt < k)
            {
                en = md - 1;
            }
            else
            {
                ans = md;
                st = md + 1;
            }
        }
        return ans;
    }

};

int main()
{

    LT2517 lt;

    //myvi v = { 13,5,1,8,21,2 };
    //int k = 3;

    //myvi v = { 1,3,1 };
    //int k = 2;

    myvi v = { 3,3,3,3,3 };
    int k = 2;

    cout << lt.lt2517a(v, k) << endl;

    return 0;
}
