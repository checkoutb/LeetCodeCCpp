
#include "../header/myheader.h"

class LT1906
{
public:

// D


//int cnt[100001][101] = {};
//    for (int i = 0; i < nums.size(); ++i)
//        for (int j = 1; j <= 100; ++j)
//            cnt[i + 1][j] = cnt[i][j] + (nums[i] == j);
//    for (int i = 0; i < qs.size(); ++i) {
//        int prev = 0, delta = INT_MAX;
//        for (int j = 1; j <= 100; ++j)
//            if (cnt[qs[i][1] + 1][j] - cnt[qs[i][0]][j]) {
//                delta = min(delta, prev == 0 ? INT_MAX : j - prev);
//                prev = j;
//            }
//        res.push_back(delta == INT_MAX ? -1 : delta);
//    }
// prefix sum,是指 个数的和。  这样的话， 减去 就知道 这个区间内 这个数有多少个了。。


//    vector<int> res, idx[101];
//    for (int i = 0; i < nums.size(); ++i)
//        idx[nums[i]].push_back(i);
//    for (int i = 0; i < qs.size(); ++i) {
//        int prev = 0, delta = INT_MAX;
//        for (int j = 1; j <= 100; ++j) {
//            auto it = lower_bound(begin(idx[j]), end(idx[j]), qs[i][0]);
//            if (it != end(idx[j]) && *it <= qs[i][1]) {
//                delta = min(delta, prev == 0 ? INT_MAX : j - prev);
//                prev = j;
//            }
//        }
//        res.push_back(delta == INT_MAX ? -1 : delta);
//    }
// 数及 所有下标。
// 对所有数[1,100]遍历， 看这个数是否有 下标 在 query 中。


// 。。。



// g

// 难道真的靠缓存？


// tle。。。 比a还慢。。
// 或者直接dp。
    vector<int> lt1906b(vector<int>& nums, vector<vector<int>>& queries)
    {
        int sz1 = nums.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));
        vector<int> ans(queries.size());
//        vector<int> vi(101, 0);
        set<int> set2;
        for (int i = 0; i < sz1; ++i)
        {
            set2.insert(nums[i]);
            int t2 = 10000;
            for (int j = i + 1; j < sz1; ++j)
            {
                set2.insert(nums[j]);
                set<int>::iterator it1 = set2.find(nums[j]);
                set<int>::iterator it3 = std::next(it1);
                if (it3 != end(set2))
                {
                    t2 = min(t2, *it3 - nums[j]);
                }
                if (it1 != begin(set2))
                {
                    set<int>::iterator it2 = std::prev(it1);
                    t2 = min(t2, nums[j] - *it2);
                }
                vvi[i][j] = t2 == 10000 ? -1 : t2;
            }
            set2.clear();
        }
        for (int i = 0; i < queries.size(); ++i)
        {
            ans[i] = vvi[queries[i][0]][queries[i][1]];
        }
        return ans;
    }


// tle...
// How does the maximum value being 100 help us?
//      使用size==1的桶排序。
// 唯一不清楚的就是需不需要缓存。缓存吃内存，不缓存觉得tle。。缓存的话map<startIndex, map<endIndex, vector<int>(101)>> 好像也没有太大用，需要start一样才能生效。。不，可以碰到以后就使用。
//          并且 由于重复无所谓的，所以还能。。
    vector<int> lt1906a(vector<int>& nums, vector<vector<int>>& queries)
    {
//        std::fill()
        vector<int> vi(101);            // bool
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i)
        {
            int st = queries[i][0];
            int en = queries[i][1];
            int mx = -1;
            int mn = 1000;
            std::fill(begin(vi), end(vi), 0);
            for (int j = st; j <= en; ++j)
            {
                vi[nums[j]] = 1;
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
            }
            int t2 = mn;
            int a = 10000;
            for (int j = mn + 1; j <= mx; ++j)
            {
                if (vi[j] == 1)
                {
                    a = min(a, (j - t2));
                    t2 = j;
                }
            }
            ans.push_back(a == 10000 ? -1 : a);
        }
        return ans;
    }

};

int main()
{
    myvi v = {1,3,4,8};
    myvvi vv = {{0,1},{1,2},{2,3},{0,3}};

//    myvi v = {4,5,2,2,7,10};
//    myvvi vv = {{2,3},{0,2},{0,5},{3,5}};

    LT1906 lt;

    myvi vi = lt.lt1906b(v, vv);

    showVectorInt(vi);

    return 0;
}
