
#include "../header/myheader.h"

class LT0764
{
public:


// discuss
//    for (int i = 0; i < N; i++) {
//        for (int j = 0, k = N - 1, l = 0, r = 0, u = 0, d = 0; j < N; j++, k--) {
//            grid[i][j] = Math.min(grid[i][j], l = (grid[i][j] == 0 ? 0 : l + 1));  // left direction
//            grid[i][k] = Math.min(grid[i][k], r = (grid[i][k] == 0 ? 0 : r + 1));  // right direction
//            grid[j][i] = Math.min(grid[j][i], u = (grid[j][i] == 0 ? 0 : u + 1));  // up direction
//            grid[k][i] = Math.min(grid[k][i], d = (grid[k][i] == 0 ? 0 : d + 1));  // down direction
//        }
//    }
// 对每行/列，从2侧往中间，碰到0，就重置长度为0，不是0，长度就+1， 4个方向的长度的min就是这个点的结果。


//Runtime: 416 ms, faster than 19.74% of C++ online submissions for Largest Plus Sign.
//Memory Usage: 33.3 MB, less than 100.00% of C++ online submissions for Largest Plus Sign.
    int lt764a(int N, vector<vector<int>>& mines)
    {
        vector<int> arr(N, 1);
        vector<vector<int>> arr2(N, arr);           // 能直接一条的 vector<vector<>> a(N, new vector<int>)
        int ans = 0;

        for (vector<int> v2 : mines)
        {
            arr2[v2[0]][v2[1]] = 0;
        }
        for (int i = ans; i < N - ans; i++)
        {
            for (int j = ans; j < N - ans; j++)
            {
                ans = max(ans, finda1(arr2, i , j, N));
            }
        }

        return ans;
    }

    int finda1(vector<vector<int>>& arr2, int i, int j, int N)
    {
        if (!arr2[i][j])
            return 0;
        int k = 1;
        while(i >= k && j >= k && i + k < N && j + k < N && arr2[i + k][j] && arr2[i - k][j] && arr2[i][j + k] && arr2[i][j - k])
        {
            k++;
        }
        return k;
    }


};

int main()
{

    int N = 5;
    vector<vector<int>> mines = {{4,2}};

    LT0764 lt;

    cout<<lt.lt764a(N, mines)<<endl;

    return 0;
}
