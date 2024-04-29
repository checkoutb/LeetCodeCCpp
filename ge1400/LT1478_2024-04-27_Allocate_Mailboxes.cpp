
#include "../header/myheader.h"

class LT1478
{
public:

    // D D



// Runtime
// 35ms
// Beats22.73%of users with C++
// Memory
// 9.94MB
// Beats58.79%of users with C++

    // < 100
    // 最小时， mailbox 肯定可以在 house上，  就是在 2个house中间的话，移动到 任意一个house上， 距离不变的。 所以只需要考虑 mailbox 在 house 上的 情况。    硬写dp啊。 但 怎么写？ bs？no

    // hint 1 & 2
    int minDistance(vector<int>& houses, int k)
    {
        std::ranges::sort(houses);
        int sz1 = houses.size();
        vector<int> vi(sz1, INT_MAX >> 1);

        for (int i = 1; i <= k; ++i)
        {
            vector<int> v2(sz1, INT_MAX >> 1);

            for (int j = sz1 - i; j >= 0; --j)
            {
                for (int k = j; k <= sz1 - i; ++k)
                {
                    v2[j] = min(v2[j], mndis(houses, j, k) + (k + 1 >= sz1 ? 0 : vi[k + 1]));
                }
            }
#ifdef __test
            showVectorInt(v2);
#endif
            swap(vi, v2);
        }
        return vi[0];
    }

    int mndis(vector<int>& houses, int st, int en)
    {
        int md = (st + en) / 2;
        int t2 = houses[md];
        int ans = 0;
        for (int i = st; i <= en; ++i)
        {
            ans += abs(houses[i] - t2);
        }
#ifdef __test
        cout<<st<<" - "<<en<<", "<<ans<<endl;
#endif
        return ans;
    }
};

int main()
{

    LT1478 lt;

    myvi v {1,4,8,10,20};
    int k {3};

    cout<<lt.minDistance(v, k);

    return 0;
}
