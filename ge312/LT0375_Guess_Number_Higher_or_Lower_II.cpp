
#include "../header/myheader.h"

class LT0375
{
public:


// 看了discuss，问题：有一个数在[1，1]之间，请问这个数是？，此时不会猜错。。花费0
// 问题：有一个数在[1,2]之间，此时必然猜1，如果1错了，花费1，1没错，就没有花费。如果猜2，那么可能的花费是2.。所以 不得不1.
// 最多又最少。。最多的可能，最少的花费。

//    For each number x in range[i~j]
//    we do: result_when_pick_x = x + max{DP([i~x-1]), DP([x+1, j])}
//    --> // the max means whenever you choose a number, the feedback is always bad and therefore leads you to a worse branch.
//    then we get DP([i~j]) = min{xi, ... ,xj}
//    --> // this min makes sure that you are minimizing your cost.

//    int DP(int[][] t, int s, int e){
//        if(s >= e) return 0;
//        if(t[s][e] != 0) return t[s][e];
//        int res = Integer.MAX_VALUE;
//        for(int x=s; x<=e; x++){
//            int tmp = x + Math.max(DP(t, s, x-1), DP(t, x+1, e));
//            res = Math.min(res, tmp);
//        }
//        t[s][e] = res;
//        return res;
//    }


    // error
    int lt0375a(int n)
    {
        int result = 0;
        int low = 1;
        int high = n;
        while (low < high)
        {

        }
        return result;
    }
};

int main()
{
    int n = 10;

    LT0375 lt;

    return 0;
}
