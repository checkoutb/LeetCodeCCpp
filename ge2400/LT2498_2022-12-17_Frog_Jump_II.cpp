
#include "../header/myheader.h"

class LT2498
{
public:

    // D D

    //return max(st[1] - st[0],
    //    transform_reduce(begin(st) + 2, end(st), begin(st), 0,
    //        [](int a, int b) { return max(a, b); },
    //        [](int i, int j) { return i - j; }));



    // 感觉是，不管如何，都是 隔一个跳，即使 偶数，还是 隔一个跳，最后超越end的时候被拦下来，并且这步 是小于 回程的第一步的，所以无所谓
    // 但是我不知道 为什么不需要 t2。。。
    //Runtime159 ms
    //    Beats
    //    86.32 %
    //    Memory65.4 MB
    //    Beats
    //    68.62 %
    int lt2498a(vector<int>& stones)
    {
        int sz1 = stones.size();

        int ans = stones[1] - stones[0];

        for (int i = 2; i < sz1; ++i)
        {
            ans = max(ans, stones[i] - stones[i - 2]);
        }
        //if (sz1 % 2)
        //{
            return ans;
        //}

        //int t2 = sz1 > 3 ? INT_MAX : -1;
        //for (int i = 3; i < sz1; ++i)
        //{
        //    t2 = min(t2, stones[i] - stones[i - 3]);
        //}
        //return max(ans, t2);
    }

};

int main()
{

    LT2498 lt;


    return 0;
}
