
#include "../header/myheader.h"

class LT2178
{
public:

// D D




//Runtime: 152 ms, faster than 96.49% of C++ online submissions for Maximum Split of Positive Even Integers.
//Memory Usage: 40.6 MB, less than 52.07% of C++ online submissions for Maximum Split of Positive Even Integers.
// 不重复偶数
// 。。。 数学题。。 2，4，6，8  然后 多余的放到最后一个上 就是 最多的。。。
// (2+n)*(n/2)/2 < sum
// n^2 + 2n < 4sum
// n^2 + 2n - 4sum
// (-2 + sqrt(4 + 16sum)) / 2  ... 直接啊。都要return的。。
    vector<long long> lt2178a(long long finalSum)
    {
        vector<long long> ans;
        if (finalSum & 1)
            return ans;
        long long t2 = 2;
        while (finalSum >= t2)
        {
            ans.push_back(t2);
            finalSum -= t2;
            t2 += 2;
        }
        ans[ans.size() - 1] += finalSum;
        return ans;
    }

};

int main()
{

    LT2178 lt;


    return 0;
}
