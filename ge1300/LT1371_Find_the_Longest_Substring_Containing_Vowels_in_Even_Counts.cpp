
#include "../header/myheader.h"

class LT1371
{
public:

// D D

//        unordered_map<int, int> m{{0, -1}};
//        int res = 0, n = s.length(), cur = 0;
//        for (int i = 0; i < n; i++) {
//            cur ^= 1 << string("aeiou").find(s[i]) + 1 >> 1;
//            if (!m.count(cur)) m[cur] = i;
//            res = max(res, i - m[cur]);
//        }
//        return res;
// ...



//Runtime: 120 ms, faster than 80.44% of C++ online submissions for Find the Longest Substring Containing Vowels in Even Counts.
//Memory Usage: 16.4 MB, less than 83.28% of C++ online submissions for Find the Longest Substring Containing Vowels in Even Counts.
//'a', 'e', 'i', 'o', 'u'
    int lt1371a(string s)
    {
        int sz1 = s.size();
        int mpa[123] = {0};
        int ans = 0;
        std::fill(begin(mpa), end(mpa), -1);
        mpa['a'] = 0;
        mpa['e'] = 1;
        mpa['i'] = 2;
        mpa['o'] = 3;
        mpa['u'] = 4;
        int arr[5] = {0};
        #define isVowel(s) (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        for (int i = 0; i < sz1 - ans; ++i)
        {
            for (int m = 0; m < 5; ++m)
                arr[m] = 0;
            for (int j = i; j < sz1; ++j)
            {
                if (mpa[s[j]] != -1)
                {
                    arr[mpa[s[j]]]++;
                }
                if (j - i + 1 > ans)
                {
                    for (int k = 0; k < 5; ++k)
                    {
                        if (arr[k] % 2 == 1)
                        {
                            goto AAA;
                        }
                    }
                    ans = max(ans, j - i + 1);
                }
                AAA:
                continue;
            }
            while (i < sz1 && !isVowel(s))
            {
                ++i;
            }
        }
        return ans;
    }

};

int main()
{

    string s = "eleetminicoworoep";
//    string s = "leetcodeisgreat";
//    string s = "bcbcbc";

    LT1371 lt;

    cout<<lt.lt1371a(s)<<endl;

    return 0;
}
