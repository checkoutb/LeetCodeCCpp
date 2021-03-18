
#include "../header/myheader.h"

class LT1760
{
public:

// D D

//The number of operation we need is (a - 1) / mid

//        while (left < right) {
//            int mid = (left + right) / 2, count = 0;
//            for (int a : A)
//                count += (a - 1) / mid;
//            if (count > k)
//                left = mid + 1;
//            else
//                right = mid;
//        }


//    while (l < r) {
//        int m = (l + r) / 2;
//        if (accumulate(begin(ns), end(ns), 0, [&](int s, int n){ return s + (n - 1) / m; }) <= maxOperations)
//            r = m;
//        else
//            l = m + 1;
//    }




//Runtime: 200 ms, faster than 47.65% of C++ online submissions for Minimum Limit of Balls in a Bag.
//Memory Usage: 55.8 MB, less than 5.61% of C++ online submissions for Minimum Limit of Balls in a Bag.
// hint: binary search
    int lt1760a(vector<int>& nums, int maxOperations)
    {
        int l = 1;
        std::sort(begin(nums), end(nums));
//        int r = *max_element(begin(nums), end(nums));
        int r = nums[nums.size() - 1];
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            bool can = true;
//            vector<int>::iterator it = std::lower_bound(begin(nums), end(nums), );
            int t2 = maxOperations;
            #ifdef __test
            cout<<l<<", "<<r<<", "<<mid<<endl;
            #endif // __test
            for (vector<int>::iterator it = std::upper_bound(begin(nums), end(nums), mid); it != end(nums); it++)
            {
                t2 -= ((*it / mid) + (*it % mid > 0 ? 1 : 0) - 1);
//                cout<<t2<<", "<<*it<<endl;
                if (t2 < 0)
                {
                    can = false;
                    break;
                }
            }
            if (can)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }

};

int main()
{
//    myvi v = {9};
//    int k = 2;

//    myvi v = {2,4,8,2};
//    int k = 4;

    myvi v = {7,17};
    int k = 2;

    LT1760 lt;

    cout<<lt.lt1760a(v, k);

    return 0;
}
