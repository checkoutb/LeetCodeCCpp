
#include "../header/myheader.h"

class LT1930
{
public:

// D D


//        res = 0
//        for c in string.ascii_lowercase:
//            i, j = s.find(c), s.rfind(c)
//            if i > -1:
//                res += len(set(s[i + 1: j]))
//        return res


//    int first[26] = {[0 ... 25] = INT_MAX}, last[26] = {}, res = 0;
//    for (int i = 0; i < s.size(); ++i) {
//        first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
//        last[s[i] - 'a'] = i;
//    }
//    for (int i = 0; i < 26; ++i)
//        if (first[i] < last[i])
//            res += unordered_set<char>(begin(s) + first[i] + 1, begin(s) + last[i]).size();
//    return res;


//        for (int i=1; i<n; i++) {
//            leftCnt[i] = leftCnt[i-1] | (1<<(s[i-1]-'a')); //turn on the bit
//        }
//        for (int i=n-2; i>=0; i--) {
//            rightCnt[i] = rightCnt[i+1] | (1<<(s[i+1]-'a')); //turn on the bit
//        }
//        for (int i=1; i<n-1; i++) {
//            cnts[s[i]-'a'] |= (leftCnt[i] & rightCnt[i]);
//        }
//        int ret = 0;
//        for (int c : cnts)
//            ret += __builtin_popcount(c);
//        return ret;






//Runtime: 352 ms, faster than 65.31% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
//Memory Usage: 13 MB, less than 77.76% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
    int lt1930d(string s)
    {
        int lst[26] = {0};
        bool got[26] = {false};
//        std::fill()
        unordered_map<char, int> mapArr[26] = {};
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (lst[s[i] - 'a'] == 0)
                lst[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            int t2 = ch - 'a';
            for (int j = 0; j < 26; ++j)
            {
                if (got[j])
                {
                    if (lst[j] > i)           // .....不需要map了，，只需要set。。。
                    {
                        mapArr[j][ch]++;
                    }
                }
            }
            if (got[t2] == false)
                got[t2] = true;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            ans += mapArr[i].size();
        }
        return ans;
    }


    int lt1930c(string s)
    {
        bool got[26] = {false};
        unordered_map<char, int> maparr[26] = {};
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            for (int j = 0; j < 26; ++j)
            {
                if (got[j])
                {
                    maparr[j][ch]++;            // abaqwertyui,  第二个a后面的 也会被记录。。。。
                }
            }
            if (got[ch - 'a'] == false)
                got[ch - 'a'] = true;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            int t2 = maparr[i][(char) (i + 'a')];
            if (t2 == 0)
                continue;
            #ifdef __test
            cout<<i<<", "<<t2<<", "<<maparr[i].size()<<endl;
            #endif // __test
            ans += maparr[i].size();
            if (t2 == 1)
                ans--;
        }
        return ans;
    }



// 数量也不多， 26×26 个 回文。
// 第一个a 和 最后一个 a 之间有多少个 unique的 char。 就有多少种。
    int lt1930b(string s)
    {
        bool got[26] = {false};
        unordered_set<char> setarr[26] = {};
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            for (int j = 0; j < 26; ++j)
            {
                if (got[j])
                {
                    setarr[j].insert(ch);
                }
            }
            if (got[ch - 'a'] == false)
                got[ch - 'a'] = true;
//            if (!got[ch - 'a'])
//            {
//                got[ch - 'a'] = true;
//            }
//            else
//            {
//                setarr[ch - 'a'].insert(ch);
//            }
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            ans += setarr[i].size();
        }
        return ans;
    }

// error ... unique。。 而且 这段代码 错了。
// 至少隔一个char， 存在的相等。
    int lt1930a(string s)
    {
        unordered_map<char, int> map2;
        int ans = 0;
        map2[s[0]] = 1;
        int sz1 = s.size();
        for (int i = 2; i < sz1; ++i)
        {
            ans += map2[s[i]];
            map2[s[i - 1]]++;
        }
        return ans;
    }

};

int main()
{
    string s = "aabca";
//    string s = "adc";
//    string s = "bbcbaba";
//    string s = "ckafnafqo";     // 4

    LT1930 lt;

    cout<<lt.lt1930d(s)<<endl;

    return 0;
}
