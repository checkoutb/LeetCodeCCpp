
#include "../header/myheader.h"

class LT2654
{
public:





    //Runtime7 ms
    //    Beats
    //    67.12 %
    //    Memory27.9 MB
    //    Beats
    //    7.94 %
    int minOperations(vector<int>& nums)
    {
        int sz1 = nums.size();
        
        int cnt1 = std::count(begin(nums), end(nums), 1);
        if (cnt1 > 0)
            return sz1 - cnt1;

        vector<int> vi(begin(nums), end(nums));
        for (int i = 1; i < sz1; ++i)
        {
            vector<int> v2(sz1);
#ifdef __test
            showVectorInt(vi);
#endif
            for (int j = i; j < sz1; ++j)
            {
                v2[j] = gcda1(max(vi[j - 1], nums[j]), min(vi[j - 1], nums[j]));

                //cout << vi[j - 1] << " - " << nums[j] << " --- " << v2[j] << endl;

                if (v2[j] == 1)
                    return i + sz1 - 1;
            }
            swap(vi, v2);
        }
        return -1;
    }

    int gcda1(int a, int b)
    {
        return b == 0 ? a : gcda1(b, a % b);
    }

};

int main()
{

    LT2654 lt;

    myvi v = { 6,10,15 };

    cout << lt.minOperations(v) << endl;

    return 0;
}
