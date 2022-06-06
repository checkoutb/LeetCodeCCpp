
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //return zip(*M)        // py2
    //return list(zip(*A))      // py3.. zip don't return list


//Runtime: 13 ms, faster than 73.06 % of C++ online submissions for Transpose Matrix.
//Memory Usage : 10.7 MB, less than 13.79 % of C++ online submissions for Transpose Matrix.
    vector<vector<int>> lta(vector<vector<int>>& matrix)
    {
        int sz1( matrix.size() ), sz2( matrix[0].size() );      // 不能用{ xx.size() }, {}里面需要常量(?)
        vector<vector<int>> vvi(sz2, vector<int>(sz1, 0));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                vvi[j][i] = matrix[i][j];
            }
        }
        return vvi;
    }

};

int main()
{

    LT lt;


    return 0;
}
