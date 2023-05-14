
#include "../header/myheader.h"

class LT2659
{
public:



/*

3 4 1
413
134
34
4

1-2
3-0
4-1

有序的第几大
原始的第几大。 小于


21403

01234
00202


。。。
range op?


相对距离？

(循环)向前，比自己大的，直到最小值。不 直到小于自己的最大的。

range query.
计算自己的下标，和小于自己的最大的下标 之间有多少 已经 remove 了。 这个计算用 BIT 之类的。
然后把自己remove掉。 然后继续。

*/

//Runtime299 ms
//Beats
//92.31%
//Memory76.3 MB
//Beats
//76.92%
    long long lta(vector<int>& nums)
    {
        int sz1 = nums.size();
        FenwickTree ft(sz1);

        vector<pair<int, int>> vp(sz1);

        for (int i = 0; i < sz1; ++i)
        {
            vp[i].first = nums[i];
            vp[i].second = i;
        }
        std::sort(std::begin(vp), end(vp));

        int lst = vp[0].second;
        long long ans = lst;
        ft.add(lst, 1);
        for (int i = 1; i < sz1; ++i)
        {
            int t2 = vp[i].second;
            if (lst < t2)
            {
                ans += t2 - lst - 1 - ft.sum(lst + 1, t2 - 1);
            }
            else
            {
                ans += t2 + sz1 - lst - 1 - ft.sum(t2 - 1) - ft.sum(lst + 1, sz1 - 1);
            }

            lst = t2;
            ft.add(lst, 1);
        }

        return ans + sz1;
    }

    struct FenwickTree
    {
        vector<int> bit;
        int n;

        FenwickTree(int n)
        {
            this->n = n;
            this->bit.assign(n, 0);
        }
        int sum(int r)
        {
            int ans = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1)
                ans += bit[r];
            return ans;
        }
        int sum(int l, int r)
        {
            if (l > r)
                return 0;
            return sum(r) - sum(l - 1);
        }
        void add(int idx, int delta)
        {
            for (; idx < n; idx = idx | (idx + 1))
                bit[idx] += delta;
        }
    };

};

int main()
{

    LT2659 lt;

    //myvi v = {3,4,-1};
    //myvi v = {1,2,4,3};
    myvi v = {1,2,3};

    cout<<lt.lta(v)<<endl;

    return 0;
}
