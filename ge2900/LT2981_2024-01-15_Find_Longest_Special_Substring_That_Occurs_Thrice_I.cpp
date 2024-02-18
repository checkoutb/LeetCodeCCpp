
#include "../header/myheader.h"

class LT2981
{
public:




    // ...提交到 II 上了。

// Runtime
// 141ms
// Beats95.60%of users with C++
// Memory
// 48.32MB
// Beats60.42%of users with C++
    int maximumLength(string s)
    {
        std::vector<std::vector<int>> vvi(26);
        size_t sz1 = s.size();
        size_t t2 = 0;
        for (size_t i = 0; i < sz1; ++i)
        {
            t2 = i;
            while (i + 1 < sz1 && s[i + 1] == s[i])         // longest substring with same char
            {
                ++i;
            }
            t2 = i - t2 + 1;
            for (int m = 0; m < 3 && t2 > 0; ++m)           // thrice
            {
                vvi[s[i] - 'a'].push_back(static_cast<int>(t2));
                --t2;
            }
        }
        int ans = -1;
        for (auto& vi : vvi)
        {
            if (vi.size() < 3)
                continue;

            std::sort(begin(vi), end(vi));      // partial_sort
            ans = max(ans, vi[vi.size() - 3]);
        }
        return ans;
    }

};

int main()
{

    LT2981 lt;

    string s = "qwerty";

    cout<<lt.maximumLength(s)<<endl;

    return 0;
}
