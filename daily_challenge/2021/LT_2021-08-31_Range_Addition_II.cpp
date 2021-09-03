
#include "../../header/myheader.h"

class LT
{
public:

// D D

//int mina =m, minb = n;

//for(const auto&pos : ops)

//for(auto pr:ops)

// for-each (可能)比 for 快。




// AC
// 最小的x * 最小的y
    int lta(int m, int n, vector<vector<int>>& ops)
    {
        if (ops.empty())
            return m * n;

        int mni = INT_MAX;
        int mnj = INT_MAX;
        for (int i = 0; i < ops.size(); ++i)
        {
            mni = min(mni, ops[i][0]);
            mnj = min(mnj, ops[i][1]);
        }
        return mni * mnj;
    }

};

int main()
{

    LT lt;


    return 0;
}
