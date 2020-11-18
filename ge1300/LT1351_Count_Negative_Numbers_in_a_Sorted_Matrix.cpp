
#include "../header/myheader.h"

class LT1351
{
public:

// D D

//        int res = 0;
//        int m = grid.length;
//        int n = grid[0].length;
//        int i = 0;
//        int j = n - 1;
//        while (i < m && j >= 0) {
//            if (grid[i][j] < 0) {
//                res += m - i;
//                j--;
//            } else {
//                i++;
//            }
//        }
//        return res;
// >0 就可以换行， <0 说明 这个点 下面所有的都是负数， 所以 + (m-i) ,并且 j从最后开始，第一次 grid[0][n-1] 如果是负数，那么 0,n-1 下面的全是负数。




//Runtime: 32 ms, faster than 51.58% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
//Memory Usage: 10.8 MB, less than 26.49% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
    int lt1351a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size(), sz2 = grid[0].size();
        int mnj = 0;
        int ans = 0;
        for (int i = sz1 - 1; i >= 0 && mnj < sz2; --i)
        {
            for (int j = sz2 - 1; j >= mnj; --j)
            {
                if (grid[i][j] >= 0)
                {
                    mnj = j + 1;
                    break;
                }
                ans++;
            }
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> vv = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};

    LT1351 lt;

    cout<<lt.lt1351a(vv);

    return 0;
}
