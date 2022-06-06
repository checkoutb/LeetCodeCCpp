
#include "../header/myheader.h"

class LT0939
{
public:

    // D D

    //int result = numeric_limits<int>::max();


    //int minAreaRect(vector<vector<int>>& points, int res = INT_MAX) {
    //    unordered_map<int, set<int>> x;
    //    for (auto p : points) x[p[0]].insert(p[1]);
    //    for (auto i = x.begin(); i != x.end(); ++i)
    //        for (auto j = next(i); j != x.end(); ++j) {
    //            if (i->second.size() < 2 || j->second.size() < 2) continue;
    //            vector<int> y;
    //            set_intersection(begin(i->second), end(i->second),
    //                begin(j->second), end(j->second), back_inserter(y));
    //            for (int k = 1; k < y.size(); ++k)
    //                res = min(res, abs(j->first - i->first) * (y[k] - y[k - 1]));
    //        }
    //    return res == INT_MAX ? 0 : res;
    //}


//Runtime: 131 ms, faster than 96.35 % of C++ online submissions for Minimum Area Rectangle.
//Memory Usage : 19.7 MB, less than 86.04 % of C++ online submissions for Minimum Area Rectangle.
    // 找到4个点，组成 边平行于x/y轴的 面积最小的 矩形。
    // 。。只想到：按照x轴排序下，for for 遍历所有的点，一个做为左下角，一个做为右上角，尝试形成矩形。 。。 可能是 左上 + 右下。。
    //          以后，长>ans 宽>ans 的可以放弃。
    // (4*10^4)^2 = 16亿
    // pair 的hash是怎么弄的。vector的呢？
    int lt0939a(vector<vector<int>>& points)
    {
        //const int MUL = 4 * 10e4 + 1;

        set<pair<int, int>> set2;       // 没有unordered_set<pair<int, int>> ？ 本地(visual studio community 2022 c++)会报错：调用了已隐式删除的方法。
        std::sort(begin(points), end(points));

        for (vector<int>& vi : points)
        {
            set2.insert(std::make_pair(vi[0], vi[1]));
        }
        int ans = INT_MAX;
        for (int i = 0; i < points.size(); ++i)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < points.size(); ++j)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 == x2 || y1 == y2)
                    continue;
                
                if (abs((x2 - x1) * (y2 - y1)) >= ans)
                    continue;

                if (set2.find(make_pair(x1, y2)) != end(set2) && set2.find(std::make_pair(x2, y1)) != end(set2))
                {
                    ans = abs((x2 - x1) * (y2 - y1));
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }

};

int main()
{

    LT0939 lt;

    //myvvi vv = { {1,1},{1,3},{3,1},{3,3},{2,2} };
    myvvi vv = { {1,1},{1,3},{3,1},{3,3},{4,1},{4,3} };
    

    cout << " - -" << endl;
    cout << lt.lt0939a(vv) << endl;


    return 0;
}
