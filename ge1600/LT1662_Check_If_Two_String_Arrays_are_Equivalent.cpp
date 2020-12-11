
#include "../header/myheader.h"

class LT1662
{
public:

// D D





//Runtime: 4 ms, faster than 88.53% of C++ online submissions for Check If Two String Arrays are Equivalent.
//Memory Usage: 11.7 MB, less than 45.27% of C++ online submissions for Check If Two String Arrays are Equivalent.
// in order
    bool lt1662a(vector<string>& word1, vector<string>& word2)
    {
        int i1 = 0, i2 = 0;
        int w1 = 0, w2 = 0;
        while(true)
        {
            if (w1 == word1[i1].size())
            {
                i1++;
                w1 = 0;
            }
            if (w2 == word2[i2].size())
            {
                i2++;
                w2 = 0;
            }
            if (i1 == word1.size())
                return i2 == word2.size();
            if (i2 == word2.size())
                return i1 == word1.size();
            if (word1[i1][w1] != word2[i2][w2])
                return false;
            w1++;
            w2++;
        }
        return false;
    }

};

int main()
{
    vector<string> vs1 = {"ab", "c"};
    vector<string> vs2 = {"a", "bc"};

    LT1662 lt;

    cout<<lt.lt1662a(vs1, vs2);

    return 0;
}
