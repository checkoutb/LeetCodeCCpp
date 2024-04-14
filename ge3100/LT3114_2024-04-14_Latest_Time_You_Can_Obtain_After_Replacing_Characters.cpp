
#include "../header/myheader.h"

class LT3114
{
public:




// Runtime
// 0ms
// Beats100.00%of users with C++
// Memory
// 7.53MB
// Beats80.00%of users with C++

    // 这周的题目强度是真的高啊。 3.3%
// 3114. Latest Time You Can Obtain After Replacing Characters 31.4% Easy
// 3115. Maximum Prime Difference 55.5% Medium
// 3116. Kth Smallest Amount With Single Denomination Combination 3.3% Hard
// 3117. Minimum Sum of Values by Dividing Array 6.4% Hard
    string findLatestTime(string s)
    {
        if (s[0] == '?')
        {
            s[0] = s[1] == '?' ? '1' : (s[1] <= '1' ? '1' : '0');
        }
        if (s[1] == '?')
        {
            s[1] = s[0] == '1' ? '1' : '9';
        }
        if (s[3] == '?')
            s[3] = '5';
        if (s[4] == '?')
            s[4] = '9';

        return s;
    }

};

int main()
{

    LT3114 lt;


    return 0;
}
