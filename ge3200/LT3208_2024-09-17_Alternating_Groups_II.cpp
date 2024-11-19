
#include "../header/myheader.h"

class LT3208
{
public:


    // D D

        // for (int i = 0; i < k - 1; ++i) 
        //     colors.push_back(colors[i]);
        // int res = 0;
        // int cnt = 1;
        // for (int i = 1; i < colors.size(); ++i) 
        // {
        //     if (colors[i] != colors[i - 1]) 
        //         ++cnt;
        //     else 
        //         cnt = 1;
            
        //     if (cnt >= k) ++res;
        // }
    // 双倍，就不需要考虑 % sz1 了
    // cnt 计数 alternate 的长度。 我的 st en，也只是为了 en-st+1， 但是 只想到了 必须==k，没有想到 > k 也可以 +1
    


// Runtime
// 70ms
// Beats67.61%
// Analyze Complexity
// Memory
// 101.62MB
// Beats57.37%

    

    // 0 red,  1 blue
    // subarray length k, alternate color.
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int st = 0;
        int en = 0;  // [st, en] is alternate
        int sz1 = colors.size();
        int cnt = 0;
        while (st < sz1) {
            if (en < st) {
                en = st;
            }

            int t2 = (en + 1) % sz1; // circle
            if (colors[t2] != colors[en % sz1]) {
                ++en;
            } else {
                st = en + 1;
            }
            if (en - st + 1 == k) {
                ++cnt;
                ++st;
            }
        }
        return cnt;
    }


};

int main()
{

    LT3208 lt;


    return 0;
}
