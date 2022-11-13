
#include "../header/myheader.h"

class LT2451
{
public:







//Runtime0 ms
//Beats
//100 %
//Memory7.3 MB
//Beats
//94.27 %
    string lt2451a(vector<string>& words)
    {
        int sz1 = words.size();
        int sz2 = words[0].size();

        int df1 = 123;
        int df2 = 123;
        int id1 = -1;
        int id2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int j = 1; j < sz2; ++j)
        {
            id1 = 0;
            df1 = words[0][j] - words[0][j - 1];
            cnt1 = 1;
            cnt2 = 0;
            df2 = 123;
            for (int i = 1; i < sz1; ++i)
            {
                if (words[i][j] - words[i][j - 1] != df1)
                {
                    df2 = words[i][j] - words[i][j - 1];
                    cnt2++;
                    id2 = i;
                }
                else
                {
                    ++cnt1;
                }
            }
            if (df2 != 123)
            {
                if (cnt2 == 1)
                {
                    return words[id2];
                }
                else
                {
                    return words[id1];
                }
            }
        }

        return words[0];
    }

};

int main()
{

    LT2451 lt;


    return 0;
}
