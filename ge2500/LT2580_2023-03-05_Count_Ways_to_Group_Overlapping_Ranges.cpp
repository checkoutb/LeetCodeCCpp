
#include "../header/myheader.h"

class LT2580
{
public:

    // D D



    //Runtime309 ms
    //    Beats
    //    100 %
    //    Memory72.7 MB
    //    Beats
    //    100 %
    // 相交 就 合并。  2^n
    int lt2580a(vector<vector<int>>& ranges)
    {
        int sz1 = ranges.size();

        sort(begin(ranges), end(ranges), [](const vector<int>& v1, const vector<int>& v2) {
                if (v1[0] == v2[0])
                {
                    return v1[1] > v2[1];
                }
                else
                {
                    return v1[0] < v2[0];
                }
            });

        int en = ranges[0][1];      // ]
        int cnt = 1;

        for (int i = 1; i < sz1; ++i)
        {
            if (ranges[i][0] > en)
            {
                ++cnt;
            }
            en = max(en, ranges[i][1]);
        }

        const int MOD = 1e9 + 7;
        int ans = 1;
        while (cnt > 0)
        {
            ans = (ans * 2) % MOD;
            --cnt;
        }
        return ans;
    }

};

int main()
{

    LT2580 lt;

    //myvvi vv = { {6,10},{5,15} };
    myvvi vv = { {1,3},{10,20},{2,5},{4,8},{4,7} };


    cout << lt.lt2580a(vv) << endl;

    return 0;
}
