
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //boolean[] cols = new boolean[n];     // columns   |
    //boolean[] d1 = new boolean[2 * n];   // diagonals \
    //boolean[] d2 = new boolean[2 * n];   // diagonals /
// 
// 
    //for (int col = 0; col < n; col++) {
    //    int id1 = col - row + n;
    //    int id2 = col + row;
    //    if (cols[col] || d1[id1] || d2[id2]) continue;
    //    cols[col] = true; d1[id1] = true; d2[id2] = true;
    //    backtracking(row + 1, cols, d1, d2, n);
    //    cols[col] = false; d1[id1] = false; d2[id2] = false;
    //}
    //..45度135度，x,y有规律。





//Runtime: 11 ms, faster than 39.00 % of C++ online submissions for N - Queens II.
//Memory Usage : 6.2 MB, less than 46.51 % of C++ online submissions for N - Queens II.
    int lta(int n)
    {
        vector<vector<bool>> vvb(n, vector<bool>(n, false));
        return dfsa1(vvb, 0);
    }

    // vvb: true -> Queue
    int dfsa1(vector<vector<bool>>& vvb, int row)
    {
        if (row == vvb.size())
        {
            return 1;
        }
        int ans = 0;
        for (int j = 0; j < vvb.size(); ++j)
        {
            if (valida1(vvb, row, j))
            {
                vvb[row][j] = true;
                ans += dfsa1(vvb, row + 1);
                vvb[row][j] = false;
            }
        }
#ifdef __test
        cout << row << ", " << ans << endl;
#endif
        return ans;
    }

    bool valida1(vector<vector<bool>>& vvb, int i, int j)
    {
        int ja = j - 1, jb = j, jc = j + 1;
        for (int ia = i - 1; ia >= 0; --ia)
        {
            if ((vvb[ia][jb]) || (ja >= 0 && vvb[ia][ja]) || (jc < vvb.size() && vvb[ia][jc]))
            {
#ifdef __test
                cout << "fail..." << i << ", " << j << endl;
#endif
                return false;
            }
            ja--;
            jc++;
        }
#ifdef __test
        cout << ",,," << i << ", " << j << ", " << endl;
#endif
        return true;
    }
};

int main()
{

    LT lt;

    int n = 4;

    cout << lt.lta(n) << endl;

    return 0;
}
