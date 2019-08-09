
#include "../header/myheader.h"

class LT0417
{
public:


// details
//        vector<vector<bool>> pacific(m, vector<bool>(n, false));
//        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
//        for (int i = 0; i < m; ++i) {
//            dfs(matrix, pacific, INT_MIN, i, 0);
//            dfs(matrix, atlantic, INT_MIN, i, n - 1);
//        }
//        for (int i = 0; i < n; ++i) {
//            dfs(matrix, pacific, INT_MIN, 0, i);
//            dfs(matrix, atlantic, INT_MIN, m - 1, i);
//        }
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (pacific[i][j] && atlantic[i][j]) {
//                    res.push_back({i, j});
//                }
//            }
//        }
//        return res;
//    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int pre, int i, int j) {
//        int m = matrix.size(), n = matrix[0].size();
//        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < pre) return;
//        visited[i][j] = true;
//        dfs(matrix, visited, matrix[i][j], i + 1, j);
//        dfs(matrix, visited, matrix[i][j], i - 1, j);
//        dfs(matrix, visited, matrix[i][j], i, j + 1);
//        dfs(matrix, visited, matrix[i][j], i, j - 1);
//    }
// 只需要以4条边为起始来dfs。。。 第一次可能就错在这里。而且第一次dp数组只有一个。更复杂了。。



// 基本都是上面这种。


//Runtime: 52 ms, faster than 65.77% of C++ online submissions for Pacific Atlantic Water Flow.
//Memory Usage: 15.6 MB, less than 56.41% of C++ online submissions for Pacific Atlantic Water Flow.

//......

    vector<vector<int>> lt0417b(vector<vector<int>>& matrix)
    {
        vector<vector<int>> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ans;
        vector<vector<int>> dp1(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> dp2(matrix.size(), vector<int>(matrix[0].size(), 0));
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();

        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz2; j++)
            {
                funb1(matrix, dp1, i, j);
            }
        }

        std::reverse(matrix.begin(), matrix.end());
        for (vector<vector<int>>::iterator it1 = matrix.begin(); it1 != matrix.end(); it1++)
        {
            std::reverse((*it1).begin(), (*it1).end());
        }

        for (int i = 0; i < sz1; i++)
            for (int j = 0; j < sz2; j++)
                funb1(matrix, dp2, i, j);

        std::reverse(dp2.begin(), dp2.end());
        for (int i = 0; i < sz1; i++)
        {
            std::reverse(dp2[i].begin(), dp2[i].end());
        }

        for (int i = 0; i < sz1; i++)
            for (int j = 0; j < sz2; j++)
            {
                if (dp1[i][j] + dp2[i][j] == 2)
                    ans.push_back({i, j});
            }

        return ans;
    }

    int funb1(vector<vector<int>>& m, vector<vector<int>>& dp, int i, int j)
    {
        int flag = ((i == 0) || (j == 0));

        if (flag == 1 || dp[i][j] == 1)
            return dp[i][j] = 1;

        bool f1 = false;
        if (m[i][j] >= m[i][j - 1])
        {
            flag |= (dp[i][j - 1] == 1);
            if (dp[i][j - 1] == -1)
                f1 = true;
        }
        if (m[i][j] >= m[i - 1][j])
        {
            flag |= (dp[i - 1][j] == 1);
            if (dp[i - 1][j] == -1)
                f1 = true;
        }

        if (flag == 1)
        {
            dp[i][j] = 1;
        }
        else
        {
            if (f1)
                dp[i][j] = -1;
            if (!f1 && i + 1 < m.size())
            {
                if (m[i][j] >= m[i + 1][j])
                {
                    dp[i][j] = -1;
                }
            }
            if (dp[i][j] != -1 && j + 1 < m[0].size())
            {
                if (m[i][j] >= m[i][j + 1])
                {
                    dp[i][j] = -1;
                }
            }
        }
        if (dp[i][j] == 1)
            fillb1(m, dp, i, j, dp[i][j]);

        return dp[i][j];
    }

