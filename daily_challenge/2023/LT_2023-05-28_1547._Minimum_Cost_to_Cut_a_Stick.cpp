
#include "../../header/myheader.h"

class LT
{
public:





//    Runtime92 ms
//    Beats
//    51.63%
//    Memory10.2 MB
//    Beats
//    80.63%
    int lta(int n, vector<int>& cuts)
    {
        std::sort(begin(cuts), end(cuts));
        int sz1 = cuts.size();

        vector<vector<int>> vvi(sz1, vector<int>(sz1, INT_MAX));

        return dfs_memo_1(cuts, vvi, 0, sz1 - 1, 0, n);
    }

    int dfs_memo_1(vector<int>& cuts, vector<vector<int>>& vvi, int st, int en, int stk_st, int stk_en)
    {
        if (st > en)
            return 0;
        if (vvi[st][en] != INT_MAX)
            return vvi[st][en];
        if (st == en)
        {
            vvi[st][en] = stk_en - stk_st;
            return vvi[st][en];
        }
        int mn = INT_MAX;
        int t2 = 0;
        for (int i = st; i <= en; ++i)
        {
            t2 = dfs_memo_1(cuts, vvi, st, i - 1, stk_st, cuts[i]) + dfs_memo_1(cuts, vvi, i + 1, en, cuts[i], stk_en);
            if (t2 < mn)
                mn = t2;
        }
        vvi[st][en] = mn + stk_en - stk_st;
        return vvi[st][en];
    }

};

int main()
{

    LT lt;

//    int n{7};
//    myvi vi = {1,3,4,5};

    int n{9};
    myvi vi = {5,6,1,4,2};

    cout<<lt.lta(n, vi)<<endl;

    return 0;
}
