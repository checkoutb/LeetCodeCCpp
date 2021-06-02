
#include "../../header/myheader.h"

class LT
{
public:

// D D

// 。。。 ltaaa  更像 solution中 的binary search,, 当然 我没有用 lower_bound, upper_bound, 但可以用，并且用的话，能更快。。

//        for (char &c : searchWord) {
//            prefix += c;
//
//            // Get the starting index of word starting with `prefix`.
//            start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();
//
//            // Add empty vector to result.
//            result.push_back({});
//
//            // Add the words with the same prefix to the result.
//            // Loop runs until `i` reaches the end of input or 3 times or till the
//            // prefix is same for `products[i]` Whichever comes first.
//            for (int i = start; i < min(start + 3, n) && !products[i].compare(0, prefix.length(), prefix); i++)
//                result.back().push_back(products[i]);
//
//            // Reduce the size of elements to binary search on since we know
//            bsStart = start;
//        }
// 这里通过下标来 划取一个合适的区间，而且没有划 end。。
// ltaaa 是直接 从原数组中erase 不合适的元素， 有确定end。


// Trie是真的造了一颗树。。
// 挺繁的。

//    struct Node {
//        bool isWord = false;
//        vector<Node *> children{vector<Node *>(26, NULL)};
//    } * Root, *curr;

//    void dfsWithPrefix(Node * curr, string & word, vector<string> & result) {
//        if (result.size() == 3)
//            return;
//        if (curr->isWord)
//            result.push_back(word);
//
//        // Run DFS on all possible paths.
//        for (char c = 'a'; c <= 'z'; c++)
//            if (curr->children[c - 'a']) {
//                word += c;
//                dfsWithPrefix(curr->children[c - 'a'], word, result);
//                word.pop_back();
//            }
//    }

//    void insert(string & s) {
//        // Points curr to the root of trie.
//        curr = Root;
//        for (char &c : s) {
//            if (!curr->children[c - 'a'])
//                curr->children[c - 'a'] = new Node();
//            curr = curr->children[c - 'a'];
//        }
//        // Mark this node as a completed word.
//        curr->isWord = true;
//    }

//    vector<string> getWordsStartingWith(string & prefix) {
//        curr = Root;
//        vector<string> result;
//
//        // Move curr to the end of prefix in its trie representation.
//        for (char &c : prefix) {
//            if (!curr->children[c - 'a'])
//                return result;
//            curr = curr->children[c - 'a'];
//        }
//        dfsWithPrefix(curr, prefix, result);
//        return result;
//    }





// AC
//Runtime: 48 ms
//Memory Usage: 23.3 MB
// 暴力
// 降序排列，从头开始搜索 word[0]， vector 3个元素，rotate array. 好像也不容易。
// .. shengxu, 要的是min
    vector<vector<string>> ltaa(vector<string>& products, string searchWord)
    {
//        vector<string> vs(3);
//        vector<vector<string>> ans(searchWord.size(), vector<string>());        // 默认初始化是什么？就是 vector<string> ？
        vector<vector<string>> ans(searchWord.size());
//        std::sort(begin(products), end(products), std::greater<string>());
        std::sort(begin(products), end(products));
        #ifdef __test
        for (string& s : products)
            cout<<s<<", ";
        cout<<endl;
        cout<<" ------- "<<endl;
        #endif // __test

        string tar = "";
        int idx = 0;
        for (int i = 0; i < searchWord.size(); ++i)
        {
            tar += searchWord[i];
            // 不需要vs。
//            if (products[idx].startWith())             starts_with(C++20)
            while (idx < products.size())
                if (startWith(products[idx], tar))
                {
                    ans[i].push_back(products[idx]);
                    if (idx + 1 < products.size() && startWith(products[idx + 1], tar))
                    {
                        ans[i].push_back(products[idx + 1]);
                        if (idx + 2 < products.size() && startWith(products[idx + 2], tar))
                        {
                            ans[i].push_back(products[idx + 2]);
                        }
                    }
                    break;
                }
                else
                {
//                    #ifdef __test
//                    cout<<idx<<endl;
//                    getchar();
//                    cout<<"?";
//                    #endif // __test
                    idx++;
                }
            if (ans[i].empty())
                break;
        }

        return ans;
    }

