
#include "../header/myheader.h"

class LT1253
{
public:

// D D

//            } else if (colsum[i] == 1) {
//                matrix.get(0).add(upper > lower ? 1 : 0);
//                matrix.get(1).add(upper > lower ? 0 : 1);

//    vector<vector<int>> res(2, vector<int>(cs.size()));
//    for (auto i = 0; i < cs.size(); u -= res[0][i], l -= res[1][i++]) {
//        res[0][i] = cs[i] == 2 || (cs[i] == 1 && l < u);
//        res[1][i] = cs[i] == 2 || (cs[i] == 1 && !res[0][i]);
//    }
//    return u == 0 && l == 0 ? res : vector<vector<int>>();


//Runtime: 132 ms, faster than 88.16% of C++ online submissions for Reconstruct a 2-Row Binary Matrix.
//Memory Usage: 58.2 MB, less than 87.23% of C++ online submissions for Reconstruct a 2-Row Binary Matrix.
    vector<vector<int>> lt1253a(int upper, int lower, vector<int>& colsum)
    {
        int sum2 = std::accumulate(begin(colsum), end(colsum), 0);
        if ((upper + lower) != sum2)
            return vector<vector<int>>();
        int cnt2 = std::count(begin(colsum), end(colsum), 2);
        if (cnt2 > min(upper, lower))
            return vector<vector<int>>();
        vector<vector<int>> ans(2, vector<int>(colsum.size(), 0));

        for (int i = 0; i < colsum.size(); ++i)
        {
            int cs = colsum[i];
            if (cs == 2)
            {
                --upper;
                --lower;
                ans[0][i] = 1;
                ans[1][i] = 1;
                colsum[i] = 0;
            }
        }
        for (int i = 0; i < colsum.size(); ++i)
        {
            int cs = colsum[i];
            if (cs == 1)
            {
                if (upper > 0)
                {
                    --upper;
                    ans[0][i] = 1;
                }
                else
                {
                    ans[1][i] = 1;
                }
            }
        }

//        for (int i = 0; i < ans[0].size(); ++i)
//        {
//            int cs = colsum[i];
//            if (cs == 2)
//            {
//                ans[0][i] = 1;
//                ans[1][i] = 1;
//            }
//            else if (cs == 1)
//            {
//                if (upper > 0)
//                {
//                    --upper;
//                    ans[0][i] = 1;
//                }
//                else
//                {
//                    ans[1][i] = 1;
//                }
//            }
//        }

        return ans;
    }

};

int main()
{

//    int u{2}, l{1};
//    vector<int> vc = {1,1,1};
//    int u{2}, l{3};
//    vector<int> vc = {2,2,1,1};

//    int u{5}, l{5};
//    vector<int> vc = {2,1,2,0,1,0,1,2,0,1};

    int u{9}, l{2};
    vector<int> vc = {0,1,2,0,0,0,0,0,2,1,2,1,2};


    LT1253 lt;

    vector<vector<int>> vvi = lt.lt1253a(u,l,vc);

    for (vector<int>& vi : vvi)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
