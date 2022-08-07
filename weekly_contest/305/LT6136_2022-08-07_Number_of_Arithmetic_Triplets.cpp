
#include "../../header/myheader.h"

class LT6136
{
public:




    // AC
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int sz1 = nums.size();
        int ans = 0;
        multiset<int> mset(begin(nums), end(nums));
        unordered_set<int> set2;
        mset.erase(nums[0]);
        set2.insert(nums[0]);

        for (int i = 1; i < sz1 - 1; ++i)
        {
            mset.erase(nums[i]);

            if (set2.find(nums[i] - diff) != set2.end() && mset.find(nums[i] + diff) != mset.end())
            {
                ans++;
            }

            set2.insert(nums[i]);
        }
        return ans;
    }

};

int main()
{

    LT6136 lt;

    myvi v = { 0,1,4,6,7,10 };
    int df = 3;

    cout << lt.arithmeticTriplets(v, df) << endl;
    return 0;
}
