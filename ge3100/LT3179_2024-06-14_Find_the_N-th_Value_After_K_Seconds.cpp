
#include "../header/myheader.h"

class LT3179
{
public:




// Runtime
// 242ms
// Beats57.47%
// Analyze Complexity
// Memory
// 8.56MB
// Beats73.93%
    int valueAfterKSeconds(int n, int k) {
        std::vector<int> vi(n, 1);
        const int MOD = 1e9 + 7;
        while (k-- > 0) {
            for (int i = 1; i < n; ++i) {
                vi[i] = (vi[i - 1] + vi[i]) % MOD;
            }
        }
        return vi[n - 1];
    }


};

int main()
{

    LT3179 lt;


    return 0;
}
