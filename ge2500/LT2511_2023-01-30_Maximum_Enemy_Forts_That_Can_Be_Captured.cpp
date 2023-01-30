
#include "../header/myheader.h"

class LT2511
{
public:


    // D D

    //for (int i = 0, j = 0; i < forts.size(); ++i)
    //    if (forts[i] != 0) {
    //        if (forts[j] == -forts[i])
    //            res = max(res, i - j - 1);
    //        j = i;
    //    }




    //Runtime3 ms
    //    Beats
    //    53.85 %
    //    Memory7.8 MB
    //    Beats
    //    19.51 %

    // -1:empty, 0:enemy, 1:mine
    // 1 -> -1, ¶àÉÙ¸ö0
    int lt2511a(vector<int>& forts)
    {
        int lst0 = -1;
        int lst1 = -1;
        int ans = 0;

        for (int i = 0; i < forts.size(); ++i)
        {
            if (forts[i] == 0)
            {
                continue;
            }
            else if (forts[i] == -1)  // empty
            {
                if (lst1 != -1)
                {
                    ans = max(i - lst1 - 1, ans);
                    lst1 = -1;
                }
                lst0 = i;
            }
            else    // mine
            {
                if (lst0 != -1)
                {
                    ans = max(i - lst0 - 1, ans);
                    lst0 = -1;
                }
                lst1 = i;
            }
        }
        return ans;
    }

};

int main()
{

    LT2511 lt;

    //myvi v = { 1,0,0,-1,0,0,0,0,1 };
    myvi v = { 0,0,1,-1 };


    cout << lt.lt2511a(v) << endl;

    return 0;
}
