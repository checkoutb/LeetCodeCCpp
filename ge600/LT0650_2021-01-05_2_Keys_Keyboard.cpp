
#include "../header/myheader.h"

class LT0650
{
public:

// D D

//        int k=2,ans=0;
//        while(n>1)
//        {
//            while(n%k==0) {n/=k; ans+=k;}
//            k++;
//        }
//        return ans;
// 优先除。


//        int s = 0;
//        for (int d = 2; d <= n; d++) {
//            while (n % d == 0) {
//                s += d;
//                n /= d;
//            }
//        }
//        return s;
// 被2整除后的数，不可能再被2整除。


//    def minSteps(self, n):
//        for i in xrange(2, int(n**0.5) + 1):
//            if n % i == 0:
//                return self.minSteps(n / i) + i
//        return 0 if n == 1 else n


//        for (int i = 2; i <= n; i++) {
//            dp[i] = i;
//            for (int j = i-1; j > 1; j--) {
//                if (i % j == 0) {
//                    dp[i] = dp[j] + (i/j);
//                    break;
//                }
//            }
//        }



//Runtime: 4 ms, faster than 64.51% of C++ online submissions for 2 Keys Keyboard.
//Memory Usage: 6.8 MB, less than 40.31% of C++ online submissions for 2 Keys Keyboard.
// 应该是 因式分解，获得 质数。。  不过[1,1000]
    int lt0650a(int n)
    {
        vector<int> v(n + 1, INT_MAX);
        v[1] = 0;
        for (int i = 1; i < n; ++i)
        {
            int cnt = v[i] + 2;         // copy + paste
            int stp = i + i;
            while (stp <= n)
            {
                v[stp] = min(v[stp], cnt);
                cnt++;
                stp += i;
            }
        }
        return v[n];
    }

};

int main()
{
    int n{3};

    LT0650 lt;

    cout<<lt.lt0650a(n);

    return 0;
}
