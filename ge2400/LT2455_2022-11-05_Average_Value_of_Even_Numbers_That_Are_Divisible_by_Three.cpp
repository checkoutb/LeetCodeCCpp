
#include "../header/myheader.h"

class LT2455
{
public:

    // D D



//Runtime16 ms
//Beats
//71.32 %
//Memory13.7 MB
//Beats
//60.36 %
    int lt2455a(vector<int>& nums)
    {
        int sum2 = 0;
        int cnt = 0;
        for (int i : nums)
        {
            if (i % 6 == 0)
            {
                sum2 += i;
                ++cnt;
            }
        }
        return cnt == 0 ? 0 : (sum2 / cnt);
    }

};

int main()
{

    LT2455 lt;


    return 0;
}
