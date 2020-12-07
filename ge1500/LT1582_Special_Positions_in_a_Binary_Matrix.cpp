
#include "../header/myheader.h"

class LT1582
{
public:

// D D

//        int row[r];
//        int col[c];
//        memset(row, 0, sizeof(row));
//        memset(col, 0, sizeof(col));




//Runtime: 36 ms, faster than 91.37% of C++ online submissions for Special Positions in a Binary Matrix.
//Memory Usage: 13.3 MB, less than 64.73% of C++ online submissions for Special Positions in a Binary Matrix.
    int lt1582a(vector<vector<int>>& mat)
    {
//        int cntRow = 0;
//        int cntCol = 0;
//
//        return min(cntRow, cntCol);
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        vector<int> vr(sz1);
        vector<int> vc(sz2);
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                vr[i] += mat[i][j];
                vc[j] += mat[i][j];
            }
        }
        #ifdef __test
        showVectorInt(vr);
        showVectorInt(vc);
        #endif // __test

        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (mat[i][j] && vr[i] == 1 && vc[j] == 1)
                    ans++;
            }
        }
        return ans;
    }

};

int main()
{
    myvvi vv = {{1,0,0},{0,0,1},{1,0,0}};

    LT1582 lt;

    cout<<lt.lt1582a(vv);

    return 0;
}
