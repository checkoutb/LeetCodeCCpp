
#include "../header/myheader.h"

class LT2404
{
public:


    // D D

    //auto even_end = remove_if(begin(nums), end(nums), [](int n) { return n % 2; });
    //sort(begin(nums), even_end);
    //int cnt = 0, max_cnt = 0, res = -1;
    //for (auto it = begin(nums); it != even_end; ++it) {
    //    cnt = it != begin(nums) && *it == *prev(it) ? cnt + 1 : 1;
    //    res = max_cnt < cnt ? *it : res;
    //    max_cnt = max(max_cnt, cnt);
    //}


    //if (int cnt = ++m[n]; cnt >= max_cnt) {
    //    res = max_cnt < cnt ? n : min(res, n);
    //    max_cnt = cnt;
    //}



//Runtime: 141 ms, faster than 79.07 % of C++ online submissions for Most Frequent Even Element.
//Memory Usage : 30.5 MB, less than 99.20 % of C++ online submissions for Most Frequent Even Element.
    int lt2404a(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        int ans = -1;
        int mx = 0;

        int sz1 = nums.size();
        int cnt = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] % 2 == 0)
            {
                cnt = 1;
                while ((i + 1 < sz1) && nums[i + 1] == nums[i])
                {
                    ++cnt;
                    ++i;
                }
                if (cnt > mx)
                {
                    ans = nums[i];
                    mx = cnt;
                }
                cnt = 0;
            }
        }
        if (cnt > mx)
        {
            ans = nums[sz1 - 1];
        }
        return ans;
    }

};

int main()
{

    LT2404 lt;


    return 0;
}
