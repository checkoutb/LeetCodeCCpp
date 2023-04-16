
#include "../../header/myheader.h"

class LT6376
{
public:


    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        int ans = -1;
        int mx = -1;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            t2 = 0;
            for (int j = 0; j < sz2; ++j)
            {
                t2 += mat[i][j];
            }
            if (t2 > mx)
            {
                ans = i;
                mx = t2;
            }
        }
        return { ans, mx };
    }

};

int main()
{

    LT6376 lt;


    return 0;
}
