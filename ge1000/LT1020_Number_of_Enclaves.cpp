
#include "../header/myheader.h"

class LT1020
{
public:

// D D

//        int count = 0, m = A.size(), n = A[0].size();
//        vector<vector<bool>> v(m, vector<bool>(n, false));
//        function<void(int,int)> dfs = [&](int i, int j) {                         // !!!!!
//            if (i < 0 || i >= m || j < 0 || j >= n) return;
//            if (v[i][j] || A[i][j] != 1) return;
//            v[i][j] = true;
//            count--;
//            dfs(i-1, j);
//            dfs(i, j-1);
//            dfs(i+1, j);
//            dfs(i, j+1);
//        };
//
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (A[i][j] == 1) {
//                    count++;
//                    if (i == 0 || j == 0 || i == m-1 || j == n-1)
//                        dfs(i, j);
//                }
//            }
//        }
//        return count;


//  return accumulate(begin(A), end(A), 0, [](int s, vector<int> &r)
//    { return s + accumulate(begin(r), end(r), 0); });





// ?? 搞不懂，今天所有的 内存都很爆炸，，但是这里没有用到 大量内存啊。
// 。。 detail里提供了内存的， 最少的是22mb,占了75.51%。。。所以不可能是 5.1% 的。
//Runtime: 116 ms, faster than 85.28% of C++ online submissions for Number of Enclaves.
//Memory Usage: 22.1 MB, less than 5.10% of C++ online submissions for Number of Enclaves.
// ??题目看了半天，，感觉是：grid外面全是1， 找到 不和外部连接的 岛的面积。
    int lt1020a(vector<vector<int>>& A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            filla1(A, i, 0);
            filla1(A, i, A[0].size() - 1);
        }
        for (int j = 0; j < A[0].size(); j++)
        {
            filla1(A, 0, j);
            filla1(A, A.size() - 1, j);
        }
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[0].size(); j++)
            {
                ans += A[i][j];
            }
        }
        return ans;
    }

    void filla1(vector<vector<int>>& A, int i, int j)
    {
        if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size())
            return;
        if (A[i][j] == 0)
            return;
        A[i][j] = 0;
        filla1(A, i, j + 1);
        filla1(A, i, j - 1);
        filla1(A, i + 1, j);
        filla1(A, i - 1, j);
    }

};

int main()
{

//    vector<vector<int>> vv = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    vector<vector<int>> vv = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};

    LT1020 lt;

    cout<<lt.lt1020a(vv)<<endl;

    return 0;
}
