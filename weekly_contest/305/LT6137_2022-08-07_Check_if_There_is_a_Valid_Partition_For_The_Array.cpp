
#include "../../header/myheader.h"

class LT6137
{
public:





    // AC
    bool ltb(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<bool> vb(sz1, false);

        for (int i = 1; i < sz1; ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                if (i == 1 || vb[i - 2])
                    vb[i] = true;
                else
                {
                    if (i > 1 && nums[i - 2] == nums[i])
                    {
                        vb[i] = i ==2 ? true : vb[i - 3];
                    }
                }

                //vb[i] = i > 1 ? vb[i - 2] : true;
            }
            else
            {
                if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)
                {
                    vb[i] = i > 2 ? vb[i - 3] : true;
                }
            }
        }

        return vb[sz1 - 1];
    }


    // ++ ...
    // 只有2个，且2个相同
    // 只有3个，且3个相同
    // 只有3个，且 +1 +1
    bool validPartition(vector<int>& nums) {

        int sz1 = nums.size();
        for (int i = 0; i < sz1; ++i)
        {
            int cnt = 1;
            while (i + 1 < sz1 && nums[i] == nums[i + 1])
            {
                cnt++;
                i++;
            }

            //if (i + 1 == sz1)
            //{
            //    if (cnt >= 2)
            //    {
            //        return true;
            //    }
            //}
            int cnt2 = 1;
            ++i;
            while (i + 1 < sz1 && nums[i] + 1 == nums[i + 1])
            {
                ++i;
                cnt2++;
            }



        }
        return true;
    }

    //bool dfsa1(vector<int>& vi, int idx, bool lst3eq)
    //{
    //    if (idx == vi.size())
    //        return true;
    //    if (idx + 1 == vi.size())
    //        return lst3eq && (vi);

    //    bool ans = false;
    //    if (vi[idx] == vi[idx + 1])
    //        if (dfsa1(vi, idx + 2, false))
    //            return true;

    //    if (idx + 2 == vi.size())
    //        return false;

    //    if (vi[idx] == vi[idx + 1] && vi[idx] == vi[idx + 2])
    //        if (dfsa1(vi, idx + 3, true))
    //            return true;

    //    if (vi[idx] == vi[idx + 1] - 1)
    //    {
    //        if ((vi[idx] == vi[idx + 2] - 2))
    //        {

    //        }
    //    }
    //}

};

int main()
{

    LT6137 lt;

    myvi v = { 4,4,4,5,6,5,5,5 };

    cout << lt.ltb(v) << endl;

    return 0;
}
