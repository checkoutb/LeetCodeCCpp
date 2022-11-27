
#include "../header/myheader.h"

class LT2486
{
public:






    //Runtime72 ms
    //    Beats
    //    40 %
    //    Memory10.7 MB
    //    Beats
    //    80 %
    int lt2486a(string s, string t)
    {
        int sz1 = s.size(), sz2 = t.size();
        int idxt = 0;       // to be check

        for (int i = 0; i < sz1 && idxt < sz2; ++i)
        {
            if (s[i] == t[idxt])
            {
                ++idxt;
            }
        }
        return sz2 - idxt;
    }

};

int main()
{

    LT2486 lt;


    return 0;
}
