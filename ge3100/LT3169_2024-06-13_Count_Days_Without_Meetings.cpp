
#include "../header/myheader.h"

class LT3169
{
public:






// Runtime
// 316ms
// Beats76.80%
// Analyze Complexity
// Memory
// 125.56MB
// Beats69.85%
    int countDays(int days, vector<vector<int>>& meetings) {
        std::sort(std::begin(meetings), std::end(meetings));
        int ans = 0;
        int en = 0;
        for (int i = 0; i < meetings.size(); ++i) {
            if (meetings[i][0] > en) {
                ans += meetings[i][0] - en - 1;
            }
            en = std::max(en, meetings[i][1]);
        }
        if (en < days)
            ans += days - en;
        return ans;
    }


};

int main()
{

    LT3169 lt;


    return 0;
}
