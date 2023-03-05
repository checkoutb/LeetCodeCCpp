
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // for (char c : Integer.toString(count).toCharArray())




    //Runtime6 ms
    //    Beats
    //    53.56 %
    //    Memory9 MB
    //    Beats
    //    42.12 %
    int lta(vector<char>& chars)
    {
        int sz1 = chars.size();
        int idx = 0;
        int cnt = 0;
        int i2 = 0;
        //vector<int> vi(4, -1);
        for (int i = 0; i < sz1; i = i2)
        {
            i2 = i + 1;
            while (i2 < sz1 && chars[i2] == chars[i])
            {
                ++i2;
            }

            cnt = i2 - i;

            chars[idx++] = chars[i];
            bool b2 = false;
            if (cnt >= 1000)
            {
                chars[idx++] = char('0' + cnt / 1000);
                cnt %= 1000;
                b2 = true;
            }
            if (cnt >= 100 || b2)
            {
                chars[idx++] = char('0' + cnt / 100);
                cnt %= 100;
                b2 = true;
            }
            if (cnt >= 10 || b2)
            {
                chars[idx++] = char('0' + cnt / 10);
                cnt %= 10;
                b2 = true;
            }
            if (cnt > 1 || b2)
            {
                chars[idx++] = char('0' + cnt);
            }

            //cnt = 0;
            //while (i + 1 < sz1 && chars[i] == chars[i + 1])
            //{
            //    ++i;
            //    ++cnt;
            //}
        }
        return idx;
    }

};

int main()
{

    LT lt;

    vector<char> vc = { 'a','a','b','b','c','c','c' };

    int sz2 = lt.lta(vc);

    cout << sz2 << endl;
    for (char ch : vc)
    {
        cout << ch << ' ';
    }
    cout << endl;
    return 0;
}
