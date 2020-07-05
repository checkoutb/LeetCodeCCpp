
#include "../header/myheader.h"

class LT0953
{
public:

// D D
//        return is_sorted(words.begin(), words.end(), [&indices](
//                const string &w1,
//                const string &w2
//        ) {
//            auto l1 = w1.size(), l2 = w2.size();
//            for (auto i = 0; i < min(l1, l2); ++i) {
//                auto c1 = w1[i], c2 = w2[i];
//                if (c1 != c2) {
//                    return indices[c1 - 'a'] < indices[c2 - 'a'];
//                }
//            }
//            return l1 < l2;
//        });


//        int mapping[26];
//        for (int i = 0; i < 26; i++)
//            mapping[order[i] - 'a'] = i;
//        for (string &w : words)
//            for (char &c : w)
//                c = mapping[c - 'a'];
//        return is_sorted(words.begin(), words.end());
// 转回来了。。


//    int[] mapping = new int[26];
//    public boolean isAlienSorted(String[] words, String order) {
//        for (int i = 0; i < order.length(); i++)
//            mapping[order.charAt(i) - 'a'] = i;
//        for (int i = 1; i < words.length; i++)
//            if (bigger(words[i - 1], words[i]))
//                return false;
//        return true;
//    }
//
//    boolean bigger(String s1, String s2) {
//        int n = s1.length(), m = s2.length();
//        for (int i = 0; i < n && i < m; ++i)
//            if (s1.charAt(i) != s2.charAt(i))
//                return mapping[s1.charAt(i) - 'a'] > mapping[s2.charAt(i) - 'a'];
//        return n > m;
//    }
// 。。。 只需要和前一个比较就可以了。


//Runtime: 4 ms, faster than 99.12% of C++ online submissions for Verifying an Alien Dictionary.
//Memory Usage: 9.4 MB, less than 98.80% of C++ online submissions for Verifying an Alien Dictionary.
    bool lt0953a(vector<string>& words, string order)
    {
        int arr[26] = {0};
        int i = 0;
        for(char ch : order)
        {
            arr[ch - 'a'] = i++;
        }

        i = 0;
        while (words.size() > 1)
        {
            vector<string>::iterator it = words.begin();
            while (it != words.end() && it->size() <= i)
            {
                it = words.erase(it);
            }
            if (it == words.end())
                break;
            char ch = it->operator[](i);
            it++;
            while (it != words.end())
            {
                if (i >= it->size())
                {
                    return false;
                }
                else
                {
                    if (arr[it->operator[](i) - 'a'] != arr[ch - 'a'])
                    {
                        if (arr[it->operator[](i) - 'a'] < arr[ch - 'a'])
                        {
                            return false;
                        }
                        else
                        {
                            ch = it->operator[](i);
                            it = words.erase(it);
                        }
                    }
                    else
                    {
                        it++;
                    }
                }
            }
            i++;
        }

        return true;
    }

};

int main()
{

//    vector<string> vs = {"hello","leetcode"};
//    string o = "hlabcdefgijkmnopqrstuvwxyz";

//    vector<string> vs = {"word","world","row"};
//    string o = "worldabcefghijkmnpqstuvxyz";

//    vector<string> vs = {"apple","app"};
    vector<string> vs = {"app", "apple"};
    string o = "abcdefghijklmnopqrstuvwxyz";

    LT0953 lt;

    cout<<lt.lt0953a(vs, o)<<endl;

    return 0;
}
