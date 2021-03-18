
#include "../header/myheader.h"

class LT1763
{
public:

// D D

//string longestNiceSubstring(string s, int start = 0, int end = -1) {
//    if (end == -1)
//        end = s.size();
//    int cnt[26][2] = {}, j = start - 1;
//    for (auto i = start; i < end; ++i)
//        cnt[tolower(s[i]) - 'a'][(bool)islower(s[i])] = 1;
//    string res;
//    for (auto i = start; i <= end; ++i) {
//        int ch = i == end ? -1 : tolower(s[i]) - 'a';
//        if (ch == -1 || cnt[ch][0] + cnt[ch][1] == 1) {
//            if (j == -1 && ch == -1)
//                return s;
//            auto res1 = longestNiceSubstring(s.substr(j + 1, i - j - 1));
//            if (res1.size() > res.size())
//                res = res1;
//            j = i;
//        }
//    }
//    return res;
//}
//The idea is to find mismatched characters (lower without upper, or vice-versa),
//and split the string (possibly multiple times) on these characters.


//        if (s.length() < 2) return "";
//        char[] arr = s.toCharArray();
//        Set<Character> set = new HashSet<>();
//        for (char c: arr) set.add(c);
//        for (int i = 0; i < arr.length; i++) {
//            char c = arr[i];
//            if (set.contains(Character.toUpperCase(c)) && set.contains(Character.toLowerCase(c))) continue;
//            String sub1 = longestNiceSubstring(s.substring(0, i));
//            String sub2 = longestNiceSubstring(s.substring(i+1));
//            return sub1.length() >= sub2.length() ? sub1 : sub2;
//        }
//        return s;


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Nice Substring.
//Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Longest Nice Substring.
    string lt1763a(string s)
    {
        string ans;
        int arr[26] = {0};          // 0: none,  1: lower,  2: upper,  -1: both
        for (int i = 0; i < s.size(); ++i)
        {
            std::fill(begin(arr), end(arr), 0);
            for (int j = i; j < s.size(); ++j)
            {
                if (s[j] >= 'a')
                {
                    if (arr[s[j] - 'a'] == 0)
                    {
                        arr[s[j] - 'a'] = 1;
                    }
                    else if (arr[s[j] - 'a'] == 2)
                    {
                        arr[s[j] - 'a'] = -1;
                    }
                }
                else
                {
                    if (arr[s[j] - 'A'] == 0)
                    {
                        arr[s[j] - 'A'] = 2;
                    }
                    else if (arr[s[j] - 'A'] == 1)
                    {
                        arr[s[j] - 'A'] = -1;
                    }
                }
                bool nice = true;
                for (int k = 0; k < 26; ++k)
                {
                    if (arr[k] > 0)
                    {
                        nice = false;
                        break;
                    }
                }
                #ifdef __test
//                cout<<"."<<endl;
                #endif // __test
                if (nice && (j - i + 1) > ans.size())
                {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }

};

int main()
{
//    string s = "YazaAay";
    string s = "dDzeE";

    LT1763 lt;

    cout<<lt.lt1763a(s)<<endl;

    return 0;
}
