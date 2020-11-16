
#include "../header/myheader.h"

class LT1314
{
public:


// D D

//        vector<vector<int>> p(r+1, vector<int>(c+1, 0));
//        for(int i = 1 ; i <= r ; i++) {
//            for(int j = 1 ; j <= c ; j++) {
//                p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1] + mat[i-1][j-1];
//            }
//        }
//                sum[i-1][j-1] = p[r2][c2] - p[r1-1][c2] - p[r2][c1-1] + p[r1-1][c1-1];





//Runtime: 20 ms, faster than 32.76% of C++ online submissions for Matrix Block Sum.
//Memory Usage: 9.9 MB, less than 27.08% of C++ online submissions for Matrix Block Sum.
    vector<vector<int>> lt1314a(vector<vector<int>>& mat, int K)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        vector<vector<int>> ans(sz1, vector<int>(sz2));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 1; j < sz2; ++j)
            {
                mat[i][j] += mat[i][j - 1];
            }
        }

//        #ifdef __test
//        for (vector<int>& vi : mat)
//        {
//            for (int i : vi)
//                cout<<i<<", ";
//            cout<<endl;
//        }
//        #endif // __test

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                int rmx = std::min(sz1 - 1, i + K);
                int rmn = std::max(0, i - K);
                int cmx = std::min(sz2 - 1, j + K);
                int cmn = std::max(0, j - K);
                int sum2 = 0;


                for (int k = rmn; k <= rmx; ++k)
                {
                    sum2 += (mat[k][cmx] - ((cmn - 1) < 0 ? 0 : mat[k][cmn - 1]));
                }
//                cout<<i<<", "<<j<<", "<<rmx<<", "<<rmn<<", "<<cmx<<", "<<cmn<<endl;
                ans[i][j] = sum2;
            }
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> vv = {{1,2,3},{4,5,6},{7,8,9}};
//    int k = 1;
    int k = 2;

    LT1314 lt;

    vector<vector<int>> ans = lt.lt1314a(vv, k);

    for (vector<int>& vi : ans)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
