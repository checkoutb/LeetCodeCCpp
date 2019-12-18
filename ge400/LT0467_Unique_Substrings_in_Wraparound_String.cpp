
#include "../header/myheader.h"

class LT0467
{
public:



// 4ms
//		int len = 0;
//		int size[26] = { 0 };
//		for (int i = p.length() - 1; i >= 0; i--) {
//			if (p[i] + 1 == p[i + 1])
//				len++;
//			else if ('z' == p[i] && 'a' == p[i + 1])
//				len++;
//			else
//				len = 1;
//			int index = p[i] - 'a';
//			if (size[index] < len)
//				size[index] = len;
//		}
//		int count = 0;
//		for (int i = 0; i < 26; i++)
//			count += size[i];
//		return count;
// 。。。 直接保存 最长长度。。。。。。。。。从后向前。。终点一样，但是起点不一样，就应该从后向前么？
// 还有， 每个起点是包含在 字符串中的，所以字符串个数就是 长度。。。而非 1..length 的等差数列。

// .......................................................................

// 。。。[4, 16]ms。。。这。。。

// isContinuous . break 时 应该能把 [i, j] 为起始 的字符串长度算出来。因为[i, j]为起始，终点肯定是 j-1，因为 j和j-1 不连续，就需要遍历dp[p[x] - 'a'][] 来看是否已存在。。
//Runtime: 1232 ms, faster than 5.13% of C++ online submissions for Unique Substrings in Wraparound String.
//Memory Usage: 11.2 MB, less than 14.29% of C++ online submissions for Unique Substrings in Wraparound String.

