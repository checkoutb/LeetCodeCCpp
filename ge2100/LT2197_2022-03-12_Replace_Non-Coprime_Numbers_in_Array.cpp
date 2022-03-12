
#include "../header/myheader.h"

class LT2197
{
public:

// D D

//    list<int> l(begin(nums), end(nums));
//    for (auto it = begin(l); it != end(l); ++it)
//        if (it != begin(l)) {
//            int n1 = *prev(it), n2 = *it;
//            int it_gcd = gcd(n1, n2);
//            if (it_gcd > 1) {
//                l.erase(prev(it));
//                *it = (long long)n1 * n2 / it_gcd;
//                --it;
//            }
//        }
//    return vector<int>(begin(l), end(l));

//        int j = 0, N = A.size();
//        for (int i = 0; i < N; ++i, ++j) {
//            A[j] = A[i];
//            for (; j - 1 >= 0 && gcd(A[j], A[j - 1]) > 1; --j) { // When we can merge leftwards from `A[j]`, keep merging
//                A[j - 1] = (long)A[j] * A[j - 1] / gcd(A[j], A[j - 1]); // replace `A[j-1]` with LCM of `A[j-1]` and `A[j]`.
//            }
//        }
//        A.resize(j);
//        return A;

//        vector<int> res;
//        for (int a: A) {
//            while (true) {
//                int x = __gcd(res.empty() ? 1 : res.back(), a);
//                if (x == 1) break; // co-prime
//                a *= res.back() / x;
//                res.pop_back();
//            }
//            res.push_back(a);
//        }


//Runtime: 366 ms, faster than 32.87% of C++ online submissions for Replace Non-Coprime Numbers in Array.
//Memory Usage: 120.5 MB, less than 94.99% of C++ online submissions for Replace Non-Coprime Numbers in Array.
// 硬算。。。
    vector<int> lt2197a(vector<int>& nums)
    {
        stack<int> stk;
        stk.push(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
        {
            int t3 = nums[i];
            while (!stk.empty())
            {
                int t2 = stk.top();
                int gd = gcda1(max(t2, t3), min(t2, t3));
                if (gd > 1)
                {
                    stk.pop();
                    t3 = 1LL * t2 * t3 / gd;
//                    stk.pop();
//                    stk.push(t2 * t3 / gd);
                }
                else
                {
                    break;
                }
            }
            stk.push(t3);
        }
        vector<int> ans(stk.size());
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            ans[i] = stk.top();
            stk.pop();
        }
        return ans;
    }

    int gcda1(int a, int b)
    {
//        if (a < b)
//            swap(a, b);
        if (b == 0)
            return a;
        return gcda1(b, a % b);
    }

};

int main()
{

    LT2197 lt;


    return 0;
}
