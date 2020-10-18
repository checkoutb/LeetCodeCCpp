
#include "../header/myheader.h"

class LT1006
{
public:

// D D
//    public int helper(int N) {
//        if (N == 0) return 0;
//        if (N == 1) return 1;
//        if (N == 2) return 1;
//        if (N == 3) return 1;
//        return N - (N - 1) * (N - 2) / (N - 3) + helper(N - 4);
//    }


//N = 0, return 0
//N = 1, return 1
//N = 2, return 2
//N = 3, return 6
//N = 4, return 7
//N = 5 + 4K, return N + 2
//N = 6 + 4K, return N + 2
//N = 7 + 4K, return N - 1
//N = 8 + 4K, return N + 1


//        if N <= 2:
//            return N
//        if N <= 4:
//            return N + 3
//
//        if (N - 4) % 4 == 0:
//            return N + 1
//        elif (N - 4) % 4 <= 2:
//            return N + 2
//        else:
//            return N - 1


//i * (i-1) / (i-2) = i+1 when i >= 5
//    i * (i-1) / (i-2) + (i-3) - (i-4) * (i-5) / (i-6) + (i-7) - (i-8) * .... + rest elements
//=   (i+1) + "(i-3)" - "(i-4) * (i-5) / (i-6)" + "(i-7)" - "(i-8) * " .... + rest elements
//=   (i+1) + "(i-3) - (i-3)" + "(i-7) - (i-7)" +  ....  + rest elements
//=   (i+1) + rest elements


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Clumsy Factorial.
//Memory Usage: 6.3 MB, less than 7.43% of C++ online submissions for Clumsy Factorial.
// clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
    int lt1006a(int N)
    {
        int ans = N;
        if (--N > 0)
        {
            ans = ans * N;
        }
        if (--N > 0)
        {
            ans /= N;
        }
        if (--N > 0)
            ans += N;
        while (N > 0)
        {
            int t = --N;
            t *= -1;
            if (--N > 0)
            {
                t = t * N;
            }
            if (--N > 0)
            {
                t = t / N;
            }
            if (--N > 0)
            {
                t = t + N;
            }
            ans += t;
        }

        return ans;
    }

};

int main()
{

    int arr[] = {4,10};

    LT1006 lt;

    for (int i : arr)
    {
        cout<<lt.lt1006a(i)<<endl;
    }

    return 0;
}
