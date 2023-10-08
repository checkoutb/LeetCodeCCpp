
#include "../header/myheader.h"

class LT2855
{
public:




//Runtime11 ms
//Beats
//36.97%
//Memory23.4 MB
//Beats
//40.47%
    int minimumRightShifts(vector<int>& nums)
    {
        if (nums.size() == 1)
            return 0;

        int mni = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < nums[(i - 1 + nums.size()) % nums.size()])
            {
                if (mni == -1)
                    mni = i;
                else
                    return -1;
            }
        }
        return (nums.size() - mni) % nums.size();
    }

};

int main()
{

    LT2855 lt;


    return 0;
}
