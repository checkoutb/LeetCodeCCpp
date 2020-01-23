
#include "../header/myheader.h"

class LT0542
{
public:






// int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// queue.add(new int[] {r, c});
// 用Queue保存 点0，循环Queue直到empty，设置4个方向的距离，如果其他点被影响到了，就加入Queue，




//Runtime: 172 ms, faster than 98.67% of C++ online submissions for 01 Matrix.
//Memory Usage: 20.7 MB, less than 100.00% of C++ online submissions for 01 Matrix.

    vector<vector<int>> lt0542b(vector<vector<int>>& matrix)
    {
        for (auto& p : matrix)
        {
            for (int& a : p)
            {
                if (a != 0)
                {
                    a = matrix.size() + matrix[0].size();
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (i + 1 < matrix.size() && matrix[i + 1][j] != 0)
                {
                    matrix[i + 1][j] = min(matrix[i + 1][j], matrix[i][j] + 1);                 // [0][0] + 1 <= INT_MAX, 所以不能用INT_MAX 初始化。
                }
                if (j + 1 < matrix[0].size() && matrix[i][j + 1] != 0)
                {
                    matrix[i][j + 1] = min(matrix[i][j + 1], matrix[i][j] + 1);
                }
            }
        }

        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            for (int j = matrix[0].size() - 1; j >= 0; j--)
            {
                if (i > 0 && matrix[i -1][j] != 0)
                {
                    matrix[i - 1][j] = min(matrix[i - 1][j], matrix[i][j] + 1);
                }
                if (j > 0 && matrix[i][j - 1] != 0)
                {
                    matrix[i][j - 1] = min(matrix[i][j - 1], matrix[i][j] + 1);
                }
            }
        }
        return matrix;

    }



// 19 / 48 . tle
    vector<vector<int>> lt0542a(vector<vector<int>>& matrix)
    {
        for (auto& p : matrix)          // &, &
        {
            for (int& a : p)
            {
                if (a != 0)
                {
                    a = INT_MAX;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    dfsa1(matrix, i + 1, j, 1);
                    dfsa1(matrix, i, j + 1, 1);
                    dfsa1(matrix, i - 1, j, 1);
                    dfsa1(matrix, i, j - 1, 1);
                }
            }
        }
        return matrix;
    }

    void dfsa1(vector<vector<int>>& m, int i, int j, int v)
    {
        if (i < 0 || i >= m.size() || j < 0 || j >= m[0].size())
            return;
        if (v > m[i][j])
            return;
        if (m[i][j] == 0)
            return;
        m[i][j] = v;
        dfsa1(m, i + 1, j, v + 1);
        dfsa1(m, i, j + 1, v + 1);
        dfsa1(m, i - 1, j, v + 1);
        dfsa1(m, i, j - 1, v + 1);
    }

};

int main()
{
    vector<vector<int>> vv = {{0,0,0},{0,1,0},{1,1,1}};

    LT0542 lt;
    lt.lt0542b(vv);

    for (auto p : vv)
    {
        for (int i : p)
        {
            cout<<i<<", ";
        }
        cout<<endl;
    }

    return 0;
}
