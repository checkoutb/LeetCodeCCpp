
#include "../header/myheader.h"

class LT1039
{
public:



    // g



//     int minScoreTriangulation(vector<int>& values)
//     {
//         int sz1 = values.size();
//
//     }


    // error
    //
    int minScoreTriangulation__eeee(vector<int>& values)
    {
        int sz1 = values.size();
        if (sz1 == 3)
            return values[0] * values[1] * values[2];
        if (sz1 == 4)
            return min(values[0] * values[2] * (values[1] + values[3]), values[1] * values[3] * (values[0] + values[2]));

        vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));

        for (int df {2}; df <= sz1 - 1; ++df)
        {
            for (int i = 0; i < sz1; ++i)
            {
                int t2 = (i + df) % sz1;
                // vvi[i][i + df] = min(values[i] * values[i + df] * values[i + 1] + vvi[i + 1][i + df],
                //                      values[i] * values[i + df] * values[i + df - 1] + vvi[i][i + df - 1]);
                vvi[i][t2] = min(values[i] * values[t2] * values[(i + 1) % sz1] + vvi[(i + 1) % sz1][t2],
                                     values[i] * values[t2] * values[(t2 - 1 + sz1) % sz1] + vvi[i][(t2 - 1 + sz1) % sz1]);

#ifdef __test
                cout<<i<<", "<<t2<<", "<<df<<endl;
#endif

            }
        }

// #ifdef __test
//         for (auto& vi : vvi)
//         {
//             showVectorInt(vi);
//         }
// #endif
//
//         vector<vector<int>> vv2(sz1, vector<int>(sz1, 0));
//         int ans = INT_MAX;
//         for (int i = 0; i < sz1; ++i)
//         {
//             for (int j = i + 2; j < sz1; ++j)
//             {
//                 vv2[i][j] = vvi[i][j] + vvi[j][i];
//                 ans = min(ans, vv2[i][j]);
//             }
//         }

        // for (int df = 2; df <= sz1 - 1; ++df)
        // {
        //     for (int i = 0; i < sz1; ++i)
        //     {
        //         int t2 = (i + df) % sz1;
        //         vv2[i][t2]
        //     }
        // }

        // int ans = INT_MAX;
        // for (int i = 0; i < sz1; ++i)
        // {
        //     ans = min(ans, vvi[i][(i + sz1 - 2) % sz1]);
        // }
        // return ans;
    }
};

int main()
{

    LT1039 lt;

    // myvi v {3,7,4,5};
    // myvi v {1,2,3};
    myvi v {1,3,1,4,1,5};

    cout<<lt.minScoreTriangulation(v)<<endl;

    return 0;
}
