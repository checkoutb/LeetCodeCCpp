
#include "../header/myheader.h"

class LT1009
{
public:


// D D

//        int X = 1;
//        while (N > X) X = X * 2 + 1;
//        return N ^ X;

//  int c = 1;
//  while (c < N) c = (c << 1) + 1;
//  return N ^ c;


//The idea is to find the bit length of N, construct a string of 1's with the same length, and XOR with N.
//For example, 5 in binary is 101. Notice that 101 ^ 111 = 010 (2 in decimal).
//    int comp = 1;
//    while (comp < N)
//        comp = (comp << 1) | 1;
//    return N ^ comp;




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Complement of Base 10 Integer.
//Memory Usage: 6.1 MB, less than 6.11% of C++ online submissions for Complement of Base 10 Integer.
    int lt1009a(int N)
    {
        int arr[32] = {0};
        int i = 0;
        int mod = 1;
        while (N >= mod)
        {
            mod <<= 1;
            i++;
        }
        i--;
        mod >>= 1;
        while (N > 0)
        {
            if (N >= mod)
            {
                arr[i] = 1;
                N -= mod;
            }
            mod >>= 1;
            i--;
        }
        #ifdef __test
        for_each(begin(arr), end(arr), fun_cout);
        cout<<endl;
        #endif // __test
        bool can = false;
        for (int i = 31; i >= 0; i--)
        {
            if (arr[i] == 1)
                can = true;
            if (can)
            {
                arr[i] = (arr[i] + 1) % 2;
            }
        }
        if (!can)
            return 1;
        mod = 1;
        int ans = 0;
        for (int i = 0; i < 31; i++)
        {
            if (arr[i] == 1)
            {
                ans += mod;
            }
            mod <<= 1;
        }
        return ans;
    }

};

int main()
{

    int arr[] = {5,7,10,0};

    LT1009 lt;

    for (int i : arr)
    {
        cout<<lt.lt1009a(i)<<endl;
    }

    return 0;
}
