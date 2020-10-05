
#include "../header/myheader.h"

class LT0679
{
public:



// gg


// double de chufa..
    bool lt0679b(vector<int>& nums)
    {
        int sum = std::accumulate(begin(nums), end(nums), 0);
        if (sum == 24)
            return true;
        if (sum > 24)
        {
            for (int n : nums)
            {
                if (sum - 2*n == 24)
                    return true;
            }
        }


        return false;
    }



// wrong
// +++,++-, 2 12, 38,46
    bool judgePoint24(vector<int>& nums)
    {
        sort(begin(nums), end(nums), std::less<int>());
        int sum = std::accumulate(begin(nums), end(nums), 0);
        if (sum == 24)
            return true;
        if (sum > 24)
        {
            for (int n : nums)
            {
                if (sum - 2*n == 24)
                    return true;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int t2 = nums[i];
            if (t2 == 4 || t2 == 3 || t2 == 6 || t2 == 2 || t2 == 8)
            {
                if (canMakea2(nums, i, 24 / t2))
                {
                    return true;
                }
            }
        }

        int arr[] = {4,3,2,6,8,12};
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int t3 : arr)
                {
                    if (canMakea3(nums[i], nums[j], t3))
                    {
                        if (canMakea1(nums, i, j, 24 / t3))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

//    bool canMakea2(int a, int b, int c, int t)
    bool canMakea2(vector<int>& nums, int nota, int t)
    {
        int arr[3] = {0};
        int a,b,c;
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == nota)
            {
                continue;
            }
            arr[j] = nums[i];
            j++;
        }
        a = arr[0], b = arr[1], c = arr[2];
        int re = t - a;
        if (canMakea3(b,c,re))
            return true;
        re = t + a;
        if (canMakea3(b,c,re))
            return true;
        if (t % a == 0)
        {
            re = t / a;
            if (canMakea3(b,c,re))
                return true;
        }
        if (a % t == 0)
        {
            re = a / t;
            if (canMakea3(b,c,re))
                return true;
        }
        re = t * a;
        if (canMakea3(b,c,re))
            return true;
        return false;
    }

    bool canMakea3(int a, int b, int t)
    {
        t = abs(t);
        a = max(a, b);
        b = min(a, b);
        if (a - b == t)
            return true;
        if (a + b == t)
            return true;
        if (a * b == t)
            return true;
        if (a % b == 0 && a / b == t)
            return true;
        return false;
    }

//    bool canMakea1(int a, int b, int t)
    bool canMakea1(vector<int>& nums, int nota, int notb, int t)
    {
        int arr[2] = {0};
        int a,b;
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == nota || i == notb)
                continue;
            arr[j] = nums[i];
            j++;
        }
        a = arr[0], b = arr[1];
        return canMakea3(a,b,t);
    }
};

int main()
{

    LT0679 lt;


    return 0;
}
