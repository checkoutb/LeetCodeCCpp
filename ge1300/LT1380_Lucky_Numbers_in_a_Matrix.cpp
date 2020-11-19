
#include "../header/myheader.h"

class LT1380
{
public:

// D D

//                if (mi[i] == mx[j])
//                    res.add(mi[i]);




//Runtime: 40 ms, faster than 63.18% of C++ online submissions for Lucky Numbers in a Matrix.
//Memory Usage: 12 MB, less than 20.80% of C++ online submissions for Lucky Numbers in a Matrix.
// min in row,   max in col
    vector<int> lt1380a (vector<vector<int>>& matrix)
    {
        int sz1 = matrix.size(), sz2 = matrix[0].size();
        vector<int> mnr(sz1, INT_MAX);
        vector<int> mxc(sz2);
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                mnr[i] = min(mnr[i], matrix[i][j]);
                mxc[j] = max(mxc[j], matrix[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (matrix[i][j] == mnr[i] && matrix[i][j] == mxc[j])
                {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> vv = {{3,7,8},{9,11,13},{15,16,17}};

    LT1380 lt;

    vector<int> v = lt.lt1380a(vv);

    showVectorInt(v);

    return 0;
}
