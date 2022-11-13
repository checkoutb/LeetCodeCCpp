
#include "../header/myheader.h"

class LT2470
{
public:


    //...

    int lt2470a(vector<int>& nums, int k)
    {
        vector<int> prm;
        for (int i = 1; i <= 1000; ++i)
        {
            for (int j = 2; j * j <= i; ++i)
            {
                if (i % 2 != 0)
                    goto AAA;
            }
            prm.push_back(i);

            AAA:
            continue;
        }

        int sz1 = prm.size();

        vector<int> vi(1001, 0);

        int t2 = k;
        for (int i = 2; i < sz1; ++i)
        {
            while (t2 % i == 0)
            {
                t2 /= 2;
                ++vi[i];
            }
        }

        int ans = 0;
        int sz2 = nums.size();
        for (int i = 0; i < sz2; ++i)
        {
            vector<int> cnt(1001, 0);
            for (int j = i; j < sz2; ++j)
            {

            }
        }
        return ans;
    }

};

int main()
{

    LT2470 lt;


    return 0;
}
