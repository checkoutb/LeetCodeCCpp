
#include "../header/myheader.h"

class LT1438
{
public:

// D D

// 2个 deque 最快，    170ms
// 1个 multiset       420ms

//        int i = 0, j;
//        multiset<int> m;
//        for (j = 0; j < A.size(); ++j) {
//            m.insert(A[j]);
//            if (*m.rbegin() - *m.begin() > limit)
//                m.erase(m.find(A[i++]));
//        }
//        return j - i;
// m差不多是一个窗口，按大小有序，  >limit时，说明 不满足了。
// if。。。 还有  return j-i。。。。   这2个配合在一起，就对了。 因为每次i/j都只移动一个，所以窗口只会越来越大，所以能直接 j-i。。。
// multiset是必须的，因为移除max后，可以通过multiset直接获得现在的max。

//        deque<int> maxd, mind;
//        int i = 0, j;
//        for (j = 0; j < A.size(); ++j) {
//            while (!maxd.empty() && A[j] > maxd.back()) maxd.pop_back();
//            while (!mind.empty() && A[j] < mind.back()) mind.pop_back();
//            maxd.push_back(A[j]);
//            mind.push_back(A[j]);
//            if (maxd.front() - mind.front() > limit) {
//                if (maxd.front() == A[i]) maxd.pop_front();
//                if (mind.front() == A[i]) mind.pop_front();
//                ++i;
//            }
//        }
//        return j - i;
// 2个deque 代替 multiset。
// maxd 是desc， mind是asc。   所以maxd.front 是 区间最大值。
// 当不满足时，就移动i，并且如果i是 最大/最小，就从 队列中移除。


//Runtime: 584 ms, faster than 13.14% of C++ online submissions for Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.
//Memory Usage: 47.8 MB, less than 100.00% of C++ online submissions for Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.
    int lt1438a(vector<int>& nums, int limit)
    {
        int ans = 0;
        int mx = 0;
        int mn = INT_MAX;
        for (int i = 0; i < nums.size() - ans; ++i)
        {
            mx = 0;
            mn = INT_MAX;
            for (int j = i; j < nums.size(); ++j)
            {
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
                if (mx - mn > limit)
                {
                    ans = max(j - i, ans);
                    break;
                }
            }
            if (mx - mn <= limit)
                ans = max(int (nums.size())- i, ans);
        }
        return ans;
    }

};

int main()
{
//    vector<int> v = {8,2,4,7};
//    int k{4};
    vector<int> v = {10,1,2,4,7,2};
    int k{5};

    LT1438 lt;

    cout<<lt.lt1438a(v, k);

    return 0;
}
