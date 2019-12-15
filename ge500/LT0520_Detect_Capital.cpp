
#include "../header/myheader.h"

class LT0520
{
public:



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Detect Capital.
//Memory Usage: 8.3 MB, less than 50.00% of C++ online submissions for Detect Capital.

    bool lt0520a(string word)
    {
        if (word.size() < 2)
            return true;
        if ((word[0] >= 'a' && word[1] < 'a'))
            return false;

        bool isLow = !(word[0] < 'a' && word[1] < 'a');
        for (int i = 2; i < word.size(); i++)
        {
            bool isLow2 = word[i] >= 'a';
            if (isLow ^ isLow2)
            {
                return false;
            }
        }
        return true;
    }
};
