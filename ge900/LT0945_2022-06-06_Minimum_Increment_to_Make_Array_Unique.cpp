
#include "../header/myheader.h"

class LT0945
{
public:

    // D D

    //map<int, int> count;
    //for (int a : A) count[a]++;
    //int res = 0, need = 0;
    //for (auto x : count) {
    //    res += x.second * max(need - x.first, 0) + x.second * (x.second - 1) / 2;
    //    need = max(need, x.first) + x.second;
    //}






//Runtime: 214 ms, faster than 59.35 % of C++ online submissions for Minimum Increment to Make Array Unique.
//Memory Usage : 65.6 MB, less than 69.62 % of C++ online submissions for Minimum Increment to Make Array Unique.
    int lt0945b(vector<int>& nums)
    {
        int ans = 0;
        sort(begin(nums), end(nums));
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] <= nums[i - 1])
            {
                ans += (nums[i - 1] + 1 - nums[i]);
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ans;
    }


    // error...
    // 找空隙？ 1,2,1,2,3,4,7  1->5,2->6 == 1->6,2->5
    // 大于自身的最小空隙。
    // or  1,2,2,3,4  2->5 == 2->3,3->4,4->5
    int lt0945a(vector<int>& nums)
    {
        std::sort(begin(nums), end(nums));
        int cnt = 0;
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])     // t2 == 0....
            {
                ans += cnt;
                cnt++;
            }
            else   // [i] > [i - 1]
            {
                int t2 = nums[i] - nums[i - 1] - 1;
                if (t2 == 1)
                {
                    ans += cnt;
                }
                else
                {
                    if (t2 >= cnt)
                    {
                        ans += (long) (cnt + 1) * cnt / 2;
                        cnt = 0;
                    }
                    else
                    {
                        ans += (long)(cnt + 1 - t2) * (cnt - t2) / 2;
                        cnt -= t2;
                        ans += cnt;
                    }
                }
            }
        }
        return ans + (long) (cnt + 1) * cnt / 2;
    }

};

int main()
{

    LT0945 lt;

    vector<int> vi = { 1,2,2 };

    //vector<int> vi = { 3,2,1,2,1,7 };

    cout << lt.lt0945b(vi) << endl;

    return 0;
}
