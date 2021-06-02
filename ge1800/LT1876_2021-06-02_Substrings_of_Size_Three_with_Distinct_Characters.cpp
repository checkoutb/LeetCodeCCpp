
#include "../header/myheader.h"

class LT1876
{
public:


// D D

//    for(int i = 0; i < s.size(); ++i) {
//        repeat += cnt[s[i]]++ == 1;
//        repeat -= i >= 3 && cnt[s[i - 3]]-- == 2;
//        res += i >= 2 && repeat == 0;
//    }




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Substrings of Size Three with Distinct Characters.
//Memory Usage: 6.2 MB, less than 73.54% of C++ online submissions for Substrings of Size Three with Distinct Characters.
    int lt1876a(string s)
    {
        int ans = 0;
        for (int i = 2; i < s.size(); ++i)
        {
            if (s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2])
                ans++;
        }
        return ans;
    }

};

int main()
{

    LT1876 lt;


    return 0;
}
