
#include "../header/myheader.h"

class LT2899
{
public:







// Runtime
// 4ms
// Beats81.06%of users with C++
// Memory
// 25.33MB
// Beats28.87%of users with C++
    vector<int> lastVisitedIntegers(vector<int>& nums)
    {
        vector<int> ans;
        vector<int> seen;
        int cntNeg = 0;
        for (int n : nums)
        {
            if (n == -1)
            {
                ++cntNeg;
                if (seen.size() >= cntNeg)
                {
                    ans.push_back(seen[cntNeg - 1]);
                }
                else
                {
                    ans.push_back(-1);
                }
            }
            else
            {
                cntNeg = 0;
                seen.insert(seen.begin(), n);
            }
        }
        return ans;
    }
};

int main()
{

    LT2899 lt;


    return 0;
}
