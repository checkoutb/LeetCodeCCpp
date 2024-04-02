
#include "../header/myheader.h"

class LT3093
{
public:





// Runtime
// 414ms
// Beats49.76%of users with C++
// Memory
// 818.14MB
// Beats65.14%of users with C++

// node->str = str1;  node2->str = str1;    node->str = "1";   str1 == "1",  node2->str=="1"

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery)
    {
        TrieNode *root = new TrieNode(wordsContainer[0].size(), 0);
        // for (string& s : wordsContainer)
        for (int i = 0; i < wordsContainer.size(); ++i)
        {
            insert2Trie(wordsContainer[i], root, i);
            // showTrie(root);
            // cout<<"\n-----------\n";
        }


        // showTrie(root);

        vector<int> ans(wordsQuery.size());
        for (int i = 0; i < wordsQuery.size(); ++i)
        {
            ans[i] = findStr(wordsQuery[i], root);
        }
        return ans;
    }

    struct TrieNode {
        // string& str;     // ................
        int sz1;
        int idx;
        TrieNode * arr[26] = {nullptr};     // ..
        TrieNode(int sz, int i2) {
            sz1 = sz;
            idx = i2;
        }
        // TrieNode(string& s2, int i2): str{s2} {
        //     // str = s2;
        //     idx = i2;
        // }
    };

    void insert2Trie(string& str, TrieNode* root, int idx)
    {
        TrieNode* node = root;
        // if (node->str.size() > str.size())
        // {
        //     node->str = str;
        //     node->idx = idx;
        // }

        if (node->sz1 > str.size())
        {
            node->sz1 = str.size();
            node->idx = idx;
        }


        for (int i = str.size() - 1; i >= 0; --i)
        {
            char ch = str[i];
            if (node->arr[ch - 'a'] == nullptr)
            {
                node->arr[ch - 'a'] = new TrieNode(str.size(), idx);
            }
            node = node->arr[ch - 'a'];
            // cout<<str<<" iii "<<idx<<", "<<node->str<<endl;
            if (node->sz1 > str.size())
            {
                // cout<<str<<" uuuuuuuuu "<<idx<<endl;
                // node->str = str;
                node->sz1 = str.size();
                node->idx = idx;
            }
        }
    }

    int findStr(string& str, TrieNode* root)
    {
        TrieNode * node = root;
        for (int i = str.size() - 1; i >= 0; --i)
        {
            int t2 = str[i] - 'a';
            if (node->arr[t2] == nullptr)
                break;
            node = node->arr[t2];
        }
        return node->idx;
    }


    void showTrie(TrieNode* root)
    {
        std::queue<TrieNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int sz1 = q.size();
            while (sz1-- > 0)
            {
                TrieNode* p = q.front();
                q.pop();
                // cout<<p->str<<", "<<p->idx<<endl;
                for (int i = 0; i < 26; ++i)
                {
                    if (p->arr[i] != nullptr)
                    {
                        cout<<i<<", ";
                        q.push(p->arr[i]);
                    }
                }
            }
            cout<<"\n ========== \n";
        }
    }

};

int main()
{

    LT3093 lt;

    vector<string> vs = {"abcd","bcd","xbcd"};
    vector<string> vs2 = {"cd","bcd","xyz"};

    myvi vi = lt.stringIndices(vs, vs2);

    showVectorInt(vi);

    string s = "1111";
    string& s2 = s;
    string& s3 = s;
    s += "22";
    cout<<s<<", "<<s2<<", "<<s3<<endl;
    s2 = "zzz";
    cout<<s<<", "<<s2<<", "<<s3<<endl;

    return 0;
}
