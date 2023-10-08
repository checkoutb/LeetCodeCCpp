
#include "../header/myheader.h"

class LT2748
{
public:






// Runtime11 ms
// Beats
// 99.76%
// Memory68 MB
// Beats
// 8.83%
    int countBeautifulPairs(vector<int>& nums)
    {
        int arr2[10] = {0};
        int ans = 0;
        for (int i : nums)
        {
            ++arr2[i % 10];
        }
        bool arr[10][10] = {{false}};
        for (int i = 1; i < 10; ++i)
        {
            for (int j = i + 1; j < 10; ++j)
            {
                if (gcda1(j, i) == 1)
                {
                    arr[i][j] = true;
                    arr[j][i] = true;
                }
            }
        }
        arr[1][1] = true;           // .
        for (int i = 0; i < nums.size(); ++i)
        {
            int t2 = nums[i];
            --arr2[t2 % 10];
            while (t2 >= 10)
                t2 /= 10;
            for (int j = 1; j < 10; ++j)
            {
                if (arr[t2][j])
                {
                    ans += arr2[j];
                }
            }
        }
        return ans;
    }

    int gcda1(int a, int b)
    {
        return b == 0 ? a : gcda1(b, a % b);
    }

};

int main()
{

    LT2748 lt;


    return 0;
}
