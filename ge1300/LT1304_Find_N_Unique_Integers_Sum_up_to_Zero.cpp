
#include "../header/myheader.h"

class LT1304
{
public:

// D D

//        for (int i = 0; i < n; ++i)
//            A[i] = i * 2 - n + 1;

//    for (int i = 1; i < n; i++) {
//        a[i] = i;
//        a[0] -= i;
//    }
// 出乎意料。


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find N Unique Integers Sum up to Zero.
//Memory Usage: 7.1 MB, less than 21.01% of C++ online submissions for Find N Unique Integers Sum up to Zero.
    vector<int> lt1304a(int n)
    {
        vector<int> ans(n);
        int t2 = (n % 2 == 1) ? 1 : -1;
        for (int i = 1; i < n; i += 2)
        {
            ans[i] = i;
            ans[i + t2] = (-i);
        }
        return ans;
    }

};

int main()
{

    vector<int> v = {5,3,1,2};

    LT1304 lt;

    for (int i : v)
    {
        vector<int> vi = lt.lt1304a(i);
        showVectorInt(vi);
    }

    return 0;
}
