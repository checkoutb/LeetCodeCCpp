
#include "../header/myheader.h"

class LT2611
{
public:





    //Runtime151 ms
    //    Beats
    //    61.41 %
    //    Memory105.3 MB
    //    Beats
    //    86.85 %
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k)
    {
        int sz1 = reward1.size();
        vector<pair<int, int>> vp(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            vp[i].first = reward1[i] - reward2[i];
            vp[i].second = i;
        }

        std::sort(rbegin(vp), rend(vp));
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (i < k)
                ans += reward1[vp[i].second];
            else
                //ans += vp[i].first > 0 ? reward1[vp[i].second] : reward2[vp[i].second];
                ans += reward2[vp[i].second];
        }
        return ans;
    }

};

int main()
{

    LT2611 lt;


    return 0;
}
