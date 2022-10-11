
#include "../header/myheader.h"

class LT2414
{
public:

// D D

//    int j = 0, res = 1;
//    for (int i = 1; i < s.size(); ++i) {
//        if (s[i] != s[j] + i - j)
//            j = i;
//        res = max(res, i - j + 1);
//    }



//Runtime: 48 ms, faster than 81.41% of C++ online submissions for Length of the Longest Alphabetical Continuous Substring.
//Memory Usage: 15.4 MB, less than 46.74% of C++ online submissions for Length of the Longest Alphabetical Continuous Substring.
    int lt2414a(string s)
    {
        int sz1 = s.size();
        int ans = 1;
        int t2 = 1;
        for (int i = 1; i < sz1; ++i)
        {
            if (s[i] == (s[i - 1] + 1))
            {
                ++t2;
            }
            else
            {
                if (ans < t2)
                    ans = t2;
                t2 = 1;
            }
        }
        if (ans < t2)
            ans = t2;
        return ans;
    }

};

int main()
{

    LT2414 lt;


    return 0;
}
