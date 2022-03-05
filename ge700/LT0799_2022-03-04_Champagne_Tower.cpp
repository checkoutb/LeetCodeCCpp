
#include "../header/myheader.h"

class LT0799
{
public:

// D D

//        vector<double> res(102);
//        res[0] = poured;
//        for (int row = 1; row <= query_row; row++)
//            for (int i = row; i >= 0; i--)
//                res[i + 1] += res[i] = max(0.0, (res[i] - 1) / 2);
//        return min(res[query_glass], 1.0);
// 一维数组。






//Runtime: 7 ms, faster than 77.72% of C++ online submissions for Champagne Tower.
//Memory Usage: 6 MB, less than 91.14% of C++ online submissions for Champagne Tower.
// daily 的题目，正好之前也没有做出来。
// 杨辉三角
// 100层能硬算吧。
/*
.5 1 .5
 1 1 1
0 .5 .5 0

1 2 1
.5 1.5 1.5 .5

1 3 3 1
.5 2 3 2 .5

速率之比，但是有些之前就已经有酒了。

0
01
012
0123
01234

+1

(0+1) / 2  (1+2)/2      0 1

给相同下标 和 下标+1 的

*/
    double champagneTower(int poured, int query_row, int query_glass)
    {
        double arr[100][100] = {{0.0}};
        for (int i = 0; i < 100; ++i)
        {
            for (int j = 0; j < 100; ++j)
            {
                arr[i][j] = 0.0;
            }
        }
        arr[0][0] = poured;
        for (int i = 0; i < query_row && i < 99; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (arr[i][j] > 1)
                {
                    arr[i + 1][j] += (arr[i][j] - 1) / 2;
                    arr[i + 1][j + 1] += (arr[i][j] - 1) / 2;
                }
            }
        }
//        #ifdef __test
//        for (int i = 0; i < 33; ++i)
//        {
//            for (int j = 0; j <= i; ++j)
//            {
//                cout<<arr[i][j]<<", ";
//            }
//            cout<<endl;
//        }
//        #endif // __test
        arr[query_row][query_glass] = min(1.0, arr[query_row][query_glass]);
        return arr[query_row][query_glass];
    }

};

int main()
{

    LT0799 lt;

//    int arr[] = {1,1,1};
//    int arr[] = {2,1,1};
    int arr[] = {100000009, 33, 17};

    cout<<lt.champagneTower(arr[0], arr[1], arr[2])<<endl;

    return 0;
}
