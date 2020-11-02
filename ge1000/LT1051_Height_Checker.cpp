
#include "../header/myheader.h"

class LT1051
{
public:


// D D

// 有一个用了 桶，高度是下标，值是这个高度多少人。
// 然后 开始对比。



//Runtime: 4 ms, faster than 79.06% of C++ online submissions for Height Checker.
//Memory Usage: 8.4 MB, less than 28.75% of C++ online submissions for Height Checker.
    int lt1051a(vector<int>& heights)
    {
        vector<int> cp(begin(heights), end(heights));
        std::sort(begin(cp), end(cp));
        int ans = 0;
        for (int i = 0; i < cp.size(); i++)
        {
            if (cp[i] != heights[i])
            {
                ans++;
            }
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> vv = {{1,1,4,2,1,3},{5,1,2,3,4},{1,2,3,4,5}};

    LT1051 lt;

    for (int i = 0; i < vv.size(); i++)
    {
        cout<<lt.lt1051a(vv[i])<<endl;
    }

    return 0;
}
