
#include "../header/myheader.h"

class LT1227
{
public:

// D D
//f(n) = 1/n                                    -> 1st person picks his own seat
//    + 1/n * 0                                 -> 1st person picks last one's seat
//	+ (n-2)/n * (                            ->1st person picks one of seat from 2nd to (n-1)th
//        1/(n-2) * f(n-1)                   -> 1st person pick 2nd's seat
//        1/(n-2) * f(n-2)                  -> 1st person pick 3rd's seat
//        ......
//        1/(n-2) * f(2)                     -> 1st person pick (n-1)th's seat
//	)
//
//=> f(n) = 1/n * ( f(n-1) + f(n-2) + f(n-3) + ... + f(1) )



// 1
// 2
// 3: 1/3 * 1,  1/3 * 0, 1/3 * 1/2
// 4 1/4*1, 1/4*0, 1/4*2

};

int main()
{

    LT1227 lt;


    return 0;
}
