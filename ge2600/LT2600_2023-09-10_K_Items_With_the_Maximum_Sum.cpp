
#include "../header/myheader.h"

class LT2600
{
public:







    //Runtime0 ms
    //    Beats
    //    100 %
    //    Memory6.1 MB
    //    Beats
    //    21.65 %
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        if (k <= numOnes)
            return k;
        else if (k <= (numOnes + numZeros))
            return numOnes;
        else
            return numOnes - (k - numOnes - numZeros);
    }

};

int main()
{

    LT2600 lt;


    return 0;
}
