
#include "../header/myheader.h"

class LT0869
{
public:

// D D
//        char[] a1 = String.valueOf(N).toCharArray();
//        Arrays.sort(a1);
//        String s1 = new String(a1);
// 1 << i .toCharArray . sort. new String.


//    bool reorderedPowerOf2(int N) {
//        long c = counter(N);
//        for (int i = 0; i < 32; i++)
//            if (counter(1 << i) == c) return true;
//        return false;
//    }
//
//    long counter(int N) {
//        long res = 0;
//        for (; N; N /= 10) res += pow(10, N % 10);
//        return res;
//    }
// ...
// 数字转成 次方， 数字N 代表 第N位上+1。



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reordered Power of 2.
//Memory Usage: 6.1 MB, less than 76.31% of C++ online submissions for Reordered Power of 2.
    bool lt0869a(int N)
    {
        int sz1 = 0;
        int n = N;
        int arr[10] = {0};
        while (n > 0)
        {
            sz1++;
            arr[n % 10]++;
            n /= 10;
        }
        int p2 = 1;
        while (getSZa1(p2) < sz1)
        {
            p2 *= 2;
        }
        while (getSZa1(p2) == sz1)
        {
            int p3 = p2;
            int arr2[10] = {0};
            while (p3 > 0)
            {
                arr2[p3 % 10]++;
                p3 /= 10;
            }
            bool eq = true;
            for (int i = 0; i < 10; i++)
            {
                if (arr[i] != arr2[i])
                {
                    eq = false;
                    break;
                }
            }
            if (eq)
                return true;
            p2 *= 2;
        }
        return false;
    }

    inline int getSZa1(int n)
    {
        int sz1 = 0;
        while (n > 0)
        {
            sz1++;
            n /= 10;
        }
        return sz1;
    }
};

int main()
{

//    int n = 46;
    int n = 10;

    LT0869 lt;

    cout<<lt.lt0869a(n)<<endl;

    return 0;
}
