
#include "../header/myheader.h"

class LT1262
{
public:

    // D D


    //vector<int> dp(3);
    //for (int a : A)
    //    for (int i : vector<int>(dp))
    //        dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);
    //return dp[0];
    //
    // .....


    //int res = 0, leftOne = 20000, leftTwo = 20000;
    //for (int n : nums) {
    //    res += n;
    //    if (n % 3 == 1) {
    //        leftTwo = Math.min(leftTwo, leftOne + n);
    //        leftOne = Math.min(leftOne, n);
    //    }
    //    if (n % 3 == 2) {
    //        leftOne = Math.min(leftOne, leftTwo + n);
    //        leftTwo = Math.min(leftTwo, n);
    //    }
    //}
    //if (res % 3 == 0) return res;
    //if (res % 3 == 1) return res - leftOne;
    //return res - leftTwo;




//Runtime: 55 ms, faster than 86.85 % of C++ online submissions for Greatest Sum Divisible by Three.
//Memory Usage : 25 MB, less than 80.72 % of C++ online submissions for Greatest Sum Divisible by Three.
    int lt1262c(vector<int>& nums)
    {
        //int sum2 = accumulate(begin(nums), end(nums), 0);
        //if (sum2 % 3 == 0)
        //    return sum2;

        //sort(begin(nums), end(nums));


        int sum2 = 0;
        int mod2 = INT_MAX;
        int mod1 = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum2 += nums[i];
            if (nums[i] % 3 == 2 && nums[i] < mod2)
                mod2 = nums[i];
            if (nums[i] % 3 == 1 && nums[i] < mod1)
                mod1 = nums[i];
        }
        if (sum2 % 3 == 0)
            return sum2;

        //sort(begin(nums), end(nums));

        int mn11 = INT_MAX;
        int mn12 = INT_MAX;
        int mn21 = INT_MAX;
        int mn22 = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
        {
            int t2 = nums[i];
            if (t2 % 3 == 1)
            {
                if (t2 < mn11)
                {
                    mn12 = mn11;
                    mn11 = t2;
                }
                else if (t2 < mn12)
                {
                    mn12 = t2;
                }
            }
            else if (t2 % 3 == 2)
            {
                if (t2 < mn21)
                {
                    mn22 = mn21;
                    mn21 = t2;
                }
                else if (t2 < mn22)
                {
                    mn22 = t2;
                }
            }
        }

        if (sum2 % 3 == 1)
        {
            int t2 = mn22 == INT_MAX ? mod1 : min(mod1, mn21 + mn22);
            if (t2 == INT_MAX)
                return 0;
            return sum2 - t2;
        }
        else
        {
            int t2 = mn12 == INT_MAX ? mod2 : min(mod2, mn11 + mn12);
            if (t2 == INT_MAX)
                return 0;
            return sum2 - t2;
        }


        // 1+1 = 2
        // 2+2 = 1


        //unordered_set<int> set1;
        //unordered_set<int> set2;

        //for (int i = 0; i < nums.size(); ++i)
        //{
        //    int t2 = nums[i];
        //    if (t2 % 3 == 0)
        //        continue;
        //    if (t2 >= mod1 && t2 >= mod2)
        //        break;

        //    if (t2 < mod1)
        //    {
        //        unordered_set<int> s1;

        //        for (int n : set1)
        //        {

        //        }

        //        swap(set1, s1);
        //    }
        //    
        //}

        //vector<int> v1(mod1);
        //vector<int> v2(mod2);

        //for (int i = 0; i < nums.size(); ++i)
        //{
        //    int t2 = nums[i];
        //    if (t2 >= mod1 && t2 >= mod2)
        //        break;
        //    if (t2 < mod1)
        //    {
        //        for (int j = 0; j < mod1; ++j)
        //        {
        //            if (v1[j] != 1)
        //        }
        //    }
        //    if (t2 < mod2)
        //    {

        //    }
        //}

    }


    // error
    int lt1262b(vector<int>& nums)
    {
        int sum2 = 0;
        int mod2 = INT_MAX;
        int mod1 = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum2 += nums[i];
            if (nums[i] % 3 == 2 && nums[i] < mod2)
                mod2 = nums[i];
            if (nums[i] % 3 == 1 && nums[i] < mod1)
                mod1 = nums[i];
        }

        switch (sum2 % 3)
        {
        case 0:
            return sum2;
        case 1:
            if (mod1 != INT_MAX)
                return sum2 - mod1;
            break;
        case 2:
            if (mod2 != INT_MAX)
                return sum2 - mod2;
            break;
        }

        if (sum2 % 3 == 1)
            return 0;

        int mn1 = INT_MAX;
        int mn2 = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 3 == 1)
            {
                if (nums[i] < mn1)
                {
                    mn2 = mn1;
                    mn1 = nums[i];
                }
                else if (nums[i] < mn2)
                {
                    mn2 = nums[i];
                }
            }
        }

        if (mn2 == INT_MAX)
            return 0;

        return sum2 - mn1 - mn2;
    }


    int lt1262a(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        int sum2 = std::accumulate(begin(nums), end(nums), 0);

        if (sum2 % 3)
        {
            int t2 = 3 - sum2 % 3;
            //for (int i = 0; i <)
        }

        return sum2;
    }

};

int main()
{

    LT1262 lt;

    //myvi v = { 3,5,6,1,8 };
    //myvi v = { 4 };
    myvi v = { 1,2,3,4,4 };

    //myvi v = { 2,6,2,2,7 };

    cout << lt.lt1262c(v) << endl;

    return 0;
}
