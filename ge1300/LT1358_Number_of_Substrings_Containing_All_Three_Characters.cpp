
#include "../header/myheader.h"

class LT1358
{
public:

// D

//            ++count[s[j] - 'a'];
//            while (count[0] && count[1] && count[2])
//                --count[s[i++] - 'a'];
//            res += i;


// tle.
    int lt1358a(string s)
    {
        int ans = 0;
        int hasA, hasB, hasC;
        for (int i = 0; i < s.size(); i++)
        {
            hasA = hasB = hasC = false;
            for (int j = i; j < s.size(); ++j)
            {
                hasA = hasA || (s[j] == 'a');
                hasB = hasB || (s[j] == 'b');
                hasC = hasC || (s[j] == 'c');
                if (hasA && hasB && hasC)
                {
                    ans += (s.size() - j);
                    break;
                }
            }
        }
        return ans;
    }

};

int main()
{

//    string s = "aaacb";
    string s = "abcabc";

    LT1358 lt;

    cout<<lt.lt1358a(s);

    return 0;
}
