
#include "../header/myheader.h"

class LT1997
{
public:


    // D

    // dp[i] = (2*dp[i-1] - dp[A[i-1]] + 2) % M


    // Steps to reach room i-1 for the first time, which is steps[i-1]
    // 1 step to go to nextVisit[i-1]
    // Steps to reach room i-1 for the second time, which is steps[i-1] - steps[nextVisit[i-1]], since this time we start from room nextVisit[i-1] instead of room 0
    // 1 step to finally move to room i

    // dp 是 第一次访问 的 步数





    // Can you use Dynamic Programming to avoid recomputing the number of days it takes to visit room i from room nextVisit[i]?

    // error , 想不出
    int firstDayBeenInAllRooms(vector<int>& nextVisit)
    {
        const int MOD = 1e9 + 7;
        int ans = 0;
        int sz1 = nextVisit.size();
        vector<int> vi(sz1, 0);
        // vector<bool> vcntodd(sz1, false);
        vector<pair<int, int>> vpii(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            vpii[i].first = -1;
        }

        int t2 = 0;
        for (int i = 0; i < sz1 - 1; ++i)
        {
            // must odd
            t2 = 2;  // 2步， 奇数，从i跳到 nextVisit[i]，  偶数次，从i 跳到 i+1
            for (int st = nextVisit[i]; st < i; ++st)   // 从 nextVisit 跳到 i
            {
                if (vpii[st].first == -1)
                {
                    // 还在 st
                    t2 = (t2 + vi[st]) % MOD;
                    // 在 st + 1 ， 所以 st<i, 就可以跳到 i 上。
                }
                else
                {
                    t2 = (t2 + vpii[st].second) % MOD;
                    st = vpii[st].first;
                }
            }
            vi[i] = t2;
            vpii[nextVisit[i]].first =  i;
            vpii[nextVisit[i]].second = t2;

#ifdef __test
            std::cout<<nextVisit[i]<<"->"<<i<<", "<<t2<<std::endl;
#endif

            ans = (ans + t2) % MOD;
        }

#ifdef __test
        showVectorInt(vi);
#endif
        return ans;
    }

    // tle

    // room  0 - n-1
    // day 0 - INT_MAX
    //
    // ++cnt_this_room, if odd { next day, visit <= room number that is nextVisit }
    //      even, next is (i+1)mod n
    // nextVisit[i] <= i
    // 感觉以前感觉看过，但是我不知道了。 反正肯定是dp了。
    // [sz1][2]  偶数达到，奇数到达，
    // 当我到达 x的时候， <x 的 room 应该全是 偶数次 吧。 所以 可以 dp， 不然  我是奇数次，但是前面有些偶数，有些奇数， 要追踪状态，这不太可能。
    // 所以 第1次，第3,5,7次 进入， 消耗的时间 是相同的。   第2,4,6,消耗一天。
    // 但是 感觉 还是得 n^2 啊， 因为 退回去后，还是得一步步 走过来。  类似跳表？ 先不用试下。
    int firstDayBeenInAllRooms____tle(vector<int>& nextVisit)
    {
        const int MOD = 1e9 + 7;
        int ans = 0;
        int sz1 = nextVisit.size();
        vector<int> vi(sz1, 0);
        vector<bool> vcntodd(sz1, false);
        int t2 = 0;
        for (int i = 0; i < sz1 - 1; ++i)
        {
            // must odd
            t2 = 2;  // 2步， 奇数，从i跳到 nextVisit[i]，  偶数次，从i 跳到 i+1
            for (int st = nextVisit[i]; st < i; ++st)
            {
                t2 = (t2 + vi[st]) % MOD;
            }
            vi[i] = t2;
            ans = (ans + t2) % MOD;
        }

#ifdef __test
        showVectorInt(vi);
#endif
        return ans;
    }

};

int main()
{

    LT1997 lt;

    // myvi v = {0,1,2,0};
    myvi v = {0,0,0,0,0,0,0,0,0,9,1,8};     // 2048

    std::cout<<lt.firstDayBeenInAllRooms(v)<<std::endl;

    return 0;
}
