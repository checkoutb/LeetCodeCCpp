
#include "../header/myheader.h"

class LT2488
{
public:

    // D D

    //unordered_map<int, int> cnt;
    //int p = find(begin(n), end(n), k) - begin(n), res = 0;
    //for (int i = p, bal = 0; i < n.size(); ++i) {
    //    bal += n[i] == k ? 0 : n[i] < k ? -1 : 1;
    //    ++cnt[bal];
    //}
    //for (int i = p, bal = 0; i >= 0; --i) {
    //    bal += n[i] == k ? 0 : n[i] < k ? -1 : 1;
    //    res += cnt[-bal] + cnt[-bal + 1];
    //}
    //return res;





    //Runtime380 ms
    //    Beats
    //    37.50 %
    //    Memory61.3 MB
    //    Beats
    //    37.50 %
    // 
    // 找到 k
    // 向 2侧扩展， 计算 大于 k 的 和 小于k 的。
    // 但是怎么扩展。
    // 差值，
    // diff 可以知道 odd even的。。不需要vi。。
    int lt2488a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int idxk = -1;
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] == k)
            {
                idxk = i;
                break;
            }
        }

        // <diff, <even length count, odd>>
        // < idxk
        unordered_map<int, vector<int>> map2;

        unordered_map<int, vector<int>> map3;

        int cnt = 0;        // > - <
        for (int i = idxk - 1; i >= 0; --i)
        {
            if (nums[i] > k)
            {
                ++cnt;
            }
            else
            {
                --cnt;
            }
            if (map2.find(cnt) == map2.end())
            {
                map2[cnt] = { 0,0 };
            }
            map2[cnt][(idxk - i) % 2]++;        // no k
        }
        if (map2.find(0) == map2.end())     // empty
            map2[0] = { 0,0 };
        map2[0][0]++;

        cnt = 0;        // < - >
        for (int i = idxk + 1; i < sz1; ++i)
        {
            cnt += nums[i] > k ? -1 : 1;
            if (map3.find(cnt) == map3.end())
                map3[cnt] = { 0,0 };
            map3[cnt][(i - idxk) % 2]++;
        }
        if (map3.find(0) == map3.end())
            map3[0] = { 0,0 };
        map3[0][0]++;

        for (auto& [diff, vi] : map2)
        {
            if (map3.find(diff) != map3.end())
            {
                ans += (vi[0] + vi[1]) * (map3[diff][0] + map3[diff][1]);
            }
            if (map3.find(diff - 1) != map3.end())
            {
                ans += (vi[0] + vi[1]) * (map3[diff - 1][0] + map3[diff - 1][1]);
            }
        }
        return ans;
    }

};

int main()
{

    LT2488 lt;

    //myvi v = { 3, 2, 1, 4, 5 };
    //int k = 4;

    myvi v = { 2,3,1 };
    int k = 3;

    cout << lt.lt2488a(v, k) << endl;

    return 0;
}
