
#include "../../header/myheader.h"

class LT100040
{
public:



    // AC

    // select && selected count > nums[i]
    // not select && selected count < nums[i]
    // way
    int countWays(vector<int>& nums)
    {
        map<int, int> map2;
        for (int i : nums)
            ++map2[i];
        
        int chosen = 0;
        int ans = 0;
        int lst = -1;
        for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            int t2 = it->first;     // limit            // not choose
            int t3 = it->second;    // count of student

            if (chosen < t2 && chosen > lst)
            {
                ++ans;
            }

            lst = t2;
            chosen += t3;
        }
        if (map2.rbegin()->first < nums.size())
            ++ans;
        return ans;
    }

};

int main()
{

    LT100040 lt;


    return 0;
}
