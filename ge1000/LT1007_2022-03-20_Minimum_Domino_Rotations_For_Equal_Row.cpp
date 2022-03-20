
#include "../header/myheader.h"

class LT1007
{
public:

// D D


//        vector<int> countA(7), countB(7), same(7);
//        int n = A.size();
//        for (int i = 0; i < n; ++i) {
//            countA[A[i]]++;
//            countB[B[i]]++;
//            if (A[i] == B[i])
//                same[A[i]]++;
//        }
//        for (int i  = 1; i < 7; ++i)
//            if (countA[i] + countB[i] - same[i] == n)
//                return n - max(countA[i], countB[i]);
//        return -1;



//  auto top = A[0], bot = B[0], top1 = 0, bot1 = 0, top2 = 0, bot2 = 0;
//  for (auto i = 0; i < A.size(); ++i) {
//    if (A[i] != top && B[i] != top) top = 0;
//    if (A[i] != bot && B[i] != bot) bot = 0;
//    top1 += A[i] == top;
//    bot1 += B[i] == top;
//    top2 += A[i] == bot;
//    bot2 += B[i] == bot;
//  }
//  return top || bot ? min(A.size() - max(top1, bot1), A.size() - max(top2, bot2)) : -1;
// 一共就2种， 要么 全 A[0]， 要么 全 B[0]。。。 并不是6种，然后乘以上下。。


//Runtime: 206 ms, faster than 39.64% of C++ online submissions for Minimum Domino Rotations For Equal Row.
//Memory Usage: 111.6 MB, less than 29.27% of C++ online submissions for Minimum Domino Rotations For Equal Row.
// daily && not accepted...
// 一个数字至少出现一半，然后计算下 是否可以，以及哪里代价小。
    int lt1007a(vector<int>& tops, vector<int>& bottoms)
    {
        int sz1 = tops.size();
        int arr[7] = {0};
        for (int i = 0; i < sz1; ++i)
        {
            arr[tops[i]]++;
            arr[bottoms[i]]++;
        }
        int tar = -1;
        for (int i = 1; i <= 6; ++i)
        {
            if (arr[i] >= sz1)
            {
                tar = i;
                break;
            }
        }
        int chg1 = 0;
        int chg2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (tops[i] != tar)
            {
                if (bottoms[i] != tar)
                    return -1;
                chg1++;
            }
            if (bottoms[i] != tar)
            {
                chg2++;
            }
        }
        return min(chg1, chg2);
    }

};

int main()
{

    LT1007 lt;


    return 0;
}
