
#include "../header/myheader.h"

class LT0964
{
public:




    //g


    // error 3, 84500047 == 64          // 看了solution，把 if (x*x<=target) 改成 if(x<=target)， 过了，然后是下面的失败。
    // 3, 98000076 == 134
    unordered_map<int, int> map2;
    
    int leastOpsExpressTarget(int x, int target)
    {
        long long t2 = x;
        int ans = 0;
        if (target == 0)
            return -1;

        if (map2.find(target) != map2.end())
            return map2[target];

        map2[target] = 111111111;

#ifdef __test
        //cout << x << ", " << target << endl;
#endif

        if (x <= target)       // if (x*x<=target)
        {
            t2 = x;
            while (t2 * x < target)
            {
                t2 *= x;
                ++ans;
            }
            int t3 = min(leastOpsExpressTarget(x, target - t2), 1 + leastOpsExpressTarget(x, t2 * x - target));
            ans += t3 + 1;
            map2[target] = ans;
            return ans;
        }
        else
        {
            int t3 = target / x + (target - target / x * x) * 2;
            if (t3 != 0)
                --t3;

            int t4 = target / x + 1 + ((target / x + 1) * x - target) * 2;
            if (t4 != 0)
                --t4;

            ans = min(t3, t4);
            map2[target] = ans;
            return ans;
        }
    }



    // error
    // 优先 乘法，  + 和 - 是一样的， 所以 比较的是 距离 target的 距离( 不需要考虑符号)
    int lt0964a(int x, int target)
    {
        long long t2 = static_cast<long long>(x);
        
        int ans = 0;

        while (x * x <= target)
        {
            t2 = x;
            while (t2 * x <= target)
            {
                t2 *= x;
                ++ans;
            }

            if ((t2 * x - target) < (target - t2))
            {
                ++ans;              // 这里多了一次。不知道
                target = t2 * x - target;
            }
            else
            {
                target = target - t2;
            }

//            if (target != 0)
                ++ans;
        }

        if (ans == 0)
            --ans;

        ans += target / x;          // + or -  x

        target %= x;
        //if (target != 0)
        //    ++ans;

        ans += min(target * 2, 1 + (x - target) * 2);          // + or -   x/x    ;   +1+1   or  +x-1-1

        return ans;

    }

    //int dfsa1(int x, int t)
    //{
    //    int ans = 0;

    //    long long t2 = static_cast<long long>(x);

    //    while (t2 < target)
    //    {

    //    }

    //    return ans;
    //}

};

int main()
{

    LT0964 lt;

    //int x = 3, t = 19;

    //int x = 5, t = 501;

    //int x = 123, t = 1;

    //int x = 100, t = 100000000;

    int x = 3, t = 84500047;

    cout << lt.leastOpsExpressTarget(x, t) << endl;

    return 0;
}
