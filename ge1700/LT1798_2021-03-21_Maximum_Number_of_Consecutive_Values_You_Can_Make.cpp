
#include "../header/myheader.h"

class LT1798
{
public:

// D D

//        sort(A.begin(), A.end());
//        int res = 1;
//        for (int a: A) {
//            if (a > res) break;
//            res += a;
//        }

//    sort(begin(c), end(c));
//    int max_val = 1;
//    for (auto i = 0; i < c.size() && c[i] <= max_val; ++i)
//        max_val += c[i];



// 很简单，也很难。。
//Runtime: 188 ms, faster than 100.00% of C++ online submissions for Maximum Number of Consecutive Values You Can Make.
//Memory Usage: 66.6 MB, less than 100.00% of C++ online submissions for Maximum Number of Consecutive Values You Can Make.
// hint 1 && 2: 感觉是：sort，前x个能不能组成 coins[x+1]-1 ,如果能，那么也一定能组成 coins[x + 1] * 2 - 1. 就看下一个coins[x+2]是不是在这个范围内。
    int lt1798a(vector<int>& coins)
    {
        int val = 0;
        std::sort(begin(coins), end(coins));
        for (int i = 0; i < coins.size(); ++i)
        {
            if (coins[i] - 1 <= val)
            {
                val += coins[i];
            }
        }
        return val + 1;
    }

};

int main()
{
//    myvi v = {1,1,1,4};
    myvi v = {1,4,10,3,1};

    LT1798 lt;

    cout<<lt.lt1798a(v)<<endl;

    return 0;
}
