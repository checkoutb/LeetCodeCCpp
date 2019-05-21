
#include "../header/myheader.h"

class LT0373
{
public:


// ....error..
    vector<vector<int>> lt0373c(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<vector<int>> result;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        if (k == 0 || sz1 ==0 || sz2 == 0)
        {
            return result;
        }

        int t1, t2;
        result.push_back({nums1[t1], nums2[t2]});
        int s1, s2, i1, i2;
        for (int i = 0; i < k; i++)
        {
            s1 = nums1[t1 + 1] + nums2[t2];
            s2 = nums1[t2] + nums2[t1 + 1];
        }

        return result;
    }


// error
    // 记录前一个数在另一个数组中配对的的开始。
    vector<vector<int>> lt0373b(vector int>& nums1, vector<int>& nums2, int k)
    {
        vector<vector<int>> result;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        if (k == 0 || sz1 ==0 || sz2 == 0)
        {
            return result;
        }

        int t1, t2, p1, p2;
        int s1, s2, s3, s4;

        for (int i = 0; i < k; i++)
        {
//            s1 = nums1[t1 + 1] + nums2[t2];
//            s2 = nums1[t1] + nums2[t2 + 1];
//            s3 = nums1[t1 - 1] + nums2[p1];
//            s4 = nums1[p2] + nums2[t2 - 1];
            s1 = nums1[t1 + 1] + nums2[p1];
            s2 = nums1[p2] + nums2[t2 + 1];
            s3 = nums1[t1] + nums2[t2 + 1];
            s4 = nums1[t1 + 1] + nums2[t2];

            if (s1 > s2)
            {
                t1 = p2;
                t2++;
            }
            else
            {
                t2 = p1;
                t1++;
            }

        }
        return result;
    }

    // error,没这么简单，游标可能向前的。
    vector<vector<int>> lt0373a(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<vector<int>> result;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        if (k == 0 || sz1 ==0 || sz2 == 0)
        {
            return result;
        }
        int i1 = 0;
        int i2 = 0;
        int t1 = 0;
        int t2 = 0;
        k = min(sz1 * sz2, k);

        result.push_back({nums1[i1], nums2[i2]});     // coooooooool...
        for (int i = 1; i < k; i++)
        {
            if (i1 == sz1 - 1)
            {
                i2++;
                result.push_back({nums1[i1], nums2[i2]});
            }
            else if (i2 == sz2 - 1)
            {
                i1++;
                result.push_back({i1, i2});
            }
            else
            {
                t1 = nums1[i1 + 1] + nums2[0];
                t2 = nums1[0] + nums2[i2 + 1];
                if (t1 < t2)
                {
                    i1++;
                    result.push_back({nums1[i1], nums2[i2]});
                }
                else
                {
                    i2++;
                    result.push_back({nums1[i1], nums2[i2]});
                }
            }
        }
        return result;
    }
};

int main()
{
    LT0373 lt;
//    vector<int> nums1 = {1,7,11};
//    vector<int> nums2 = {2,4,6};
//    int k = 3;

    vector<int> nums1 = {1,1,2};
    vector<int> nums2 = {1,2,3};
    int k = 10;


    vector<vector<int>> a = lt.lt0373a(nums1, nums2, k);

    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i][0]<<", "<<a[i][1]<<endl;
    }
    return 0;
}
