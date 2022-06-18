
#include "../../header/myheader.h"

class LT
{
public:



};


// D D


//class Trie {
//public:
//    int value;
//    Trie* son[Z];
//
//    Trie() : son() { }
//
//    Trie* put(char c, int v) {
//        int i = c - 'a';
//        if (son[i] == NULL) son[i] = new Trie();
//        son[i]->value = v;
//        return son[i];
//    }
//
//    ~Trie() {
//        for (int i = 0; i < Z; i++)
//            delete son[i];
//    }
//};



//class WordFilter {
//    class Trie {
//        struct TrieNode {
//            TrieNode* children[128];
//            int word;
//
//            TrieNode() : children{}, word(-1) {}
//        } root;
//
//    public:
//        Trie(const std::vector<std::string>& words) {
//            int word_index = 0;
//
//            for (const std::string& word : words) {
//                for (int suf_len = 0; suf_len <= word.length(); suf_len++) {
//                    TrieNode* node = &root;
//
//                    for (int i = word.length() - suf_len; i < word.length(); i++) {
//                        if (node->children[word[i]] == nullptr) {
//                            node->children[word[i]] = new TrieNode();
//                        }
//
//                        node = node->children[word[i]];
//                    }
//
//                    if (node->children['#'] == nullptr) {
//                        node->children['#'] = new TrieNode();
//                    }
//
//                    node = node->children['#'];
//                    node->word = std::max(node->word, word_index);
//
//                    for (char letter : word) {
//                        if (node->children[letter] == nullptr) {
//                            node->children[letter] = new TrieNode();
//                        }
//
//                        node = node->children[letter];
//                        node->word = std::max(node->word, word_index);
//                    }
//                }
//
//                word_index++;
//            }
//        }
//
//        int find(const std::string& prefix, const std::string& suffix) {
//            TrieNode* node = &root;
//
//            for (int i = 0; i < suffix.length() and node; i++) {
//                node = node->children[suffix[i]];
//            }
//
//            if (node == nullptr) {
//                return -1;
//            }
//
//            node = node->children['#'];
//
//            if (node == nullptr) {
//                return -1;
//            }
//
//            for (int i = 0; i < prefix.length() and node; i++) {
//                node = node->children[prefix[i]];
//            }
//
//            return node ? node->word : -1;
//        }
//    };
//
//    Trie trie;
//
//public:
//    WordFilter(vector<string>& words) : trie(words) {}
//
//    int f(string prefix, string suffix) {
//        return trie.find(prefix, suffix);
//    }
//};


//class TNode {
//public:
//    TNode() {
//        next.resize(27, nullptr);
//    }
//    vector<TNode*> next;
//    int idx;
//};


//class WordFilter {
//public:
//    class Trie {
//    public:
//        array<Trie*, 26> children;
//        vector<int> indices;
//        Trie() {
//            children = { nullptr };
//        }
//        void insert(char c, int i) {
//            if (!children[c - 'a']) {
//                children[c - 'a'] = new Trie;
//            }
//            children[c - 'a']->indices.push_back(i);
//        }
//    };




//Take "apple" as an example, we will insert add "apple{apple", "pple{apple", "ple{apple", "le{apple", "e{apple", "{apple" into the Trie Tree.
//If the query is : prefix = "app", suffix = "le", we can find it by querying our trie for
//"le { app".
//We use '{' because in ASCii Table, '{' is next to 'z'





//class WordFilter :
//    def __init__(self, words) :
//    W = ' '.join(w + '=' + w for w in words[:: - 1])
//    self.f = lambda p, s : W.count('=', W.find(s + '=' + p)) - 1
// ..warui warui pythonic..




//Runtime: 1187 ms, faster than 13.44 % of C++ online submissions for Prefixand Suffix Search.
//Memory Usage : 141.2 MB, less than 75.37 % of C++ online submissions for Prefixand Suffix Search.
struct Node
{
    char ch;
    //vector<int> vi;                 // tle... 只需要记录这个结尾的 最大的就可以了。。。 WordFilter 初始化为 几千个"a" + 几千个"b"， 然后 几千个 f(a, a)....
    int mxi = -1;
    vector<Node*> vp;
    Node(char ch2) : ch(ch2) {
        vp = vector<Node*>(26);
    }
};

