
#include "../../header/myheader.h"

class LT
{
public:

// D D




// AC
    vector<int> lta(vector<int>& nums, int target)
    {
        unordered_map<int, int> map2;
        for (int i = 0; i < nums.size(); ++i)
        {
            int t2 = nums[i];
            if (map2.find(target - t2) != map2.end())
            {
                return {map2[target - t2], i};
            }
            map2[t2] = i;
        }
        return {-1, -1};
    }

};

int main()
{

    LT lt;


    return 0;
}
