
#include "../header/myheader.h"

class LT0648
{
public:


// D D

//        Set<String> set = new HashSet<>();
//        for (String s : dict) set.add(s);
//
//        StringBuilder sb = new StringBuilder();
//        String[] words = sentence.split("\\s+");
//
//        for (String word : words) {
//            String prefix = "";
//            for (int i = 1; i <= word.length(); i++) {
//                prefix = word.substring(0, i);
//                if (set.contains(prefix)) break;
//            }
//            sb.append(" " + prefix);
//        }
//
//        return sb.deleteCharAt(0).toString();



//class trie {
//    bool isRoot = false;
//    trie* l[26] = {};
//public:
//    void insert(string& word, int ch, int sz) {
//        isRoot |= ch == sz;
//        if (!isRoot) { // stop at the shortest root.
//            if (l[word[ch] - 'a'] == nullptr) l[word[ch] - 'a'] = new trie();
//            l[word[ch] - 'a']->insert(word, ch + 1, sz);
//        }
//    }
//    int root(string& word, int st, int ch, int sz) {
//        if (st + ch == sz || word[st + ch] == ' ' || this->isRoot) return ch;
//        if (l[word[st + ch] - 'a'] == nullptr) { // root was not found
//            while (st + ch < sz && word[st + ch] != ' ') ++ch; // skipping the entire word
//            return ch;
//        }
//        return l[word[st + ch] - 'a']->root(word, st, ch + 1, sz);
//    }
//};
//string replaceWords(vector<string>& dict, string snt) {
//    trie t;
//    string res;
//    for (auto s : dict) t.insert(s, 0, s.size());
//    for (int i = 0; i < snt.size(); ) {
//        if (snt[i] == ' ') res += snt[i++];
//        auto chars = t.root(snt, i, 0, snt.size());
//        res += snt.substr(i, chars);
//        for (i += chars; i < snt.size() && snt[i] != ' '; ++i);
//    }
//    return res;
//}
// Trie... meng.


//Runtime: 44 ms, faster than 99.81% of C++ online submissions for Replace Words.
//Memory Usage: 23.9 MB, less than 94.34% of C++ online submissions for Replace Words.
// 词根+后继， 但是后继也得是个单词啊。这里不管后继是不是单词的。。
// 要构造Trie啊。
    string lt0648a(vector<string>& dictionary, string sentence)
    {
        sort(begin(dictionary), end(dictionary), [](string& s1, string& s2){ return s1.length() < s2.length(); });

        #ifdef __test
        for_each(begin(dictionary), end(dictionary), fun_cout_s);
        cout<<endl;
        #endif // __test

        unordered_map<char, vector<string>> map2;
        for (string& s : dictionary)
        {
            map2[s[0]].emplace_back(s);
        }

        string ans = "";
        string subs = "";
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ' || i == sentence.size() - 1)
            {
                if (i == sentence.size() - 1)
                    subs += sentence[i];                // lou le yige 'p'...
                vector<string>& vs = map2[subs[0]];
                bool suc = false;
                for (string& pre : vs)
                {
                    if (pre.size() >= subs.size())
                        continue;
                    bool fail = false;
                    for (int j = 0; j < pre.size(); j++)
                    {
                        if (pre[j] != subs[j])
                        {
                            fail = true;
                            break;
                        }
                    }
                    if (!fail)
                    {
                        suc = true;
                        ans += (pre + (i == sentence.size() - 1 ? "" : " "));
                        break;
                    }
                }
                if (!suc)
                    ans += subs + (i == sentence.size() - 1 ? "" : " ");
                subs = "";
            }
            else
            {
                subs += sentence[i];
            }
        }
        return ans;
    }


};

int main()
{

//    vector<string> vs = {"cat","bat","rat"};
//    string s = "the cattle was rattled by the battery";

//    vector<string> vs = {"a","b","c"};
//    string s = "aadsfasf absbs bbab cadsfafs";

    vector<string> vs = {"a","aa","aaa","aaaa"};            // keyi xian shanchu yixie...
    string s = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";



    LT0648 lt;

    cout<<lt.lt0648a(vs, s)<<endl;

    return 0;
}
