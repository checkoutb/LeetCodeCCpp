
#include "../header/myheader.h"

class LT0820
{
public:

// D D
//        for (string w : s)
//            for (int i = 1; i < w.size(); ++i)
//                s.erase(w.substr(i));
// .............

//class TrieNode {
//public:
//    unordered_map<char, TrieNode *> next;
//};


//    for (auto i = 0; i < ws.size(); ++i) reverse(ws[i].begin(), ws[i].end());
//    sort(ws.begin(), ws.end());
//    for (auto i = 0; i < ws.size() - 1; ++i) res += ws[i] == ws[i + 1].substr(0, ws[i].size()) ? 0 : ws[i].size() + 1;
//    return res + ws[ws.size() - 1].size() + 1;
// reverse + sort.


//Runtime: 160 ms, faster than 37.72% of C++ online submissions for Short Encoding of Words.
//Memory Usage: 21.4 MB, less than 100.00% of C++ online submissions for Short Encoding of Words.
// 后序的Trie。。 单词是另一个单词的后缀，
// ends_with..
    int lt0820a(vector<string>& words)
    {
        map<char, vector<string>> map2;
        std::sort(words.begin(), words.end(), [](string& s1, string& s2) { return s1.size() < s2.size(); });        // ... c++返回bool，java返回int...

        #ifdef __test
        for_each(begin(words), end(words), fun_cout_s);
        cout<<endl;
        #endif // __test

        for (string s : words)
        {
            map2[s[s.size() - 1]].push_back(s);
        }
        for (auto& p : map2)                // &&&&&....
        {
            vector<string>& vs2 = p.second;
            for (int i = 0; i < vs2.size(); i++)
            {
                for (int j = i + 1; j < vs2.size(); j++)
                {
                    int pos = vs2[j].rfind(vs2[i]);
                    if (pos != std::string::npos && (pos + vs2[i].size() == vs2[j].size()))
                    {
                        vs2.erase(vs2.begin() + i);
                        i--;
                        break;
                    }
                }
            }
        }
        int ans = 0;
        for (auto p : map2)
        {
            for (string s : p.second)
            {
                ans += s.size() + 1;
            }
        }
        return ans;
    }

};

int main()
{

    vector<string> v = {"time", "me"
    , "bell"
    };

    LT0820 lt;

    cout<<lt.lt0820a(v)<<endl;

    return 0;
}
