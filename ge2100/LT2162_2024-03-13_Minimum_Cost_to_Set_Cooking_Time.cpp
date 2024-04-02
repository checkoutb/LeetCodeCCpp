
#include "../header/myheader.h"

class LT2162
{
public:




// Runtime
// 4ms
// Beats18.39%of users with C++
// Memory
// 7.20MB
// Beats87.36%of users with C++

    // 80min  90sec
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
    {
        int ans = INT_MAX;
        if (targetSeconds < 60)
        {
            ans = cala1(targetSeconds, moveCost, pushCost, startAt);
            return ans;
        }
        int mins = targetSeconds / 60;
        int secs = targetSeconds % 60;

        if (mins < 100)
            // ans = cala1(mins, moveCost, pushCost, startAt) + cala1(secs, moveCost, pushCost, secs < 10 ? 0 : (mins % 10)) + (secs < 10 ? pushCost : 0);
        {
            ans = cala1(mins, moveCost, pushCost, startAt);
            if (secs < 10)
            {
                ans += cala1(secs, moveCost, pushCost, 0);
                ans += (mins % 10 == 0) ? 0 : moveCost;         // move and push a '0'
                ans += pushCost;
            }
            else
            {
                ans += cala1(secs, moveCost, pushCost, mins % 10);
            }
        }

#ifdef __test
        cout<<ans<<"  1111111\n";
#endif

        secs += 60;
        if (secs > 99)
            return ans;

        --mins;

        if (mins == 0)
        {
            ans = min(ans, cala1(secs, moveCost, pushCost, startAt));
        }
        else
        {
            // secs + 60, must > 10
            ans = min(ans, cala1(mins, moveCost, pushCost, startAt) + cala1(secs, moveCost, pushCost, mins % 10));
        }
        #ifdef __test
        cout<<ans<<"  222222\n";
        #endif
        return ans;
    }

    int cala1(int targetSeconds, int moveCost, int pushCost, int startAt)
    {
        int ans = 0;
        if (targetSeconds < 10)
        {
            ans = pushCost + (startAt == targetSeconds ? 0 : moveCost);
        }
        else
        {
            ans = pushCost * 2 + (targetSeconds % 10 == targetSeconds / 10 ? 0 : moveCost) + (targetSeconds / 10 == startAt ? 0 : moveCost);
        }
#ifdef __test
        cout<<targetSeconds<<", "<<startAt<<" = "<<ans<<'\n';
#endif
        return ans;
    }

};

int main()
{

    LT2162 lt;

    // int a = 1, b = 2, c = 1, d = 600;
    // int a = 0, b = 1, c = 4, d = 9;     // 5
    // int a = 9, b = 123123, c = 1, d = 6039;
    int a = 1, b = 583, c = 18, d = 64;

    cout<<lt.minCostSetTime(a,b,c,d)<<endl;

    return 0;
}
