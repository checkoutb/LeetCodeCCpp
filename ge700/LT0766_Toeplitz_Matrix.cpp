
#include "../header/myheader.h"

class LT0766
{
public:


// D && D
//        for(int i=1 ; i < matrix.size(); i++)
//            for(int j = 1; j < matrix[0].size(); j++)
//                if(matrix[i][j] != matrix[i-1] [j-1])
//                    return false;
//        return true;
// ......


//Runtime: 24 ms, faster than 17.51% of C++ online submissions for Toeplitz Matrix.
//Memory Usage: 17.7 MB, less than 14.29% of C++ online submissions for Toeplitz Matrix.
    bool lt0766a(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = rows - 1; i >= 0; i--)
        {
            int a = i;
            int b = cols - 1;
            int tar = matrix[a][b];
            while (a >= 0 && b >= 0)
            {
                int tar2 = matrix[a][b];
                if (tar2 != tar)
                {
                    return false;
                }
                a--, b--;
            }
        }

        for (int j = 1; j < cols; j++)
        {
            int a = rows - 1;
            int b = j;
            int tar = matrix[a][b];
            while (a >= 0 && b >= 0)
            {
                if (tar != matrix[a][b])
                {
                    return false;
                }
                a--, b--;
            }
        }

        return true;
    }

};

int main()
{

//    vector<vector<int>> m = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    vector<vector<int>> m = {{1,2}, {2,2}};

    LT0766 lt;

    cout<<lt.lt0766a(m)<<endl;

    return 0;
}