    int fillb1(vector<vector<int>>& m, vector<vector<int>>& dp, int i, int j, int val)
    {
        if (i + 1 < m.size() && dp[i + 1][j] == -1 && m[i + 1][j] >= m[i][j])
        {
            dp[i + 1][j] = val;
            fillb1(m, dp, i + 1, j, val);
        }
        if (j + 1 < m[0].size() && dp[i][j + 1] == -1 && m[i][j + 1] >= m[i][j])
        {
            dp[i][j + 1] = val;
            fillb1(m, dp, i, j + 1, val);
        }
        if (dp[i - 1][j] == -1 && m[i - 1][j] >= m[i][j])
        {
            dp[i - 1][j] = val;
            fillb1(m, dp, i - 1, j, val);
        }
        if (dp[i][j - 1] == -1 && m[i][j - 1] >= m[i][j])
        {
            dp[i][j - 1] = val;
            fillb1(m, dp, i, j - 1, val);
        }
        return dp[i][j];
    }




    // heap buffer overflow...越界or容量不够？ 前者，一直以为是后者。。。
    vector<vector<int>> lt0417a(vector<vector<int>>& matrix)
    {
        vector<vector<int>> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ans;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

        recursiona1(matrix, dp, 0, 0);

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                recursiona1(matrix, dp, i, j);
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (dp[i][j] == 3)
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    int recursiona1(vector<vector<int>>& m, vector<vector<int>>& dp, int i, int j)
    {
        int flag = 0;
        if (i == 0 || j == 0)
            flag = flag | 1;
        if (i == m.size() - 1 || j == m[0].size() - 1)
            flag = flag | 2;
        if (flag == 3)
        {
            dp[i][j] = 3;
        }

        if (dp[i][j] == 3)
        {
            return dp[i][j];
        }

        int t1 = 0;
        if (i - 1 >= 0 && m[i][j] >= m[i - 1][j])
        {
            t1 = dp[i - 1][j];
            flag |= t1;
        }

        if (flag != 3 && i + 1 < m.size() && m[i][j] >= m[i + 1][j])
        {
            if (dp[i + 1][j] != 0)
                t1 = dp[i + 1][j];
            else
                t1 = recursiona1(m, dp, i + 1, j);
            flag |= t1;
        }

        if (flag != 3 && j - 1 >= 0 && m[i][j] >= m[i][j - 1])
        {
            t1 = dp[i][j - 1];
            flag |= t1;
        }

        if (flag != 3 && j + 1 < m.size() && m[i][j] >= m[i][j + 1])
        {
            if (dp[i][j + 1] != 0)
                t1 = dp[i][j + 1];
            else
                t1 = recursiona1(m, dp, i, j + 1);
            flag |= t1;
        }
        dp[i][j] = flag;
        return flag;
    }
};

int main()
{
//    vector<vector<int>> vv = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
//    vector<vector<int>> vv = {{1,2},{3,1}};

    vector<vector<int>> vv =
    {
        {4,2,16,13,8,7},
        {16,0,2,9,0,8},
        {15,10,8,5,17,19},
        {9,9,4,0,19,2},
        {10,12,9,10,13,19},
        {4,14,14,14,9,12},
        {7,0,14,8,2,3},
        {16,6,18,11,10,17},
        {12,2,6,8,18,1},
        {13,2,12,3,9,16},
        {8,12,3,8,3,17},
        {8,13,18,7,17,14},
        {0,1,10,7,18,4},
        {15,15,5,13,19,16},
        {16,10,2,18,17,7},
        {19,19,14,13,19,7},
        {17,18,12,8,15,15},
        {10,5,2,6,3,9},
        {16,14,8,19,16,17},
        {7,5,12,18,12,2},
        {14,10,12,16,9,17},
        {1,18,19,6,1,3},
        {4,3,5,10,14,18},
        {3,3,4,14,15,7},
        {14,2,15,11,15,13},
        {10,0,10,2,7,3},
        {7,14,19,10,14,5},
        {0,9,5,10,10,0}
    };

//    vector<vector<int>> vv = {{100,118,119,111},
//        {4,3,5,11},
//        {3,3,4,16}
//    };

    LT0417 lt;
//    cout<<endl<<"result : "<<lt.lt0417a(vv)<<endl;
    vv = lt.lt0417b(vv);
    cout<<endl<<endl;
    for (int i = 0; i < vv.size(); i++)
    {
        for_each(vv[i].begin(), vv[i].end(), fun_cout);
        cout<<endl;
    }

    return 0;
}
