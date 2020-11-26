
#include "../header/myheader.h"

class LT1464
{
public:

// D D

//		if (n > m1)
//            m2 = exchange(m1, n);
//		else
//			m2 = max(m2, n);



//Runtime: 8 ms, faster than 86.58% of C++ online submissions for Maximum Product of Two Elements in an Array.
//Memory Usage: 10.4 MB, less than 21.74% of C++ online submissions for Maximum Product of Two Elements in an Array.
    int lt1464a(vector<int>& nums)
    {
        int mx1 = 0;
        int mx2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > mx1)
            {
                mx2 = mx1;
                mx1 = nums[i];
            }
            else
            {
                if (nums[i] > mx2)
                {
                    mx2 = nums[i];
                }
            }
        }
        int ans = (mx2 - 1) * (mx1 - 1);
        return ans;
    }

};

int main()
{

    LT1464 lt;


    return 0;
}
