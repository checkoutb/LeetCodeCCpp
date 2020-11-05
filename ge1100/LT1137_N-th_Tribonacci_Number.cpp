
#include "../header/myheader.h"

class LT1137
{
public:

// D D
//        int f[]={0,1,1,2};
//        for(int i=4;i<=n;i++)
//            f[i%4] = f[(i-1)%4] + f[(i-2)%4] + f[(i-3)%4];
//        return f[n%4];



// yaome jiandan, yaome nan.
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-th Tribonacci Number.
//Memory Usage: 6.5 MB, less than 8.68% of C++ online submissions for N-th Tribonacci Number.
    int lt1137a(int n)
    {
        int arr[] = {0,1,1};
        if (n < 3)
        {
            return arr[n];
        }
        while (n-- >= 3)
        {
            int t1 = arr[0];
            arr[0] = arr[1];
            arr[1] = arr[2];
            arr[2] = t1 + arr[0] + arr[1];
        }
        return arr[2];
    }

};

int main()
{
//    int n = 4;
    int n = 25;

    LT1137 lt;

    cout<<lt.lt1137a(n)<<endl;

    return 0;
}
