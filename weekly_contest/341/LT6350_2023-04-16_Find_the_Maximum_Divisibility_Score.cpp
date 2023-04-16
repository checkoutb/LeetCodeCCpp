
#include "../../header/myheader.h"

class LT6350
{
public:



    // AC
    // ¡£¡£
    int lta(vector<int>& nums, vector<int>& divisors)
    {
        set<int> set2;
        int sz1 = nums.size();
        int sz2 = divisors.size();

        sort(rbegin(nums), rend(nums));
        int mx = -1;
        int ans = -1;
        for (int i = 0; i < sz2; ++i)
        {
            int t2 = divisors[i];
            if (set2.find(t2) != set2.end())
                continue;
            set2.insert(t2);
            int cnt = 0;
            for (int j = 0; j < sz1 && t2 <= nums[j]; ++j)
            {
                if (nums[j] % t2 == 0)
                    ++cnt;
            }
            if (cnt > mx)
            {
                mx = cnt;
                ans = i;
            }
            else if (cnt == mx && divisors[ans] > divisors[i])
                ans = i;
        }
        return divisors[ans];
    }

};

int main()
{

    LT6350 lt;

    //myvi v1 = { 4,7,9,3,9 };
    //myvi v2 = { 2,3 };

    myvi v1 = { 73, 13, 20, 6 };
    myvi v2 = { 56, 75, 83, 26, 24, 53, 56, 61 };

    cout << lt.lta(v1, v2) << endl;

    return 0;
}
