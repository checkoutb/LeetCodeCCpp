
#include "../header/myheader.h"

class LT2022
{
public:



//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                mat[i][j] = original[i * n + j];
//            }
//        }



//Runtime: 175 ms, faster than 49.60% of C++ online submissions for Convert 1D Array Into 2D Array.
//Memory Usage: 85.2 MB, less than 97.55% of C++ online submissions for Convert 1D Array Into 2D Array.
    vector<vector<int>> lt2022a(vector<int>& original, int m, int n)
    {
        if (original.size() != m * n)
            return {};
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < original.size(); i++)
        {
            ans[i / n][i % n] = original[i];
        }
        return ans;
    }

};

int main()
{

    LT2022 lt;


    return 0;
}
