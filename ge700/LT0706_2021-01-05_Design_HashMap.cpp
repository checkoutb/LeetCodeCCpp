
#include "../header/myheader.h"

class LT0706
{
public:



};

// D D

//        class ListNode {
//            int key, val;
//            ListNode next;
//            ListNode(int key, int val) {
//                this.key = key;
//                this.val = val;
//            }
//        }
//
//final ListNode[] nodes = new ListNode[10000];





//Runtime: 152 ms, faster than 77.37% of C++ online submissions for Design HashMap.
//Memory Usage: 46.2 MB, less than 83.12% of C++ online submissions for Design HashMap.
// 最好 vp 有序。 list， 但是list 无法二分，   vector能二分，但是为了有序，插入时会移动数据。。。 感觉 跳表最合适了，但。。
class MyHashMap {

    vector<vector<pair<int, int>>> vvp;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        vvp = vector<vector<pair<int, int>>>(1000);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key % 1000;
        vector<pair<int, int>>& vp = vvp[idx];
        for (int i = 0; i < vp.size(); ++i)
        {
            if (vp[i].first == key)
            {
                vp[i].second = value;
                return;
            }
        }
        vp.push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key % 1000;
        vector<pair<int, int>>& vp = vvp[idx];
        for (int i = 0; i < vp.size(); ++i)
        {
            if (vp[i].first == key)
                return vp[i].second;            // maybe -1;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        vector<pair<int, int>>& vp = vvp[key % 1000];
        for (int i = 0; i < vp.size(); ++i)
        {
            if (vp[i].first == key)
            {
                vp[i].second = -1;
                return;
            }
        }
    }
};



int main()
{

    LT0706 lt;

    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    cout<<endl<<hashMap.get(1);            // returns 1
    cout<<endl<<hashMap.get(3);            // returns -1 (not found)
    hashMap.put(2, 1);          // update the existing value
    cout<<endl<<hashMap.get(2);            // returns 1
    hashMap.remove(2);          // remove the mapping for 2
    cout<<endl<<hashMap.get(2);            // returns -1 (not found)


    return 0;
}
