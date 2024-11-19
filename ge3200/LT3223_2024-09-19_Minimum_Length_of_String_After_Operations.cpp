
#include "../header/myheader.h"

class LT3223
{
public:



    // D D

    // for (int i = 0; i < 26; i++) out += (mem[i] > 2)? (2- (mem[i] % 2)): mem[i];

    

// Runtime
// 99ms
// Beats83.40%
// Analyze Complexity
// Memory
// 30.66MB
// Beats77.29%

    

    // 1,3,5,7 -> 1,  2,4,6 -> 2
    int minimumLength(string s) {
        int arr[26] = {0};
        for (char ch : s) {
            ++arr[ch - 'a'];
        }
        int ans = 0;
        for (int a : arr) {
            if (a == 0)
                continue;
            ans += (a % 2 == 1 ? 1 : 2);
        }
        return ans;
    }


};

int main()
{

    LT3223 lt;


    return 0;
}
