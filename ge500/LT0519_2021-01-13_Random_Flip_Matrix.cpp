
#include "../header/myheader.h"

class LT0519
{
public:



};


// will not exceed 1000.   稀疏矩阵。
class Solution {
    vector<vector<int>> vv;
    int mod;
    int oriMod;
    int cols;
public:
    Solution(int n_rows, int n_cols) {
        vv = vector<vector<int>>(n_rows, vector<int>());
        mod = n_rows * n_cols;
        oriMod = mod;
        cols = n_cols;
    }

    vector<int> flip() {
        int idx = rand() % mod;
        for (int i = 0; i < vv.size(); ++i)
        {
            if ((cols - vv[i].size()) >= idx)
            {
                // idx + count of not 0
//                int cnt1 = 0;
                if (idx == )
                for (int j = 0; j < vv.size(); ++j)
                {
                    if (idx + )
                }
//                for (int j = 0; j < vv.size(); ++j)
//                {
//
//                }

//                for (int j = 0; j < vv.size(); ++j)
//                {
//                    if (idx <=)
//                }
            }
            else
            {
                idx -= (cols - vv[i].size());
            }
        }
    }

    void reset() {
        for (int i = 0; i < vv.size(); ++i)
            if (!vv.empty())
                vv.clear();
        mod = oriMod;
    }
};

int main()
{

    LT0519 lt;


    return 0;
}
