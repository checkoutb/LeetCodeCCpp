
#include "../header/myheader.h"

class LT1974
{
public:

// D D





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Time to Type Word Using Special Typewriter.
//Memory Usage: 6.2 MB, less than 25.00% of C++ online submissions for Minimum Time to Type Word Using Special Typewriter.
// 每次移动一位。
    int lt1974a(string word)
    {
        int ans = 0;
        char p = 'a';
        for (char ch : word)
        {
//            if (p != ch)
//            {
                ans += min((p - ch + 26) % 26, (ch - p + 26) % 26);
//            }
            ans++;          // type
            p = ch;
        }
        return ans;
    }

};

int main()
{
    string s = "zjpc";

    LT1974 lt;

    cout<<lt.lt1974a(s);

    return 0;
}
