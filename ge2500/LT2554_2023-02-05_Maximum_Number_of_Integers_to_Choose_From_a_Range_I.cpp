
#include "../header/myheader.h"

class LT2554
{
public:

    // D D

    //vector<bool> avail(n + 1, true);
    //for (auto& x : banned)
    //    if (x <= n) avail[x] = false;
    //int ans = 0;
    //for (int x = 1; x <= n; ++x)
    //    if (avail[x]) {
    //        maxSum -= x;
    //        if (maxSum < 0) break;
    //        ++ans;
    //    }



    //Runtime302 ms
    //    Beats
    //    100 %
    //    Memory113.4 MB
    //    Beats
    //    44.44 %
    int lt2554a(vector<int>& banned, int n, int maxSum)
    {
        int sz1 = banned.size();
        sort(begin(banned), end(banned));
        int ans = 0;
        int idx = 0;
        int sum2 = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (idx < sz1 && banned[idx] == i)
            {
                while (idx < sz1 && banned[idx] == i)            // . not distinct
                    ++idx;
                continue;
            }

            if (sum2 + i <= maxSum)
            {
                ++ans;
                sum2 += i;
            }
            else
            {
                break;
            }
            
        }

        return ans;
    }

};

int main()
{

    LT2554 lt;

    myvi v = { 87,193,85,55,14,69,26,133,171,180,4,8,29,121,182,78,157,53,26,7,117,138,57,167,8,103,32,110,15,190,139,16,49,138,68,69,92,89,140,149,107,104,2,135,193,87,21,194,192,9,161,188,73,84,83,31,86,33,138,63,127,73,114,32,66,64,19,175,108,80,176,52,124,94,33,55,130,147,39,76,22,112,113,136,100,134,155,40,170,144,37,43,151,137,82,127,73 };
    int n = 1079;
    int mx = 87;

    cout << lt.lt2554a(v, n, mx) << endl;

    return 0;
}
