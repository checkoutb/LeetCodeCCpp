
#include "../../header/myheader.h"

class LT
{
public:

// D D


//                if(!i || !j)
//                    dp[i][j] = 0;
//                else if(nums2[i-1] == nums1[j-1])
//                    dp[i][j] = dp[i-1][j-1]+1;
//                else
//                    dp[i][j] = 0;
//
//                if(dp[i][j] > res)
//                    res = dp[i][j];







// AC
// toString
    int lta(vector<int>& nums1, vector<int>& nums2)
    {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, 0));
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (nums1[i] == nums2[j])
                {
                    if (i > 0 && j > 0)
                    {
                        vvi[i][j] = vvi[i - 1][j - 1] + 1;
                        ans = max(ans, vvi[i][j]);
                    }
                    else
                    {
                        vvi[i][j] = 1;
                        ans = max(ans, 1);
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v1 = {1,2,3,2,1};
//    myvi v2 = {3,2,1,4,7};

    myvi v1 = {0,0,0,0,0};
    myvi v2 = {0,0,0,0};

    LT lt;

    cout<<lt.lta(v1, v2)<<endl;

    return 0;
}
