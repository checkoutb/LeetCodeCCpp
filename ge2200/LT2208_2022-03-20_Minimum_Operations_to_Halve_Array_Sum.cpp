
#include "../header/myheader.h"

class LT2208
{
public:

// D D

//    double sum = accumulate(begin(nums), end(nums), 0.0), orig = sum, cnt = 0;
//    priority_queue<double> pq(begin(nums), end(nums));
//    for (; sum * 2 > orig; ++cnt) {
//        double n = pq.top(); pq.pop();
//        sum -= n / 2;
//        pq.push(n / 2);
//    }


//Runtime: 355 ms, faster than 14.29% of C++ online submissions for Minimum Operations to Halve Array Sum.
//Memory Usage: 88.8 MB, less than 14.29% of C++ online submissions for Minimum Operations to Halve Array Sum.
// 贪心，最大的 /2   。。 这个 == half 算不算。。 算。
    int lt2208a(vector<int>& nums)
    {
        priority_queue<double> priq;
        double sum2 = 0;
        for (int i : nums)
        {
            sum2 += i;
            priq.push(i);
        }
        double rm = 0.0;
        double half = sum2 / 2;
        int ans = 0;
        while (rm < half)
        {
            double tp = priq.top();
            priq.pop();
            rm += tp / 2;
            tp /= 2;
            priq.push(tp);
            ans++;
        }
        return ans;
    }

};

int main()
{

    LT2208 lt;

    myvi v = {5,19,8,1};

    cout<<lt.lt2208a(v);

    return 0;
}
