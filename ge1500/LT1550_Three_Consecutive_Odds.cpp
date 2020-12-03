
#include "../header/myheader.h"

class LT1550
{
public:

// D D

//    for (auto i = 0; i < arr.size() && odds < 3; ++i)
//        odds = arr[i] % 2 ? odds + 1 : 0;
//    return odds == 3;


//Runtime: 4 ms, faster than 95.40% of C++ online submissions for Three Consecutive Odds.
//Memory Usage: 8.5 MB, less than 90.43% of C++ online submissions for Three Consecutive Odds.
    bool lt1550a(vector<int>& arr)
    {
        for (int i = 0, mxi = arr.size() - 2; i < mxi; ++i)
        {
            if (arr[i] % 2)
            {
                ++i;
                if (arr[i] % 2)
                {
                    ++i;
                    if (arr[i] % 2)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

};

int main()
{

    LT1550 lt;


    return 0;
}
