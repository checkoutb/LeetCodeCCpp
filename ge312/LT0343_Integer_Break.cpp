
#include "../header/myheader.h"

class LT0343
{
public:

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Integer Break.
//Memory Usage: 8.3 MB, less than 43.18% of C++ online submissions for Integer Break.
// 都是4ms。


// discuss。
// 分解出来的因子始终是2或3.。。看了，好像和e有关。


//        if(n==2) return 1;
//        if(n==3) return 2;
//        int product = 1;
//        while(n>4){
//            product*=3;
//            n-=3;
//        }
//        product*=n;
//
//        return product;
// 看来是有限3，没有3才2.


// 还有dp的。。
//        if(n <= 3) return n - 1;
//        vector<int> dp(n + 1, 0);
//        for(int i = 1; i <= n; i++) {
//            if(i <= 4) dp[i] = i;
//            else {
//                for(int j = 1; j < i; j++) {
//                    dp[i] = max(dp[i], dp[j] * dp[i - j]);
//                }
//            }
//        }
//        return dp[n];
// dp[n]代表 n这个数的 最大 因子乘积，..>1的任何数都可以拆成<它的2个数的乘积。


//还有个dp
//        vector<int> maxArr(n+1, 0);
//
//        /** For a number i: write i as a sum of integers, then take the product of those integers.
//        maxArr[i] = maximum of all the possible products */
//
//        maxArr[1] = 0;
//        maxArr[2] = 1; // 2=1+1 so maxArr[2] = 1*1
//
//        for (int i=3; i<=n; i++) {
//            for (int j=1; j<i; j++) {
//                /** Try to write i as: i = j + S where S=i-j corresponds to either one number or a sum of two or more numbers
//
//                Assuming that j+S corresponds to the optimal solution for maxArr[i], we have two cases:
//                (1) i is the sum of two numbers, i.e. S=i-j is one number, and so maxArr[i]=j*(i-j)
//                (2) i is the sum of at least three numbers, i.e. S=i-j is a sum of at least 2 numbers,
//                and so the product of the numbers in this sum for S is maxArr[i-j]
//                (=maximum product after breaking up i-j into a sum of at least two integers):
//                maxArr[i] = j*maxArr[i-j]
//                */
//                maxArr[i] = max(maxArr[i], max(j*(i-j), j*maxArr[i-j]));
//            }
//        }
//        return maxArr[n];
// 这里，把i 拆成 j 和 i-j (2个因子), 或者 j 和 arr[i-j] (多个因子)的最大值。。。觉得比上面的差了点。。。




//    a^2 + b^2 >= 2ab  还有一个想不出了。。反正肯定是 a=b的时候最合适。
    int lt0343a(int n)
    {
        int result = 0;
        int i = 2;
        int t1 = 0;
        int t2 = 0;
        int t3 = 0;
        while (i <= n)
        {
            t1 = 1;
            t3 = n;
            for (int j = i; j > 0; j--)
            {
                t2 = t3 / j;
                t3 -= t2;
                t1 *= t2;
                #ifdef __test
                cout<<t1<<","<<t2<<","<<t3<<endl;
                #endif // __test
            }
            if (t1 > result)
                result = t1;
            else
                break;
            i++;
        }
        return result;
    }
};

int main()
{
    int n = 10;

    LT0343 lt;
    cout<<endl<<lt.lt0343a(n)<<endl;
    return 0;
}
