
#include "../header/myheader.h"

class LT0509
{
public:


// d && d
// 数组。。。。
// 还有直接计算，就是3个变量 互相+ N次。。


//Runtime: 4 ms, faster than 66.15% of C++ online submissions for Fibonacci Number.
//Memory Usage: 8.9 MB, less than 5.97% of C++ online submissions for Fibonacci Number.

// recursiona1 中没有第二个 if时。。但是map2[n] = val 还在。。
//Runtime: 108 ms, faster than 14.93% of C++ online submissions for Fibonacci Number.
//Memory Usage: 8.7 MB, less than 5.97% of C++ online submissions for Fibonacci Number.

    int lt0509a(int N)
    {
        unordered_map<int, int> map2;
        return recursiona1(N, map2);
    }

    int recursiona1(int n, unordered_map<int, int>& map2)
    {
        if (n == 0 || n == 1)
            return n;
        if (map2.find(n) != map2.end())
            return map2[n];
        int val = recursiona1(n - 1, map2) + recursiona1(n - 2, map2);
        map2[n] = val;
        return val;
    }
};

int main()
{
    int i = 30;

    LT0509 lt;
    cout<<lt.lt0509a(i)<<endl;

    return 0;
}
