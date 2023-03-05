
#include "../header/myheader.h"

class LT2490
{
public:




    //Runtime6 ms
    //    Beats
    //    33.40 %
    //    Memory6.8 MB
    //    Beats
    //    20.90 %
    bool lt2490a(string s)
    {
        int sz1 = s.size();
        if (s[0] != s[sz1 - 1])
            return false;

        for (int i = 1; i < sz1; ++i)
        {
            if (s[i] == ' ' && s[i - 1] != s[i + 1])
            {
                return false;
            }
        }
        return true;
    }

};

int main()
{

    LT2490 lt;


    return 0;
}
