
#include "../header/myheader.h"

class LT2042
{
public:






//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if Numbers Are Ascending in a Sentence.
//Memory Usage: 6.2 MB, less than 90.35% of C++ online submissions for Check if Numbers Are Ascending in a Sentence.
    bool lt2042a(string s)
    {
        int lst = -123123;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int t2 = 0;
                while (s[i] >= '0' && s[i] <= '9')
                {
                    t2 = t2 * 10 + (s[i] - '0');
                    i++;
                }
                if (t2 > lst)
                    lst = t2;
                else
                    return false;
            }
        }
        return true;
    }

};

int main()
{

    LT2042 lt;


    return 0;
}
