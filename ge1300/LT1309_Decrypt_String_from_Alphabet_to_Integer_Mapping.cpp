
#include "../header/myheader.h"

class LT1309
{
public:

// D D

//  for (int i = 0; i < s.size(); ++i) {
//    if (i < s.size() - 2 && s[i + 2] == '#') {
//      res += 'j' + (s[i] - '1') * 10 + s[i + 1] - '0';
//      i += 2;
//    }
//    else res += 'a' + (s[i] - '1');
//  }


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decrypt String from Alphabet to Integer Mapping.
//Memory Usage: 6.5 MB, less than 37.34% of C++ online submissions for Decrypt String from Alphabet to Integer Mapping.
    string lt1309a(string s)
    {
        string ans;
        for (int i = s.size() - 1; i >= 0;)
        {
            if (s[i] == '#')
            {
                char ch1 = s[i - 2];
                char ch2 = s[i - 1];
                ans += char ('a' + (ch1 - '0') * 10 + (ch2 - '0') - 1);
                i -= 3;
            }
            else
            {
                ans += char ('a' + s[i] - '0' - 1);
                --i;
            }
        }
        std::reverse(begin(ans), end(ans));
        return ans;
    }

};

int main()
{

//    string s = "10#11#12";
//    string s = "1326#";
//    string s = "25#";
    string s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";

    LT1309 lt;

    cout<<lt.lt1309a(s);

    return 0;
}
