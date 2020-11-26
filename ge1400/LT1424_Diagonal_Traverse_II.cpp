
#include "../header/myheader.h"

class LT1424
{
public:

// D

// row + col 相同，说明在同一个斜列。然后遍历也是有序的。




// tle
    vector<int> lt1424b(vector<vector<int>>& nums)
    {
        int row2 = nums.size();
        vector<int> vlen(row2);
        for (int i = 0; i < row2; ++i)
            vlen[i] = nums[i].size();
        vector<int> ans(std::accumulate(begin(vlen), end(vlen), 0), -1);
        for (int i = 0; i < row2; ++i)
        {
            for (int j = 0, jmx = nums[i].size(); j < jmx; ++j)
            {
                int l3 = j;
                int idx = j;
                for (int k = i + 1; l3 > 0 && k < row2; ++k)
                {
                    idx += min(l3, vlen[k]);
                    l3--;
                }
                l3 = j + 1;
                for (int k = i - 1; k >= 0; --k)
                {
                    idx += min(l3, vlen[k]);
                    l3++;
                }
                #ifdef __test
                cout<<nums[i][j]<<" : "<<idx<<endl;
                #endif // __test
                ans[idx] = nums[i][j];
            }
        }
        return ans;
    }



// tle...
    vector<int> lt1424a(vector<vector<int>>& nums)
    {
        vector<int> ans;
        int row2 = nums.size();
        int col2 = 0;
        for (int i = 0; i < row2; ++i)
        {
            col2 = max((int) nums[i].size(), col2);
        }

        for (int i = 0; i < row2; ++i)
        {
            int m = i;
            int n = 0;
            while (m >= 0)
            {
                if (n < nums[m].size())
                    ans.push_back(nums[m][n]);
                m--;
                n++;
            }
        }
        for (int j = 1; j < col2; ++j)
        {
            int m = row2 - 1;
            int n = j;
            while (m >= 0)
            {
                if (n < nums[m].size())
                    ans.push_back(nums[m][n]);
                m--;
                n++;
            }
        }

        return ans;
    }

};

int main()
{
//    vector<vector<int>> vv = {{1,2,3},{4,5,6},{7,8,9}};
//    vector<vector<int>> vv = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
//    vector<vector<int>> vv = {{1,2,3,4,5,6}};
    vector<vector<int>> vv = {{1,2,3},{4},{5,6,7},{8},{9,10,11}};

    LT1424 lt;

    vector<int> v = lt.lt1424b(vv);

    showVectorInt(v);

    return 0;
}