void insertTrie(Node* parent, string& s, int idx, int i)
{
    if (idx == s.size() || idx == 10)
    {
        //(parent->vi).push_back(i);
        if (i > parent->mxi)
            parent->mxi = i;
        return;
    }
    int t2 = s[idx] - 'a';
    if (parent->vp[t2] != nullptr)
    {
        ;
    }
    else
    {
        //&parent.vp[t2] = new Node(s[idx]);          // ??? 改成这种，然后又让我改 ->
                                    // 应该是 vp 改了的原因。。。
        parent->vp[t2] = new Node(s[idx]);
    }
    insertTrie(parent->vp[t2], s, idx + 1, i);
}

void getAll(Node* parent, string& s, int idx, vector<int>& ans)
{
    if (idx >= s.size())
    {
        if (parent->mxi != -1)
            ans.push_back(parent->mxi);

        //if (!parent->vi.empty())
        //    ans.insert(ans.end(), begin(parent->vi), end(parent->vi));
        //for (Node* p : parent->vp)
        for (int i = 0; i < parent->vp.size(); ++i)
        {
            Node* p = parent->vp[i];            // parent->vp[i] 非标准语法；请使用 "&" 来创建指向成员的指针
            if (p != nullptr)
                getAll(p, s, idx + 1, ans);
        }
        return;
    }
    if ((parent->vp)[s[idx] - 'a'] != nullptr)
    {
        getAll((parent)->vp[s[idx] - 'a'], s, idx + 1, ans);
    }
}

class WordFilter {
    Node* root = new Node('1');
    Node* sfx = new Node('2');
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i)
        {
            insertTrie(this->root, words[i], 0, i);
            string s2 = words[i];
            reverse(begin(s2), end(s2));
            insertTrie(this->sfx, s2, 0, i);
        }
    }

    int f(string prefix, string suffix) {
        vector<int> v1;
        getAll(this->root, prefix, 0, v1);
        vector<int> v2;
        reverse(begin(suffix), end(suffix));
        getAll(this->sfx, suffix, 0, v2);
        sort(begin(v1), end(v1));
        sort(begin(v2), end(v2));
        int i1 = v1.size() - 1;
        int i2 = v2.size() - 1;
        while (i1 >= 0 && i2 >= 0 && v1[i1] != v2[i2])
        {
            if (v1[i1] > v2[i2])
            {
                i1--;
            }
            else
            {
                i2--;
            }
        }
        return (i1 < 0 || i2 < 0) ? -1 : v1[i1];
    }
};


int main()
{

    LT lt;

    //vector<string> vs = { "apple","asadasfe"};
    //WordFilter wf(vs);
    ////WordFilter wf({ "apple" });
    //cout << endl << wf.f("a", "e");


    //["WordFilter", "f", "f", "f", "f", "f", "f", "f", "f", "f", "f"]
    //[[["cabaabaaaa", "ccbcababac", "bacaabccba", "bcbbcbacaa", "abcaccbcaa", 
    //    "accabaccaa", "cabcbbbcca", "ababccabcb", "caccbbcbab", "bccbacbcba"]], 
    //    ["bccbacbcba", "a"], ["ab", "abcaccbcaa"], ["a", "aa"], ["cabaaba", "abaaaa"], 
    //    ["cacc", "accbbcbab"], ["ccbcab", "bac"], ["bac", "cba"], ["ac", "accabaccaa"], 
    //    ["bcbb", "aa"], ["ccbca", "cbcababac"]]

    vector<string> vs = { "cabaabaaaa", "ccbcababac", "bacaabccba", "bcbbcbacaa", "abcaccbcaa", "accabaccaa", "cabcbbbcca", "ababccabcb", "caccbbcbab", "bccbacbcba" };
    WordFilter wf(vs);
    vector<vector<string>> q = { {"bccbacbcba", "a"},{"ab", "abcaccbcaa"},{"cabaaba", "abaaaa"} };      // 9 4 0
    for (vector<string>& v : q)
    {
        cout << endl << wf.f(v[0], v[1]) << endl;
    }

    return 0;
}
