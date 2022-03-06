
#include "../header/myheader.h"

class LT2139
{
public:

// D D


//    while (target > 1 && maxDoubles--) {
//        res += 1 + target % 2;
//        target /= 2;
//    }
//    return res + target - 1;


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Moves to Reach Target Score.
//Memory Usage: 5.9 MB, less than 75.30% of C++ online submissions for Minimum Moves to Reach Target Score.
// 肯定最后double啊。
    int lt2139a(int target, int maxDoubles)
    {
        int ans = 0;
        while (target > 1)
        {
            if (target % 2)
            {
                ans++;
                target--;
            }
            else
            {
                if (maxDoubles > 0)
                {
                    ans++;
                    target /= 2;
                    maxDoubles--;
                }
                else
                {
                    ans += (target - 1);
                    target = 1;
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT2139 lt;


    return 0;
}
