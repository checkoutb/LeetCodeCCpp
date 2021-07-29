
#include "../../header/myheader.h"

class LT
{
public:

// D

//If we have A[k] * 2 != A[i] + A[j],
//(A[k] + x) * 2 = A[k] * 2 + 2x != A[i] + A[j] + 2x = (A[i] + x) + (A[j] + x)
//E.g: [1,3,2] + 1 = [2,4,3].

//If we have A[k] * 2 != A[i] + A[j],
//for any x != 0,
//(A[k] * x) * 2 = A[k] * 2 * x != (A[i] + A[j]) * x = (A[i] * x) + (A[j] * x)
//E.g: [1,3,2] * 2 = [2,6,4]

//Assume we have a beautiful array A with length N
//A1 = A * 2 - 1 is beautiful with only odds from 1 to N * 2 -1
//A2 = A * 2 is beautiful with only even from 2 to N * 2
//B = A1 + A2 beautiful array with length N * 2











// g

// 我记得是  奇数 偶数。。。 前半部分奇数，后半部分偶数，，  奇数+偶数 != 2*Z ..
// 1 3 2 4
// 1 5 3 2 4
// 2 6 4
// 1 5 3 7
// 1 9 5 3 7
// 1 9 7 5 3        7 5 3 f
// 1 11 9 7 5 3         f
// 好像是都×2.。。。。 想起来了。。。
// 1
// 12
// 12 24
// 21
// 21 42
// 2143         // 加最大值
// 2143 6587 。。 3 5 7
// 1243
// 1243 7865   1 2 3
//。。。。
// 12
// 13
// 135 。。
// 153
// 1537     ？
// 13 + 4 = 57
// 1357  f
// 1375
// 1375  9 11 15 13         // 1 5 9 。。
// 13
// 5713
// 13 15 9 11 5 7 1 3       951.。。
    vector<int> lta(int n)
    {

    }

};

int main()
{

    LT lt;


    return 0;
}
