
#include "../header/myheader.h"

class LT1975
{
public:

// D D





//Runtime: 152 ms, faster than 12.50% of C++ online submissions for Maximum Matrix Sum.
//Memory Usage: 35.2 MB, less than 12.50% of C++ online submissions for Maximum Matrix Sum.
// 似乎可以变成 最多一个负数。的。
    long long lt1975a(vector<vector<int>>& matrix)
    {
        int sz1 = matrix.size();
        int cntNeg = 0;
        int mn = INT_MAX;
        long long ans = 0L;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {
                int t2 = matrix[i][j];
                if (t2 < 0)
                {
                    cntNeg++;
                    t2 = -t2;
                }
                ans = ans + t2;
                mn = min(mn, t2);
            }
        }
        #ifdef __test
        cout<<ans<<", "<<cntNeg<<", "<<mn<<endl;
        #endif // __test
        return ans - ((cntNeg % 2 == 0) ? 0 : mn * 2);      // * 2...
    }

};

int main()
{
    myvvi vv = {{1,2,3},{-1,-2,-3},{1,2,3}};

    LT1975 lt;

    cout<<lt.lt1975a(vv)<<endl;

    return 0;
}
