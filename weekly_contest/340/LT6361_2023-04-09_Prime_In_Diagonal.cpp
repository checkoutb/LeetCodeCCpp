
#include "../../header/myheader.h"

class LT6361
{
public:



    // AC ... >1 没加，错了一次。。
    int diagonalPrime(vector<vector<int>>& nums) {

        int sz1 = nums.size();
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i][i] > 1 && nums[i][i] > ans && isPrime(nums[i][i]))
                ans = nums[i][i];

            if (nums[i][sz1 - 1 - i] > 1 && nums[i][sz1 - 1 - i] > ans && isPrime(nums[i][sz1 - 1 - i]))
                ans = nums[i][sz1 - 1 - i];
        }
        return ans;
    }

    bool isPrime(int a)
    {
        for (int i = 2; i * i <= a; ++i)
        {
            if (a % i == 0)
                return false;
        }
        return true;
    }

};

int main()
{

    LT6361 lt;


    return 0;
}