    bool startWith(string& source, string& tar)
    {
        if (source.size() < tar.size())
            return false;
        for (int i = 0; i < tar.size(); ++i)
        {
            if (source[i] != tar[i])
                return false;
        }
        return true;
    }


// AC .. 二分也很难。。
//Runtime: 36 ms
//Memory Usage: 23.3 MB
// 二分
    vector<vector<string>> lta(vector<string>& products, string searchWord)
    {
        vector<vector<string>> ans(searchWord.size());
        std::sort(begin(products), end(products), std::less<string>());
        #ifdef __test
        for (string& s : products)
            cout<<s<<", ";
        cout<<endl<<" - --    ------- "<<endl;
        #endif // __test
        int idx = 0;
        string tar = "";
        for (int i = 0; i < searchWord.size(); ++i)
        {
            tar += searchWord[i];
            idx = binarySearch(products, idx, tar);
            #ifdef __test
//            cout<<i<<", "<<tar<<", "<<idx<<", "<<idx<<endl;
//            cout<<i<<", "<<tar<<", "<<idx<<", "<<products[idx]<<endl;
            #endif // __test
            for (int j = 0; j < 3; ++j)
            {
                if ((idx + j) < products.size() && startWith(products[idx + j], tar))
                {
                    ans[i].push_back(products[idx + j]);
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }

    int binarySearch(vector<string>& products, int idx, string& tar)
    {
        int st = idx;
        int en = products.size() - 1;
        while (st <= en)
        {
            int mid = (st + en) / 2;
            #ifdef __test
//            cout<<mid<<", "<<st<<", "<<en<<endl;;
//            getchar();
            #endif // __test
            if (tar < products[mid])
            {
//                cout<<tar<<", "<<products[mid]<<", "<<mid<<endl;
                en = mid - 1;
            }
            else if (tar == products[mid])
            {
                st = mid;
                en = st - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
//        cout<<st<<" + "<<en<<endl;
        return st;
    }


//Use Trie data structure to store the best three matching. Traverse the Trie.
// 好像没有写过struct。。。
// 构建树的话，要消耗很多空间在 struct.map 上啊。    vector<string> 中string 是不同的吧。使的，所以会消耗额外的空间。所以用pointer
// 不可能构建一颗完全的树吧。
// 除非这种是 查询密集型的， 构造树消耗太大了。。
// 。。。 好像想错了， 构造树是 靠遍历 products的，  之前想的是，尽量减少树结点，所以想直接用searchWord。。这样等于把上面的lta/ltaa又做了一遍。。
    struct Node
    {
        char ch;
        unordered_map<char, Node*> map2;        // 不能赋予 nullptr  NULL
        vector<string*> vsp;
    };


// AC coooooooooool
//Runtime: 56 ms
//Memory Usage: 23.4 MB
    vector<vector<string>> ltaaa(vector<string>& products, string searchWord)
    {
        int sz1 = products.size();
        int sz2 = searchWord.size();
        vector<vector<string>> ans(sz2);
        std::sort(std::begin(products), end(products));

//        Node* root = makeTrie(products, 0, sz1 - 1, searchWord, 0);

        for (int i = 0; i < sz2; ++i)
        {
            travelAsTrie(products, searchWord, i, ans);
        }

        return ans;
    }

    void travelAsTrie(vector<string>& vs, string& word, int idx, vector<vector<string>>& ans)
    {
        // 也不必dfs了。。不需要独立的方法。。尾递归。。 这个只需要一个 for就能替换掉了。 ok不写递归，但是还是一个独立的方法。
        // 这里可以lower_bound upper_bound。
        for (int i = 0; i < vs.size();)
        {
            if (vs[i][idx] != word[idx])
            {
                vs.erase(begin(vs) + i);
            }
            else
            {
                ++i;
            }
        }
        for (int i = 0, mxi = min(3, (int) vs.size()); i < mxi; ++i)
            ans[idx].push_back(vs[i]);
    }

    // 构建Trie的时候可以和 searchWord一起，来减枝。
    // sort
    Node* makeTrie(vector<string>& vs, int st, int en, string& word, int idx)
    {
        // 2 pointer swap 到最后？ or erase？
        for (int i = 0; i < vs.size();)
        {
            if (vs[i][idx] != word[idx])
            {
                vs.erase(begin(vs) + i);
            }
            else
            {
                ++i;
            }
        }

        for (int i = st; i <= en; ++i)
        {
            string& src = vs[i];
            if (src[idx] == word[idx])
            {
                // 需要提前剔除，不然这里不知道 en。
                // 提前剔除了以后，似乎就不需要构造node 了，直接在这里找前3个就可以了。。
            }
        }
    }
};

int main()
{
    vector<string> vs = {"mobile","mouse","moneypot","monitor","mousepad"};
    string s = "mouse";

//    vector<string> vs = {"havana"};
//    string s = "havana";

    cout<<("bags" > "bag")<<endl;   // F
    cout<<("b" > "a")<<endl;        // F
    cout<<("b" <= "a")<<endl;       // T
    cout<<("bags" < "bag")<<endl;   // T
    cout<<("mou" > "mouse")<<endl;  // T
    // ?????? 但是 二分的时候  mou < mouse 是true
    // 字典顺序 大的， 反而小。
    // 比得是 谁在前面。

    string s23 = "aaa";
    vector<string > vs23;
    vs23.push_back(s23);

    vector<string> vs25;
    vs25.push_back(s23);

    s23.push_back('q');
    cout<<s23<<endl;
    cout<<vs23[0]<<endl;
    cout<<vs25[0]<<endl;

    string* p1 = &s23;
    string* p2 = &vs23[0];
    string* p3 = &vs25[0];

    cout<<p1<<", "<<p2<<", "<<p3<<endl;     // 看地址，p2,p3是一起的， p1是独立的。
    auto* p4 = &vs23;       // 和p1 一起。     所以s23,vs23,vs25是栈，  vector中的元素在堆。
    cout<<p4<<endl;             // p2,p3 小， 所以堆从 小往大走， 栈相反。
                        // 是的，看它们的 地址的变化。

    vector<string*> vs11;
    vector<string*> vs22;
    vs11.push_back(&s23);
    vs22.push_back(&s23);
    cout<<vs11[0]<<", "<<vs22[0]<<endl;

//    vector<string> vs = {"bags","baggage","banner","box","cloths"};
//    string s = "bags";

//    vector<string> vs = {"havana"};
//    string s = "haha";

    LT lt;

    vector<vector<string>> vvs = lt.ltaaa(vs, s);
    for (int i = 0; i < vvs.size(); ++i)
    {
        for (string& s : vvs[i])
            cout<<s<<", ";
        cout<<endl;
    }

    return 0;
}
