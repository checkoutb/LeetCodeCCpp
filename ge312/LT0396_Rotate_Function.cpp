
#include "../header/myheader.h"

class LT0396
{
public:


//Runtime: 8 ms, faster than 96.50% of C++ online submissions for Rotate Function.
//Memory Usage: 9.7 MB, less than 26.15% of C++ online submissions for Rotate Function.

// [INT_MAX, INT_MAX]..... 还有点。。LeetCode是64位的，所以long是可以的。


    // 差
    int lt0396a(vector<int>& A)
    {
        long long sz1 = A.size();
        long long sum2 = 0;
        long long sum1 = 0;
        int i = 0;
        for (int a : A)
        {
            sum1 += (a * i);
            sum2 += a;
            i++;
        }

        #ifdef __test
        cout<<sum1<<", "<<sum2<<endl;
        #endif // __test

        int ans = sum1;
        i = sz1 - 1;
        int t1 = sum1;
        for (; i > 0; i--)
        {
            t1 += (sum2 - A[i] * sz1);

            #ifdef __test
            cout<<t1<<endl;
            #endif // __test

            ans = max(t1, ans);
        }
        return ans;
    }
};

int main()
{
//    vector<int> a = {4,3,2,6};
    vector<int> a = {INT_MAX, INT_MAX};

    LT0396 lt;
    cout<<lt.lt0396a(a)<<endl;

    return 0;
}
