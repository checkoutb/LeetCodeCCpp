
#include "../../header/myheader.h"

class LT6341
{
public:



    // AC
    int isWinner(vector<int>& player1, vector<int>& player2)
    {
        int sz1 = player1.size();
        int a = 0;
        int b = 0;
        int lst10a = -10;
        int lst10b = -10;

        for (int i = 0; i < sz1; ++i)
        {
            a += player1[i] * (1 + (i - lst10a <= 2));
            b += player2[i] * (1 + (i - lst10b <= 2));

            if (player1[i] == 10)
                lst10a = i;
            if (player2[i] == 10)
                lst10b = i;
        }
        if (a == b)
            return 0;
        return a > b ? 1 : 2;
    }

};

int main()
{

    LT6341 lt;


    return 0;
}
