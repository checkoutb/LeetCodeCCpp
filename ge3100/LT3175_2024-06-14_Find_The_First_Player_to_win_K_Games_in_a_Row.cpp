
#include "../header/myheader.h"

class LT3175
{
public:




// Runtime
// 137ms
// Beats92.23%
// Analyze Complexity
// Memory
// 118.87MB
// Beats96.63%
    int findWinningPlayer(vector<int>& skills, int k) {
        int sz1 = skills.size();
        int ans = 0;
        int cnt = 0;
        for (int i = 1; i < sz1; ++i) {
            if (skills[i] > skills[ans]) {
                cnt = 1;
                ans = i;
                if (cnt == k) { // ...
                    break;
                }
            } else {
                ++cnt;
                if (cnt == k) {
                    break;
                }
            }
        }
        return ans;
    }
    


};

int main()
{

    LT3175 lt;


    return 0;
}
