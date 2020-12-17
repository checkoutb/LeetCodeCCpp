
#include "../header/myheader.h"

class LT0120
{
public:

// D D

//    int n = triangle.size();
//    vector<int> minlen(triangle.back());
//    for (int layer = n-2; layer >= 0; layer--) // For each layer
//    {
//        for (int i = 0; i <= layer; i++) // Check its every 'node'
//        {
//            // Find the lesser of its two children, and sum the current value in the triangle with it.
//            minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i];
//        }
//    }
//    return minlen[0];



//Runtime: 8 ms, faster than 89.10% of C++ online submissions for Triangle.
//Memory Usage: 8.6 MB, less than 98.39% of C++ online submissions for Triangle.
// 有tle。
    int lt0120a(vector<vector<int>>& triangle)
    {
        int sz1 = triangle.size();
//        vector<int> vi(triangle[sz1 - 1].size());
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                int t1 = j == 0 ? INT_MAX : (triangle[i - 1][j - 1] + triangle[i][j]);
                int t2 = j == (triangle[i].size() - 1) ? INT_MAX : (triangle[i - 1][j] + triangle[i][j]);
                triangle[i][j] = min(t1, t2);
//                cout<<triangle[i][j]<<",";
            }
        }
        int ans = INT_MAX;
        for (int i : triangle[sz1 - 1])
            ans = min(i, ans);
        return ans;
    }

};

int main()
{
    vector<vector<int>> vv = {{2},{3,4},{6,5,7},{4,1,8,3}};

    LT0120 lt;

    cout<<lt.lt0120a(vv)<<endl;

    return 0;
}
