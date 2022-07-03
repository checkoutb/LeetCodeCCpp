
#include "../../header/myheader.h"

class LT
{
public:

    // D D


    //for (int i = 1; i < n; i++)
    //{
    //    if (nums[i] - nums[i - 1] > 0)
    //    {
    //        inc = dec + 1;
    //    }
    //    else if (nums[i] - nums[i - 1] < 0)
    //    {
    //        dec = inc + 1;
    //    }
    //}


    //for (int i = 1; i < nums.length; i++) {
    //    if (nums[i] > nums[i - 1]) {
    //        up[i] = down[i - 1] + 1;
    //        down[i] = down[i - 1];
    //    }
    //    else if (nums[i] < nums[i - 1]) {
    //        down[i] = up[i - 1] + 1;
    //        up[i] = up[i - 1];
    //    }
    //    else {
    //        down[i] = down[i - 1];
    //        up[i] = up[i - 1];
    //    }
    //}


    //def wiggleMaxLength(self, nums) :
    //    nan = float('nan')
    //    diffs = [a - b for a, b in zip([nan] + nums, nums + [nan]) if a - b]
    //    return sum(not d * e >= 0 for d, e in zip(diffs, diffs[1:]))



//Runtime: 12 ms, faster than 28.34 % of C++ online submissions for Wiggle Subsequence.
//Memory Usage : 7.6 MB, less than 11.24 % of C++ online submissions for Wiggle Subsequence.
    // 小于它的&值最大的。。
    // 上一个比它大的，上一个比它小的。
    int lta(vector<int>& nums)
    {
        int sz1 = nums.size();
        int ans = 0;
        vector<vector<int>> vvi(sz1, vector<int>(2, 0));        // 0:下降， 1:上升
        for (int i = 0; i < sz1; ++i)
        {
            int bg = 0, sm = 0;
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[j] > nums[i])
                    bg = max(bg, vvi[j][1]);
                else if (nums[j] < nums[i])
                    sm = max(sm, vvi[j][0]);
            }
            vvi[i][0] = bg + 1;
            vvi[i][1] = sm + 1;
            ans = max(ans, max(bg, sm) + 1);

            //int bg = -1, sm = -1;
            //for (int j = i - 1; j >= 0 && (bg == -1 || sm == -1); --j)
            //{
            //    if (bg == -1 && nums[j] > nums[i])
            //        bg = j;
            //    if (sm == -1 && nums[j] < nums[i])
            //        sm = j;
            //}
            //vvi[i][0] = bg == -1 ? 1 : vvi[bg][1] + 1;
            //vvi[i][1] = sm == -1 ? 1 : vvi[sm][0] + 1;
            //ans = max(ans, max(vvi[i][0], vvi[i][1]));
        }
        return ans;
    }

};

int main()
{

    LT lt;

    //myvi v = { 1,7,4,9,2,5 };

    //myvi v = { 1,17,5,10,13,15,10,5,16,8 };

    //myvi v = { 1,2,3,4 };

    myvi v = {33, 53, 12, 64, 50, 41, 45, 21, 97, 35, 47, 92, 39, 0, 93, 55, 40, 46, 69, 42, 6, 95, 51, 68, 72, 9, 32, 84, 34, 64, 6, 2, 26, 98, 3, 43, 30, 60, 3, 68, 82, 9, 97, 19, 27, 98, 99, 4, 30, 96, 37, 9, 78, 43, 64, 4, 65, 30, 84, 90, 87, 64, 18, 50, 60, 1, 40, 32, 48, 50, 76, 100, 57, 29, 63, 53, 46, 57, 93, 98, 42, 80, 82, 9, 41, 55, 69, 84, 82, 79, 30, 79, 18, 97, 67, 23, 52, 38, 74, 15};

    cout << lt.lta(v) << endl;

    return 0;
}
