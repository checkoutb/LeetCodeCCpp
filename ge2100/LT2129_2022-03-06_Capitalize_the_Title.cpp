
#include "../header/myheader.h"

class LT2129
{
public:


// D D

//    for (int i = 0, j = 0; i <= s.size(); ++i) {
//        if (i == s.size() || s[i] == ' ') {
//            if (i - j > 2)
//                s[j] = toupper(s[j]);
//            j = i + 1;
//        }
//        else
//            s[i] = tolower(s[i]);
//    }




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Capitalize the Title.
//Memory Usage: 6.2 MB, less than 78.65% of C++ online submissions for Capitalize the Title.
    string lt2129a(string title)
    {
        int len = 0;
        for(int i = 0; i <= title.size(); ++i)
        {
            if (i == title.size() || title[i] == ' ')
            {
                if (len > 2)
                {
                    title[i - len] = std::toupper(title[i - len]);
                }
                else
                {
                    title[i - len] = std::tolower(title[i - len]);
                }
                for (int j = i - len + 1; j < i; ++j)
                {
                    title[j] = tolower(title[j]);
                }
                len = 0;
            }
            else
            {
                len++;
            }
        }
        return title;
    }

};

int main()
{

    LT2129 lt;


    return 0;
}
