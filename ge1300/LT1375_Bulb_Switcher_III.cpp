
#include "../header/myheader.h"

class LT1375
{
public:

// D D





//Runtime: 112 ms, faster than 84.31% of C++ online submissions for Bulb Switcher III.
//Memory Usage: 38.8 MB, less than 41.72% of C++ online submissions for Bulb Switcher III.
// 前面的max < light[i], && max == i.  说明左侧的灯全亮了。
    int lt1375a(vector<int>& light)
    {
        int ans = 0;
        int mx = 0;
        for (int i = 0, mxi = light.size(); i < mxi; ++i)
        {
            mx = max(mx, light[i]);
            if (mx == (i + 1))
                ans++;
        }
        return ans;
    }

};

int main()
{
//    vector<int> vi = {2,1,3,5,4};
//    vector<int> vi = {3,2,4,1,5};
//    vector<int> vi = {2,1,4,3,6,5};
    vector<int> vi = {1,2,3,4,5,6};

    LT1375 lt;

    cout<<lt.lt1375a(vi)<<endl;

    return 0;
}
