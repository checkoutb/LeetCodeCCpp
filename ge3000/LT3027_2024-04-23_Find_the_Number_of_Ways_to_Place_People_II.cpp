
#include "../header/myheader.h"

class LT3027
{
public:


    // D D
        // auto cmp = [&](vector<int>& c, vector<int>& t) {
        //     if (c[0] == t[0]) return c[1] > t[1];
        //     return c[0] < t[0];
        // };
        // sort(points.begin(), points.end(), cmp);
        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     int cx = points[i][0], cy = points[i][1];
        //     int k = -10000000000;
        //     for (int j = i + 1; j < n; j++) {
        //         int tx = points[j][0], ty = points[j][1];
        //         if (ty > cy) continue;
        //         if (ty > k) {
        //             ans++;
        //             k = ty;
        //         }
        //     }
        // }
    // ...brute-force...


// Runtime
// 136ms
// Beats84.49%of users with C++
// Memory
// 44.99MB
// Beats24.68%of users with C++
    // 任选2个点，一个点alice，左上， 另一个bob，右下角， 矩形 中/边 不能有 其他点
    // bob的点 是一个 圆弧。  mono-stack？ ... no
    int numberOfPairs(vector<vector<int>>& points)
    {
        sort(begin(points), end(points), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
        });

        // for (int i = )

        // for (int i = )

        map<int, int> map2; // alice; <y, x>
        int x, y, mxx;
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) // bob
        {
            x = points[i][0];
            y = points[i][1];
            mxx = INT_MIN;
            for (map<int, int>::iterator it = map2.lower_bound(y); it != map2.end(); it++)
            {
                if (it->second <= mxx)
                    continue;
                mxx = it->second;
                ++ans;
            }
            map2[y] = x;
        }
        return ans;
    }
};

int main()
{

    LT3027 lt;


    return 0;
}
