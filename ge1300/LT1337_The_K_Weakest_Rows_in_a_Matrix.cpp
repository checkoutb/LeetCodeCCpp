
#include "../header/myheader.h"

class LT1337
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







//Runtime: 24 ms, faster than 85.97% of C++ online submissions for The K Weakest Rows in a Matrix.
//Memory Usage: 11.1 MB, less than 16.65% of C++ online submissions for The K Weakest Rows in a Matrix.
    vector<int> lt1337a(vector<vector<int>>& mat, int k)
    {
        int sz2 = mat[0].size();
        int sz1 = mat.size();
        vector<int> ans;
        unordered_set<int> set2;
        for (int j = 0; j < sz2; ++j)
        {
            for (int i = 0; i < sz1; ++i)
            {
                if (set2.find(i) != set2.end())
                    continue;
                if (mat[i][j] == 0)
                {
                    set2.insert(i);
                    ans.push_back(i);
                    if (ans.size() == k)
                        goto AAA;
                }
            }
        }
        AAA:
        for (int i = 0; i < sz1; ++i)
        {
            if (ans.size() == k)
                break;
            else
            {
                if (set2.find(i) == set2.end())
                {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> vv = {{1,1,0,0,0},
                             {1,1,1,1,0},
                             {1,0,0,0,0},
                             {1,1,0,0,0},
                             {1,1,1,1,1}};
    int k = 3;

    LT1337 lt;

    vector<int> v = lt.lt1337a(vv, k);

    showVectorInt(v);

    return 0;
}
