
#include "../../header/myheader.h"

class LT
{
public:

// D D

// solution 中有一个优化，把 s 变成 vector<pair<char, index>> .char 是在 t中出现的。 然后再 sliding window




// AC
    string lta(string s, string t)
    {
        int arr[123] = {0};
        int tar[123] = {0};
        for (char& ch : t)
            tar[ch]++;
        int st = 0;
        int a = -1, b = s.size();
        for (int i = 0; i < s.size(); ++i)
        {
            arr[s[i]]++;
            if (arr[s[i]] >= tar[s[i]])
            {
                for (int j = 'A'; j <= 'z'; ++j)
                {
                    if (arr[j] < tar[j])
                    {
                        goto AAA;
                    }
                }
                while (arr[s[st]] > tar[s[st]])
                {
                    arr[s[st]]--;
                    st++;
                }
                if ((i - st) < (b - a))
                {
                    b = i;
                    a = st;
                }
            }
            AAA:
            continue;
        }
        if (a == -1)
            return "";
        return s.substr(a, (b - a + 1));
    }

};

int main()
{
//    string s = "ADOBECODEBANC", t = "ABC";
//    string s = "a", t = "aa";
    string s = "aa", t = "a";

    LT lt;

    cout<<lt.lta(s, t)<<endl;

    return 0;
}
