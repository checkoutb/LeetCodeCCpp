
#include "../header/myheader.h"

class LT0455
{
public:


// else可以删除，ans==gi...


//Runtime: 40 ms, faster than 88.91% of C++ online submissions for Assign Cookies.
//Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Assign Cookies.

    int lt0455a(vector<int>& g, vector<int>& s)
    {
        int ans = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int gi = 0;
        int si = 0;
        int sz1 = g.size();
        int sz2 = s.size();
        while (gi < sz1 && si < sz2)
        {
            if (g[gi] <= s[si])
            {
                ans++;
                gi++;
                si++;
            }
            else
            {
                si++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> g = {1,2};
    vector<int> s = {1,2,3};

    LT0455 lt;
    cout<<lt.lt0455a(g,s)<<endl;

    return 0;
}