    int lt0467a3(string p)
    {
        int sz1 = p.size();
        if (sz1 <= 1)
            return sz1;
        int ans = 0;

        int dp[26][sz1 + 1] = {{0}};
        for (int i = 0; i < 26; i++)
            for (int j = 0; j <= sz1; j++)
                dp[i][j] = 0;

        for (int i = 0; i < sz1; i++)
        {
            if (dp[p[i] - 'a'][1] == 0)
            {
                ans++;
            }
            dp[p[i] - 'a'][1] = i + 1;
            for (int j = i + 1; j < sz1; j++)
            {
                if (!isContinuous(p[j-1], p[j]))
                    break;
                if (!dp[p[i] - 'a'][j - i + 1])
                {
                    ans++;
                }
                dp[p[i] - 'a'][j - i + 1] = j + 1;
            }
        }
        return ans;
    }


// 比dp版本更慢。。dp是60多吧，10000长度，dp需要400mb内存，stackoverflow..这个30，tle...
    int lt0467a2(string p)
    {
        int sz1 = p.size();
        if (sz1 <= 1)
            return sz1;
        int ans = 0;
//        int dp[sz1][sz1] = {{0}};                       // ....
        int arr1[26] = {0};
        set<int> exists[26] = {};
        for (int i = 0; i < sz1; i++)
        {
            arr1[p[i] - 'a'] += 1;
            exists[p[i] - 'a'].insert(1);
        }


        for (int i : arr1)
        {
            ans += (i != 0);
        }

        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                if (exists[p[i] - 'a'].find(j-i) != exists[p[i]-'a'].end() && isContinuous(p[j-1], p[j]))
                {
//                    dp[i][j] = 1;
                    if (exists[p[i]-'a'].find(j-i+1) != exists[p[i]-'a'].end())
                    {
                        //
                    }
                    else
                    {
                        exists[p[i]-'a'].insert(j-i+1);
                        ans++;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        return ans;
    }

    // ... abcd..xyzabcd..xyz....  abcd..xyz 是重复的。。。
    int lt0467c(string p)
    {
        int arr1[26] = {0};
        int ans = 0;
        int j = 0;
//        for (int i = 0; i < p.size(); i++)
//        {
//            arr1[p[i] - 'a'] = 1;
//        }
        for (int i = 0; i < p.size(); i = j)
        {
            arr1[p[i] - 'a'] = max(1, arr1[p[i] - 'a']);
            for (j = i + 1; j < p.size() && p[j] == next(p[j-1]); j++)
            {
                arr1[p[i] - 'a'] = max(j - i + 1, arr1[p[i] - 'a']);
            }
        }

        #ifdef __test
        cout<<endl;
        for_each(begin(arr1), end(arr1), fun_cout);
        cout<<endl;
        #endif // __test

        for (int i = 0; i < 26; i++)
        {
            int j = 1;
            int t1 = arr1[i];
            while (j <= 26)
            {
                if (t1 - j >= arr1[(i + j) % 26])
                {
                    arr1[(i + j) % 26] = 0;
                }
                j++;
            }
        }

        #ifdef __test
        cout<<endl;
        for_each(begin(arr1), end(arr1), fun_cout);
        cout<<endl;
        #endif // __test

        for (int i = 0; i < 26; i++)
        {
            int j = arr1[i];
            if (j == 0)
                continue;
            ans += (j * (j + 1) / 2);

            #ifdef __test
            cout<<". . "<<ans<<", "<<j<<endl;
            #endif // __test

            for (int k = 0; k < i; k++)
            {
                int j2 = arr1[k];
                if (j2 == 0)
                    continue;
                j2 -= (i - k);
                j2 = max(j2, arr1[i] - (k + 26 - i));
                if (j2 > 0)
                    ans -= (j2 * (j2 + 1) / 2);

                #ifdef __test
                cout<<j2<<", "<<i<<", "<<k<<", "<<ans<<endl;
                #endif // __test

            }
            #ifdef __test
            cout<<ans<<endl;
            #endif // __test
        }
        return ans;
    }

    // zabcxxxxxabcd . abc 重复的。
    int lt0467b(string p)
    {
        map<char, int> map1;
        int ans = 0;
        int t1 = 0;
        int j = 0;
        for (int i = 0; i < p.size(); i = j)
        {
            for (j = i + 1; j < p.size() && p[j] == next(p[j-1]); j++)
            {
                //
            }
            map1[p[i]] = max((j - i), map1[p[i]]);
        }
        for (auto p : map1)
        {

            cout<<p.first<<", "<<p.second<<endl;

            int i = p.second;
            ans += (i * (i + 1) / 2);
//            set<int> set1 = p.second;
//            for (int i : set1)
//            {
//                #ifdef __test
//                cout<<p.first<<", "<<i<<endl;
//                #endif // __test
//                ans += (i * (i + 1) / 2);
//            }
        }
        return ans;
    }

    char next(char c)
    {
        if (c == 'z')
            return 'a';
        return (char) (c + 1);
    }

    int lt0467a(string p)
    {
        int sz1 = p.size();
        if (sz1 <= 1)
            return sz1;
        int ans = 0;
        int dp[sz1][sz1] = {{0}};                       // ....
        int arr1[26] = {0};
        for (int i = 0; i < sz1; i++)
        {
            arr1[p[i] - 'a'] += 1;
            dp[i][i] = 1;
        }

        set<int> exists[26] = {};

        for (int i : arr1)
        {
            ans += (i != 0);
        }

        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                if (dp[i][j-1] && isContinuous(p[j-1], p[j]))
                {
                    dp[i][j] = 1;
                    if (exists[p[i]-'a'].find(j-i+1) != exists[p[i]-'a'].end())
                    {
                        //
                    }
                    else
                    {
                        exists[p[i]-'a'].insert(j-i+1);
                        ans++;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        return ans;
    }

    bool isContinuous(char a, char b)
    {
        return (b==a+1) || (a=='z' && b=='a');
    }
};

int main()
{
//    string s = "zabababababc";
//    string s = "fghijklmnolmnopfghijkklmnopqr";
//    string s = "zaba";

//    string s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

//    string s = "abaab";

    LT0467 lt;
    cout<<endl<<"------- a2: "<<endl<<lt.lt0467a3(s)<<endl;
    cout<<"------- a: "<<endl<<lt.lt0467a(s)<<endl;

    return 0;
}
