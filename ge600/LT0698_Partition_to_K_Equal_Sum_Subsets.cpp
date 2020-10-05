
#include "../header/myheader.h"

class LT0698
{
public:



// error
    bool lt0698a(vector<int>& nums, int k)
    {
        int sum2 = std::accumulate(begin(nums), end(nums), 0);
        if (sum2 % k != 0)
            return false;
        int tar = sum2 / k;
        std::sort(begin(nums), end(nums));
        if (nums[nums.size() - 1] > tar)
            return false;

        for (int i = 0; i < nums.size() && nums[i] <= tar; i++)
        {
            if (nums[i] == tar)
            {
                sum2 -= tar;
                nums[i] = 0;
            }
        }
//        unordered_map<int, int> map2;
//        for (int n : nums)
//        {
//            if (n != 0)
//                map2[n]++;
//        }
        while (sum2 > 0)
        {
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (nums[i] == 0)
                    continue;
                if (dfsa1(nums, i - 1, tar - nums[i]) != 0)
                {
                    #ifdef __test
                    cout<<nums[i]<<" : ";
                    for_each(begin(nums), end(nums), fun_cout);
                    cout<<endl;
                    #endif // __test
                    return false;
                }
                else
                {
                    sum2 -= tar;
                    nums[i] = 0;
                }
            }
        }
        return true;
    }

    int dfsa1(vector<int>& nums, int i, int tar)
    {
        if (tar == 0)
            return 0;
        if (i < 0)
            return -1;
//        if (nums[i] == tar)
//            return 0;
//        if (nums[i] > tar)
//            return -1;
        if (tar < 0)
            return -1;
        for (int j = 0; j <= i; j++)
        {
            if (nums[j] == 0)
                continue;
            int a = dfsa1(nums, j - 1, tar - nums[j]);
            if (a == 0)
            {
                nums[j] = 0;
                return 0;
            }
        }
        return -1;
    }

};

int main()
{

//    vector<int> v = {4, 3, 2, 3, 5, 2, 1};
//    int k = 4;

//    vector<int> v = {10,10,10,7,7,7,7,7,7,6,6,6};
//    int k = 3;

    vector<int> v = {2,11,1,10,4,10,1,4,2};
    int k = 3;

    LT0698 lt;

    cout<<lt.lt0698a(v, k);

    return 0;
}
