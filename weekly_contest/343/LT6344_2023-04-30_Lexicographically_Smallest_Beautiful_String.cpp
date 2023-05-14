
#include "../../header/myheader.h"

class LT6344
{
public:



    // AC
    // >=2 no palind   k   lexi-min
    // > s    s is beautiful
    string lta(string s, int k)
    {
        char mxch = char('a' + k - 1);
        int sz1 = s.size();
        
        for (int i = sz1 - 1; i >= 0; --i)
        {
            for (char ch = char(s[i] + 1); ch <= mxch; ++ch)
            {
                if ((i == 0 || s[i - 1] != ch) && (i <= 1 || s[i - 2] != ch))
                {
                    s[i] = ch;
                    int j = i + 1;
                    for (; j < sz1; ++j)
                    {
                        for (k = 'a'; k <= mxch; ++k)
                        {
                            if ((j == 0 || k != s[j - 1]) && (j <= 1 || k != s[j - 2]))
                            {
                                s[j] = k;
                                break;
                            }
                        }
                    }
                    if (j == sz1)
                        return s;
                }
            }
        }

        return "";
    }

    

};

int main()
{

    LT6344 lt;

    //string s = "abcz";
    //int k = 26;

    string s = "dc";
    int k = 4;

    cout << lt.lta(s, k) << endl;

    return 0;
}
