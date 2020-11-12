
#include "../header/myheader.h"

class LT1222
{
public:


// D D

//        int a[8][8];
//        memset(a,0,sizeof(a));


//    for (auto i = -1; i <= 1; ++i)
//        for (auto j = -1; j <= 1; ++j) {
//            if (i == 0 && j == 0) continue;
//            auto x = k[0] + i, y = k[1] + j;
//            while (min(x, y) >= 0 && max(x, y) < 8) {
//                if (b[x][y]) {
//                    res.push_back({ x, y });
//                    break;
//                }
//                x += i, y += j;
//            }
//        }



//Runtime: 8 ms, faster than 68.70% of C++ online submissions for Queens That Can Attack the King.
//Memory Usage: 11.4 MB, less than 24.02% of C++ online submissions for Queens That Can Attack the King.
    vector<vector<int>> lt1222a(vector<vector<int>>& queens, vector<int>& king)
    {
        vector<vector<int>> vv(8, vector<int>(8, 0));
        for (vector<int>& q : queens)
            vv[q[0]][q[1]] = 1;
        vector<vector<int>> ans;
        bool got[8] = {false};
        int arr[8][2] = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        for (int i = 1; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (!got[j])
                {
                    int m = king[0] + i * arr[j][0];
                    int n = king[1] + i * arr[j][1];
                    if (m < 0 || n < 0 || m >= 8 || n >= 8)
                    {
                        got[j] = true;
                    }
                    else
                    {
                        if (vv[m][n] == 1)
                        {
                            ans.push_back({m, n});
                            got[j] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{

//    vector<vector<int>> q = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
//    vector<int> k = {0,0};

//    vector<vector<int>> q = {{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}};
//    vector<int> k = {3,3};

    vector<vector<int>> q = {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},
    {1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},
    {7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}};
    vector<int> k = {3,4};

    LT1222 lt;

    vector<vector<int>> vv = lt.lt1222a(q, k);

    for (vector<int>& v : vv)
    {
        cout<<v[0]<<", "<<v[1]<<endl;
    }

    return 0;
}
