
#include "../header/myheader.h"

class LT0789
{
public:

// D D 差不多都是这样



//Runtime: 12 ms, faster than 24.30% of C++ online submissions for Escape The Ghosts.
//Memory Usage: 10.4 MB, less than 50.00% of C++ online submissions for Escape The Ghosts.
// 感觉只需要计算(0,0)到target的距离，和每个ghost到target的距离啊。。
    bool lt0789a(vector<vector<int>>& ghosts, vector<int>& target)
    {
        int len2 = std::abs(target[0]) + std::abs(target[1]);           // need abs
        for (vector<int> v : ghosts)
        {
            int len3 = std::abs(v[0] - target[0]) + std::abs(v[1] - target[1]);
            if (len3 <= len2)
                return false;
        }
        return true;
    }

};

int main()
{

    vector<vector<int>> ghs = {{1,9},{2,-5},{3,8},{9,8},{-1,3}};
    vector<int> tar = {8,-10};


    LT0789 lt;

    cout<<lt.lt0789a(ghs, tar)<<endl;

    return 0;
}
