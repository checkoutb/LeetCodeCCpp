
#include "../header/myheader.h"

class LT0474
{
public:




// tle...
// daily chanllenge
// 01
    int lt0474a(vector<string>& strs, int m, int n)
    {
        int sz1 = strs.size();
        vector<pair<int, int>> vp(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            int cnt0 = 0;
            int cnt1 = 0;
            for (char ch : strs[i])
            {
                if (ch == '0')
                {
                    cnt0++;
                }
                else
                {
                    cnt1++;
                }
            }
            vp[i] = make_pair(cnt0, cnt1);
        }

        int ans = 0;
        dfsa1(vp, m, n, ans, 0, 0);
        return ans;
    }

    void dfsa1(vector<pair<int, int>>& vp, int mx0, int mx1, int& ans, int cnt, int idx)
    {
        if (idx == vp.size())
        {
            if (cnt > ans)
                ans = cnt;
            return;
        }
        for (int i = idx; i < vp.size(); ++i)
        {
            if (vp[i].first <= mx0 && vp[i].second <= mx1)
            {
                dfsa1(vp, mx0 - vp[i].first, mx1 - vp[i].second, ans, cnt + 1, i + 1);
            }
        }
        if (cnt > ans)
            ans = cnt;
    }

};

int main()
{

    LT0474 lt;


    return 0;
}
