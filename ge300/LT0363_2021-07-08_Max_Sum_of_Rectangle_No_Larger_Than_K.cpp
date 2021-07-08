
#include "../header/myheader.h"

class LT0363
{
public:


// D

// Kadane






// tle.
// 做一个sum，然后forforforfor
// 点，代表了 00 和 这个点 形成的矩形的 和。
    int lt0363a(vector<vector<int>>& matrix, int k)
    {
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 1; j < sz2; ++j)
            {
                matrix[i][j] += matrix[i][j - 1];       // qian lie
            }
        }
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
        #ifdef __test
        for (myvi& vi : matrix)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test

        int ans = INT_MIN;

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                int t2 = matrix[i][j];
                if (t2 < k)
                    ans = max(ans, t2);
                for (int a = 0; a <= i; ++a)
                {
                    for (int b = 0; b <= j; ++b)
                    {
                        int t3 = 0;
                        if (a > 0 && b > 0)
                        {
                            t3 = matrix[a - 1][j] + matrix[i][b - 1] - matrix[a - 1][b - 1];
                        }
                        else if (a > 0)     // b == 0
                        {
                            // 最好往右下平移。。
                            t3 = matrix[a - 1][j];
                        }
                        else if (b > 0)     // a == 0
                        {
                            t3 = matrix[i][b - 1];
                        }

                        if ((t2 - t3) <= k)
                        {
                            ans = max(ans, t2 - t3);
                        }
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{
//    myvvi vv = {{1,0,1},{0,-2,3}};
//    int k = 2;

    myvvi vv = {{2,2,-1}};
    int k = 3;

    LT0363 lt;

    cout<<lt.lt0363a(vv, k)<<endl;

    return 0;
}
