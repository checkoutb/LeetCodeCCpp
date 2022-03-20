
#include "../header/myheader.h"

class LT1011
{
public:

// D D

//  while (l < r) {
//    auto m = (l + r) / 2;
//    if (countDays(ws, m) <= D) r = m;
//    else l = m + 1;
//  }
//  return l;


//        while (left < right) {
//            int mid = (left + right) / 2, need = 1, cur = 0;
//            for (int i = 0; i < weights.size() && need <= D; cur += weights[i++])
//                if (cur + weights[i] > mid)
//                    cur = 0, need++;
//            if (need > D) left = mid + 1;
//            else right = mid;
//        }
//        return left;


// 边界太难了。。
//Runtime: 95 ms, faster than 30.41% of C++ online submissions for Capacity To Ship Packages Within D Days.
//Memory Usage: 26 MB, less than 94.55% of C++ online submissions for Capacity To Ship Packages Within D Days.
// 二分
    int lt1011a(vector<int>& weights, int days)
    {
        int l = 1, r = 50000000;
        int ans = 0;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            int cnt2 = 0;
            int t2 = 0;
            for (int i = 0; i < weights.size(); ++i)
            {
                if (weights[i] > mid || cnt2 >= days)
                {
                    cnt2 = days + 1;
                    break;
                }
                if (t2 + weights[i] <= mid)
                {
                    t2 += weights[i];
                }
                else
                {
                    cnt2++;
                    t2 = weights[i];
                }
            }
            cnt2++;
            if (cnt2 <= days)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        return ans;
    }

};

int main()
{

    LT1011 lt;

//    myvi v = {1,2,3,4,5,6,7,8,9,10};
//    int d = 5;

//    myvi v = {3,2,2,4,1,4};
//    int d = 3;

//    myvi v = {1,2,3,1,1};
//    int d = 4;

    myvi v = {1,2,3,4,5,6,7,8,9,10};
    int d = 1;


    cout<<lt.lt1011a(v, d)<<endl;

    return 0;
}
