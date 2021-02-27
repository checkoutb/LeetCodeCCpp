
#include "../header/myheader.h"

class LT1072
{
public:

// D D

//Find the i-th row, which has the most same or totaly different rows in the matrix.



//  while (m.size() > res) {
//    vector<vector<int>> m1;
//    for (auto i = 1, j = 0; i < m.size(); ++i) {
//      for (j = 0; j < m[i].size() && m[0][0] ^ m[i][0] == m[0][j] ^ m[i][j]; ++j);
//      if (j != m[i].size()) m1.push_back(m[i]);
//    }
//    res = max(res, m.size() - m1.size());
//    m = m1;
//  }
//  return res;
// m1是 无法 和 第一行 完全相等/完全相反 的，  所以m.size() - m1.size() 就是 和第一行完全==或者完全!=， 就是一种结果。
// 直接剔除了 和第一行 完全==/!= 的 行.  外层的while 也能加速。
// m[0][0] ^ m[i][0] == m[0][j] ^ m[i][j],  用各自的第一个char 来定义 这2行是完全==还是完全!=, 然后当 后续出现 不满足的，就退出。



// .. 现在这个 和之前tle的 差不多，就是多了 all1,all0， 加速了，所以过了。。。

//Runtime: 1368 ms, faster than 5.32% of C++ online submissions for Flip Columns For Maximum Number of Equal Rows.
//Memory Usage: 64.5 MB, less than 86.17% of C++ online submissions for Flip Columns For Maximum Number of Equal Rows.
// 感觉 只需要 对每一行判断下， 如果这行 全0/1，那么 整个矩阵 有多少 行是元素值唯一的。 毕竟一行确定后，其他行也就定下来了。
    int lt1072a(vector<vector<int>>& matrix)
    {
        unordered_set<int> all1;
        unordered_set<int> all0;
        int ans = 0;
        vector<bool> chg(matrix[0].size());
        for (int i = 0; i < matrix.size(); ++i)
        {
            vector<int>& v = matrix[i];
            if (all1.find(i) == all1.end())
            {
                for (int j = 0; j < v.size(); ++j)
                {
                    chg[j] = (v[j] != 1);
                }
                int t2 = allequala1(matrix, chg, all1, all0);
                ans = max(ans, t2);
            }
            if (all0.find(i) == all0.end())
            {
                for (int j = 0; j < v.size(); ++j)
                    chg[j] = (v[j] != 0);
                int t2 = allequala1(matrix, chg, all1, all0);
                ans = max(ans, t2);
            }
        }

        return ans;
    }
    int allequala1(vector<vector<int>>& vv, vector<bool>& chg, unordered_set<int>& all1, unordered_set<int>& all0)
    {
        int ans = 0;
        for (int i = 0; i < vv.size(); ++i)
        {
            vector<int>& v = vv[i];
            int t2 = 0;     // 1<<0   1<<1
            for (int j = 0; j < v.size(); ++j)
            {
                t2 |= 1 << (chg[j] ? (v[j] + 1) % 2 : v[j]);
            }
            if (t2 < 3)
            {
                ans++;
                if (t2 == 1)
                    all0.insert(i);
                else
                    all1.insert(i);
            }
        }
        return ans;
    }

};

int main()
{
//    myvvi vv = {{0,1},{1,1}};
//    myvvi vv = {{0,1},{1,0}};
    myvvi vv = {{0,0,0},{0,0,1},{1,1,0}};

    LT1072 lt;

    cout<<lt.lt1072a(vv)<<endl;

    return 0;
}
