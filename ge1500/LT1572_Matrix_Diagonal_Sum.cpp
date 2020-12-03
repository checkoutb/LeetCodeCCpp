
#include "../header/myheader.h"

class LT1572
{
public:

// D D


//    return accumulate(begin(m), end(m), 0, [&](int s, vector<int> &v){
//       return s + v[++i] + (i == v.size() - i - 1 ? 0 : v[v.size() - i - 1]);
//    });


//return sum(sum(r[j] for j in {i, len(r) - i - 1}) for i, r in enumerate(m))


//Runtime: 28 ms, faster than 65.35% of C++ online submissions for Matrix Diagonal Sum.
//Memory Usage: 11.5 MB, less than 79.41% of C++ online submissions for Matrix Diagonal Sum.
    int lt1572a(vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            ans += (mat[i][i] + mat[i][sz1 - 1 - i]);
        }
        if (sz1 % 2)
            ans -= mat[sz1 / 2][sz1 / 2];
        return ans;
    }

};

int main()
{

    LT1572 lt;


    return 0;
}
