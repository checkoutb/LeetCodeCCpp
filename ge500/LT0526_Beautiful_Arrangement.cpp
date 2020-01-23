
#include "../header/myheader.h"

class LT0526
{
public:




// 有个从大数开始，使用swap，来避免vector<bool>。下标从大数开始，那么下标更大的都是使用过的数字.
// 不过好像没用，它得需要一个int数组来保存 数字(通过swap，将用过的数字换到后面去。)。。而不是通过bool数组的下标来表示数字。。

// 素数从大开始？。 D&&D 里没看到。基本都是递归。用 int& i，来传递 结果。



//Runtime: 32 ms, faster than 84.75% of C++ online submissions for Beautiful Arrangement.
//Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Beautiful Arrangement.

    int lt0526a(int N)
    {
        vector<bool> v(N + 1, true);

//        for(bool b : v)
//            cout<<b<<endl;

        int ans = recursiona1(N, v);
        return ans;
    }

    int recursiona1(int i, vector<bool>& v)
    {
        if (i == 1)
        {
            return 1;
        }
        int ans = 0;
        for (int j = 1; j < v.size(); j++)
        {
            if (v[j] && (j % i == 0 || i % j == 0))
            {
                v[j] = false;
                ans += recursiona1(i - 1, v);
                v[j] = true;
            }
        }
        return ans;
    }
};

int main()
{
    int N = 2;

    LT0526 lt;
    cout<<lt.lt0526a(N)<<endl;

    return 0;
}
