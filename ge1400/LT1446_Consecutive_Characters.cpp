
#include "../header/myheader.h"

class LT1446
{
public:

// D D






//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Consecutive Characters.
//Memory Usage: 7.1 MB, less than 76.48% of C++ online submissions for Consecutive Characters.
    int lt1446a(string s)
    {
        int ans = 0;
        int cnt = 1;
        for (int i = 1, mxi = s.size(); i < mxi; ++i)
        {
            if (s[i] == s[i - 1])
            {
                cnt++;
            }
            else
            {
                ans = max(cnt, ans);
                cnt = 1;
            }
        }
        ans = max(cnt, ans);
        return ans;
    }

};

int main()
{
    vector<string> vs = {"leetcode", "abbcccddddeeeeedcba", "triplepillooooow", "hooraaaaaaaaaaay", "asdzxc"};

    LT1446 lt;

    for (string& s : vs)
    {
        cout<<lt.lt1446a(s)<<endl;
    }

    return 0;
}
