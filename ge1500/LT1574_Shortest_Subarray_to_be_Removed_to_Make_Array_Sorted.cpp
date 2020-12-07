
#include "../header/myheader.h"

class LT1574
{
public:


// D D

//        while(j - 1 >= 0 && arr[j] >= arr[j-1]) j--;
//
//        int x = j;
//        int right = j;
//        for(int i = 0; i < j; i++) {
//            if(i > 0 && arr[i] < arr[i-1]) break;
//            while(right < arr.size() && arr[right] < arr[i]) right++;
//
//            x = min(x, right - i - 1);
//        }


//    const int n = std::size(arr);
//
//    auto make_forward = [](auto x) { return (--x.base()); };
//
//    const int L = --std::is_sorted_until(std::begin(arr), std::end(arr), std::less<>{}) - std::begin(arr);
//    const int R = ++make_forward(std::is_sorted_until(std::rbegin(arr), std::rend(arr), std::greater<>{})) - std::begin(arr);
//
//    auto lst_leq = [&]<typename T>(const std::vector<T>& A, int ll, int rr, T x) {
//      std::optional<int> acc = {};
//      for (auto [lo, hi] = std::pair{ll, rr}; lo <= hi; NULL) {
//        const int mid = lo + (hi - lo) / 2;
//        if (A[mid] <= x) {
//          acc.emplace(mid);
//          lo = mid + 1;
//        }
//        else {
//          hi = mid - 1;
//        }
//      }
//      return acc;
//    };
//
//    auto fst_geq = [&]<typename T>(const std::vector<T>& A, int ll, int rr, T x) {
//      std::optional<int> acc = {};
//      for (auto [lo, hi] = std::pair{ll, rr}; lo <= hi; NULL) {
//        const int mid = lo + (hi - lo) / 2;
//        if (A[mid] >= x) {
//          acc.emplace(mid);
//          hi = mid - 1;
//        }
//        else {
//          lo = mid + 1;
//        }
//      }
//      return acc;
//    };
//
//    auto solve_splitted = [&]() {
//      struct {
//        mutable int i;
//        mutable int j;
//        mutable int acc;
//      } state {.i = 0, .j = R, .acc = std::max(n - R, L)};
//
//      for (auto &[i, j, acc] = state; i <= L or j <= n - 1; ) {
//        if (i <= L and j >= n) {
//          acc = std::max(acc, i + 1);
//          ++i;
//        }
//        else if (i > L and j < n) {
//          acc = std::max(acc, L + n - j);
//          ++j;
//        }
//        else if (arr[i] <= arr[j]) {
//          acc = std::max(acc, n - j + i + 1);
//          i = lst_leq(arr, i + 1, L, arr[j]).value_or(i + 1);
//        }
//        else if (arr[i] > arr[j]) {
//          j = fst_geq(arr, j + 1, n - 1, arr[i]).value_or(n);
//        }
//      }
//      return n - state.acc;
//
//      return std::min({n - state.acc, R, n - L});
//    };
//
//
//    auto solve = [&]() {
//      if (L == n - 1) {
//        return 0;
//      }
//      else {
//        return solve_splitted();
//      }
//    };
//
//    return solve();
//  }


//    int sz = n.size(), r = sz - 1;
//    for (; r > 0 && n[r - 1] <= n[r]; --r) ;
//    auto res = r;
//    for (int l = 0; l < r && (l == 0 || n[l - 1] <= n[l]); ++l) {
//        while (r < sz && n[r] < n[l])
//            ++r;
//        res = min(res, r - l - 1);
//    }


//    int sz = n.size(), r = sz - 1;
//    for (; r > 0 && n[r - 1] <= n[r]; --r) ;
//    auto res = r;
//    for (int l = 0; l < r && (l == 0 || n[l - 1] <= n[l]); ++l) {
//        while (r < sz && n[r] < n[l])
//            ++r;
//        res = min(res, r - l - 1);
//    }


//https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/discuss/830480/C%2B%2B-O(N)-Sliding-window-Explanation-with-Illustrations


// 200 - 260 ms.
//Runtime: 316 ms, faster than 5.23% of C++ online submissions for Shortest Subarray to be Removed to Make Array Sorted.
//Memory Usage: 67.5 MB, less than 9.91% of C++ online submissions for Shortest Subarray to be Removed to Make Array Sorted.
    int lt1574a(vector<int>& arr)
    {
        int sz1 = arr.size();
        int i = sz1 - 2;
        for (; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                break;
            }
        }
        if (i < 0)
            return 0;
        int t2 = i + 1;
        vector<int> vi(arr.begin() + i + 1, arr.end());

        #ifdef __test
        showVectorInt(vi);
        cout<<t2<<endl;
        #endif // __test

//        int ans = INT_MAX;
        int ans = t2;
        for (i = 0; i < sz1; i++)
        {
            if (i > 0)
            {
                if (arr[i] < arr[i - 1])
                {
                    break;
                }
            }
            int val = arr[i];
            vector<int>::iterator it = std::lower_bound(begin(vi), end(vi), val);
            if (it == end(vi))
            {
                ans = min(ans, sz1 - i - 1);
//                cout<<ans<<endl;
            }
            else
            {
                ans = min(ans, (int) std::distance(begin(vi), it) + t2 - i - 1);
            }

//            int dis = std::distance(begin(arr), std::lower_bound(begin(arr), end(arr), val));
//            ans = min(ans, t2 - i + dis - 2);
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,2,3,10,4,2,3,5};
//    myvi v = {5,4,3,2,1};
//    myvi v = {1,2,3};
//    myvi v = {1};

    myvi v = {16,10,0,3,22,1,14,7,1,12,15};         // 8

    LT1574 lt;

    cout<<lt.lt1574a(v)<<endl;

    return 0;
}
