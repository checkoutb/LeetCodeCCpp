
#include "../../header/myheader.h"

class LT
{
public:

// D D

// int m = nums.size(), n = nums[0].size(), o = m * n;




// AC
    vector<vector<int>> lta(vector<vector<int>>& mat, int r, int c)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        if (sz1 * sz2 != r * c)
            return mat;
        vector<vector<int>> vvi(r, vector<int>(c, 0));
        int idx = 0;
        while (idx < r * c)
        {
            vvi[idx / c][idx % c] = mat[idx / sz2][idx % sz2];
            idx++;
        }
        return vvi;
    }

};

int main()
{
    myvvi vv = {{1,2},{3,4}};
    int r(1), c{4};

    LT lt;

    myvvi vvi = lt.lta(vv, r, c);

    for (myvi& v : vvi)
    {
        for (int i : v)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
