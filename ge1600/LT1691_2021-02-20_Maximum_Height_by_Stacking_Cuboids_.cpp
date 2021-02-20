
#include "../header/myheader.h"

class LT1691
{
public:

// D

//        for (auto& a : A) sort(begin(a), end(a));
//        A.push_back({0, 0, 0});
//        sort(begin(A), end(A));
//        int n = A.size(), res = 0;
//        vector<int> dp(n);
//        for (int i = 1; i < n; i++)
//            for (int j = 0; j < i; j++)
//                if (A[j][0] <= A[i][0] and A[j][1] <= A[i][1] and A[j][2] <= A[i][2]) {
//                    dp[i] = max(dp[i], dp[j] + A[i][2]);
//                    res = max(res, dp[i]);
//                }
//        return res;
// ... sort(begin(A), end(A)).
// 每个方块 尝试 包含 前面的方块，如果可以，那就+1层。高度+。
// 由于sort， 所以 前面的方块 不可能包含 后面，    后面的 可能可能可能 包含 前面。


//        for(auto& v:cuboids) sort(v.begin(), v.end());
//        cuboids.push_back(vector{0,0,0});
//        sort(cuboids.begin(), cuboids.end());
//        const int n = cuboids.size();
//        auto dp = vector(n, 0);
//        for(int i=0;i<n;i++) for(int j=i+1; j<n; j++)
//            if(cuboids[i][1]<=cuboids[j][1] &&cuboids[i][2]<=cuboids[j][2]) dp[j] = max(dp[j], cuboids[j][2] + dp[i]);
//        return *max_element(dp.begin(), dp.end());


// tle, 比之前快一点。
    int lt1691b(vector<vector<int>>& cuboids)
    {
        int sz1 = cuboids.size();
        for (int i = 0; i < sz1; ++i)
        {
            std::sort(begin(cuboids[i]), end(cuboids[i]));
        }
        vector<bool> vis(sz1, false);
        dfsb1(cuboids, vis, 100, 100, 100, 0);
        return ans;
    }
    int ans = 0;
    void dfsb1(vector<vector<int>>& vvi, vector<bool>& vis, int len, int wid, int hei, int allhei)
    {
        ans = max(ans, allhei);
        for (int i = 0; i < vvi.size(); ++i)
        {
            if (vis[i])
                continue;
            int l = vvi[i][0];
            int w = vvi[i][1];
            int h = vvi[i][2];
            if (l <= len && w <= wid && h <= hei)
            {
                vis[i] = true;
                dfsb1(vvi, vis, l, w, h, allhei + h);
                vis[i] = false;
            }
        }
    }



// tle
// LIS .. 自定义比较方法，长 宽 同时小于。  3种可能。
// 不， 现在是 乱序的。 需要排序 & 剔除，dfs？ memo怎么加。 memo可以的，如果在自己的上面，那么就不可能在自己的下面。bu,相等
    int lt1691a(vector<vector<int>>& cuboids)
    {
        vector<bool> vis(cuboids.size(), false);
        dfsa1(cuboids, vis, 100, 100, 100, 0);
        return ans;
    }
//    int ans = 0;
    // 1 small
    bool canIn(int l1, int w1, int h1, int l2, int w2, int h2)
    {
        vector<int> v1 = {l1, w1, h1};
        std::sort(begin(v1), end(v1));
        vector<int> v2 = {l2, w2, h2};
        std::sort(begin(v2), end(v2));
        return v1[0] <= v2[0] && v1[1] <= v2[1] && v1[2] <= v2[2];
    }
    void dfsa1(vector<vector<int>>& vvi, vector<bool>& vis, int length, int width, int height, int allheight)
    {
        ans = max(ans, allheight);
        for (int i = 0; i < vvi.size(); ++i)
        {
            if (vis[i])
                continue;
            vis[i] = true;

            if (canIn(vvi[i][0], vvi[i][1], vvi[i][2], length, width, height))
            {
                dfsa1(vvi, vis, vvi[i][0], vvi[i][1], vvi[i][2], allheight + max(max(vvi[i][0], vvi[i][1]), vvi[i][2]));
            }


//            int len = max(vvi[i][0], vvi[i][1]);
//            int wid = min(vvi[i][0], vvi[i][1]);
//            if (len <= length && wid <= width)
//            {
//                dfsa1(vvi, vis, len, wid, allheight + vvi[i][2]);
//            }
//
//            len = max(vvi[i][0], vvi[i][2]);
//            wid = min(vvi[i][0], vvi[i][2]);
//            if (len <= length && wid <= width)
//            {
//                dfsa1(vvi, vis, len, wid, allheight + vvi[i][1]);
//            }
//
//            len = max(vvi[i][1], vvi[i][2]);
//            wid = min(vvi[i][1], vvi[i][2]);
//            if (len <= length && wid <= width)
//            {
//                dfsa1(vvi, vis, len, wid, allheight + vvi[i][0]);
//            }
            vis[i] =false;
        }
    }

};

int main()
{

//    myvvi vv = {{50,45,20},{95,37,53},{45,23,12}};
    myvvi vv = {{38,25,45},{76,35,3}};
//Input: cuboids = [[38,25,45],[76,35,3]]
//Output: 76
//Explanation:
//You can't place any of the cuboids on the other.
//We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
// ???? 下面 38×25 上面 35×3 ，不是可以吗。。。

//Wrong Answer
//Details
//Input
//[[38,25,45],[76,35,3]]
//Output
//121
//Expected
//76
// 还真的错了。。

//You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj.
//You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
// md, 套娃。
// 不是 二维小于 就可以了，  需要三维小于。。

//    myvvi vv = {{7,11,17},{7,17,11},{11,7,17},{11,17,7},{17,7,11},{17,11,7}};


    LT1691 lt;

    cout<<lt.lt1691b(vv)<<endl;

    return 0;
}
