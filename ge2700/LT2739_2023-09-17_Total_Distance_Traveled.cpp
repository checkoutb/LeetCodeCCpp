
#include "../header/myheader.h"

class LT2739
{
public:

    // D D

    //while (mainTank >= 5 && additionalTank > 0) {
    //    ans = ans + 5;
    //    additionalTank--;
    //    mainTank = mainTank - 5 + 1;
    //}
    

    //int x = (mainTank - 1) / 4;
    //if (additionalTank >= x) {
    //    mainTank += x;
    //}
    //else {
    //    mainTank += additionalTank;
    //}


    //Runtime4 ms
    //    Beats
    //    88.50 %
    //    Memory6.4 MB
    //    Beats
    //    15.23 %

    // 5 1
    // 25 5 1
    // .. 9 2 -> 110
    int distanceTraveled(int mainTank, int additionalTank)
    {
        int ans = 0;
        int used = 0;
        while (mainTank > 0)
        {
            used += mainTank;
            ans += mainTank * 10;
            mainTank = min(additionalTank, used / 5);
            used %= 5;
            additionalTank -= mainTank;
        }
        return ans;
    }

};

int main()
{

    LT2739 lt;


    return 0;
}
