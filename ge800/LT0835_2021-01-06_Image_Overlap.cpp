
#include "../header/myheader.h"

class LT0835
{
public:

// D D

//        vector<int> LA, LB;
//        int N = A.size();
//        unordered_map<int, int> count;
//        for (int i = 0; i < N * N; ++i)
//            if (A[i / N][i % N] == 1)
//                LA.push_back(i / N * 100 + i % N);
//        for (int i = 0; i < N * N; ++i)
//            if (B[i / N][i % N] == 1)
//                LB.push_back(i / N * 100 + i % N);
//        for (int i : LA) for (int j : LB) count[i - j]++;
//        int res = 0;
//        for (auto it : count) res = max(res, it.second);
//        return res;



//Runtime: 100 ms, faster than 64.67% of C++ online submissions for Image Overlap.
//Memory Usage: 9.7 MB, less than 72.46% of C++ online submissions for Image Overlap.
    int lt0835a(vector<vector<int>>& img1, vector<vector<int>>& img2)
    {
        int ans = 0;
        int sz1 = img1.size();
        for (int i = -sz1 + 1; i < sz1; ++i)
        {
            for (int j = -sz1 + 1; j < sz1; ++j)
            {
                int t2 = 0;
                for (int m = 0; m < sz1; ++m)
                {
                    for (int n = 0; n < sz1; ++n)
                    {
                        int a = m + i;
                        int b = n + j;
                        if (a < sz1 && b < sz1 && a >= 0 && b >= 0)
                        {
                            if (img1[m][n] == 1 && img1[m][n] == img2[a][b])
                            {
                                t2++;
                            }
                        }
                    }
                }
                ans = max(t2, ans);
            }
        }
        return ans;
    }

};

int main()
{
//    myvvi vv1 = {{1,1,0},{0,1,0},{0,1,0}};
//    myvvi vv2 = {{0,0,0},{0,1,1},{0,0,1}};

    myvvi vv1 = {{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    myvvi vv2 = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{1,0,0,0,0}};

    LT0835 lt;

    cout<<lt.lt0835a(vv1, vv2);

    return 0;
}
