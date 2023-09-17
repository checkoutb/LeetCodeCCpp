
#include "../header/myheader.h"

class LT2745
{
public:



//Runtime0 ms
//Beats
//100%
//Memory6.3 MB
//Beats
//14.31%

    // AA BB AB
    // no AAA    no BBB
    // BB AA BB AA
    // BB AB AA BB
    // BB AB AB AA
    //
    // BB BB
    // AA AA
    // AA AB
    // AB BB
    // AA BB AA BB
    // AA BB AB AA
    // BB AB AA BB
    //
    // AB AB AB
    // AB AB AB    AA BB AA BB AA
    // BB AA BB AA BB    AB AB AB
    int longestString(int x, int y, int z)
    {
        return (z + min(x, y) * 2 + (x != y)) * 2;
    }

};

int main()
{

    LT2745 lt;


    return 0;
}
