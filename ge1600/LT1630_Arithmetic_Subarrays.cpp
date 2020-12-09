
#include "../header/myheader.h"

class LT1630
{
public:

// D D

//    for (auto i = 0; i < l.size(); ++i) {
//        int mn_e = INT_MAX, mx_e = INT_MIN, len = r[i] - l[i] + 1, j = l[i];
//        for (int j = l[i]; j <= r[i]; ++j) {
//            mn_e = min(mn_e, n[j]);
//            mx_e = max(mx_e, n[j]);
//        }
//        if (mx_e == mn_e)
//            res.push_back(true);
//        else if ((mx_e - mn_e) % (len - 1))
//             res.push_back(false);
//        else {
//            vector<bool> diffs(len);
//            int pat = (mx_e - mn_e) / (len - 1);
//            for (; j <= r[i]; ++j) {
//                if ((n[j] - mn_e) % pat || diffs[(n[j] - mn_e) / pat])
//                    break;
//                diffs[(n[j] - mn_e) / pat] = true;
//            }
//            res.push_back(j > r[i]);
//        }
//    }
// 区间最大，最小， 如果最大==最小，true
// 如果 最大-最小，不能被 len-1 整除， false。     i个点，需要 i-1 个 interval
// 如果元素不是 min + pat * N 的形式，false
// 根据 元素，间隔，计算出 下标。如果下标已经有了，说明重复， false。



//Runtime: 148 ms, faster than 73.33% of C++ online submissions for Arithmetic Subarrays.
//Memory Usage: 26.1 MB, less than 66.00% of C++ online submissions for Arithmetic Subarrays.
    vector<bool> lt1630a(vector<int>& nums, vector<int>& l, vector<int>& r)
    {
        vector<bool> ans(l.size(), false);
        for (int j = 0; j < l.size(); ++j)
        {
            vector<int> vi(begin(nums) + l[j], begin(nums) + r[j] + 1);
            sort(begin(vi), end(vi));
            for (int i = 2; i < vi.size(); ++i)
            {
                if (vi[i] - vi[i - 1] != vi[1] - vi[0])
                    goto AAA;
            }
            ans[j] = true;
            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{

//    myvi v1 = {4,6,5,9,3,7};
//    myvi v2 = {0,0,2};
//    myvi v3 = {2,3,5};

    myvi v1 = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
    myvi v2 = {0,1,6,4,8,7};
    myvi v3 = {4,4,9,7,9,10};

    LT1630 lt;

    vector<bool> vb = lt.lt1630a(v1,v2,v3);

    for (bool b :vb)
        cout<<b<<", ";

    return 0;
}
