
#include "../header/myheader.h"

class LT0677
{
public:



};


// D D

//        for (auto it = mp.lower_bound(prefix); it != mp.end() && it->first.substr(0, n) == prefix; it++)
//            sum += it->second;
// 用map，有序，


//struct trie { trie* ch[26] = {}; int sum = 0; } root;
//unordered_map<string, int> pairs;
//void insert(string key, int val) {
//    auto p = &root;
//    for (auto i = 0; i < key.size(); p->sum += val - pairs[key], ++i)
//        p = p->ch[key[i] - 'a'] = p->ch[key[i]  - 'a'] == nullptr ? new trie() : p->ch[key[i] - 'a'];
//    pairs[key] = val;
//}
//int sum(string prefix) {
//    auto p = &root;
//    for (auto i = 0; i < prefix.size() && p != nullptr; p = p->ch[prefix[i] - 'a'], ++i) ;
//    return p == nullptr ? 0 : p->sum;
//}




//Runtime: 4 ms, faster than 91.48% of C++ online submissions for Map Sum Pairs.
//Memory Usage: 8.4 MB, less than 24.37% of C++ online submissions for Map Sum Pairs.
// 这种写法很耗内存，如果 插入少，读取多，那很适合。。。看来trie树内存更爆炸？
class MapSum {

    unordered_map<string, int> map2;
    unordered_map<string, int> map3;

public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        int v = val;
        if (map2.find(key) != map2.end())
        {
            v -= map2[key];
        }
        map2[key] = val;
        string s(1, key[0]);
        map3[s] += v;
        for (int i = 1; i < key.size(); i++)
        {
            s += key[i];
            map3[s] += v;
        }
    }

    int sum(string prefix) {
        if (map3.find(prefix) == map3.end())
            return 0;
        return map3[prefix];
    }
};


int main()
{

    LT0677 lt;

    MapSum ms;
    ms.insert("apple", 3);
    cout<<ms.sum("ap")<<endl;
    ms.insert("app", 2);
    cout<<ms.sum("ap")<<endl;

    return 0;
}
