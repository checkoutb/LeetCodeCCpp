
#include "../header/myheader.h"

class LT0452
{
public:

// detail && discuss
// sort by v[1]


//Runtime: 136 ms, faster than 61.96% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
//Memory Usage: 27 MB, less than 100.00% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.

    int lt0452a(vector<vector<int>>& points)
    {
        if (points.size() == 0)
            return 0;
        int ans = 1;
        std::sort(points.begin(), points.end(), [](vector<int>& v1, vector<int>& v2){return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];});

//        for (auto p : points)
//        {
//            for (auto p2 : p)
//            {
//                cout<<p2<<", ";
//            }
//            cout<<endl;
//        }

        int i = 0;
        int sz1 = points.size();
        int sh = points[0][1];
        while (i < sz1)
        {
            if (points[i][0] > sh)
            {
                ans++;
                sh = points[i][1];
            }
            else
            {
                sh = std::min(sh, points[i][1]);
            }
            i++;
        }

        return ans;
    }
};

int main()
{

    vector<vector<int>> p = {{10,16},{2,8},{1,6},{7,12}};

    LT0452 lt;
    cout<<lt.lt0452a(p)<<endl;

    return 0;
}
