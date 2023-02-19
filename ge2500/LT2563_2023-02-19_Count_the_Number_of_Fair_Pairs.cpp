
#include "../header/myheader.h"


struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

class LT2563
{
public:

    // D D

    //long long countLess(vector<int>& nums, int val) {
    //    long long res = 0;
    //    for (int i = 0, j = nums.size() - 1; i < j; ++i) {
    //        while (i < j && nums[i] + nums[j] > val)
    //            --j;
    //        res += j - i;
    //    }
    //    return res;
    //}
    //long long countFairPairs(vector<int>& nums, int lower, int upper) {
    //    sort(begin(nums), end(nums));
    //    return countLess(nums, upper) - countLess(nums, lower - 1);
    //}
    //
    // 多少种pair 可以 sum <= upper。 多少种pair 可以 sum < lower


    //sort(beg, end);
    //for (int i = 0; i < nums.size() - 1; ++i) {
    //    ans += upper_bound(beg + i + 1, end, upper - nums[i]) - lower_bound(beg + i + 1, end, lower - nums[i]);
    //}



    //Runtime179 ms
    //    Beats
    //    86.58 %
    //    Memory56.5 MB
    //    Beats
    //    17.52 %
    //.....related topic : sort, 2 pointer......  lt2563b之前就看了， 但是没有想法。主要是 sort 会打乱顺序。
    long long lt2563c(vector<int>& nums, int lower, int upper)
    {
        int sz1 = nums.size();
        sort(begin(nums), end(nums));
        int st = sz1 - 1;
        int en = sz1 - 1;
        long long ans = 0LL;
        for (int i = 0; i < sz1; ++i)
        {
            //if ((nums[i] << 1) > upper)       // if negative
            //    break;

            while (st > i && (nums[i] + nums[st]) >= lower)
                --st;

            while (en > i && (nums[i] + nums[en]) > upper)
                --en;

            st = max(st, i);
            en = max(en, i);

            ans += (en - st);

        }
        return ans;
    }


    // ... sz = 20 0000 0000
    //long long lt2563b(vector<int>& nums, int lower, int upper)
    //{
    //    int sz1 = nums.size();
    //    long long ans = 0LL;
    //    FenwickTree ft(sz)
    //}


    // tle
    // BIT? range count
    // nlogn
    long long lt2563a(vector<int>& nums, int lower, int upper)
    {
        int sz1 = nums.size();
        long long ans = 0LL;

        vector<int> vi(1, nums[sz1 - 1]);

        for (int i = sz1 - 2; i >= 0; --i)
        {
            vector<int>::iterator it1 = std::lower_bound(begin(vi), end(vi), lower - nums[i]);
            if (it1 != vi.end())
            {
                vector<int>::iterator it2 = std::upper_bound(begin(vi), end(vi), upper - nums[i]);
                ans += std::distance(it1, it2);
            }
            it1 = std::lower_bound(begin(vi), end(vi), nums[i]);
            if (it1 == end(vi))
                vi.push_back(nums[i]);
            else
                vi.insert(it1, nums[i]);
        }
        return ans;
    }

};

int main()
{

    LT2563 lt;

    myvi v = { 0,1,7,4,4,5 };
    int l{ 3 }, u(6);

    //myvi v = { 1,7,9,2,5 };
    //int l{ 11 }, u(11);

    cout << lt.lt2563c(v, l, u) << endl;

    return 0;
}
