
#include "../header/myheader.h"

class LT1456
{
public:

// D D

//    v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = 1;



//Runtime: 28 ms, faster than 70.50% of C++ online submissions for Maximum Number of Vowels in a Substring of Given Length.
//Memory Usage: 10.3 MB, less than 58.47% of C++ online submissions for Maximum Number of Vowels in a Substring of Given Length.
//a, e, i, o, u
    int lt1456a(string s, int k)
    {
        #define isVowel(ch) (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        int cnt = 0;
        for (int i = 0; i < k; ++i)
        {
            if (isVowel(s[i]))
                cnt++;
        }
        int ans = cnt;
        for (int i = k; i < s.size(); ++i)
        {
            if (isVowel(s[i]))
                cnt++;
            if (isVowel(s[i - k]))
                cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }

};

int main()
{
    string s = "abciiidef";
    int k{3};

    LT1456 lt;

    cout<<lt.lt1456a(s, k);

    return 0;
}
