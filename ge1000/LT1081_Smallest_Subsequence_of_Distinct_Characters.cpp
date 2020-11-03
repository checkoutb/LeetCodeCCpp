
#include "../header/myheader.h"

class LT1081
{
public:

// D D

//        string res = "";
//        int last[26] = {}, seen[26] = {}, n = s.size();
//        for (int i = 0; i < n; ++i)
//            last[s[i] - 'a'] = i;
//        for (int i = 0; i < n; ++i) {
//            if (seen[s[i] - 'a']++) continue;
//            while (!res.empty() && res.back() > s[i] && i < last[res.back() - 'a'])
//                seen[res.back() - 'a'] = 0, res.pop_back();
//            res.push_back(s[i]);
//        }
//        return res;
// 。。 last ...
// 先把第一个字符到string， 往后遍历，如果当前字符 小于 back，且 以后还会出现back这个字符，就剔除back。


// 2 tle, 1 wrong....
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Smallest Subsequence of Distinct Characters.
//Memory Usage: 6.7 MB, less than 68.35% of C++ online submissions for Smallest Subsequence of Distinct Characters.
// 看了下我的316，写得真长。。。
    string lt1081a(string s)
    {
        int arr[128] = {0};
        for (char ch : s)
        {
            arr[ch]++;
        }
        int sz1 = 0;
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (arr[i] != 0)
                sz1++;
        }
        string ans;
        int st = 0;
        int arr2[128] = {0};
        while (ans.size() < sz1)
        {
            for (int i = 'a'; i <= 'z'; i++)
            {
                if (arr[i] <= 0)
                    continue;
                for (int j = 'a'; j <= 'z'; j++)
                {
                    arr2[j] = 0;
                }
                for (int j = st; j < s.size(); j++)
                {
                    if (s[j] == i)
                    {
                        while (st <= j)
                        {
                            arr[s[st]]--;
                            st++;
                        }
                        arr[s[j]] = 0;
                        goto AAA;
                    }
                    arr2[s[j]]++;
                    if (arr[s[j]] > 0 && arr2[s[j]] >= arr[s[j]])
                        break;
                }
            }
            continue;

            AAA:
            ans += s[st-1];
            continue;
        }
        return ans;
    }

};

int main()
{

//    string s = "bcabc";
//    string s = "cbacdcbc";
//    string s = "cdadabcc";          // adbc
//    string s = "cbaacabcaaccaacababa";      // abc
    string s = "aabacaaababbcabcbacabcbcbbaabcaaaaabaacc";

    LT1081 lt;

    cout<<lt.lt1081a(s)<<endl;

    return 0;
}
