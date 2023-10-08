
#include "../../header/myheader.h"

class LT
{
public:

// D D


        // while(counter<=s.length())
        // {
        //     if(s[counter]==cmp)
        //     {
        //         reverse(s, begin, counter - 1);
        //         begin=counter+1;
        //     }

        //     else if(s[counter]=='\0')
        //     {
        //         reverse(s,begin,counter-1);
        //     }

        //     counter++;
        // }




// Runtime14 ms
// Beats
// 65.92%
// Memory10.2 MB
// Beats
// 52.15%
    string reverseWords(string s)
    {
        int sz1 = s.size();
        int st = 0;
        int en = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == ' ')
            {
                en = i - 1;
                while (st < en)
                {
                    swap(s[st], s[en]);
                    ++st;
                    --en;
                }
                st = i + 1;
            }
        }
        en = sz1 - 1;
        while (st < en)
        {
            swap(s[st], s[en]);
            ++st;
            --en;
        }

        return s;
    }
};

int main()
{

    LT lt;


    return 0;
}
