
#include "../../header/myheader.h"

class LT
{
public:

// D D

// dp， 二维数组， 移一步， 移2步，....移动max步。
// 子问题是  移动步数


// details 中 recursion 占了绝大多数。





// ... 上一次好像是 bottom-up的。。。。。我。。。

// 非常的不真实的感觉。冥冥之中。。
// AC
// 数量不大，来个3维数组。  场地坐标 + 还能踢几次。       2维数组+ map
// dfs + memo == top-down dp
    int lta(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> vvvi(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        int ans = dfsa1(vvvi, startRow, startColumn, maxMove);
        return ans;
    }
    const int mod = 1E9 + 7;
    int dfsa1(vector<vector<vector<int>>>& vvvi, int i, int j, int cnt)
    {
        #ifdef __test
//        cout<<i<<", "<<j<<", "<<cnt<<endl;
        #endif // __test
        if (cnt < 0)
            return 0;
        if (i >= vvvi.size() || i < 0 || j < 0 || j >= vvvi[0].size())
            return 1;
        if (vvvi[i][j][cnt] != -1)
            return vvvi[i][j][cnt];
        // i-+cnt >0 && < vvvi.size  return 0
        int t2 = 0;
        t2 += dfsa1(vvvi, i + 1, j, cnt - 1);
        if (t2 >= mod)
            t2 %= mod;
        t2 += dfsa1(vvvi, i - 1, j, cnt - 1);
        if (t2 >= mod)
            t2 %= mod;
        t2 += dfsa1(vvvi, i, j + 1, cnt - 1);
        if (t2 >= mod)
            t2 %= mod;
        t2 += dfsa1(vvvi, i, j - 1, cnt - 1);           // for 0-3...
        if (t2 >= mod)
            t2 %= mod;
        vvvi[i][j][cnt] = t2;
        return t2;
    }

};

int main()
{
//    myvi v = {2,2,2,0,0};
    myvi v = {1,3,3,-0,1};

    LT lt;

    cout<<lt.lta(v[0], v[1], v[2], v[3], v[4]);

    return 0;
}
