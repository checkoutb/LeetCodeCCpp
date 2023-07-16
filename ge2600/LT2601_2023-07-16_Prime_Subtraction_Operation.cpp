
#include "../header/myheader.h"

class LT2601
{
public:





//Runtime28 ms
//Beats
//77.62%
//Memory25.7 MB
//Beats
//40.59%

    bool lta(vector<int>& nums)
    {
        vector<bool> vb(1001, false);   // can be divide ?
        for (int i = 2; i < 1001; ++i)
        {
            if (!vb[i])
            {
                for  (int j = i + i; j < 1001; j += i)
                    vb[j] = true;
            }
        }
        vector<int> prm;
        for (int i = 2; i < 1001; ++i)
        {
            if (!vb[i])
                prm.push_back(i);
        }

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
                continue;

            int t2 = nums[i] - nums[i + 1];
            for (int j = 0; j < prm.size(); ++j)
            {
                if (prm[j] > t2)
                {
                    nums[i] -= prm[j];
                    break;
                }
            }
            if (nums[i] <= 0 || nums[i] >= nums[i + 1])
                return false;
        }

        return true;
    }

};

int main()
{

    LT2601 lt;


    return 0;
}
