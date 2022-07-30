
#include "../header/myheader.h"

class LT2167
{
public:



    // [i][j]  substr[i-j] use 3,
    int lt2167a(string s)
    {
        int sz1 = s.size();
        vector<int> vi1(sz1, 0);        // last left idx
        vector<int> vi2(sz1, 0);        // next right idx
        vector<int> vi3(sz1, 0);        // prefix count
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == '1')
            {
                vi1[i] = i;
                vi3[i] = (i == 0 ? 0 : vi3[i - 1]) + 1;
            }
            else
            {
                vi1[i] = (i == 0 ? 0 : vi1[i - 1]);
                vi3[i] = (i == 0 ? 0 : vi3[i - 1]);
            }
        }
        for (int i = sz1 - 1; i >= 0; --i)
        {
            if (s[i] == '1')
            {
                vi2[i] = i;
            }
            else
            {
                vi2[i] = (i == sz1 - 1 ? 0 : vi2[i + 1]);
            }
        }



    }

};

int main()
{

    LT2167 lt;


    return 0;
}
