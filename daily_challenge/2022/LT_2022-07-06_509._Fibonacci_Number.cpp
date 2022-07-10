
#include "../../header/myheader.h"

class LT
{
public:

    // D D


    //for (int i = 2; i <= n; i++) {
    //    a[i] = a[i - 1] + a[i - 2];
    //}

    //while (N-- > 1)
    //{
    //    int sum = a + b;
    //    a = b;
    //    b = sum;
    //}


    //public int fib(int N) {
    //    if (N <= 1) return N;
    //    int[][] E = new int[][]{ {1, 1}, {1, 0} };
    //    int[][] I = new int[][]{ {1, 0}, {0, 1} };
    //    int[][] f = new int[][]{ {1, 0} };
    //    N = N - 1;
    //    while (N > 0) {
    //        if ((N & 1) == 1) {
    //            I = multiply(I, E);
    //        }
    //        E = multiply(E, E);
    //        N = N >> 1;
    //    }
    //    f = multiply(f, I);
    //    return f[0][0];
    //}
    //
    //private int[][] multiply(int[][] A, int[][] B) {
    //    int[][] res = new int[A.length][B[0].length];
    //    for (int i = 0; i < A.length; i++) {
    //        for (int k = 0; k < A[0].length; k++) {
    //            for (int j = 0; j < B[0].length; j++) {
    //                res[i][j] += A[i][k] * B[k][j];
    //            }
    //        }
    //    }
    //    return res;
    //}

    //F(2n - 1) = F(n - 1) ^ 2 + F(n) ^ 2
    //F(2n) = (2 * F(n - 1) + F(n)) * F(n)



//Runtime: 3 ms, faster than 60.76 % of C++ online submissions for Fibonacci Number.
//Memory Usage : 5.8 MB, less than 80.05 % of C++ online submissions for Fibonacci Number.
    int arr[31] = { 0 };
    int fib(int n)
    {
        if (arr[n] != 0)
            return arr[n];

        return arr[n] = (n >= 2 ? fib(n - 1) + fib(n - 2) : n);
    }


//Runtime: 23 ms, faster than 14.48 % of C++ online submissions for Fibonacci Number.
//Memory Usage : 6 MB, less than 41.61 % of C++ online submissions for Fibonacci Number.
    // 0 1 1 2 3
    int fib___(int n)
    {
        return n >= 2 ? fib(n - 1) + fib(n - 2) : n;
    }

};

int main()
{

    LT lt;


    return 0;
}
