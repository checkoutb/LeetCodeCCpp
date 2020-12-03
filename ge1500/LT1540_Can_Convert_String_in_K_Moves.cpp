
#include "../header/myheader.h"

class LT1540
{
public:

// D D




//Runtime: 68 ms, faster than 56.80% of C++ online submissions for Can Convert String in K Moves.
//Memory Usage: 18.1 MB, less than 70.67% of C++ online submissions for Can Convert String in K Moves.
    bool lt1540a(string s, string t, int k)
    {
        if (s.size() != t.size())
            return false;
        int arr[26] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            int diff = (t[i] - s[i] + 26) % 26;
            if (diff != 0)
            {
                arr[diff]++;
                if ((arr[diff] - 1) * 26 + diff > k)
                    return false;
            }
        }
        return true;
    }

};

int main()
{
//    string s{"input"}, t{"ouput"};
//    int k{9};

//    string s{"abc"}, t{"bcd"};
//    int k{10};

    string s{"aab"}, t{"bbb"};
    int k{27};

    LT1540 lt;

    cout<<lt.lt1540a(s, t, k);

    return 0;
}
