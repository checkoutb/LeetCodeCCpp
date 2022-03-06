
#include "../header/myheader.h"

class LT2125
{
public:

// D D





//Runtime: 141 ms, faster than 62.32% of C++ online submissions for Number of Laser Beams in a Bank.
//Memory Usage: 23 MB, less than 76.85% of C++ online submissions for Number of Laser Beams in a Bank.
    int lt2125a(vector<string>& bank)
    {
        int ans = 0;
        int t2 = 0;
        for (string& s : bank)
        {
            int t3 = count(begin(s), end(s), '1');
            if (t3 != 0)
            {
                ans += t2 * t3;
                t2 = t3;
            }
        }
        return ans;

//        int t2 = count(begin(bank[0]), end(bank[0]), '1');
//        for (int i = 0; i <)
    }

};

int main()
{

    LT2125 lt;


    return 0;
}
