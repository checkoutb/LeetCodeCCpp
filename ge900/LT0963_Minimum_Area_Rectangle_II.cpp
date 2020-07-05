
#include "../header/myheader.h"

class LT0963
{
public:






//Runtime: 128 ms, faster than 58.33% of C++ online submissions for Minimum Area Rectangle II.
//Memory Usage: 15.5 MB, less than 57.01% of C++ online submissions for Minimum Area Rectangle II.
// 一对 对边长度==， 对角线==， 是不是必然矩形？不，十字交叉，再旋转随意一个角度。
    double lt0963a(vector<vector<int>>& points)
    {
        int sz1 = points.size();
        unordered_map<int, vector<pair<int, int>>> map2;
        int len = 0;
        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                 len = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                 map2[len].push_back({i, j});
            }
        }

        #ifdef __test
        for (auto& p : map2)
        {
            cout<<p.first<<":";
            vector<pair<int, int>> pr = p.second;
            for_each(pr.begin(), pr.end(), [](pair<int, int>& pa) { cout<<pa.first<<" + "<<pa.second<<"  ; "; });
            cout<<endl;
        }
        #endif // __test

        double ans = INT_MAX;
        for (unordered_map<int, vector<pair<int, int>>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            len = it->first;
            double a = std::sqrt(len);
            double b = 0;
            double c = 0;
            vector<pair<int, int>> v2 = it->second;
            for (int i = 0; i < v2.size(); i++)
            {
                int pi1 = v2[i].first;
                int pi2 = v2[i].second;
                for (int j = i + 1; j < v2.size(); j++)
                {
                    int pi3 = v2[j].first;
                    int pi4 = v2[j].second;
                    int l1 = (points[pi1][0] - points[pi3][0]) * (points[pi1][0] - points[pi3][0]) + (points[pi1][1] - points[pi3][1]) * (points[pi1][1] - points[pi3][1]);
                    int l2 = (points[pi2][0] - points[pi4][0]) * (points[pi2][0] - points[pi4][0]) + (points[pi2][1] - points[pi4][1]) * (points[pi2][1] - points[pi4][1]);
                    if (l1 == l2)
                    {
                        b = sqrt(l1);
                        l1 = (points[pi1][0] - points[pi4][0]) * (points[pi1][0] - points[pi4][0]) + (points[pi1][1] - points[pi4][1]) * (points[pi1][1] - points[pi4][1]);
                        l2 = (points[pi2][0] - points[pi3][0]) * (points[pi2][0] - points[pi3][0]) + (points[pi2][1] - points[pi3][1]) * (points[pi2][1] - points[pi3][1]);
                        if (l1 == l2)
                        {
                            c = sqrt(l1);
                            double area1 = min(c * b, min(a * b, a * c));
                            ans = min(ans, area1);
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{1,2},{2,1},{1,0},{0,1}};

//    vector<vector<int>> vv = {{0,1},{2,1},{1,1},{1,0},{2,0}};

//    vector<vector<int>> vv = {{0,3},{1,2},{3,1},{1,3},{2,1}};

    vector<vector<int>> vv = {{3,1},{1,1},{0,1},{2,1},{3,3},{3,2},{0,2},{2,3}};

    LT0963 lt;

    cout<<lt.lt0963a(vv)<<endl;

    return 0;
}
