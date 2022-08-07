
#include "../header/myheader.h"

class LT1944
{
public:

    // D

    // 是的。


    // tle。。。 倒序 后 再升序。  是不是 vector 头部操作的问题？ 尾部就可以？
    // mono stack. binary search
    vector<int> lt1944a(vector<int>& heights)
    {
        int sz1 = heights.size();
        vector<int> vi;
        vector<int> ans(sz1);
        for (int i = sz1 - 1; i >= 0; --i)
        {
            vector<int>::iterator it = lower_bound(begin(vi), end(vi), heights[i]);
            ans[i] = distance(begin(vi), it);
            if (it != end(vi))
                ans[i]++;
            while (vi.size() > 0 && vi[0] <= heights[i])
                vi.erase(begin(vi));
            vi.insert(begin(vi), heights[i]);
        }
        return ans;
    }

};

int main()
{

    LT1944 lt;

    //myvi v = { 10,6,8,5,11,9 };
    myvi v = { 5,1,2,3,10 };

    myvi v2 = lt.lt1944a(v);

    showVectorInt(v2);

    return 0;
}
