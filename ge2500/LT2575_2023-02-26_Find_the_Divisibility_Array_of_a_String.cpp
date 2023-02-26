
#include "../header/myheader.h"

class LT2575
{
public:

    // D D




    //Runtime57 ms
    //    Beats
    //    42.86 %
    //    Memory21.7 MB
    //    Beats
    //    85.71 %
    vector<int> lt2575a(string word, int m)
    {
        int sz1 = word.size();
        vector<int> vi(sz1);

        long long t2 = 0LL;

        for (int i = 0; i < sz1; ++i)
        {
            t2 = t2 * 10 + (word[i] - '0');
            t2 %= m;
            if (t2 == 0)
                vi[i] = 1;
        }

        return vi;
    }

};

int main()
{

    LT2575 lt;

    //string w = "998244353";
    //int m = 3;

    string w = "1010";
    int m = 10;

    myvi vi = lt.lt2575a(w, m);

    showVectorInt(vi);

    return 0;
}
