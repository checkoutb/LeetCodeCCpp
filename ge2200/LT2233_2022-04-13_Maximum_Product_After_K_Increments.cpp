
#include "../header/myheader.h"

class LT2233
{
public:

// D D


//        sort(begin(A), end(A));
//        long long sum = 0, pos = 0, left = 0, ext, res;
//
//        for(long long i = 0; i < A.size(); i++) {
//            long long req = A[i] * i - sum;
//            if(req <= k) {
//                pos = i;
//                left = k - req;
//            } else break;
//            sum += A[i];
//        }


//    make_heap(begin(nums), end(nums), greater<int>());
//    while (k--) {
//        pop_heap(begin(nums), end(nums), greater<int>());
//        ++nums.back();
//        push_heap(begin(nums), end(nums), greater<int>());
//    }
//    return accumulate(begin(nums), end(nums), 1LL, [](long long res, int n) { return res * n % 1000000007; });



//Runtime: 651 ms, faster than 73.56% of C++ online submissions for Maximum Product After K Increments.
//Memory Usage: 85.9 MB, less than 82.98% of C++ online submissions for Maximum Product After K Increments.
// (a-b)^2 >= 0      a^2 + b^2 >= 2ab       when a==b , a^2 + b^2 == 2ab
// 2*3*4， 2++， +(3*4)     3++, +(2*4)    greedy
    int lt2233a(vector<int>& nums, int k)
    {
        if (nums.size() == 1)
        {
            return nums[0] + k;
        }
        priority_queue<int, vector<int>, std::greater<int>> priq(begin(nums), end(nums));
        while (k > 0)
        {
            int t2 = priq.top();
            priq.pop();
            int t3 = priq.top();
            int t4 = max(1, t3 - t2);
            t4 = min(t4, k);
            k -= t4;
            t2 += t4;
            priq.push(t2);
        }
        long ans = 1L;
        const long MOD = 1e9 + 7;
        while (!priq.empty())
        {
            int t2 = priq.top();
            priq.pop();
            ans = (ans * t2) % MOD;
        }
        return ans;
    }

};

int main()
{

    LT2233 lt;

//    myvi v = {0, 4};
//    int t = 5;

//    myvi v = {6,3,3,2};
//    int t = 2;

    myvi v = {21, 100};
    int t = 58;

    cout<<lt.lt2233a(v, t)<<endl;

    return 0;
}
