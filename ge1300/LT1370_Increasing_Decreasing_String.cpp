
#include "../header/myheader.h"

class LT1370
{
public:

// D D

//res += string(--cnt[i] >= 0 ? 1 : 0, 'a' + i);






//Runtime: 4 ms, faster than 97.44% of C++ online submissions for Increasing Decreasing String.
//Memory Usage: 7.7 MB, less than 79.63% of C++ online submissions for Increasing Decreasing String.
    string lt1370a(string s)
    {
        int arr[123] = {0};
        for (char& ch : s)
            arr[ch]++;
        string ans;
        while (ans.size() < s.size())
        {
            for (int i = 'a'; i <= 'z'; ++i)
            {
                if (arr[i] > 0)
                {
                    --arr[i];
                    ans += char (i);
                }
            }
            for (int i = 'z'; i >= 'a'; --i)
            {
                if (arr[i]-- > 0)
                {
                    ans += char (i);
                }
            }
        }
        return ans;
    }

};

int main()
{
    string s = "aaaabbbbcccc";

    LT1370 lt;

    cout<<lt.lt1370a(s)<<endl;

    return 0;
}
