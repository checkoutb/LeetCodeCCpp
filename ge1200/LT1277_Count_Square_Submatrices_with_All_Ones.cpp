
#include "../header/myheader.h"

class LT1277
{
public:


// D D

//        int res = 0;
//        for (int i = 0; i < A.size(); ++i)
//            for (int j = 0; j < A[0].size(); res += A[i][j++])
//                if (A[i][j] && i && j)
//                    A[i][j] += min({A[i - 1][j - 1], A[i - 1][j], A[i][j - 1]});
//        return res;
// i,j 是 正方形的 右下角。
// 最大正方形的尺寸 == 有多少个正方形。



//Runtime: 128 ms, faster than 86.67% of C++ online submissions for Count Square Submatrices with All Ones.
//Memory Usage: 23.8 MB, less than 89.02% of C++ online submissions for Count Square Submatrices with All Ones.
    int lt1277a(vector<vector<int>>& matrix)
    {
        int ans = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 1)
                {
                    ans += getCounta1(matrix, i, j);
                }
            }
        }
        return ans;
    }

    int getCounta1(vector<vector<int>>& ma, int i, int j)
    {
        int len = 1;
        while (true)
        {
            if ((i + len) >= ma.size() || (j + len) >= ma[0].size())
                break;
            for (int m = 0; m <= len; m++)
            {
                if (ma[i + len][j + m] != 1)
                    goto AAA;
                if (ma[i + m][j + len] != 1)
                    goto AAA;
            }
            len++;
            continue;

            AAA:
            break;
        }
        return len;
    }

};

int main()
{

//    vector<vector<int>> ma = {
//        {0,1,1,1},
//        {1,1,1,1},
//        {0,1,1,1}
//    };

//    vector<vector<int>> ma = {
//        {1,0,1},
//        {1,1,0},
//        {1,1,0}
//    };

//0 0 0
//0 1 0
//0 1 0
//1 1 1
//1 1 0
    vector<vector<int>> ma = {{0,0,0},{0,1,0},{0,1,0},{1,1,1},{1,1,0}};


    LT1277 lt;

    cout<<lt.lt1277a(ma)<<endl;

    return 0;
}
