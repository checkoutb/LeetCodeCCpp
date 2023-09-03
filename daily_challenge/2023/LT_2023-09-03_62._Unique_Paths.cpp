
#include "../../header/myheader.h"

class LT
{
public:



//Runtime3 ms
//Beats
//33.20%
//Memory6.5 MB
//Beats
//24.88%
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> vvi(m, vector<int>(n, 0));
        vvi[0][0] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i > 0)
                    vvi[i][j] += vvi[i - 1][j];
                if (j > 0)
                    vvi[i][j] += vvi[i][j - 1];
            }
        }
        return vvi[m - 1][n - 1];
    }

};

int main()
{

    LT lt;


    return 0;
}
