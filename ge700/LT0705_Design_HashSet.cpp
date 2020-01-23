
#include "../header/myheader.h"

class LT0705
{
public:



};


// details
//hashTable = vector<vector<int> >(10000, vector<int>());
//vector<int>& ptr = hashTable[key%10000];

//vector<int> _info;
//        if (key >= _info.size()) {
//            _info.resize(key + 1, 0);
//            _info[key] = 1;
//        }
//        else {
//            _info[key] = 1;
//        }
// bool数组，下标代表key，值代表是否存在。。。。

//#define MAXVALUE 1000000
//vector<bool> hash;            // 类属性
//hash.resize(MAXVALUE + 1, false);         // 构造器


//class Node {
//public:
//    int key;
//    Node* next;
//    Node(int k=-1): key(k), next(NULL) {}
//};
// 不用list。


// 稀疏图，bool数组(这可以算稠密图)


// 引用，太难了。
//Runtime: 132 ms, faster than 20.47% of C++ online submissions for Design HashSet.
//Memory Usage: 37.6 MB, less than 94.44% of C++ online submissions for Design HashSet.

class MyHashSet {
    list<pair<int, list<int>>> ROOT;
    const int MSZ = 1000;

    list<int>& finda1(int k)
    {
        int t2 = k / MSZ;
        for (list<pair<int, list<int>>>::iterator it = ROOT.begin(); it != ROOT.end(); it++)
        {
            if (it->first == t2)
            {
                return it->second;
            }
        }
        list<int> lst2;
        ROOT.push_back(make_pair(t2, lst2));
        return ROOT.back().second;
    }

    void finda2(list<int>::iterator& it, list<int>& lst, int k)
    {
        it = lower_bound(lst.begin(), lst.end(), k);
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }

    void add(int key) {
        list<int>& lst = finda1(key);
        list<int>::iterator it;
        finda2(it, lst, key);
        if (it != lst.end() && *it == key)
            return;
        lst.insert(it, key);
    }

    void remove(int key) {
        list<int>& lst = finda1(key);
        list<int>::iterator it;
        finda2(it, lst, key);
        if (it == lst.end() || *it != key)
            return;
        lst.erase(it);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        list<int>::iterator it;
        list<int>& lst = finda1(key);
        finda2(it, lst, key);
        return it != lst.end() && *it == key;
    }
};


int main()
{

    LT0705 lt;

    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    cout<<hashSet.contains(1)<<endl;    // returns true
    cout<<hashSet.contains(3)<<endl;    // returns false (not found)
    hashSet.add(2);
    cout<<hashSet.contains(2)<<endl;    // returns true
    hashSet.remove(2);
    cout<<hashSet.contains(2)<<endl;    // returns false (already removed)


//    list<int> lst2;
//    list<int>::iterator it = std::lower_bound(lst2.begin(), lst2.end(), 1);
//    cout<<&lst2<<", "<<&(*lst2.begin())<<", "<<&(*lst2.end())<<", "<<&(*it)<<endl;
//    cout<<*it<<endl;
//    lst2.push_back(1);
//    lst2.push_back(5);
//    lst2.push_back(12);


    return 0;
}
