
#include "../header/myheader.h"

class LT1074
{
public:

// D D


//        int res = 0, m = A.size(), n = A[0].size();
//        for (int i = 0; i < m; i++)
//            for (int j = 1; j < n; j++)
//                A[i][j] += A[i][j - 1];
//
//        unordered_map<int, int> counter;
//        for (int i = 0; i < n; i++) {
//            for (int j = i; j < n; j++) {
//                counter = {{0,1}};
//                int cur = 0;
//                for (int k = 0; k < m; k++) {
//                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
//                    res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
//                    counter[cur]++;
//                }
//            }
//        }
//        return res;
// 前缀和，
// i-j列间， 计算==的和。




// 4层for的 里面2层， 要不要带上 ==i,==j . 带上的时候， 横减，竖减， 会把 i,j减去的，所以不能。  这个会变成 kongbai?
//Runtime: 1380 ms, faster than 19.20% of C++ online submissions for Number of Submatrices That Sum to Target.
//Memory Usage: 9.4 MB, less than 86.59% of C++ online submissions for Number of Submatrices That Sum to Target.
    int lt1074a(vector<vector<int>>& matrix, int target)
    {
        int ans = 0;
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();
        vector<vector<int>> vv(sz1, vector<int>(sz2));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                vv[i][j] = matrix[i][j] + (i == 0 ? 0 : vv[i - 1][j]) + (j == 0 ? 0 : vv[i][j - 1]) - ((i > 0 && j > 0) ? vv[i - 1][j - 1] : 0);
                if (vv[i][j] == target)
                {
                    ans++;
                    #ifdef __test
                    cout<<i<<", "<<j<<endl;
                    #endif // __test
                }
                int tar = vv[i][j] - target;
                for (int m = 0; m < i; ++m)
                {
                    for (int n = 0; n < j; ++n)
                    {
                        if (m == i && n == j)
                            break;
                        if (vv[m][j] + vv[i][n] - vv[m][n] == tar)
                        {
                            ans++;
                            #ifdef __test
                            cout<<i<<", "<<j<<", "<<m<<", "<<n<<" . .. "<<tar<<", "<<vv[m][j]<<" || "<<vv[i][n]<<" . "<<vv[m][n]<<endl;
                            #endif // __test
                        }
                    }
                }
                for (int m = 0; m < i; ++m)
                {
                    if (vv[i][j] - vv[m][j] == target)
                        ans++;
                }
                for (int n = 0; n < j; ++n)
                {
                    if (vv[i][j] - vv[i][n] == target)
                        ans++;
                }
            }
        }
        #ifdef __test
        for (myvi& v : vv)
        {
            for (int i : v)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return ans;
    }

};

int main()
{
//    myvvi vv = {{0,1,0},{1,1,1},{0,1,0}};
//    int tar = 0;

//    myvvi vv = {{1,-1},{-1,1}};
//    int tar = 0;

    myvvi vv = {{111}};
    int tar = 0;

    LT1074 lt;

    cout<<lt.lt1074a(vv, tar);

    return 0;
}
