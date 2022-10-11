
#include "../header/myheader.h"



struct TrieNode
{
    int cnt;
    TrieNode* arr[26] = {};
};


class LT2416
{
public:

// D D

//class Trie {
//    public:
//        Trie *ch[26] = {};
//        int visited = 0;
//};


//struct Trie {
//    Trie* ch[26] = {};
//    int cnt = 0;
//    void insert(string &w, int i = 0) {
//        auto n = this;
//        for (auto c : w) {
//            if (n->ch[c - 'a'] == nullptr)
//                n->ch[c - 'a'] = new Trie();
//            n = n->ch[c - 'a'];
//            ++n->cnt;
//        }
//    }
//    int count(string &w, int i = 0) {
//        return cnt + (i == w.size() ? 0 : ch[w[i] - 'a']->count(w, i + 1));
//    }
//};


//Runtime: 1327 ms, faster than 32.76% of C++ online submissions for Sum of Prefix Scores of Strings.
//Memory Usage: 447.9 MB, less than 76.74% of C++ online submissions for Sum of Prefix Scores of Strings.
    vector<int> lt2416a(vector<string>& words)
    {
        TrieNode* node = new TrieNode();
        for (string& s : words)
        {
            mktrie(node, s, 0);
        }
        int t2 = 0;
        int ans = 0;
        vector<int> vi(words.size());
        //for (string& s : words)
        for (int i = 0; i < words.size(); ++i)
        {
            string& s = words[i];
            ans = 0;
            TrieNode* n = node;
            for (char ch : s)
            {
                t2 = ch - 'a';
                n = n->arr[t2];
                ans += n->cnt;
            }
            vi[i] = ans;
        }
        return vi;
    }

    void mktrie(TrieNode* node, string& s, int idx)
    {
        if (idx == s.size())
        {
            return;
        }
        int t2 = s[idx] - 'a';
        if (node->arr[t2] == nullptr)
        {
            node->arr[t2] = new TrieNode();
        }
        node = node->arr[t2];
        ++(node->cnt);
        mktrie(node, s, idx + 1);
    }

};


int main()
{

    LT2416 lt;

    vector<string> vs = {"abc","ab","bc","b"};

    myvi vi = lt.lt2416a(vs);

    showVectorInt(vi);

    return 0;
}
