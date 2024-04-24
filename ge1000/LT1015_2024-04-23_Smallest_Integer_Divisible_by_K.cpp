
#include "../header/myheader.h"

class LT1015
{
public:


    // D

        // for (int r = 0, N = 1; N <= K; ++N)
        //     if ((r = (r * 10 + 1) % K) == 0)
        //         return N;
        // return -1;

    // ai, buhui jiushi buhui, zai jiandan ye buhui.



    // k * x = 11..11
    int smallestRepunitDivByK(int k)
    {
        int ans = 0;



    }


    // error
    // all 1
    int smallestRepunitDivByK_eeee(int k)
    {
        int ans = 0;
        int remain = 1;
        set<int> seen;
        while (remain != 0)
        {
            if (seen.contains(remain))
                return -1;
            seen.insert(remain);

            int t3 = -1;
            for (int i = 1; i < 9; ++i)
            {
                int t2 = k * i;
                if (t2 % 10 == remain % 10)
                {
                    t3 = t2;
                    break;
                }
            }
            if (t3 == -1)
                return -1;

            remain -= t3;


        }
        return ans;
    }
};

int main()
{

    LT1015 lt;


    return 0;
}
