
#include "../header/myheader.h"

class LT2063
{
public:

// D D

//		for (int i = 0; i < n; i++)
//		{
//			int chck = 0;
//			if (word[i] == 'a' or word[i] == 'e' or word[i] == 'i' or word[i] == 'o' or word[i] == 'u')
//				chck = 1;
//			ans += (1ll*(i + 1) * (n - i)  * (chck));
//		}
// 如果 [i] 是元音，那么 必然包含这个 i 的 substr 有 (i+1)*(n-i) 种。


//        long res = 0, n = s.size();
//        for (int i = 0; i < n; ++i)
//            if (string("aeiou").find(s[i]) != string::npos)
//                res += (i + 1) * (n - i);
//        return res;


//    bool v[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
//    long long countVowels(string w) {
//        long long res = 0, sz = w.size();
//        for (int i = 0; i < w.size(); ++i)
//            res += v[w[i] - 'a'] * (i + 1) * (sz - i);
//        return res;
//    }





//Runtime: 18 ms, faster than 98.57% of C++ online submissions for Vowels of All Substrings.
//Memory Usage: 11.1 MB, less than 55.86% of C++ online submissions for Vowels of All Substrings.
// 我记得 几天前/本月 有一个差不多的题目，靠的是 找到 上一个 出现的位置。然后前面的就都包含这个了。
// 不一样，之前的是 是否出现，这里是 出现多少次。 上次出现，上上次出现，上上上次出现 ，，， ？
// 直接prefix sum 会不会更快，元音密集的话 应该prefix sum， 稀疏的话应该是 上x次出现位置。
// 。。。
// 好像很简单，以idx为结尾的所有substr 一共有 idx+1 个，如果[idx] 是元音，那么就 全部加idx+1个。如果不是，那么是 preans个。
    long long lt2063a(string word)
    {
//        unordered_map<char, vector<int>> map2;
        long long ans = 0LL;
        long long preans = 0LL;
        for (int i = 0; i < word.size(); ++i)
        {
            char ch = word[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                preans += (i + 1);
            }
//            else
//            {
                ans += preans;
//            }
        }
        return ans;
    }

};

int main()
{

    LT2063 lt;

//    string s = "aba";
//    string s = "abc";
    string s = "qqqzzz";

    cout<<lt.lt2063a(s)<<endl;

    return 0;
}
