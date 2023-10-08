
#include "../../header/myheader.h"

class LT
{
public:




//38 ms
//Beats
//24.97%
//Memory13.6 MB
//Beats
//23.75%
    bool winnerOfGame(string colors)
    {
        int sz1 = colors.size();
        int cnta = 0;
        int cntb = 0;

        for (int i = 1; i < sz1 - 1; ++i)
        {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1])
            {
                if (colors[i] == 'A')
                    ++cnta;
                else
                    ++cntb;
            }
        }
        return cnta > cntb;
    }

};

int main()
{

    LT lt;


    return 0;
}
