
#include "../header/myheader.h"

class LT1953
{
public:

// D D

//        long long sum = accumulate(milestones.begin(), milestones.end(), 0LL);
//        int mx = *max_element(milestones.begin(), milestones.end());
//        if (2 * mx > sum) {
//            sum = (sum-mx) * 2 + 1;
//        }
//        return sum;

//    long long sum = accumulate(begin(m), end(m), 0ll), max = *max_element(begin(m), end(m));
//    return min(sum, 2 * (sum - max) + 1);

//    long sum = IntStream.of(m).asLongStream().sum(), max = IntStream.of(m).max().getAsInt();
//    return Math.min(sum, 2 * (sum - max) + 1);



//Runtime: 128 ms, faster than 50.00% of C++ online submissions for Maximum Number of Weeks for Which You Can Work.
//Memory Usage: 75.5 MB, less than 33.33% of C++ online submissions for Maximum Number of Weeks for Which You Can Work.
// 就是看有没有 一个数 > 其他数的和。
    long long lt1953a(vector<int>& milestones)
    {
//        int mx = *std::max_element(begin(milestones), end(milestones));
//        int sum
        int mx = 0;
        long long sum2 = 0;
        for (int i = 0; i < milestones.size(); ++i)
        {
            mx = max(mx, milestones[i]);
            sum2 += milestones[i];
        }
        long long t2 = sum2 - mx;
        if (t2 >= mx - 1)
        {
            return sum2;
        }
        else
        {
            return t2 * 2 + 1;
        }
    }

};

int main()
{
//    myvi v = {1,2,3};
    myvi v = {5,2,1};

    LT1953 lt;

    cout<<lt.lt1953a(v)<<endl;

    return 0;
}
