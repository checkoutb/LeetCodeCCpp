
#include "../header/myheader.h"

class LT1072
{
public:

// D

// 每行转string， 相同的string 才会 经过一系列反转后 全0/1，  取 相同string 最多次发生的。。

//return max(collections.Counter(tuple(x ^ r[0] for x in r) for r in A).values())

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
// ????

// 先算下， 每行 需要修改多少个 才能全0/1， 然后 v 不满足时，直接不需要算。
// 71/85 tle...
// 暴力？   第1行全0/全1 的情况下， 一共多少。  第二行全0/1 。。
    int lt1072a(vector<vector<int>>& matrix)
    {
        int ans = 0;
        vector<int> v(matrix[0].size());

        for (int i = 0; i < matrix.size(); i++)
        {
            // all 1
            for (int j = 0; j < matrix[0].size(); j++)
            {
                v[j] = matrix[i][j] == 0 ? 1 : 0;
            }
            int cnt = 0;
            for (int m = 0; m < matrix.size(); m++)
            {
                int t2 = (matrix[m][0] + v[0]) % 2;
                bool alleq = true;
                for (int n = 1; n < matrix[0].size(); n++)
                {
                    if (t2 != (matrix[m][n] + v[n]) % 2)
                    {
                        alleq = false;
                        break;
                    }
                }
                if (alleq)
                    cnt++;
            }
            ans = max(ans, cnt);

            // all 0
            cnt = 0;
            for (int j = 0; j < matrix[0].size(); j++)
            {
                v[j] = matrix[i][j] == 0 ? 0 : 1;
            }
            for (int m = 0; m < matrix.size(); m++)
            {
                int t2 = (matrix[m][0] + v[0]) % 2;
                bool alleq = true;
                for (int n = 1; n < matrix[0].size(); n++)
                {
                    if (t2 != (matrix[m][n] + v[n]) % 2)
                    {
                        alleq = false;
                        break;
                    }
                }
                if (alleq)
                    cnt++;
            }
            ans = max(ans, cnt);

        }

        return ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{0,0,0},{0,0,1},{1,1,0}};
//    vector<vector<int>> vv = {{0,1},{1,0}};
    vector<vector<int>> vv = {{0,1},{1,1}};

    LT1072 lt;

    cout<<lt.lt1072a(vv)<<endl;

    return 0;
}
