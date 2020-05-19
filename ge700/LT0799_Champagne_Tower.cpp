
#include "../header/myheader.h"

class LT0799
{
public:

// discuss
//        vector<double> res(102);
//        res[0] = poured;
//        for (int row = 1; row <= query_row; row++)
//            for (int i = row; i >= 0; i--)
//                res[i + 1] += res[i] = max(0.0, (res[i] - 1) / 2);
//        return min(res[query_glass], 1.0);
// res[i] = max(0.0, (res[i] - 1) / 2) 这个 返回 max()的值。
// 由于是行遍历，所以只需要一维数组。  也没那么简单。


// 无头绪，抄的discuss。
// 从头往下，满了就往下丢。
    double lt0799a(int poured, int query_row, int query_glass)
    {
        double arr[100][100] = {0.0};
        arr[0][0] = poured;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                if (arr[i][j] > 1)
                {
                    arr[i + 1][j] += (arr[i][j] - 1) / 2.0;
                    arr[i + 1][j + 1] += (arr[i][j] - 1) / 2.0;
                    arr[i][j] = 1;
                }
            }
        }
        return arr[query_row][query_glass];
    }

};

int main()
{

    LT0799 lt;


    return 0;
}
