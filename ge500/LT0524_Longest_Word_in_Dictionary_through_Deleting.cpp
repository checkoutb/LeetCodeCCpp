
#include "../header/myheader.h"

class LT0524
{
public:


// Collections.sort(d, (a,b) -> a.length() != b.length() ? -Integer.compare(a.length(), b.length()) :  a.compareTo(b));


// pj += s[pi] == d[i][pj];     // 相同就+1， 不同就不进。


//Runtime: 108 ms, faster than 13.86% of C++ online submissions for Longest Word in Dictionary through Deleting.
//Memory Usage: 28.8 MB, less than 7.69% of C++ online submissions for Longest Word in Dictionary through Deleting.

    string lt0524a(string s, vector<string>& d)
    {
        map<int, set<string>> map2;

        for (string w : d)
        {
            if (w.size() <= s.size())
                map2[w.size()].insert(w);
        }

        for (map<int, set<string>>::reverse_iterator it = map2.rbegin(); it != map2.rend(); it++)
        {
//            if (it->first > s.size())
//                continue;

            set<string> set2 = it->second;
//            sort(set2.begin(), set2.end());           // 报错。。不过 set本身有序。 [](string& a, string& b) {return a < b;}, 加不加都是一样的错，没有operator-.
                                                                            // 是set<string>::iterator 的问题，这个迭代器 没有 operator-.只能前向。
            for (string t : set2)
            {
                int i = 0, j = 0;
                while (j < s.size() && i < t.size())
                {
                    if (t[i] == s[j])
                    {
                        i++;
                        j++;
                    }
                    else
                    {
                        j++;
                    }
                }
                if (i == t.size())
                {
                    return t;
                }
            }
        }
        return "";
    }
};

int main()
{
    string s = "abpcplea";
    vector<string> d = {"ale","apple","monkey","plea"};

    sort(d.begin(), d.end());
//    set<string> set2(d.begin(), d.end());
//    sort(set2.begin(), set2.end());

    set<string> set3 = {"a","c","dd","bb"};
//    sort(set3.begin(), set3.end());

    set<string>::iterator it2 = set3.begin();
    set<string>::iterator it3 = set3.end();

//    cout<<it3 - it2<<endl;            // no match for operator-
                        // 也是，set是集合，无法像vector一样 有下标。


    LT0524 lt;

    cout<<lt.lt0524a(s, d)<<endl;

    return 0;
}
