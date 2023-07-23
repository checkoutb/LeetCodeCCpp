
#include "../../header/myheader.h"

class LT6955
{
public:



    // 感觉不太好。这道题是 hard， 6分，  下道题是hard, 8分。。。。。。
    // 每个组 元素 distinct
    //      个数 > 前一个group
    // 每个元素总数不能超过 limit。

    // 2，2，2 。。。。 3


    int maxIncreasingGroups(vector<int>& lmt)
    {
        return -1;
    }


    // AC
    int EEmaxIncreasingGroups(vector<int>& lmt) {
        int sz1 = lmt.size();
        sort(rbegin(lmt), rend(lmt));
        int ans = 0;

        int st = 0;
        int en = sz1 - 1;
        while (st <= en)
        {
            int md = (st + en) / 2;
            bool can = true;

            int t2 = 1;
            long long t3 = 0LL;
            for (int i = sz1 - 1; i >= 0; --i)
            {
                if (i > md)
                {
                    t3 += lmt[i];
                }
                else
                {
                    if (lmt[i] + t3 < t2)
                    {
                        can = false;
                        break;
                    }
                    else
                    {
                        t3 = t3 + lmt[i] - t2;
                    }
                    ++t2;
                }
            }
//            for (int i = md; i >= 0; --i, ++t2)
//            {
//                if (lmt[i] < t2)
//                {
//                    can = false;
//                    break;
//                }
//            }

            if (can)
            {
                ans = max(ans, md + 1);
                st = md + 1;
            }
            else
            {
                en = md - 1;
            }
        }

//        int t2 = INT_MAX;
//        for (int i = 0; i < sz1; ++i)
//        {
//            t2 = min(t2, lmt[i] - i);
//            ans = max(ans, t2);
//        }
        return ans;
    }


    // will tle
    int EEEEmaxIncreasingGroups(vector<int>& lmt)
    {
        int sz1 = usageLimits.size();
        int ans = 0;
        bool can = true;
        while (can)
        {
            sort(rbegin(lmt), rend(lmt));
            while (lmt.back() == 0)
            {
                lmt.pop_back();
            }
            if (lmt.size() > ans)
            {
                ++ans;
                can = true;
                for (int i = 0; i < ans; ++i)
                {

                }
            }
            else
            {
                can = false;    //...break...
            }
        }
        return ans;
    }

};

int main()
{

    LT6955 lt;


    return 0;
}
