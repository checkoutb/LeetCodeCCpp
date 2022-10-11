
#include "../header/myheader.h"

class LT2409
{
public:





//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Count Days Spent Together.
//Memory Usage : 6 MB, less than 29.90 % of C++ online submissions for Count Days Spent Together.
    int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int lt2409a(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        string st = max(arriveAlice, arriveBob);
        string en = min(leaveAlice, leaveBob);

        if (st > en)
            return 0;

        int stm = toInt(st[0]) * 10 + toInt(st[1]);
        int std = toInt(st[3]) * 10 + toInt(st[4]);

        int enm = toInt(en[0]) * 10 + toInt(en[1]);
        int end = toInt(en[3]) * 10 + toInt(en[4]);

        int ans = 0;

        if (stm == enm)
        {
            return end - std + 1;
        }


        for (int i = stm + 1; i < enm; ++i)
        {
            ans += arr[i];
        }
        ans += end;
        ans += (arr[stm] - std + 1);

        return ans;

        //int amst = toInt(arriveAlice[0]) * 10 + toInt(arriveAlice[1]);
        //int adst = toInt(arriveAlice[3]) * 10 + toInt(arriveAlice[4]);

        //int amen = toInt(leaveAlice[0]) * 10 + 

        //int bmst = 

    }

    int toInt(char ch)
    {
        return ch - '0';
    }

};

int main()
{

    LT2409 lt;


    return 0;
}
