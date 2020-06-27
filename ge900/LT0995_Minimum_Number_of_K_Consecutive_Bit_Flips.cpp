
#include "../header/myheader.h"

class LT0995
{
public:


// tle... 94 / 110
// 看了discuss的title...greedy,one-pass..
    int LT0995a(vector<int>& A, int K)
    {
        int ans = 0;
        for (int i = 0;  i < A.size(); i++)
        {
            if (A[i] == 0)
            {
                ans++;
                if (i + K > A.size())
                    return -1;
                for (int j = 0; j < K; j++)
                {
                    A[i + j] = A[i + j] ? 0 : 1;
                }
            }
        }
        return ans;
    }

};

int main()
{

    vector<int> v = {0,0,0,1,0,1,1,0};
    int k = 3;

    LT0995 lt;

    cout<<lt.LT0995a(v, k)<<endl;

    return 0;
}
