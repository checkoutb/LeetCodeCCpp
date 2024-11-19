
#include "../header/myheader.h"

class LT3228
{
public:

    // D D
    
        // for (int i = 0; i < n; ++i) {
        //     ones += s[i] - '0';
        //     if (i > 0 && s[i] < s[i - 1])
        //         res += ones;
        // }
    



// Runtime
// 25ms
// Beats74.93%
// Analyze Complexity
// Memory
// 13.94MB
// Beats99.11%

    
    // 10    1->
    // max op
    int maxOperations(string s) {
        int ans = 0;
        int cnt1 = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (i > 0 && s[i - 1] == '0') {
                    ans += cnt1;
                }
                ++cnt1;
            }
        }
        if (s.back() == '0') {
            ans += cnt1;
        }
        return ans;
    }


};

int main()
{

    LT3228 lt;


    return 0;
}
