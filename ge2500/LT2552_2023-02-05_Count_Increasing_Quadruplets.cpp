
#include "../header/myheader.h"

class LT2552
{
public:




    // g


    // i j k l
    // i k j l
    // i < k < l
    // i < j < l
    // k < j
    // nnlogn
    long long lt2552a(vector<int>& nums)
    {
        int sz1 = nums.size();
        long long ans = 0LL;
        set<int>::iterator it;
        int dis;
        for (int i = 0; i < sz1; ++i)
        {
            set<int> set2;
            for (int j = i; j < sz1; ++j)
            {
                it = set2.lower_bound(nums[j]);
                dis = std::distance(begin(set2), it);
                if (dis >= 2)
                {
                    ans += 1LL * dis * (dis - 1) / 2;
                }
                if (nums[j] > nums[i])
                    set2.insert(nums[j]);
            }
        }
        return ans;
    }

};

int main()
{

    LT2552 lt;

    myvi v = { 1,3,2,4,5 };

    cout << lt.lt2552a(v) << endl;

    return 0;
}
