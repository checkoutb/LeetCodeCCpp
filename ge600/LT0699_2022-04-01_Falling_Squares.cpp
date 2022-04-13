
#include "../header/myheader.h"

class LT0699
{
public:

// D D

// .




//Runtime: 64 ms, faster than 50.00% of C++ online submissions for Falling Squares.
//Memory Usage: 10.8 MB, less than 91.15% of C++ online submissions for Falling Squares.
// v[0] - v[0]+v[1] 下标间的 最大值。
// 1000 个数
    vector<int> lt0699a(vector<vector<int>>& positions)
    {
        int sz1 = positions.size();
        vector<int> vi(sz1, 0);         //
        vector<int> ans(sz1, 0);
        int mx = positions[0][1];
        vi[0] = mx;
        ans[0] = mx;
        for (int i = 1; i < sz1; ++i)
        {
            int t2 = 0;
            int st = positions[i][0];
            int en = st + positions[i][1];
            for (int j = 0; j < i; ++j)
            {
                if (positions[j][0] < en && (positions[j][0] + positions[j][1]) > st)
                {
                    t2 = max(t2, vi[j]);
                }
            }
            vi[i] = t2 += positions[i][1];
            ans[i] = mx = max(mx, t2);
        }
        return ans;
    }

};

int main()
{

    LT0699 lt;

//    myvvi vv = {{1,2},{2,3},{6,1}};
    myvvi vv = {{101,100},{200,100}};

    myvi v = lt.lt0699a(vv);

    showVectorInt(v);

    return 0;
}
