
#include "../../header/myheader.h"

class LT
{
public:

// D D

//    int dfs( int i, int j, vector<vector<int>>& mat){
//        int m = mat.size();
//        int n = mat[0].size();
//        int count =0;
//        stack<pair<int,int> > stk;
//        stk.push(make_pair(i,j));
//        while(!stk.empty()){
//            int a = stk.top().first;
//            int b = stk.top().second;
//            stk.pop();
//            if(mat[a][b]) count++;
//            mat[a][b] = 0;
//            if(a < m-1 && mat[a+1][b]) stk.push(make_pair(a+1, b));
//            if(a > 0 && mat[a-1][b]) stk.push(make_pair(a-1, b));
//            if(b > 0 && mat[a][b-1]) stk.push(make_pair(a, b-1));
//            if(b < n-1 && mat[a][b+1]) stk.push(make_pair(a, b+1));
//        }
//        return count;
//    }
// 尾递归转为stack


// AC
// 好慢，36ms，大部分12-24， 代码都一样(差不多)。
// 螺旋 -/-> dp
    int lta(vector<vector<int>>& grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] != 0)
                {
                    ans = max(ans, dfsa1(grid, i, j));
                }
            }
        }
        return ans;
    }

    int dfsa1(vector<vector<int>>& vvi, int i, int j)
    {
        if (i < 0 || j < 0 || i >= vvi.size() || j >= vvi[0].size() || vvi[i][j] == 0)
            return 0;
        int ans = 1;
        vvi[i][j] = 0;
        ans += dfsa1(vvi, i + 1, j);
        ans += dfsa1(vvi, i - 1, j);
        ans += dfsa1(vvi, i, j + 1);
        ans += dfsa1(vvi, i, j - 1);
        return ans;
    }

};

int main()
{
    myvvi vv = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};

    LT lt;

    cout<<lt.lta(vv)<<endl;

    return 0;
}
