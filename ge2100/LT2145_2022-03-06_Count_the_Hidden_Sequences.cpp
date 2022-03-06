
#include "../header/myheader.h"

class LT2145
{
public:

// D D

//    long long left = 0, right = 0, cur = 0;
//    for (int d : diff) {
//        cur += d;
//        left = min(left, cur);
//        right = max(right, cur);
//    }
//    return max(0LL, upper - lower - (right - left) + 1);


//Runtime: 211 ms, faster than 76.35% of C++ online submissions for Count the Hidden Sequences.
//Memory Usage: 106.7 MB, less than 34.50% of C++ online submissions for Count the Hidden Sequences.
// 就是 跨度？
    int lt2145a(vector<int>& differences, int lower, int upper)
    {
        long mx = 0, mn = 0, val = 0;
        for (int i = 0; i < differences.size(); ++i)
        {
            val += differences[i];
            mx = max(mx, val);
            mn = min(mn, val);
        }
        int len2 = mx - mn;
        int len3 = upper - lower;
        return len3 >= len2 ? len3 - len2 + 1 : 0;
    }

};

int main()
{

    LT2145 lt;


    return 0;
}
