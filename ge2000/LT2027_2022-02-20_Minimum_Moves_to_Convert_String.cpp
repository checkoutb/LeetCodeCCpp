
#include "../header/myheader.h"

class LT2027
{
public:





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Moves to Convert String.
//Memory Usage: 6.5 MB, less than 39.15% of C++ online submissions for Minimum Moves to Convert String.
// X/0 -> 0  连续3个， 贪心啊。
    int lt2027a(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'X')
            {
                ans++;
                i += 2;
            }
        }
        return ans;
    }

};

int main()
{

    LT2027 lt;


    return 0;
}
