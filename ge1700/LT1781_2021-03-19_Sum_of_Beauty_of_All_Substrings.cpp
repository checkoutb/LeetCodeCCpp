
#include "../header/myheader.h"

class LT1781
{
public:

// D D






//Runtime: 204 ms, faster than 100.00% of C++ online submissions for Sum of Beauty of All Substrings.
//Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Sum of Beauty of All Substrings.
    int lt1781a(string s)
    {
        int ans = 0;
        int arr[26] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            std::fill(begin(arr), end(arr), 0);
            arr[s[i] - 'a']++;
            for (int j = i + 1; j < s.size(); ++j)
            {
                arr[s[j] - 'a']++;
                int mx = -1;
                int mn = INT_MAX;
                for (int k = 0; k < 26; ++k)
                {
                    if (arr[k] != 0)
                    {
                        mx = max(arr[k], mx);
                        mn = min(arr[k], mn);
                    }
                }
                ans += mx - mn;
            }
        }
        return ans;
    }

};

int main()
{
//    string s = "aabcb";
    string s = "aabcbaa";

    LT1781 lt;

    cout<<lt.lt1781a(s)<<endl;

    return 0;
}
