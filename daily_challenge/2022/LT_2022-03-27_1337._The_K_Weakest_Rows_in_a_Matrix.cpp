
#include "../../header/myheader.h"

class LT
{
public:

// D D

//    set<pair<int, int>> m;
//    for (auto i = 0; i < mat.size(); ++i) {
//        auto p = accumulate(begin(mat[i]), end(mat[i]), 0);
//        m.insert({p, i});
//    }
//    vector<int> res;
//    for (auto it = begin(m); k > 0; ++it, --k)
//        res.push_back(it->second);

// lower_bound



//Runtime: 23 ms, faster than 24.07% of C++ online submissions for The K Weakest Rows in a Matrix.
//Memory Usage: 10.3 MB, less than 99.00% of C++ online submissions for The K Weakest Rows in a Matrix.
// 士兵少，  相同则看 row
    vector<int> lta(vector<vector<int>>& mat, int k)
    {
        vector<int> ans(k, 0);
        int sz1 = mat.size(), sz2 = mat[0].size();
        int j = -1;
        for (int i = 0; i < k;)
        {
            for (int m = 0; m < sz1; ++m)
            {
                if (i >= k)
                    break;
                if (j + 1 == sz2 && mat[m][j] == 1)
                {
                    ans[i++] = m;
                    continue;
                }
                if (j == -1)
                {
                    if (mat[m][0] == 0)
                        ans[i++] = m;
                    continue;
                }
                if (mat[m][j] == 1 && mat[m][j + 1] == 0)
                {
                    ans[i++] = m;
                }
            }
            j++;
        }
        return ans;
    }

};

int main()
{

    LT lt;

//    myvvi vv = {{1,1,0,0,0},
//        {1,1,1,1,0},
//        {1,0,0,0,0},
//        {1,1,0,0,0},
//        {1,1,1,1,1}
//    };
//    int k = 3;

//    myvvi vv = {{1,0},{1,0},{1,0},{1,1}};
//    int k = 4;

    myvvi vv = {{1,0},{0,0},{1,0}};
    int k = 2;

    myvi v = lt.lta(vv, k);

    showVectorInt(v);

    return 0;
}
