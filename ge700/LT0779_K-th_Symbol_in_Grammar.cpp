
#include "../header/myheader.h"

class LT0779
{
public:


// D && D
// java :   return Integer.bitCount(K - 1) & 1;
// c++ :    for (n = 0, K -= 1; K ; K &= (K - 1)) n++;     return n & 1;

//    int kthGrammar(int N, int K) {
//	if (N == 1) return 0;
//	if (K % 2 == 0) return (kthGrammar(N - 1, K / 2) == 0) ? 1 : 0;
//	else return (kthGrammar(N - 1, (K + 1) / 2) == 0) ? 0 : 1;
//    }



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for K-th Symbol in Grammar.
//Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for K-th Symbol in Grammar.

// 0 01   1 10
// 根据K，能知道N扩写时，最终的结果是在 扩写后的左半部分，还是右半部分。
    int lt0779a(int N, int K)
    {
        K--;
        N--;
        int t2 = 1;
        int t3 = 0;
        int t4 = 1;
        for (int j = 0; j < N; j++)
            t4 *= 2;

        while (N-- >= 1)
        {
            t4 /= 2;
            if (K >= t4)
            {
                t3 = t3 == 0 ? 1 : 0;
                K -= t4;
            }
            else
            {
                t3 = t3 == 0 ? 0 : 1;
            }
        }
        return t3;
    }

};

int main()
{

    int N = 4, K = 5;
//    int N = 3, K = 3;

    LT0779 lt;

    cout<<lt.lt0779a(N, K)<<endl;

    return 0;
}
