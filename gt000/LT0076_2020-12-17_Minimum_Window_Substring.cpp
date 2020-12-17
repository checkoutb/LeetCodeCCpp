
#include "../header/myheader.h"

class LT0076
{
public:



// tle.
    string lt0076a(string s, string t)
    {
        int arr[123] = {0};
        for (char ch : t)
        {
            arr[ch]++;
        }
        int ts = 0;
        for (int i = 'A'; i <= 'z'; ++i)
            ts += arr[i] != 0;
        int arr2[123] = {0};
        for (char ch : s)
            arr2[ch]++;
        for (int i = 'A'; i <='z'; ++i)
        {
            if (arr[i] > arr2[i])
                return "";
        }
        string ans = s;
        for (int i = 0; i < s.size() - t.size() + 1; ++i)
        {
            if (arr[s[i]] == 0)
                continue;
            for (int i = 'A'; i <= 'z'; ++i)
            {
                arr2[i] = 0;
            }
            int t2 = 0;
            for (int j = i; j < s.size(); ++j)
            {
                arr2[s[j]]++;
                if (arr2[s[j]] == arr[s[j]])
                    t2++;
                if (t2 == ts)
                {
                    if (ans.size() > (j - i + 1))
                        ans = s.substr(i, (j - i + 1));
                    goto AAA;
                }
            }
            break;
            AAA:
            continue;
        }
        return ans;
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    LT0076 lt;

    cout<<lt.lt0076a(s, t);

    return 0;
}
