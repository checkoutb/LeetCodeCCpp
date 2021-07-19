
#include "../header/myheader.h"

class LT1905
{
public:


// D D

//int dfs(vector<vector<int>> &A, vector<vector<int>> &B, int i, int j)
//{
//    int res=1;
//    if(i<0 || i==A.size() || j<0 || j==A[0].size() || B[i][j]==0)
//    {
//        return 1;
//    }
//    B[i][j]=0;
//    res = res & dfs(A, B, i+1, j);
//    res = res & dfs(A, B, i-1, j);
//    res = res & dfs(A, B, i, j+1);
//    res = res & dfs(A, B, i, j-1);
//    return res & A[i][j];
//}


//flood-fill
// 第一次知道这种算法的名字。。。
// /ff


//int dir[5] = {0, 1, 0, -1, 0};
//pair<int, int> dfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int i, int j) {
//    if (i < 0 || j < 0 || i >= g1.size() || j >= g1[0].size() || g2[i][j] == 0)
//        return {0, 0};
//    g2[i][j] = 0;
//    pair<int, int> res{g1[i][j], 1};
//    for (int d = 0; d < 4; ++d) {
//        auto [cnt1, cnt2] = dfs(g1, g2, i + dir[d], j + dir[d + 1]);
//        res.first += cnt1;
//        res.second += cnt2;
//    }
//    return res;
//}
//int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
//    int m = g1.size(), n = g1[0].size(), res = 0;
//    for (int i = 0; i < m; ++i)
//        for (int j = 0; j < n; ++j) {
//            auto [cnt1, cnt2] = dfs(g1, g2, i, j);
//            res += cnt1 > 0 && cnt1 == cnt2;
//        }
//    return res;
//}




//Runtime: 280 ms, faster than 78.79% of C++ online submissions for Count Sub Islands.
//Memory Usage: 87.3 MB, less than 98.60% of C++ online submissions for Count Sub Islands.
// 2中的小
// 访问2的岛，看是否被1覆盖了。
    int lt1905a(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int ans = 0;
        int sz1 = grid1.size();
        int sz2 = grid1[0].size();
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (grid2[i][j] == 1)
                {
                    grid1[i][j] += 2;
                }
            }
        }
        #ifdef __test
        for (myvi& vi : grid1)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if ((grid1[i][j] & 2) == 2 && (grid1[i][j] & 4) != 4)           // grid2 && not visited
                {
                    if (dfsa1(grid1, i, j))
                    {
                        #ifdef __test
                        cout<<i<<", "<<j<<endl;
                        #endif // __test
                        ans++;
                    }
                }
            }
        }
        #ifdef __test
        for (myvi& vi : grid1)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        return ans;
    }

    int arr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    // is sub island
    bool dfsa1(vector<vector<int>>& vvi, int i, int j)
    {
        int sz1 = vvi.size();
        int sz2 = vvi[0].size();
        if (i < 0 || j < 0 || i >= sz1 || j >= sz2)
            return true;
        if ((vvi[i][j] & 2) != 2)         // 0 or 1
        {
//            cout<<"1"<<endl;
            return true;
        }
        if ((vvi[i][j] & 4) == 4)     // visited                // 优先级。。。
        {
//            cout<<"2        "<<vvi[i][j]<<", "<<(vvi[i][j] & 4)<<endl;
            return true;        // if last visit the result is false, final result will be false.
        }
//        cout<<"3"<<endl;
        // must cover island.
        vvi[i][j] = vvi[i][j] | 4;
        bool ans = (vvi[i][j] & 1) == 1;
        for (int a = 0; a < 4; ++a)         // ... i..
        {
            ans &= dfsa1(vvi, i + arr[a][0], j + arr[a][1]);
        }

        return ans;
    }

};

int main()
{
//    cout<<(1 | 4)<<endl;
//    cout<<(3 & 2)<<endl;

//    myvvi vv1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
//    myvvi vv2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};

    myvvi vv1 = {{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}};
    myvvi vv2 = {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};


    LT1905 lt;

    cout<<lt.lt1905a(vv1, vv2)<<endl;

    return 0;
}
