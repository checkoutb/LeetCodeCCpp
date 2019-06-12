
#include "../header/myheader.h"



//Runtime: 56 ms, faster than 93.44% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.
//Memory Usage: 23.8 MB, less than 55.19% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.


// 用set保存index。set默认有序。这样pop_back就肯定是最后一个。


class RandomizedCollection {
    vector<int> v2;
    unordered_map<int, list<int>> map2;     // val : indexs
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        v2.push_back(val);
        map2[val].push_back(v2.size() - 1);
        return map2[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (map2[val].empty())
            return false;

        int t1 = map2[val].back();
        int last = v2.back();
        map2[last].remove(v2.size() - 1);       // 不能直接pop_back。。。 remove。erase需要iterator，remove需要value
        map2[last].push_back(t1);
        map2[val].pop_back();
        v2[t1] = last;
        v2.pop_back();

        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int t1 = rand() % v2.size();
        return v2[t1];
    }

    #ifdef __test
    void show2()
    {
        for (auto p : v2)
            cout<<p<<", ";
        cout<<endl;
        for (unordered_map<int, list<int>>::iterator it2 = map2.begin(); it2 != map2.end(); it2++)
        {
            cout<<it2->first<<" : ";
            cout<<"[[[";
            for (auto p : it2->second)
            {
                cout<<p<<", ";
            }
            cout<<"]]]";
            cout<<endl;
        }
    }
    #endif // __test
};


int main()
{
    RandomizedCollection col;
    col.insert(10);
    col.insert(10);
    col.insert(20);
    col.insert(20);
    col.insert(30);
    col.insert(30);

    col.show2();

    col.remove(10);
        col.show2();
    col.remove(10);
        col.show2();
    col.remove(30);
        col.show2();
    col.remove(30);


    col.show2();

    for (int i = 0; i < 10; i++)
    {
        cout<<"  "<<col.getRandom()<<endl;
    }

}

int main2()
{
//    vector<int> v;
//    v[100] = 1;       // error，这个是map的。
//    cout<<v.size()<<endl;


    // Init an empty collection.
//    RandomizedCollection collection = new RandomizedCollection();     // 这个直接抄页面的。。指针不能赋给非指针变量
    RandomizedCollection collection;

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
    cout<<collection.insert(1);
    cout<<endl;

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
    cout<<collection.insert(1);cout<<endl;

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
    cout<<collection.insert(2);cout<<endl;

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
    cout<<collection.getRandom();cout<<endl;

// Removes 1 from the collection, returns true. Collection now contains [1,2].
    cout<<collection.remove(1);cout<<endl;

// getRandom should return 1 and 2 both equally likely.
    cout<<collection.getRandom();cout<<endl;

    collection.show2();

    cout<<"----------"<<endl;
    collection.insert(10);
    collection.insert(20);
    collection.insert(10);
    collection.insert(10);
    collection.insert(30);



    for (int i = 0; i < 10; i++)
    {
        cout<<collection.getRandom()<<endl;
    }

    return 0;
}
