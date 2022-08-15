
#include "../header/myheader.h"

class LT1691
{
public:

    // D D

    //int dp[101][102] = {};
    //int dfs(vector<vector<int>>& cubs, int p, int l) {
    //    if (p < 0)
    //        return 0;
    //    if (dp[p][l] > 1)
    //        return dp[p][l] - 1;
    //    int res = dfs(cubs, p - 1, l);
    //    if (l == 101 || (cubs[p][0] <= cubs[l][0] && cubs[p][1] <= cubs[l][1] && cubs[p][2] <= cubs[l][2]))
    //        res = max(res, cubs[p][2] + dfs(cubs, p - 1, p));
    //    dp[p][l] = res + 1;
    //    return res;
    //}
    //int maxHeight(vector<vector<int>>& cubs) {
    //    for (auto& c : cubs)
    //        sort(begin(c), end(c));
    //    sort(begin(cubs), end(cubs));
    //    return dfs(cubs, cubs.size() - 1, 101);
    //}


    //for (auto& a : A)
    //    sort(begin(a), end(a));
    //A.push_back({ 0, 0, 0 });
    //sort(begin(A), end(A));
    //int n = A.size(), res = 0;
    //vector<int> dp(n);
    //for (int j = 1; j < n; ++j)
    //    for (int i = 0; i < j; ++i)
    //        if (A[i][0] <= A[j][0] && A[i][1] <= A[j][1] && A[i][2] <= A[j][2]) {
    //            dp[j] = max(dp[j], dp[i] + A[j][2]);
    //            res = max(res, dp[j]);
    //        }
    //return res;



//Runtime: 16 ms, faster than 83.78 % of C++ online submissions for Maximum Height by Stacking Cuboids .
//Memory Usage : 9.1 MB, less than 89.90 % of C++ online submissions for Maximum Height by Stacking Cuboids .
    int lt1691b(vector<vector<int>>& cuboids)
    {
        for (vector<int>& vi : cuboids)
            sort(begin(vi), end(vi));

        sort(begin(cuboids), end(cuboids));

#ifdef __test
        for (myvi& vi : cuboids)
        {
            cout << vi[0] << ", " << vi[1] << ", " << vi[2] << endl;
        }
#endif

        vector<int> vi(cuboids.size());
        
        vi[0] = cuboids[0][2];

        for (int i = 1; i < cuboids.size(); ++i)
        {
            vi[i] = cuboids[i][2];
            for (int j = i - 1; j >= 0; --j)
            {
                if (
                    //cuboids[j][0] <= cuboids[i][0] && 
                    cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
                {
                    vi[i] = max(vi[i], vi[j] + cuboids[i][2]);
#ifdef __test
                    cout << i << " -- " << j << endl;
#endif
                    // 不能break。 不能max(vi[i-1])
                }
            }
        }
        return *max_element(begin(vi), end(vi));
    }


    // 无法二分的
    // 长 宽 高 都要小
    // Example 的图。。。。
    int lt1691a(vector<vector<int>>& cuboids)
    {
        for (vector<int>& vi : cuboids)
            sort(begin(vi), end(vi));

        sort(begin(cuboids), end(cuboids));

#ifdef __test
        for (myvi& vi : cuboids)
        {
            cout << vi[0] << ", " << vi[1] << ", " << vi[2] << endl;
        }
#endif

        vector<int> vi(cuboids.size());
        for (int i = 0; i < cuboids.size(); ++i)
        {
            vector<int>& v = cuboids[i];
            vector<vector<int>>::iterator it = lower_bound(begin(cuboids), end(cuboids), v, [](const vector<int>& v1, const vector<int>& v2) {
                return v1[0] <= v2[0] && v1[1] <= v2[1] && v1[2] <= v2[2];
            });

            //int idx = distance(begin(cuboids), prev(it));

            int idx = distance(begin(cuboids), prev(it));



            //if (idx == cuboids.size())
            //{
            //    vi[i] = 
            //}


#ifdef __test
            cout << i << " - " << idx << endl;
#endif
            if (idx == i)
            {

            }
            vi[i] = max(i == 0 ? 0 : vi[i - 1], vi[idx]) + v[2];
        }

        return vi[cuboids.size() - 1];
    }

};

int main()
{

    LT1691 lt;

    //myvvi vv = { {50,45,20},{95,37,53},{45,23,12} };
    //myvvi vv = { {38,25,45},{76,35,3} };
    //myvvi vv = { {7,11,17},{7,17,11},{11,7,17},{11,17,7},{11,7,17},{11,17,7} };

    myvvi vv = { {41,46,36},{15,100,100},{59,91,75},{13,82,64} };       // 182

    cout << lt.lt1691b(vv) << endl;


    myvvi v2 = { {1,111},{2,33},{1,11} };
    sort(begin(v2), end(v2));
    vector<int> v = { 1,153 };
    auto it = upper_bound(begin(v2), end(v2), v, [](const vector<int>& v1, const vector<int>& v2) {
        return v1[0] <= v2[0] && v1[1] <= v2[1];
    });

    //cout << distance(begin(v2), it) << endl;

    return 0;
}
