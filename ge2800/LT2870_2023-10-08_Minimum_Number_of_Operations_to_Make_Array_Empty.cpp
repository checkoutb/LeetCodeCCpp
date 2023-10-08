
#include "../header/myheader.h"

class LT2870
{
public:






//Runtime115 ms
//Beats
//79.75%
//Memory85.7 MB
//Beats
//16.96%
    // 2 eq , del
    // 3 eq , del
    // to empty, min op
    int minOperations(vector<int>& nums)
    {
        map<int, int> map2;
        for (int i : nums)
            ++map2[i];

        int ans = 0;
        for (auto& [_, cnt] : map2)
        {
            if (cnt == 1)
            {
                ans = -1;
                break;
            }

            ans += cnt / 3 + (cnt % 3 > 0);
        }
        return ans;
    }

};

int main()
{

    LT2870 lt;


    return 0;
}
