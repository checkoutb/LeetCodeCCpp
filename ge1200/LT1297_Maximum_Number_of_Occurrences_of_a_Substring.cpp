
#include "../header/myheader.h"

class LT1297
{
public:


// D D

//    unordered_map<string, int> m;
//    while (j < s.size()) {
//        if (++cnt[s[j++] - 'a'] == 1) ++unique;
//        while (unique > maxLetters || j - i > minSize)
//            if (--cnt[s[i++] - 'a'] == 0) --unique;
//        if (j - i == minSize)
//            res = max(res, ++m[s.substr(i, minSize)]);
//    }




//    int lt1297b(string s, int maxLetters, int minSize, int maxSize)
//    {
//        int sz1 = s.size();
//        int ans = 0;
//        int
//    }



// tle
// need maxSize ?
    int lt1297a(string s, int maxLetters, int minSize, int maxSize)
    {
        int sz1 = s.size();
        int ans = 0;
        unordered_set<int> set2;
        for (int i = 0; i <= sz1 - minSize; ++i)
        {
            set2.clear();
            int j = 0;
            for (; j < minSize - 1; ++j)
            {
                set2.insert(s[j + i]);
            }
            // j>=minSize
//            for (; j < maxSize; ++j)
//            if ()
//            {
                set2.insert(s[j + i]);
                if (set2.size() > maxLetters)
                    continue;
//                    break;

                string subs = s.substr(i, minSize);
                int idx = s.find(subs);
                if (idx != i)
                    continue;
//                    break;
                int t2 = 0;
                while (idx != std::string::npos)
                {
                    idx = s.find(subs, idx + 1);
                    t2++;
                }
//                if (t2 > ans)
//                    cout<<t2<<", "<<subs<<endl;
                ans = max(ans, t2);
//            }
        }

        return ans;
    }

};

int main()
{

//    string s{"aababcaab"};
//    int a{2}, b{3}, c{4};

//    string s{"aaaa"};
//    int a{1}, b{3}, c{3};

//    string s{"aabcabcab"};
//    int a{2}, b{2}, c{3};

    string s{"abcde"};
    int a{2}, b{3}, c{3};

    LT1297 lt;

    cout<<lt.lt1297a(s, a, b, c);

    return 0;
}
