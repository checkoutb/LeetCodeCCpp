
#include "../header/myheader.h"

class LT0329
{
public:


//Runtime: 32 ms, faster than 99.71% of C++ online submissions for Longest Increasing Path in a Matrix.
//Memory Usage: 11.7 MB, less than 100.00% of C++ online submissions for Longest Increasing Path in a Matrix.

    int lt0329a(vector<vector<int>>& matrix)
    {
        int sz1 = matrix.size();
        if (sz1 == 0)
            return 0;
        int sz2 = matrix[0].size();
        if (sz2 == 0)
            return 0;
        int result = 0;
        int t1 = 0;
        int arr2[sz1][sz2] = {};        // 空的反而全0,{{}}编译爆炸。。{{0}}，非第一行全0，第一行第一个0，其他非0.

        #ifdef __test1
        cout<<endl;
        for (auto& ar : arr2)
        {
            for (auto aq: ar)
            {
                cout<<aq<<", ";
            }
            cout<<endl;
        }
        #endif // __test

        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz2; j++)
            {
                if (arr2[i][j] != 0)
                    continue;
                t1 = recursiona1(matrix, (int*) arr2, i, j);
                if (t1 > result)
                    result = t1;
#ifdef __test
                cout<<endl;
                for (auto& ar : arr2)
                {
                    for (auto aq : ar)
                    {
                        cout<<aq<<",";
                    }
                    cout<<endl;
                }
#endif // __test
            }
        }
        return result;
    }

    // ...array...多维数组传递真的爆炸。。。。可怕。。
    int recursiona1(vector<vector<int>>& m, int* arr2, int i, int j)
    {
        int sz1 = m[0].size();
        if (arr2[i * sz1 + j] != 0)
            return arr2[i * sz1 + j];
        int result = 0;
        int t2 = 0;
        int t1 = m[i][j];
        if (j - 1 >= 0 && t1 > m[i][j - 1])
        {
            if (arr2[i * sz1 + j - 1] == 0)     // 这个没有必要，直接recursiona1就可以了，因为方法最开始会判断是否为0，不为0才继续递归。速度是这种快。
            {
                t2 = recursiona1(m, arr2, i, j - 1);
                if (t2 > result)
                    result = t2;
            }
            if (arr2[i * sz1 + j - 1] > result)
            {
                result = arr2[i * sz1 + j - 1];
            }
        }
        if (i - 1 >= 0 && t1 > m[i - 1][j])
        {
            if (arr2[(i - 1) * sz1 + j] == 0)
            {
                t2 = recursiona1(m, arr2, i - 1, j);
                if (t2 > result)
                    result = t2;
            }
            if (arr2[(i - 1) * sz1 + j] > result)
            {
                result = arr2[(i - 1) * sz1 + j];
            }
        }
        if (i + 1 < m.size() && t1 > m[i + 1][j])
        {
            if (arr2[(i + 1) * sz1 + j] == 0)
            {
                t2 = recursiona1(m, arr2, i + 1, j);
                if (t2 > result)
                    result = t2;
            }
            if (arr2[(i + 1) * sz1 + j] > result)
            {
                result = arr2[(i + 1) * sz1 + j];
            }
        }
        if (j + 1 < m[0].size() && t1 > m[i][j + 1])
        {
            if (arr2[i * sz1 + j + 1] == 0)
            {
                t2 = recursiona1(m, arr2, i, j + 1);
                if (t2 > result)
                    result = t2;
            }
            if (arr2[i * sz1 + j + 1] > result)
            {
                result = arr2[i * sz1 + j + 1];
            }
        }
        result++;
        arr2[i * sz1 + j] = result;
        return result;
    }

};

int main()
{
//    vector<vector<int>> v = {
//        {9,9,4},
//        {6,6,8},
//        {2,1,1}
//    };

//    vector<vector<int>> v = {
//        {3,4,5},
//        {3,2,6},
//        {2,2,1}
//    };

    vector<vector<int>> v = {
        {0},{1},{5},{5}
    };

    LT0329 lt;
    cout<<endl<<lt.lt0329a(v)<<endl;

    cout<<max(1111,32222)<<endl;

    return 0;
}
