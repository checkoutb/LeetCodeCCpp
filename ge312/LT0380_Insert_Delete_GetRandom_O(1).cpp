
#include "../header/myheader.h"
#include <time.h>
#include <windows.h>






// discuss 和detail 差不多。


// details：

//    map<int,int> h;
//    vector<int> data;
// data中只增不减，靠h来判定是否存在。
// random的时候：
//            int randpos = rand() % data.size();
//            if (h.find(data[randpos]) != h.end())
//                return data[randpos];
// insert：
//        h[val] = 1;
//        data.push_back(val);
// remove：
//        it = h.find(val);
//        h.erase(it);

// map，vector。remove的时候，把vector.back保存到将remove的位置，然后vector.pop_back


// list慢于vector，但是list+map 应该更符合O(1)吧。



// 大部分都是60左右。


//Runtime: 140 ms, faster than 5.32% of C++ online submissions for Insert Delete GetRandom O(1).
//Memory Usage: 22.8 MB, less than 5.06% of C++ online submissions for Insert Delete GetRandom O(1).


// 一个hashmap，一个doubly-linked-list，
// hashmap，key是insert进来的val，value是 list的元素
// RandomizedSet 不能保存相同val值。
// insert：map.get(val) != null ? return false : { list.push_back(val); map.put(val, xx); return true;};
// remove: map.get(val) == null ? return false : { list.delete(map.get(val)); map.remove(val); return true;};
// getRandom: ...这个需要数组才能O(1)。。。list没办法。但ArrayList/vector的话，insert，remove就不是O(1)
//          map提供了begin，end，能看起来O(1)。。Java里是是数组+链表实现map的存储。不知道cpp是怎么样的。底层终究不是O(1).毕竟数组扩容，复制。
//          list也提供了begin，end，不过list肯定不是O(1).,,
// 还得自己新建对象？

// cppreference，std::list 中：It is usually implemented as a doubly-linked list
// pair
// unordered_map 应该能更快点
// map.contains    (C++20)


// 17/18... getRandom...N^N次getRandom，全是同一个数。。。srand位置的问题。
// 。。random还不如内置一个i，每次i++，超过sz就归0.。然后返回begin+i。。。

class RandomizedSet {
//    map<int, pair<int, int>> map2;
//    list<pair<int, int>> list2;

    map<int, list<int>::iterator> map2;        // map<int, auto> ?
    list<int> list2;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));      // 无所谓，种子是1还是随机数，这里并不要求。
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map2.find(val) != map2.end())
            return false;
//        pair<int, int> p2(val, 1);
//        list2.push_back(p2);
//        map2.insert(val, p2);
//        return true;        // 可以直接用insert 返回 的 pair

        list2.push_front(val);
        map2.insert(make_pair(val, list2.begin()));     // ......
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map2.find(val) == map2.end())
            return false;
//        map<int, pair<int, int>>::iterator it2 = map2.find(val);
//        map2.erase(it2);
//        list2.
//        return true;

        map<int, list<int>::iterator>::iterator it2 = map2.find(val);
        list2.erase(it2->second);
        map2.erase(it2);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int sz = map2.size();
//        int t1 = rand() % sz;
//        int r = *((map2.begin() + t1)->second);

//        srand(sz);          // 设置种子，但是固定测试的话，这个sz也是相同的。
//        srand(time(NULL));      // ok, 加上Sleep后，__test中rand不同，不加Sleep，速度太快，导致rand相同序列。
        int t1 = rand() % sz;
        #ifdef __test
        // rand()函数不接受参数，默认以1为种子（即起始值）。 随机数生成器总是以相同的种子开始，所以形成的伪随机数列也相同
        cout<<"  . "<<rand()<<", "<<rand()<<", "<<rand()<<endl;         // 怎么始终都是相同的。。
        cout<<"    t1   "<<t1<<endl;
        #endif // __test


        // iterator 没有operator+(int)。。。
        auto it2 = map2.begin();
        for (int i = 0; i < t1; i++)
        {
            it2++;
        }
        int r = *(it2->second);
        return r;
    }
};

int main()
{
    RandomizedSet randomSet;
// Inserts 1 to the set. Returns true as 1 was inserted successfully.
    cout<<randomSet.insert(1);
    cout<<endl;

// Returns false as 2 does not exist in the set.
    cout<<randomSet.remove(2);
    cout<<endl;

// Inserts 2 to the set, returns true. Set now contains [1,2].
    cout<<randomSet.insert(2);
    cout<<endl;

// getRandom should return either 1 or 2 randomly.
    cout<<randomSet.getRandom();
    cout<<endl;

    Sleep(365);

// Removes 1 from the set, returns true. Set now contains [2].
    cout<<randomSet.remove(1);
    cout<<endl;

// 2 was already in the set, so return false.
    cout<<randomSet.insert(2);
    cout<<endl;

// Since 2 is the only number in the set, getRandom always return 2.
    cout<<randomSet.getRandom();
    cout<<endl;

    randomSet.insert(10);
    randomSet.insert(20);
    randomSet.insert(30);

    int t1 = -1;
    int t2 = 0;
    for (int i = 0; i < 10; i++)
    {
        t2 = randomSet.getRandom();
        if (t1 != t2)
        {
            cout<<" "<<t2<<endl;
        }
        t1 = t2;
    }

    return 0;
}
