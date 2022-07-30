
#include "../../header/myheader.h"

class LT
{
public:

    // D D




//Runtime: 8 ms, faster than 82.77 % of C++ online submissions for Valid Anagram.
//Memory Usage : 7.2 MB, less than 94.64 % of C++ online submissions for Valid Anagram.
    bool lta(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        int arr[123] = { 0 };
        for (int i = 0; i < s.size(); ++i)
        {
            arr[s[i]]++;
            arr[t[i]]--;
        }
        for (int i = 'a'; i <= 'z'; ++i)
            if (arr[i] != 0)
                return false;
        return true;
    }

};

int main()
{

    LT lt;


    return 0;
}
