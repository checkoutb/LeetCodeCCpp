
#include "../header/myheader.h"

class LT2420
{
public:

// D D

//    int before = 1, sz = nums.size();
//    vector<int> after(sz, 1), res;
//    for (int i = sz - 2; i > 0; --i)
//        after[i - 1] = nums[i] > nums[i + 1] ? 1 : after[i] + 1;
//    for (int i = 1; i < sz - 1; ++i) {
//        if (min(before, after[i]) >= k)
//            res.push_back(i);
//        before = nums[i] > nums[i - 1] ? 1 : before + 1;
//    }
//    return res;


//    int before_cnt = 1, after_cnt = 1, sz = nums.size();
//    vector<int> bid, aid;
//    for (int i = 1; i < sz; ++i) {
//        if (before_cnt >= k)
//            bid.push_back(i);
//        if (after_cnt >= k)
//            aid.push_back(sz - i - 1);
//        before_cnt = nums[i] > nums[i - 1] ? 1 : before_cnt + 1;
//        after_cnt = nums[sz - i - 1] > nums[sz - i] ? 1 : after_cnt + 1;
//    }
//    auto it = set_intersection(begin(bid), end(bid), rbegin(aid), rend(aid), begin(bid));
//    return vector<int>(begin(bid), it);



//Runtime: 327 ms, faster than 51.97% of C++ online submissions for Find All Good Indices.
//Memory Usage: 85.9 MB, less than 84.93% of C++ online submissions for Find All Good Indices.
    vector<int> lt2420a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();

        vector<int> vi(sz1);
        vector<int> ans;

        int t2 = 1;
        vi[sz1 - 1] = 0;
        for (int i = sz1 - 2; i >= 0; --i)
        {
            vi[i] = t2;
            if (nums[i] <= nums[i + 1])
            {
                ++t2;
            }
            else
            {
                t2 = 1;
            }
        }

        #ifdef __test
        showVectorInt(vi);
        #endif // __test

        t2 = 1;
        for (int i = 1; i < sz1; ++i)
        {
            if (t2 >= k && vi[i] >= k)
            {
                ans.push_back(i);
            }
            if (nums[i - 1] >= nums[i])
            {
                ++t2;
            }
            else
            {
                t2 = 1;
            }
        }

        return ans;
    }

};

int main()
{

    LT2420 lt;

    myvi v = {878724,201541,179099,98437,35765,327555,475851,598885,849470,943442};
    int k = 4;

    myvi v2 = lt.lt2420a(v, k);

    showVectorInt(v2);

    return 0;
}
