
#include "../header/myheader.h"

class LT1004
{
public:


// D D

//        int i = 0, j;
//        for (j = 0; j < A.size(); ++j) {
//            if (A[j] == 0) K--;
//            if (K < 0 && A[i++] == 0) K++;
//        }
//        return j - i;

// K<0的情况下，才会 i++。。。只要K<0，i就会++，所以保证i++发生时，K已经用完。
// i,j 的差距 只会变大。
// nb。



//Runtime: 820 ms, faster than 5.09% of C++ online submissions for Max Consecutive Ones III.
//Memory Usage: 55.5 MB, less than 8.70% of C++ online submissions for Max Consecutive Ones III.
    int lt1004a(vector<int>& A, int K)
    {
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == 1)
            {
                if (i == 0 || A[i - 1] == 0)
                {
                    int j = i;
                    int kk = K;
                    for (; j < A.size(); j++)
                    {
                        if (A[j] == 0)
                        {
                            if (kk > 0)
                            {
                                kk--;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    ans = max(ans, j - i);
                }
            }
        }
        int kk = K;
        int i = A.size() - 1;
        for (; i >= 0; i--)
        {
            if (A[i] == 0)
            {
                if (kk > 0)
                {
                    kk--;
                }
                else
                {
                    break;
                }
            }
        }
        ans = max(ans, (int) A.size() - i - 1);
        return ans;
    }

};

int main()
{
    vector<int> v = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

//    vector<int> v = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
//    int k = 3;

    LT1004 lt;

    cout<<lt.lt1004a(v, k);

    return 0;
}
