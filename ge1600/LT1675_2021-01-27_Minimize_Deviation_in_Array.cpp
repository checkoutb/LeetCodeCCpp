
#include "../header/myheader.h"

class LT1675
{
public:

// D D

//        set<int> s;
//        for (int &a : A)
//            s.insert(a % 2 ? a * 2 : a);
//        int res = *s.rbegin() - *s.begin();
//        while (*s.rbegin() % 2 == 0) {
//            s.insert(*s.rbegin() / 2);
//            s.erase(*s.rbegin());
//            res = min(res, *s.rbegin() - *s.begin());
//        }
//        return res;
// 如果最大是偶数，那么可以/2,
// 先把 奇数 * 2了， 这样，所有的数，都只能降低，不能提高。 所以只需要处理 尾巴上的偶数。 。 还有，[990,1000] 这种会变成[495,500] 还能继续变 ，所以每次都需要min。


//    int res = INT_MAX, min_n = INT_MAX;
//    priority_queue<int> pq;
//    for (auto n : nums) {
//        n = n % 2 ? n * 2 : n;
//        pq.push(n);
//        min_n = min(min_n, n);
//    }
//    while (pq.top() % 2 == 0) {
//        res = min(res, pq.top() - min_n);
//        min_n = min(min_n, pq.top() / 2);
//        pq.push(pq.top() / 2);
//        pq.pop();
//    }
//    return min(res, pq.top() - min_n);


//    int res = INT_MAX, min_n = INT_MAX;
//    for (int i = 0; i < n.size(); ++i) {
//        n[i] = n[i] % 2 ? n[i] * 2 : n[i];
//        min_n = min(min_n, n[i]);
//    }
//    make_heap(begin(n), end(n));
//    while (n[0] % 2 == 0) {
//        res = min(res, n[0] - min_n);
//        min_n = min(min_n, n[0] / 2);
//        pop_heap(begin(n), end(n));
//        n.back() /= 2;
//        push_heap(begin(n), end(n));
//    }
//    return min(res, n[0] - min_n);



//Runtime: 788 ms, faster than 54.98% of C++ online submissions for Minimize Deviation in Array.
//Memory Usage: 140.6 MB, less than 5.49% of C++ online submissions for Minimize Deviation in Array.
// 奇数 -> {奇数，奇数*2}
// 偶数 -> {偶数，/2./4./8 ... 奇数}
    int lt1675a(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<vector<int>> vvi(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = nums[i];
            while (t2 % 2 == 0)
                t2 /= 2;

            while (t2 <= nums[i])
            {
                vvi[i].push_back(t2);
                t2 *= 2;
            }
            if (nums[i] % 2 == 1)
                vvi[i].push_back(nums[i] * 2);

//            int t2 = nums[i];
//            if (t2 % 2 == 0)
//            {
//
//            }
//            else
//            {
//
//            }

//            vvi[i].push_back(nums[i]);
//            int t2 = nums[i];
//            while (t2 % 2 == 0)
//            {
//                vvi[i].push_back(nums[i]);
//            }

//            if (nums[i] % 2 == 0)
//            {
//                int t2 = nums[i];
//                while (t2 % 2 == 0)
//                {
//                    t2 /= 2;
//                    vvi[i].push_back(t2);
//                }
//            }
//            else
//            {
//                vvi[i].push_back(nums[i] * 2);
//            }
        }
        #ifdef __test
        for (myvi& v : vvi)
        {
            for (int i : v)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        for (int i = 0; i < vvi[0].size(); ++i)
        {
            dfsa1(vvi, 1, vvi[0][i], vvi[0][i]);
        }
        return ans;
    }
    int ans = INT_MAX;
    void dfsa1(vector<vector<int>>& vvi, int idx, int mn, int mx)
    {
        #ifdef __test
        cout<<mx<<" - "<<mn<<", "<<ans<<endl;
        #endif // __test
        if ((mx - mn) >= ans)
            return;
        if (idx == vvi.size())
        {
            ans = min(ans, mx - mn);
            return;
        }
        for (int i = 0; i < vvi[idx].size(); ++i)
        {
            if (vvi[idx][i] >= mn && vvi[idx][i] <= mx)
            {
                dfsa1(vvi, idx + 1, mn, mx);
                return;
            }
        }
        if (vvi[idx][vvi[idx].size() - 1] < mn)                 // .
        {
            dfsa1(vvi, idx + 1, vvi[idx][vvi[idx].size() - 1], mx);
        }
        else
        {
            for (int i = 0; i < vvi[idx].size(); ++i)
            {
                if (vvi[idx][i] >= mn)
                {
                    if (i > 0)
                    {
                        dfsa1(vvi, idx + 1, vvi[idx][i - 1], mx);
                    }
                    break;
                }
            }
        }
        // lower_bound ...upper_
        for (int i = 0; i < vvi[idx].size(); ++i)
        {
            if (vvi[idx][i] >= mx)
            {
                dfsa1(vvi, idx + 1, mn, vvi[idx][i]);
                break;
            }
        }
    }

};

int main()
{
//    myvi v = {1,2,3,4};
//    myvi v = {4,1,5,20,3};
//    myvi v = {2,10,8};
    myvi v = {9,4,3,6,2};

    LT1675 lt;

    cout<<lt.lt1675a(v);

    return 0;
}
