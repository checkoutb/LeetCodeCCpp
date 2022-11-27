
#include "../header/myheader.h"

class LT2483
{
public:

    // D D

    // 不需要数组vi。 直接记录下 个数就可以了。
    
    // int ans = 0, val = count(s.begin(), s.end(), 'Y'), m = val; 




    //Runtime110 ms
    //    Beats
    //    12.50 %
    //    Memory15.9 MB
    //    Beats
    //    12.50 %
    // 前面的 N + 后面(包含自己)的Y  最小。
    int lt2483a(string customers)
    {
        customers.push_back('N');
        int sz1 = customers.size();
        int ans = 0;
        int mx = INT_MAX;

        vector<int> vi(sz1);
        
        for (int i = sz1 - 2; i >= 0; --i)
        {
            vi[i] = vi[i + 1] + (customers[i] == 'Y');
        }

        int cntn = 0;
        int t2;
        for (int i = 0; i < sz1; ++i)
        {
            t2 = cntn + vi[i];
            if (t2 < mx)
            {
                mx = t2;
                ans = i;
            }
            cntn += customers[i] == 'N';
        }

        return ans;
    }

};

int main()
{

    LT2483 lt;


    return 0;
}
