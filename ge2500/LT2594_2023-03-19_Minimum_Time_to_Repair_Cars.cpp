
#include "../header/myheader.h"

class LT2594
{
public:

    // D D



    //Runtime57 ms
    //    Beats
    //    100 %
    //    Sorry, there are not enough accepted submissions to show data
    //    Memory53.8 MB
    //    Beats
    //    100 %
    // 
    // 为什么不是 每次修一台，这样只需要 r 分钟， 2台只需要2个r。而不是4个r。
    long long lt2594a(vector<int>& ranks, int cars)
    {
        int sz1 = ranks.size();
        long long ans = 0LL;
        long long st = 1LL;
        long long en = 100LL * (cars / sz1 + 1) * (cars / sz1 + 1);

        int arr[101] = { 0 };
        for (int i = 0; i < sz1; ++i)
        {
            ++arr[ranks[i]];
        }

        while (st <= en)
        {
            long long md = (st + en) / 2;
            int remain = cars;

            //for (int i = 0; i < sz1 && remain > 0; ++i)
            //{
            //    remain -= 
            //}

            for (int i = 1; i <= 100 && remain > 0; ++i)
            {
                if (arr[i] == 0)
                    continue;

                remain -= arr[i] * static_cast<int>(std::sqrt(md / i));
            }

            if (remain > 0)
            {
                st = md + 1;
            }
            else
            {
                ans = md;
                en = md - 1;
            }
        }
        return ans;
    }

};

int main()
{

    LT2594 lt;

    myvi v = { 4,3,2,1 };
    int c = 10;


    cout << lt.lt2594a(v, c) << endl;

    cout << sqrt(7) << endl;
    cout << 1 * sqrt(7) << endl;

    return 0;
}
