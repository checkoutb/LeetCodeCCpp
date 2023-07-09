
#include "../../header/myheader.h"

class LT6899
{
public:



    // AC

    // abs([i] - [j]) <= target
    // <= 1000
    int maximumJumps(vector<int>& nums, int target)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1, 0);
        vi[0] = 1;
        for (int i = 0; i < sz1; ++i)
        {
            if (vi[i] == 0)
                continue;
            int t2 = nums[i];

            for (int j = i + 1; j < sz1; ++j)
            {
                if (std::abs(t2 - nums[j]) <= target)
                {
                    vi[j] = std::max(vi[j], vi[i] + 1);
                }
            }
        }

#ifdef __test
        showVectorInt(vi);
#endif

        return vi[sz1 - 1] - 1;
    }

};

int main()
{

    LT6899 lt;

    myvi vi = { 1,3,6,4,1,2 };
    int tar = 2;

    cout << lt.maximumJumps(vi, tar) << endl;

    return 0;
}
