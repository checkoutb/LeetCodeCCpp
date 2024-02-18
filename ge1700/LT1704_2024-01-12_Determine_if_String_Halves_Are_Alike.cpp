
#include "../header/myheader.h"

class LT1704
{
public:

    // D D

    // set<char>


    // for (int i = 0, j = mid; i < mid; i++, j++) {
    // if (~vowels.find(S[i])) ans++;



// Runtime
// 3ms
// Beats52.79%of users with C++
// Memory
// 6.88MB
// Beats96.85%of users with C++

    bool halvesAreAlike(string s)
    {
        int cnt = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (isVowel(s[i]))
            {
                if (i < s.size() / 2)
                    ++cnt;
                else
                    --cnt;
            }
        }
        return cnt == 0;
    }

    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return string("aeiou").find(ch) != std::string::npos;
    }

};

int main()
{

    LT1704 lt;


    return 0;
}
