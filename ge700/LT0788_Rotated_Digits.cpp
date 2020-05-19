
#include "../header/myheader.h"

class LT0788
{

    int arr1[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};

public:


// DD
// dp : int a = dp[i / 10], b = dp[i % 10];



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotated Digits.
//Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Rotated Digits.
// 3 4 7
// 0 1 2 5 6 8 9
// 是真的把数字转180度。。6转180度就是9。。。有2，5，6，9就能反转后 ！= 原先
    int lt0788a(int N)
    {
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            ans += isValid(i);
        }
        return ans;
    }

    bool isValid(int n)
    {
        int t2 = 0;
        while (n > 0)
        {
            int t = n % 10;
            n /= 10;
            if (arr1[t] < 0)
                return false;
            t2 += (arr1[t] != t);
        }
        return t2 != 0;
    }

};

int main()
{

    int n = 10;

    LT0788 lt;

    cout<<lt.lt0788a(n)<<endl;

    return 0;
}
