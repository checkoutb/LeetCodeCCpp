
#include "../../header/myheader.h"

class LT
{
public:



    // a start

// Runtime3 ms
// Beats
// 71.1%
// Memory11.6 MB
// Beats
// 95.20%
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        int r1 = 0, r2 = 0, c1 = 0, c2 = 0;
        int sz1 = word1.size(), sz2 = word2.size();

        while (r1 != sz1 && r2 != sz2)
        {
            if (word1[r1][c1] != word2[r2][c2])
                return false;
            ++c1, ++c2;
            if (c1== word1[r1].size())
            {
                c1 = 0, ++r1;
            }
            if (c2 == word2[r2].size())
                c2 = 0, ++r2;
        }
        return r1 == sz1 && r2 == sz2;
    }

};

int main()
{

    LT lt;


    return 0;
}
