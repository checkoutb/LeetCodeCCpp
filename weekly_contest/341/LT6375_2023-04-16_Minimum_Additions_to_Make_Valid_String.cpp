
#include "../../header/myheader.h"

class LT6375
{
public:



    // AC
    // ... aaaac
    int lta(string word)
    {
        int ans = 0;
        int sz1 = word.size();

        for (int i = 0; i < sz1; ++i)
        {
            if (word[i] == 'a')
            {
                if (i + 1 < sz1 && word[i + 1] == 'b')
                {
                    if (i + 2 < sz1 && word[i + 2] == 'c')
                    {
                        i += 2;
                    }
                    else
                    {
                        i += 1;
                        ans += 1;
                    }
                }
                else
                {
                    if (i + 1 < sz1 && word[i + 1] == 'c')          // ...
                    {
                        ans++;
                        i++;
                    }
                    else
                    {
                        ans += 2;
                    }
                }
            }
            else if (word[i] == 'b')
            {
                if (i + 1 < sz1 && word[i + 1] == 'c')
                {
                    ++i;
                    ++ans;
                }
                else
                {
                    ans += 2;
                }
            }
            else
            {
                ans += 2;
            }
        }
        return ans;
    }

};

int main()
{

    LT6375 lt;


    return 0;
}
