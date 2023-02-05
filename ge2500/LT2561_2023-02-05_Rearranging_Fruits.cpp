
#include "../header/myheader.h"

class LT2561
{
public:


    // g


    // ... 用 最小值 作为 交换的代价。。 而不是 取 2个diff。
    long long lt2561a(vector<int>& basket1, vector<int>& basket2)
    {
        int sz1 = basket1.size();
        long long ans = 0LL;

        map<int, long long> map2;
        map<int, long long> map3;
        map<int, long long> map4;
        for (int i = 0; i < sz1; ++i)
        {
            ++map2[basket1[i]];
            ++map2[basket2[i]];

            ++map3[basket1[i]];

            ++map4[basket2[i]];
        }

        long long total = 0LL;
        for (auto& p : map2)
        {
            if (p.second % 2LL == 1LL)
                return -1LL;

            total += abs(p.second / 2 - map3[p.first]);
        }

        for (auto& [cst, cnt] : map2)
        {
            if (total == 0LL)
                break;

            long long cnt2 = map3[cst];
            if (cnt2 * 2 == cnt)
                continue;

            cnt2 = cnt / 2 - cnt2;
            if (cnt2 < 0)
                cnt2 = -cnt2;

            if (cnt2 * 2 > total)
            {
                cnt2 = total / 2;

                total = 0LL;
            }
            else
            {
                total -= cnt2 * 2;
            }

            ans += 1LL * cst * cnt2;

        }

        return ans;
    }

};

int main()
{

    LT2561 lt;

    //myvi v = { 2,2,2,4 };
    //myvi v2 = { 1,1,2,4 };

    //myvi v = { 2,3,4,1 };
    //myvi v2 = { 1,2,3,5 };

    myvi v = { 84,80,43,8,80,88,43,14,100,88 };
    myvi v2 = { 32,32,42,68,68,100,42,84,14,8 };

    cout << lt.lt2561a(v, v2) << endl;

    return 0;
}
