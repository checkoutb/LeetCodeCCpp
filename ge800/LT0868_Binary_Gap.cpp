
#include "../header/myheader.h"

class LT0868
{
public:

// D D
//        int res = 0;
//        for (int d = -32; N; N /= 2, d++)
//            if (N % 2) res = max(res, d), d = 0;
//        return res;
// d:distance.


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Gap.
//Memory Usage: 6.1 MB, less than 44.23% of C++ online submissions for Binary Gap.
    int lt0868a(int N)
    {
        int ans = 0;
        int last = -1;
        int i = 0;
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                if (last != -1)
                {
                    ans = max(i - last, ans);
                }
                last = i;
            }

            i++;
            N = N >> 1;
        }
        return ans;
    }

};

int main()
{

    int arr[] = {22, 5, 6, 8};

    LT0868 lt;

    for (int i : arr)
        cout<<lt.lt0868a(i)<<endl;

    return 0;
}
