
#include "../../header/myheader.h"

class LT
{
public:



};

// D D

//class TrieNode {
//public:
//    bool word;
//    TrieNode* children[26];
//    TrieNode() {
//        word = false;
//        memset(children, NULL, sizeof(children));
//    }
//};


//bool search(const char* word, TrieNode* node) {
//    for (int i = 0; word[i] && node; i++) {
//        if (word[i] != '.') {
//            node = node->children[word[i] - 'a'];
//        }
//        else {
//            TrieNode* tmp = node;
//            for (int j = 0; j < 26; j++) {
//                node = tmp->children[j];
//                if (search(word + i + 1, node)) {
//                    return true;
//                }
//            }
//        }
//    }
//    return node && node->word;
//}
// 非 . 时，不会递归。




//Runtime1788 ms
//Beats
//38.23 %
//Memory603.9 MB
//Beats
//21.62 %
struct TrieNode
{
    TrieNode* arr[26];
    bool en;
};


class WordDictionary {

    TrieNode* root;

public:
    WordDictionary() {
        this->root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->arr[word[i] - 'a'] == nullptr)
                node->arr[word[i] - 'a'] = new TrieNode();
            node = node->arr[word[i] - 'a'];
        }
        node->en = true;
    }

    bool search(string word) {
        return dfsa1(this->root, word, 0);
    }

    bool dfsa1(TrieNode* node, string s, int idx)
    {
        if (idx == s.size())
            return node->en;

        if (s[idx] == '.')
        {
            for (int i = 0; i < 26; ++i)
            {
                if (node->arr[i] != nullptr && dfsa1(node->arr[i], s, idx + 1))
                    return true;
            }
        }
        else
        {
            if (node->arr[s[idx] - 'a'] != nullptr && dfsa1(node->arr[s[idx] - 'a'], s, idx + 1))
                return true;
        }
        return false;
    }

};

int main()
{

    LT lt;


    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout<<endl<<wordDictionary.search("pad"); // return False
    cout << endl << wordDictionary.search("bad"); // return True
    cout << endl << wordDictionary.search(".ad"); // return True
    cout << endl << wordDictionary.search("b.."); // return True


    return 0;
}
