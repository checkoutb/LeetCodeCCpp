
#include "../../header/myheader.h"

class LT6430
{
public:


    // AC

    // 0 + k
    // k + 2K
    // k+2k+3k
    // 1234
    // 12345
    //
    // 1 3 6 10 15
    // fst snd    min snd
    //
    // < 50... ++
    vector<int> circularGameLosers(int n, int k)
    {
        vector<bool> vb(n, false);
        int idx = 0;
        int cnt = 0;
        while (true)
        {
            idx = (idx + cnt * k) % n;
            if (vb[idx])
                break;

            vb[idx] = true;
            ++cnt;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (!vb[i])
                ans.push_back(i + 1);
        }
        return ans;
    }


};

int main()
{

    LT6430 lt;


    return 0;
}
