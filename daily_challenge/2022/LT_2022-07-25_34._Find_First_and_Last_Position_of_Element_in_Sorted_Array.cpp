
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // 边界条件。
    // sz1 or sz1-1
    // (l+r)/2 or (l+r+1)/2 or (l+r)/2+1
    // <= t or < t
    // =md or =md+1/-1



    // error
    vector<int> ltc(vector<int>& nums, int target)
    {
        if (nums.empty())
            return { -1,-1 };

        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int md = (l + r) / 2;
            int t2 = nums[md];
            if (t2 >= target)
            {
                r = md;
            }
            else
            {
                l = md + 1;
            }
        }

        if (nums[l] != target)
            return { -1, -1 };

        int fst = l;

        target++;

        l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int md = (l + r) / 2;
            int t2 = nums[md];
            if (t2 >= target)
            {
                r = md;
            }
            else
            {
                l = md + 1;
            }
        }

        int lst = l - 1;

        return { fst, lst };

    }



//Runtime: 7 ms, faster than 90.42 % of C++ online submissions for Find Firstand Last Position of Element in Sorted Array.
//Memory Usage : 13.5 MB, less than 83.66 % of C++ online submissions for Find Firstand Last Position of Element in Sorted Array.
    vector<int> ltb(vector<int>& nums, int target)
    {
        if (nums.empty())
            return { -1,-1 };
        auto it1 = lower_bound(begin(nums), end(nums), target);
        auto it2 = upper_bound(begin(nums), end(nums), target);
        int fst = (it1 == end(nums) || *it1 != target) ? -1 : std::distance(begin(nums), it1);
        int lst = (it2 == begin(nums) || *prev(it2) != target) ? -1 : (std::distance(begin(nums), it2) - 1);
        return { fst, lst };
    }



    // ... 必须 logn,  非降
    vector<int> lta(vector<int>& nums, int target)
    {
        int fst = -1;
        int lst = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == target)
            {
                lst = i;
                //fst = fst != -1 ? : i;                // visual studio community 2022, syntax error
                fst = fst != -1 ? fst : i;
            }
        }
        return { fst, lst };
    }

};

int main()
{

    LT lt;

    //myvi v = { 5,7,7,8,8,10 };
    //int tar = 6;

    myvi v = {};
    int tar = 2;

    myvi v2 = lt.ltc(v, tar);

    cout << v2[0] << " - " << v2[1] << endl;

    return 0;
}
