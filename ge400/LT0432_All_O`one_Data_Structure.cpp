
#include "../header/myheader.h"


// details
//    struct Bucket {
//        int value;
//        unordered_set<string> keys;
//        Bucket(int v) : value(v) {}
//    };
//    list<Bucket> buckets;
//    unordered_map<string, list<Bucket>::iterator> mp;
//
//            auto nxt = std::next(it);
//            if ((nxt == buckets.end()) || (nxt->value != it->value + 1)) {
//                nxt = buckets.insert(nxt, Bucket(it->value + 1));
//            }
// 相同次数的key放在一个桶内。。空桶删除。没桶就增加。
// val改变时，观察前一个桶，或后一个桶，是否等于-+1。



//Runtime: 44 ms, faster than 91.30% of C++ online submissions for All O`one Data Structure.
//Memory Usage: 22.6 MB, less than 100.00% of C++ online submissions for All O`one Data Structure.


// map..max heap...min heap
// map..linked-list

class AllOne {
    struct Node {
        string key;
        int val;
        Node* prev;
        Node* next;
    };
    Node head;
    Node tail;
    map<string, Node*> map2;            // 原地爆炸。。。太难了，，，map<string, Node>。的话，后续删掉一个key后，map会部分元素前移(地址会发生变动)，导致Node里的指针地址指向错误
public:
    /** Initialize your data structure here. */
    AllOne() {
        head.next = &tail;
        tail.prev = &head;
        head.key = "";
        tail.key = "";
        head.val = INT_MIN;
        tail.val = INT_MAX;
        head.prev = NULL;
        tail.next = NULL;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        Node* n;        // 和n2一样，必须指针，否则是一个复制。
        if (map2.find(key) != map2.end()) {
            n = map2[key];
        } else {
            n = new Node();
            n->key = key;
            n->val = 1;
            n->next = head.next;
            n->prev = &head;
            head.next = n;
            if (n->next != NULL)
                n->next->prev = n;
            map2.insert({key, n});
            return;
        }

        n->val++;
        Node* n2 = n->next;             // Node n2 = *n->next; 这个n2是新建的临时变量，并不是真正n->next指向的对象，是它的一个复制。
        if (n->next != NULL && n->val > n->next->val) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            n->next = NULL;
            n->prev = NULL;
            while (n2->val < n->val) {
                n2 = n2->next;
            }
            n->prev = n2->prev;
            n->next = n2;
            n2->prev->next = n;
            n2->prev = n;
        }
    }

    // comment: dec 1, if val==1 remove.
    // problem: if val==1 remove else dec 1.
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (map2.find(key) == map2.end()) {
            return;
        }
        Node* n = map2[key];
        if (1 == n->val--) {             // 1 or 2
            n->prev->next = n->next;
            n->next->prev = n->prev;
            map2.erase(key);
        } else {
            Node* n2 = n->prev;
            if (n->prev != NULL && n->val < n->prev->val) {
                n->prev->next = n->next;
                n->next->prev = n->prev;
                n->next = NULL;
                n->prev = NULL;
                while (n2 != NULL && n2->val > n->val) {
                    n2 = n2->prev;
                }
                n->prev = n2;
                n->next = n2->next;
                n2->next->prev = n;
                n2->next = n;
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return tail.prev->key;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return head.next->key;
    }

    void show2() {
//        cout<<"map : "<<map2.size()<<endl;
//        for (auto it = map2.begin(); it != map2.end(); it++) {
//            cout<<"      "<<it->first<<", "<<it->second->val<<", ";
//            cout<<it->second->key<<", "<<it->second->prev<<", "<<it->second->next<<", ";
//            cout<<&it->second<<endl;
//        }
//        cout<<"list:"<<endl;
//        Node* n4 = &head;
//        while (n4 != NULL) {
//            cout<<n4<<"...|..."<<n4->val<<". . . "<<n4->key<<endl;
//            n4 = n4->next;
//        }
    }

};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main() {
    AllOne ao;

//    cout<<ao.getMaxKey()<<", "<<ao.getMinKey()<<endl;

//    ao.inc("aa");
//    ao.inc("ab");
//    ao.inc("ab");
//    ao.inc("cc");
//    ao.dec("cc");
//    ao.inc("ab");
//    ao.dec("ab");


    ao.inc("a");
    ao.inc("b");
    ao.inc("b");
    ao.inc("c");
    ao.inc("c");
    ao.inc("c");
    ao.dec("b");
    ao.dec("b");

    ao.show2();

    cout<<(ao.getMinKey().empty() ? "empty" : ao.getMinKey())<<endl;

    ao.dec("a");
    cout<<endl<<endl;
    ao.show2();

    cout<<(ao.getMaxKey().empty() ? "empty" : ao.getMaxKey())<<endl;
    cout<<(ao.getMinKey().empty() ? "empty" : ao.getMinKey())<<endl;



//    cout<<"........\n"<<endl;
//    ao.show2();
//    cout<<"...\n\n\n...."<<endl;
//
//    cout<<ao.getMaxKey()<<", "<<ao.getMinKey()<<endl;

}
