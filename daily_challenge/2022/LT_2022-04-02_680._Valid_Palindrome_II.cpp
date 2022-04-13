
#include "../../header/myheader.h"

class LT
{
public:

// D D

//            if (s[i] != s[j]) {
//                int i1 = i, j1 = j - 1;
//                int i2 = i + 1, j2 = j;
//                while (i1 < j1 && s[i1] == s[j1]) {
//                    i1++;
//                    j1--;
//                }
//                while (i2 < j2 && s[i2] == s[j2]) {
//                    i2++;
//                    j2--;
//                }
//                return (i1 >= j1) || (i2 >= j2);
//            }



//Runtime: 47 ms, faster than 98.59% of C++ online submissions for Valid Palindrome II.
//Memory Usage: 19.6 MB, less than 87.28% of C++ online submissions for Valid Palindrome II.
// 最多删除一个。
    bool lta(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                int st = l + 1, en = r;
                while (st <= en)            // == : abca
                {
                    if (s[st] != s[en])
                    {
                        break;
                    }
                    st++, en--;
                    if (st >= en)
                        return true;
                }
                st = l, en = r - 1;
                while (st < en)
                {
                    if (s[st] != s[en])
                    {
                        break;
                    }
                    st++, en--;
                    if (st >= en)
                        return true;
                }
                return false;
            }
            else
            {
                l++, r--;
            }
        }
        return true;
    }

};

int main()
{

    LT lt;


    return 0;
}
