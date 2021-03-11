
#include "../header/myheader.h"

class LT1727
{
public:

// D D

//        for(i = 0; i < m; i++)
//            for(j = 1; j < n; j++)
//                if(matrix[j][i] == 1)
//                    matrix[j][i] = matrix[j-1][i] + matrix[j][i];
//                else
//                    matrix[j][i] = 0;
//        for(i = 0; i < n; i++) {
//            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
//            for(j = 0; j < m; j++)
//                ans = max(ans, matrix[i][j] * (j + 1));
//        }




//Runtime: 140 ms, faster than 93.13% of C++ online submissions for Largest Submatrix With Rearrangements.
//Memory Usage: 60.6 MB, less than 64.62% of C++ online submissions for Largest Submatrix With Rearrangements.
// hint 1 & 2
//For each column, find the number of consecutive ones ending at each position.
//For each row, sort the cumulative ones in non-increasing order and "fit" the largest submatrix.
    int lt1727c(vector<vector<int>>& matrix)
    {
        vector<int> vi(matrix[0].size());
        vector<int> v2(matrix[0].size());
        int ans = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                vi[j] = matrix[i][j] == 0 ? 0 : (v2[j] + 1);
            }
            v2 = vi;
            sort(begin(vi), end(vi));
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                ans = max(ans, vi[j] * int (matrix[0].size() - j));
            }
        }
        return ans;
    }


// tle.   最多再加  while (sz > 0 && ans < sz * sz),   while (matrix.back() is all zero) {pop again}
// .. for 调用 lt1727a... 想不出了。
    int lt1727b(vector<vector<int>>& matrix)
    {
        int ans = 0;
        while (matrix.size() > 0)
        {
            ans = max(ans, lt1727a(matrix));
            matrix.pop_back();
        }
        return ans;
    }

// ... 中间的矩阵。。 error
    int lt1727a(vector<vector<int>>& matrix)
    {
        vector<int> vi;
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            int len = 0;
            for (int i = matrix.size() - 1; i >= 0; --i)
            {
                if (matrix[i][j] == 1)
                {
                    len++;
                }
                else
                {
                    break;
                }
            }
            vi.push_back(len);
        }
        std::sort(begin(vi), end(vi));
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
//        vector<int>::iterator it = begin(vi);
//        while (it != )
        int t2 = 0;
        int ans = 0;
        for (vector<int>::iterator it = std::upper_bound(begin(vi), end(vi), t2); it != end(vi); it = upper_bound(begin(vi), end(vi), t2))
        {
            t2 = *it;
            int len = std::distance(it, end(vi));
            ans = max(t2 * len, ans);
        }
        return ans;
    }

};

int main()
{
//    myvvi vv = {{0,0,1},{1,1,1},{1,0,1}};
//    myvvi vv = {{1,0,1,0,1}};
//    myvvi vv = {{1,1,0},{1,0,1}};
//    myvvi vv = {{0,0},{0,0}};

//    // 75
    myvvi vv = {
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,0,0,1,1,1,0,1,0,1,0,1,1,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,0,1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1},
    {1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1},
    {1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1},
    {1,1,1,0,0,1,1,0,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,0}};

    LT1727 lt;

    cout<<lt.lt1727c(vv)<<endl;

    return 0;
}
