
#include "../../header/myheader.h"

class LT
{
public:

// D D

//    dp[0][0] = nums1[0] * nums2[0];
//    for (int i = 0; i < n1; i++) {
//      for (int j = 0; j < n2; j++) {
//        _curr = nums1[i] * nums2[j];
//        if (i == 0 || j == 0) {
//          if (j >= 1)
//            dp[i][j] = max(_curr, dp[i][j - 1]);
//          if (i >= 1)
//            dp[i][j] = max(_curr, dp[i - 1][j]);
//        } else {
//          dp[i][j] = max(max(dp[i - 1][j], _curr),
//                         max(dp[i][j - 1], dp[i - 1][j - 1] + _curr));
//        }
//      }
//    }


//        vector<vector<int>> dp(n, vector<int>(m));
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                dp[i][j] = A[i] * B[j];
//                if (i && j) dp[i][j] += max(dp[i - 1][j - 1], 0);
//                if (i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
//                if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
//            }
//        }



//Runtime15 ms
//Beats
//90.49%
//Memory9.7 MB
//Beats
//99.49%
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
    {
        int sz1 = nums1.size();
        int sz2 = nums2.size();

        vector<int> vi(sz2, 0);
        int t2 = nums1[0];
        int t3 = 0;
        for (int j = 0; j < sz2; ++j)
            vi[j] = max((j == 0 ? (t2 * nums2[j]) : (vi[j - 1])), t2 * nums2[j]);

        for (int i = 1; i < sz1; ++i)
        {
            t2 = nums1[i];
            for (int j = sz2 - 1; j >= 0; --j)
            {
                t3 = t2 * nums2[j];
                vi[j] = max(max(vi[j], t3), j == 0 ? (t3) : (t3 + vi[j - 1]));
            }
            for (int j = 1; j < sz2; ++j)
            {
                vi[j] = max(vi[j], vi[j - 1]);
            }
            #ifdef __test
            showVectorInt(vi);
            #endif // __test
        }

        return vi[sz2 - 1];
    }

};

int main()
{

    LT lt;

//    myvi v = {2,1,-2,5};
//    myvi v2 = {3,0,-6};

//    myvi v = {-1,-1};
//    myvi v2 = {1,1};

    myvi v = {-3,-8,3,-10,1,3,9};
    myvi v2 = {9,2,3,7,-9,1,-8,5,-1,-1};        // 200

    cout<<lt.maxDotProduct(v, v2)<<endl;

    return 0;
}
