
#include "../header/myheader.h"

class LT0052
{
public:

// D D

//vector<int> spaces(5*n-2, 1);
//    int backtrack(int numSols, int row, int n, vector<int> &spaces) {
//        if (row == n) {
//            return numSols + 1;
//        }
//        for (int col = 0; col < n; col++) {
//            int diagA = n + row + col;
//            int diagB = 3*n-1 + (n-1-row) + col;
//            if (spaces[col] && spaces[diagA] && spaces[diagB]) {
//                spaces[col] = spaces[diagA] = spaces[diagB] = 0;
//                numSols = backtrack(numSols, row+1, n, spaces);
//                spaces[col] = spaces[diagA] = spaces[diagB] = 1;
//            }
//
//        }
//        return numSols;
//    }


//    private void dfs(int row, int n, int column, int diag, int antiDiag) {
//        if (row == n) {
//            ++count;
//            return;
//        }
//        for (int i = 0; i < n; ++i) {
//            boolean isColSafe = ((1 << i) & column) == 0;
//            boolean isDiagSafe = ((1 << (n - 1 + row - i)) & diag) == 0;
//            boolean isAntiDiagSafe = ((1 << (row + i)) & antiDiag) == 0;
//            if (isColSafe && isDiagSafe && isAntiDiagSafe) {
//                dfs(row + 1, n, (1 << i) | column, (1 << (n - 1 + row - i)) | diag, (1 << (row + i)) | antiDiag);
//            }
//        }
//    }




//Runtime: 8 ms, faster than 45.76% of C++ online submissions for N-Queens II.
//Memory Usage: 6.6 MB, less than 44.98% of C++ online submissions for N-Queens II.
    int lt0052a(int n)
    {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            filla1(arr, 0, i, 1);
            dfsa1(arr, 1);
            filla1(arr, 0, i, -1);
        }
        return ans;
    }
    int arr2[4][2] = {{1,1},{-1,-1},{1,-1},{-1,1}};
    void filla1(vector<vector<int>>& arr, int x, int y, int val)
    {
        int sz1 = arr.size();
        for (int i = 0; i < sz1; ++i)
        {
            arr[i][y] += val;
            arr[x][i] += val;
        }
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                int m = x + arr2[j][0] * i;
                int n = y + arr2[j][1] * i;
                if (m >= 0 && m < sz1 && n >= 0 && n < sz1)
                {
                    arr[m][n] += val;
                }
            }
        }
    }
    bool cana1(vector<vector<int>>& arr, int x, int y)
    {
        int sz1 = arr.size();
        if (arr[x][y] != 0)
            return false;
        return true;
    }
    int ans = 0;
    void dfsa1(vector<vector<int>>& arr, int row)
    {
        if (row >= arr.size())
        {
            ans++;
            return;
        }
        for (int j = 0; j < arr.size(); ++j)
        {
            if (cana1(arr, row, j))
            {
                filla1(arr, row, j, 1);
                dfsa1(arr, row + 1);
                filla1(arr, row, j, -1);
            }
        }
    }

};

int main()
{
//    int n = 4;
    int n = 1;

    LT0052 lt;

    cout<<lt.lt0052a(n);

    return 0;
}
