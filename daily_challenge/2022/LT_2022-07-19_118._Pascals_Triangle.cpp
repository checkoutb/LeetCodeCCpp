
#include "../../header/myheader.h"

class LT
{
public:

    // D D
    
    //vector<vector<int>> r(numRows);

    //for (int i = 0; i < numRows; i++) {
    //    r[i].resize(i + 1);
    //    r[i][0] = r[i][i] = 1;

    //    for (int j = 1; j < i; j++)
    //        r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    //}


//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Pascal's Triangle.
//Memory Usage : 6.6 MB, less than 31.97 % of C++ online submissions for Pascal's Triangle.
    vector<vector<int>> lta(int numRows)
    {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        for (int i = 1; i < numRows; ++i)
        {
            ans[i].push_back(1);

            for (int j = 1; j < ans[i - 1].size(); ++j)
            {
                ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            }

            ans[i].push_back(1);
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
