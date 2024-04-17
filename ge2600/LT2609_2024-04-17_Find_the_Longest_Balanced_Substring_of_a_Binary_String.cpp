
#include "../header/myheader.h"

class LT2609
{
public:




// Runtime
// 4ms
// Beats52.00%of users with C++
// Memory
// 8.71MB
// Beats69.78%of users with C++
    int findTheLongestBalancedSubstring(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size();)
        {
            if (s[i] == '0')
            {
                int cnt0 = 0;
                int cnt1 = 0;
                while (i < s.size() && s[i] == '0')
                {
                    ++i;
                    ++cnt0;
                }
                while (i < s.size() && s[i] == '1')
                {
                    ++i;
                    ++cnt1;
                }
                ans = max(ans, min(cnt0, cnt1) << 1);
            }
            else
            {
                ++i;
            }
        }
        return ans;
    }
};

int main()
{

    LT2609 lt;


    return 0;
}
