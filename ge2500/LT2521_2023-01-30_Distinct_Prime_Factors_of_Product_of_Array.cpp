
#include "../header/myheader.h"

class LT2521
{
public:

    // D D

    // the fact that a number can have at most one prime factor that is greater than its square root.
    
    //We only need to know primes up to sqrt(1000).
    //    If, after dividing n by all these primes, n is still greater than 1, then what remains is a large prime.
    // 
    // int ps[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};




    //Runtime107 ms
    //    Beats
    //    48.81 %
    //    Memory19 MB
    //    Beats
    //    26.52 %
    int lt2521a(vector<int>& nums)
    {
        vector<bool> vb(1001, true);       // index is prime?

        for (int i = 2; i < 1001; ++i)
        {
            if (vb[2])
            {
                for (int j = i + i; j < 1001; j += i)
                {
                    vb[j] = false;
                }
            }
        }

        vector<int> prms;
        for (int i = 2; i < 1001; ++i)
        {
            if (vb[i])
                prms.push_back(i);
            vb[i] = false;          // exist?
        }

        for (int num : nums)
        {
            for (int i = 0; i < prms.size() && num >= prms[i]; ++i)
            {
                while (num >= prms[i] && (num % prms[i] == 0))
                {
                    num /= prms[i];
                    vb[prms[i]] = true;
                }
            }
        }
        int ans = 0;
        for (int i = 2; i < vb.size(); ++i)
        {
            if (vb[i])
                ++ans;
        }
        return ans;
    }

};

int main()
{

    LT2521 lt;

    //myvi v = { 2,4,3,7,10,6 };
    myvi v = { 2,4,8,32 };

    cout << lt.lt2521a(v) << endl;

    return 0;
}
