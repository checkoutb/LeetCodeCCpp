
#include "../header/myheader.h"

class LT2105
{
public:

// D D

//if (a < A[i]) a = ca, ++ans;




//Runtime: 170 ms, faster than 76.42% of C++ online submissions for Watering Plants II.
//Memory Usage: 78.1 MB, less than 95.16% of C++ online submissions for Watering Plants II.
// 打水的次数，  这个打水的时候，另一方能不能浇水？ 随便。 instantaneously  瞬间加满水。
    int lt2105a(vector<int>& plants, int capacityA, int capacityB)
    {
        int wa = capacityA;
        int wb = capacityB;
        int ia = 0;
        int ib = plants.size() - 1;
        int ans = 0;
        while (ia < ib)
        {
            if (wa < plants[ia])
            {
                ans++;
                wa = capacityA;
            }
            if (wb < plants[ib])
            {
                ans++;
                wb = capacityB;
            }
            wa -= plants[ia];
            wb -= plants[ib];
            ia++;
            ib--;
        }
        if (ia == ib)
        {
            if (max(wa, wb) < plants[ia])
                ans++;
        }
        return ans;
    }

};

int main()
{

    LT2105 lt;


    return 0;
}
