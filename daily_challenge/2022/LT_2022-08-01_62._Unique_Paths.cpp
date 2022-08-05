
#include "../../header/myheader.h"

class LT
{
public:

// D D

//vector<vector<int>> dp(m, vector<int>(n, 1));
// init 1

//(m+n)! / (m! * n!)



//Runtime: 3 ms, faster than 44.81% of C++ online submissions for Unique Paths.
//Memory Usage: 6.1 MB, less than 59.42% of C++ online submissions for Unique Paths.
    int ltb(int m, int n)
    {
        if (m > n)
            swap(m, n);
        vector<int> vi(m, 1);
        for (int j = 1; j < n; ++j)
        {
            for (int i = 1; i < m; ++i)
                vi[i] += vi[i - 1];
        }
        return vi[m - 1];
    }


//Runtime: 6 ms, faster than 12.58% of C++ online submissions for Unique Paths.
//Memory Usage: 6.6 MB, less than 26.54% of C++ online submissions for Unique Paths.
    int lta(int m, int n)
    {
        vector<vector<int>> vvi(m, vector<int>(n, 0));
        vvi[0][0] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                vvi[i][j] += (i > 0 ? vvi[i - 1][j] : 0) + (j == 0 ? 0 : vvi[i][j - 1]);
            }
        }
        #ifdef __test
        for (myvi& v : vvi)
        {
            showVectorInt(v);
        }
        #endif // __test
        return vvi[m - 1][n - 1];
    }

};

int main()
{

    LT lt;

    int m{3},n{7};

    cout<<lt.ltb(m,n)<<endl;

    return 0;
}
