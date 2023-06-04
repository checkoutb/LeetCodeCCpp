
#include "../../header/myheader.h"

class LT6424
{
public:


    // AC
    int semiOrderedPermutation(vector<int>& nums)
    {
        int sz1 = nums.size();
        int idx1 = -1;
        int idxN = -1;
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] == 1)
            {
                idx1 = i;
            }
            else if (nums[i] == sz1)
            {
                idxN = i;
            }
        }

        return idx1 + sz1 - idxN - 1 - (idx1 > idxN);
    }

};

int main()
{

    LT6424 lt;


    return 0;
}
