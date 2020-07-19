
#include "../header/myheader.h"

class LT0867
{
public:

// D
//zip(*M)



//Runtime: 20 ms, faster than 96.22% of C++ online submissions for Transpose Matrix.
//Memory Usage: 10.6 MB, less than 86.22% of C++ online submissions for Transpose Matrix.
    vector<vector<int>> lt0867a(vector<vector<int>>& A)
    {
        int rows = A.size();
        int cols = A[0].size();
        vector<vector<int>> ans(cols, vector<int>(rows, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ans[j][i] = A[i][j];
            }
        }
        return ans;
    }


};

int main()
{

    vector<vector<int>> vv = {{1,2,3},{4,5,6}
//    ,{7,8,9}
    };

    LT0867 lt;

    vector<vector<int>> vv2 = lt.lt0867a(vv);

    for_each(begin(vv2), end(vv2), [](vector<int>& v) { for_each(begin(v), end(v), fun_cout); cout<<endl; });

    return 0;
}
