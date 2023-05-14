
#include "../../header/myheader.h"

class LT
{
public:




//    Runtime5 ms
//    Beats
//    23.2%
//    Memory7 MB
//    Beats
//    84.6%
    double average(vector<int>& salary)
    {
        int mn = 12345678;
        int mx = -1;
        int sum2 = 0;
        for (int i : salary)
        {
            sum2 += i;
            if (i < mn)
                mn = i;
            if (i > mx)
                mx = i;
        }
        return 1.0 * (sum2 - mn - mx) / (salary.size() - 2);
    }

};

int main()
{

    LT lt;


    return 0;
}
