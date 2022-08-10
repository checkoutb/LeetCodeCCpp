
#include "../header/myheader.h"

class LT2366
{
public:

    // D D





//Runtime: 142 ms, faster than 75.00 % of C++ online submissions for Minimum Replacements to Sort the Array.
//Memory Usage : 54.6 MB, less than 75.00 % of C++ online submissions for Minimum Replacements to Sort the Array.
    // �ǽ� [i+1] >= [i]  ֻ���ܱ�С������ �Ӻ���ǰ�ߡ�
    long long lt2366a(vector<int>& nums)
    {
        long long ans = 0LL;
        int sz1 = nums.size();
        int mx = nums[sz1 - 1];
        for (int i = sz1 - 2; i >= 0; --i)
        {
            ans += (nums[i] - 1) / mx;
            //mx = nums[i] % mx;              // .11 �ֳ�5-5-1 �϶������ʣ� 4-4-3 ���á�
            int t2 = (nums[i] - 1) / mx + 1;
            mx = nums[i] / t2;
        }

        return ans;
    }

};

int main()
{

    LT2366 lt;

    //myvi v = { 3,9,3 };
    //myvi v = { 1,2,3,4,5 };
    myvi v = { 4,11,5 };


    cout << lt.lt2366a(v) << endl;

    return 0;
}
