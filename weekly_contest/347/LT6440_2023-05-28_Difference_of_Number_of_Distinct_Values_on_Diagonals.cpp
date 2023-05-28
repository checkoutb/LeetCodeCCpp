
#include "../../header/myheader.h"

class LT6440
{
public:



    // AC
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
        vector<vector<long long>> vvl(sz1, vector<long long>(sz2, 0LL));
        vector<vector<long long>> vvl2(sz1, vector<long long>(sz2, 0LL));

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                vvl[i][j] = (1LL << grid[i][j]) | ((i > 0 && j > 0) ? vvl[i - 1][j - 1] : 0);
            }
        }

        for (int i = sz1 - 1; i >= 0; --i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                vvl2[i][j] = (1LL << grid[i][j]) | ((i + 1 < sz1 && j + 1 < sz2) ? vvl2[i + 1][j + 1] : 0);
            }
        }

        #ifdef __test
        for (int i = 0; i < sz1; ++i)
        {
            for (long long ll : vvl[i])
            {
                cout<<ll<<", ";
            }
            cout<<endl;
        }
        cout<<" ---------------- "<<endl;
        for (vector<long long>& vl : vvl2)
        {
            for (long long ll : vl)
            {
                cout<<ll<<", ";
            }
            cout<<endl;
        }

        #endif // __test

        vector<vector<int>> vvi(sz1, vector<int>(sz2, 0));

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                vvi[i][j] = abs(((i > 0 && j > 0) ? cnt1(vvl[i - 1][j - 1]) : 0) - ((i + 1 < sz1 && j + 1 < sz2) ? cnt1(vvl2[i + 1][j + 1]) : 0));
            }
        }
        return vvi;
    }

    int cnt1(long long a)               // ... not int...
    {
        int ans = 0;
        while (a > 0)
        {
            ans += (a & 1);
            a >>= 1;
        }
        return ans;
    }

};

int main()
{

    LT6440 lt;

    //myvvi vv = {{1,2,3},{3,1,5},{3,2,1}};
    myvvi vv = {{5,50,39,37},
                {2,19,36,26},
                {27,3,23,10},
                {20,33,8,39}};

    myvvi vv2 = lt.differenceOfDistinctValues(vv);

    for (myvi& vi : vv2)
    {
        showVectorInt(vi);
    }


    return 0;
}
